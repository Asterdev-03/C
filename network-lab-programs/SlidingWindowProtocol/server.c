#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define SIZE 4

int main()
{
    int serverSocket, clientSocket;
    char buffer[1000], str[1000], temp[1000];

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

    printf("Enter text to send: ");
    scanf("%s", str);

    int i = 0;
    while (i < strlen(str))
    {
        memset(buffer, 0, sizeof(buffer));
        strncpy(buffer, str + i, SIZE);
        int len = strlen(buffer);
        for (int j = 0; j < len; j++)
        {
            sprintf(temp, "%d", i + j);
            strcat(buffer, temp);
        }
        printf("Frame Transmitted: %s \n", buffer);
        send(clientSocket, buffer, sizeof(buffer), 0);

        recv(clientSocket, buffer, sizeof(buffer), 0);
        int status = atoi(buffer);
        if (status == -1)
        {
            printf("Transmission is successfull \n");
            i += SIZE;
        }
        else
        {
            printf("Recieved an error in %d \n", status);
            i = status;
        }
    }
    strcpy(buffer, "exit");
    send(clientSocket, buffer, sizeof(buffer), 0);
    printf("Exiting\n");

    return 0;
}
