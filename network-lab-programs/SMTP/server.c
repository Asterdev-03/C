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
    printf("Recieved: %s \n", buffer);
    strcpy(buffer, "Server Greeting Hello");
    send(clientSocket, buffer, sizeof(buffer), 0);

    recv(clientSocket, buffer, sizeof(buffer), 0);
    printf("MAIL FROM: %s \n", buffer);

    recv(clientSocket, buffer, sizeof(buffer), 0);
    printf("RECPT TO: %s \n", buffer);

    recv(clientSocket, buffer, sizeof(buffer), 0);
    printf("Mail Received: %s \n", buffer);

    return 0;
}
