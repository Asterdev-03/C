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
    int choice;

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

    while (1)
    {
        recv(clientSocket, buffer, sizeof(buffer), 0);
        if (strcmp(buffer, "exit") == 0)
        {
            printf("Exiting\n");
            break;
        }
        printf("Data Received: %s \n", buffer);

        printf("Do you want to report an error? (1-Yes, 0-No): ");
        scanf("%d", &choice);
        if (choice == 0)
        {
            strcpy(buffer, "-1");
            send(clientSocket, buffer, sizeof(buffer), 0);
        }
        else
        {
            printf("Enter sequence no. of frame where error is found:");
            scanf("%s", buffer);
            send(clientSocket, buffer, sizeof(buffer), 0);
        }
    }

    return 0;
}
