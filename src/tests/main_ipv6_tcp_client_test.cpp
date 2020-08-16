//
// file:			main_ipv6_tcp_client_test.cpp  
// created on:		2020 Aug 16  
// created by:		D. Kalantaryan (davit.kalantaryan@gmail.com)
//

#include <stdio.h>
#include <stdlib.h>
#ifdef _WIN32
#else
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#endif
#include "ipv6_tcp_server_client_common.h"
 
int main(int a_argc, char* a_argv[])
{
	int sock_fd = -1;
	struct sockaddr_in6 server_addr;
	int ret;
	char ch = 'a';
 
	/* Arguments could be used in getaddrinfo() to get e.g. IP of server */
	if(a_argc<2){
		fprintf(stderr,"server ipv6 address is not provided!\n");
		return 1;
	}
 
	/* Create socket for communication with server */
	sock_fd = socket(AF_INET6, SOCK_STREAM, IPPROTO_TCP);
	if (sock_fd == -1) {
		perror("socket()");
		return EXIT_FAILURE;
	}
 
	/* Connect to server running on localhost */
	server_addr.sin6_family = AF_INET6;
	inet_pton(AF_INET6, a_argv[1], &server_addr.sin6_addr);
	server_addr.sin6_port = htons(SERVER_PORT);
 
	/* Try to do TCP handshake with server */
	ret = connect(sock_fd, (struct sockaddr*)&server_addr, sizeof(server_addr));
	if (ret == -1) {
		perror("connect()");
		close(sock_fd);
		return EXIT_FAILURE;
	}
 
	/* Send data to server */
	ret = write(sock_fd, &ch, 1);
	if (ret == -1) {
		perror("write");
		close(sock_fd);
		return EXIT_FAILURE;
	}
 
	/* Wait for data from server */
	ret = read(sock_fd, &ch, 1);
	if (ret == -1) {
		perror("read()");
		close(sock_fd);
		return EXIT_FAILURE;
	}
 
	printf("Received %c from server\n", ch);
 
	/* DO TCP teardown */
	ret = close(sock_fd);
	if (ret == -1) {
		perror("close()");
		return EXIT_FAILURE;
	}
 
	return EXIT_SUCCESS;
}
