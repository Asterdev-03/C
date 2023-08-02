#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main()
{
    int serverSocket, clientSocket;
    char buffer[1000];
    FILE *fp;

    struct sockaddr_in serverAddr;
    socklen_t addrSize;

    serverSocket = socket(PF_INET, SOCK_STREAM, 0);
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(7891);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    memset(serverAddr.sin_zero, '\0', sizeof(serverAddr.sin_zero));
    bind(serverSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr));
    addrSize = sizeof(serverAddr);

    if (listen(serverSocket, 5) == 0)
    {
        printf("listening\n");
    }
    else
    {
        printf("error\n");
    }

    clientSocket = accept(serverSocket, (struct sockaddr *)&serverAddr, &addrSize);
    printf("Connected\n");

    recv(clientSocket, buffer, sizeof(buffer), 0);

    fp = fopen(buffer, "r");
    while (fgets(buffer, sizeof(buffer), fp))
    {
        send(clientSocket, buffer, sizeof(buffer), 0);
    }
    strcpy(buffer, "completed");
    send(clientSocket, buffer, sizeof(buffer), 0);

    return 0;
}
