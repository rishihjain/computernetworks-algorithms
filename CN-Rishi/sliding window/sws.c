#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define SERVER_PORT 8080
#define PACKET_SIZE 1024

int main() {
    int sockfd;
    struct sockaddr_in server_addr, client_addr;

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd == -1) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("Error binding");
        exit(EXIT_FAILURE);
    }

    char buffer[PACKET_SIZE];
    int expected_seq_num = 0;

    while (1) {
        socklen_t client_addr_len = sizeof(client_addr);
        int recv_len = recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr *)&client_addr, &client_addr_len);

        if (recv_len == -1) {
            perror("Error receiving data");
            continue;
        }

        buffer[recv_len] = '\0';
        printf("Received: %s\n", buffer);

        usleep(1000); 

        printf("Sending ACK for Packet %d\n", expected_seq_num);
        sendto(sockfd, &expected_seq_num, sizeof(int), 0, (struct sockaddr *)&client_addr, client_addr_len);

        expected_seq_num++;
    }

    close(sockfd);
    return 0;
}

