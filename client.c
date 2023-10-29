#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>

#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 554

int main() {
    int rtspSocket;
    struct sockaddr_in serverAddr;
    char requestBuffer[1024];

    rtspSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (rtspSocket < 0) {
        perror("Erro ao criar soquete");
        exit(1);
    }

    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(SERVER_PORT);
    serverAddr.sin_addr.s_addr = inet_addr(SERVER_IP);

    if (connect(rtspSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) < 0) {
        perror("Erro ao conectar ao servidor RTSP");
        close(rtspSocket);
        exit(1);
    }

    printf("Conectado ao servidor RTSP em %s:%d\n", SERVER_IP, SERVER_PORT);

    // Construa a solicitação RTSP (exemplo: solicitação de OPTIONS)
    snprintf(requestBuffer, sizeof(requestBuffer), "OPTIONS rtsp://%s:%d RTSP/1.0\r\n\r\n", SERVER_IP, SERVER_PORT);

    // Envie a solicitação para o servidor
    if (send(rtspSocket, requestBuffer, strlen(requestBuffer), 0) < 0) {
        perror("Erro ao enviar solicitação RTSP");
        close(rtspSocket);
        exit(1);
    }

    // Receba e processe a resposta do servidor RTSP
    char responseBuffer[1024];
    int bytesRead = recv(rtspSocket, responseBuffer, sizeof(responseBuffer), 0);
    if (bytesRead < 0) {
        perror("Erro ao receber resposta RTSP");
        close(rtspSocket);
        exit(1);
    }

    responseBuffer[bytesRead] = '\0';
    printf("Resposta do servidor RTSP:\n%s\n", responseBuffer);

    // Feche a conexão RTSP
    close(rtspSocket);

    return 0;
}
