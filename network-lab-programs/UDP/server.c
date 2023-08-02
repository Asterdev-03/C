#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main()
{
    int serverSocket;
    char buffer[1000];

    struct sockaddr_in serverAddr;
    socklen_t addrSize;

    serverSocket = socket(AF_INET, SOCK_DGRAM, 0);
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(7891);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    memset(serverAddr.sin_zero, '\0', sizeof(serverAddr.sin_zero));
    bind(serverSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr));
    addrSize = sizeof(serverAddr);

    if (listen(serverSocket, 5) < 0)
    {
        printf("listening\n");
    }
    else
    {
        printf("error\n");
    }

    recvfrom(serverSocket, buffer, sizeof(buffer), 0, (struct sockaddr *)&serverAddr, &addrSize);
    printf("Data Received: %s \n", buffer);

    sleep(3);

    strcpy(buffer, "Bye");
    sendto(serverSocket, buffer, sizeof(buffer), 0, (struct sockaddr *)&serverAddr, addrSize);
    printf("Data Send: %s \n", buffer);
    return 0;
}
