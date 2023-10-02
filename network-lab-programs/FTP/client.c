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
    char buffer[1000], fname[200];
    FILE *fp;

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

    printf("Enter existing file name: ");
    scanf("%s", buffer);
    send(clientSocket, buffer, sizeof(buffer), 0);

    printf("Enter new file name: ");
    scanf("%s", fname);

    fp = fopen(fname, "w");

    while (1)
    {
        recv(clientSocket, buffer, sizeof(buffer), 0);
        if (strcmp(buffer, "completed") == 0)
        {
            printf("\nFile Transferred \n");
            break;
        }
        fprintf(fp, "%s", buffer);
        printf("%s", buffer);
    }

    return 0;
}
