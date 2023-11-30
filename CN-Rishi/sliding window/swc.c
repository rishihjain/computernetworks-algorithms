#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/time.h>
#include <math.h>

#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 8080
#define PACKET_SIZE 1024
#define PACKETS 15

double get_time() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (double)tv.tv_sec + (double)tv.tv_usec / 1000000.0;
}

int main() {
    int sockfd;
    struct sockaddr_in server_addr;

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd == -1) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    server_addr.sin_addr.s_addr = inet_addr(SERVER_IP);

    char buffer[PACKET_SIZE];
    int next_seq_num = 0;
    int base = 0;
    int total_packets_sent = 0;

    double Tp, Tt;
    printf("Enter Tp (Propagation Time) in usec: ");
    scanf("%lf", &Tp);
    printf("Enter Tt (Transmission Time) in usec: ");
    scanf("%lf", &Tt);

    double a = Tp / Tt;

    int window_size = (int)fmin(1 + 2 * a, pow(2, log2(1 + 2 * a)));

    printf("Window size: %d\n", window_size);

    double start_time, end_time;
    double total_transmission_time = 0.0; 

    while (total_packets_sent < PACKETS) {
        int packets_to_send = window_size;
        

        while (next_seq_num < base + packets_to_send && next_seq_num < PACKETS) {
            
            double total_time = Tt + Tp + Tt + Tp; 

            
            total_transmission_time += total_time;

            snprintf(buffer, sizeof(buffer), "Packet %d", next_seq_num);
            sendto(sockfd, buffer, strlen(buffer), 0, (struct sockaddr *)&server_addr, sizeof(server_addr));
            printf("Sent: %s\n", buffer);

            next_seq_num++;
            total_packets_sent++;
        }

        
        for (int ack = base; ack < next_seq_num; ack++) {
            printf("Received ACK for Packet %d\n", ack);
        }

        base = next_seq_num;
    }

    printf("All packets sent successfully.\n");
    printf("Total transmission time for all packets: %f usecs\n", total_transmission_time);

    close(sockfd);
    return 0;
}

