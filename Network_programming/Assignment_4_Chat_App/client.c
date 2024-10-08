#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>
#include<unistd.h>

int main(int argc, char **argv)
{
    int sockfd, n;
    char sendline[100];
    char recvline[100];
    struct sockaddr_in servaddr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    bzero(&servaddr, sizeof servaddr);
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(22000);
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    // inet_pton(AF_INET,"127.0.0.1",&(servaddr.sin_addr));
    connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)); 
    while (1)
    {
        bzero(sendline, 100);
        bzero(recvline, 100);
        printf("send to server: ");
        fgets(sendline, 100, stdin); /*stdin = 0 , for standard input */
        if(strcmp(sendline,"exit")==0){
            break; close(sockfd);(0);
        }
        send(sockfd, sendline, strlen(sendline), 0);
        // $PLACEHOLDER$
        printf("recieved from server: ");
        recv(sockfd, recvline, 100, 0);
        printf("%s", recvline);
    }
}