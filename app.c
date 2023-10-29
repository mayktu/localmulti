#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define RTSP_PORT 554

int main() {
    int rtspSocket;
    struct sockaddr_in serverAddr, clientAddr;
    socklen_t clientAddrLen = sizeof(clientAddr);

    rtspSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (rtspSocket < 0) {
        perror("Erro ao criar soquete");
        exit(1);
    }

    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(RTSP_PORT);

    if (bind(rtspSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr) < 0)) {
        perror("Erro ao fazer o bind");
        close(rtspSocket);
        exit(1);
    }

    if (listen(rtspSocket, 5) < 0) {
        perror("Erro ao ouvir");
        close(rtspSocket);
        exit(1);
    }

    printf("Servidor RTSP está ouvindo na porta %d\n", RTSP_PORT);

    while (1) {
        int clientSocket = accept(rtspSocket, (struct sockaddr*)&clientAddr, &clientAddrLen);
        if (clientSocket < 0) {
            perror("Erro ao aceitar conexão do cliente");
            close(rtspSocket);
            exit(1);
        }

        printf("Cliente conectado: %s:%d\n", inet_ntoa(clientAddr.sin_addr), ntohs(clientAddr.sin_port));

        // Aqui você pode implementar a lógica para gerenciar a sessão RTSP
        // Isso pode incluir negociações de mídia, como seleção de codec, início e pausa do streaming, etc.

        close(clientSocket);
        printf("Cliente desconectado: %s:%d\n", inet_ntoa(clientAddr.sin_addr), ntohs(clientAddr.sin_port));
    }

    close(rtspSocket);

    return 0;
}
