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

    clientSocket = socket(PF_INET, SOCK_STREAM, 0);

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(7891);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    memset(serverAddr.sin_zero, '\0', sizeof(serverAddr.sin_zero));
    addrSize = sizeof(serverAddr);

    connect(clientSocket, (struct sockaddr *)&serverAddr, addrSize);
    printf("Connected\n");

    strcpy(buffer, "Client Greeting Hello");
    send(clientSocket, buffer, sizeof(buffer), 0);
    recv(clientSocket, buffer, sizeof(buffer), 0);
    printf("Received: %s \n", buffer);

    printf("Enter FROM address: ");
    scanf("%s", buffer);
    send(clientSocket, buffer, sizeof(buffer), 0);

    printf("Enter TO address: ");
    scanf("%s", buffer);
    send(clientSocket, buffer, sizeof(buffer), 0);

    printf("Enter mail body:\n");
    int i = 0;
    char ch;
    while ((ch = getchar()) != '#') // stops when input is #
    {
        if (ch == '\0')
            continue;
        buffer[i++] = ch;
    }
    buffer[i] = '\0';

    printf("%s", buffer);
    send(clientSocket, buffer, sizeof(buffer), 0);

    return 0;
}
