# Nome do executável que será gerado
EXECUTABLE = server

# Lista de arquivos fonte do seu servidor RTSP
SOURCES = server.c client.c

# Compilador e opções de compilação
CC = gcc
CFLAGS = -Wall -g

# Diretório onde os arquivos de inclusão estão localizados
INCLUDES = -I./include

# Diretório onde as bibliotecas estão localizadas
LIBS = -L./lib

# Bibliotecas a serem vinculadas
# LDLIBS = -lname_da_biblioteca
LDLIBS = ''

# Comando padrão
all: $(EXECUTABLE)

$(EXECUTABLE): $(SOURCES)
    $(CC) $(CFLAGS) $(INCLUDES) $(LIBS) $(SOURCES) -o $(EXECUTABLE) $(LDLIBS)

clean:
    rm -f $(EXECUTABLE)
