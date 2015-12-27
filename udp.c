#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#define DEBUG_PRINT(text) printf("%s", text)

int udp_send(const char *sendbuf)
{
	int		fd;
	struct		sockaddr_in server;
	struct		hostent *he;
	socklen_t	len;

	if((fd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == -1)
	{
		DEBUG_PRINT("Function socket() error.\n");
		return EXIT_FAILURE;
	}

	bzero(&server, sizeof(server));
	server.sin_family = AF_INET;
	server.sin_port = htons(11600);

	if((he = gethostbyname("127.0.0.1")) == NULL)
	{
		DEBUG_PRINT("Function gethostbyname() error.\n");
		close(fd);
		return EXIT_FAILURE;
	}

	server.sin_addr = *((struct in_addr *)he->h_addr);

	len = sizeof(struct sockaddr_in);

	if(sendto(fd, sendbuf, strlen(sendbuf), 0, (struct sockaddr *)&server, len) != strlen(sendbuf))
	{
		DEBUG_PRINT("Funtcion sendto() error.\n");
		close(fd);
		return EXIT_FAILURE;
	}

	close(fd);
	return EXIT_SUCCESS;
}
