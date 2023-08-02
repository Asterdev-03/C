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
    int found = 0, position = -1;
    char buffer[1000];
    char dict[4][3][1024] = {
        {"Term1", "Meaning1", "Antonym1"},
        {"Term2", "Meaning2", "Antonym2"},
        {"Term3", "Meaning3", "Antonym3"},
        {"Term4", "Meaning4", "Antonym4"},
    };

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

    while (1)
    {
        recv(clientSocket, buffer, sizeof(buffer), 0);
        printf("Word: %s \n", buffer);
        for (int i = 0; i < 4; i++)
        {
            if (strcmp(buffer, dict[i][0]) == 0)
            {
                found = 1;
                position = i;
                break;
            }
        }
        if (found == 1)
        {
            strcpy(buffer, dict[position][1]);
            send(clientSocket, buffer, sizeof(buffer), 0);
            strcpy(buffer, dict[position][2]);
            send(clientSocket, buffer, sizeof(buffer), 0);
            found = 0;
        }
        else
        {
            strcpy(buffer, "Not Found");
            send(clientSocket, buffer, sizeof(buffer), 0);
            send(clientSocket, buffer, sizeof(buffer), 0);
        }
    }

    return 0;
}
