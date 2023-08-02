#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main()
{
    int clientSocket;
    char buffer[1000];

    struct sockaddr_in serverAddr;
    socklen_t addrSize;

    clientSocket = socket(AF_INET, SOCK_DGRAM, 0);

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(7891);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    memset(serverAddr.sin_zero, '\0', sizeof(serverAddr.sin_zero));
    addrSize = sizeof(serverAddr);

    strcpy(buffer, "Hello");
    sendto(clientSocket, buffer, sizeof(buffer), 0, (struct sockaddr *)&serverAddr, addrSize);
    printf("Data Send: %s \n", buffer);

    recvfrom(clientSocket, buffer, sizeof(buffer), 0, (struct sockaddr *)&serverAddr, &addrSize);
    printf("Data Received: %s \n", buffer);

    return 0;
}
