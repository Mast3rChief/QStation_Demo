#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DEBUG_PRINT(text) printf("%s", text)

int http_request(const char *server)
{
	FILE*	stream;
	char	request[1024], buf[1024];

	if(server)
	{
		sprintf(request, "curl --silent --insecure %s", server); // I am so sorry for this :/

		stream = popen(request, "r");
		fread(buf, sizeof(char), sizeof(buf), stream);
		pclose(stream);

		if(strstr(buf, "\"last_value\":\"OFF\"") != 0) return 2;
		else if(strstr(buf, "\"last_value\":\"ON\"") != 0) return 3;
		else return EXIT_FAILURE;
	}
	else
	{
		return EXIT_FAILURE;
	}
}
