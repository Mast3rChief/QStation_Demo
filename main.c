#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "http.h"
#include "udp.h"

int main(void)
{
	int 	prev_value = 100;
	int 	recent_value = 1;
	FILE*	stream;
	char	request[1024], buf[1024];

	stream = fopen("config.ini", "r");
	fread(buf, sizeof(char), sizeof(buf), stream); 
	fclose(stream);

	while(1)
	{
		sprintf(request, "https://io.adafruit.com/api/feeds/qstation?x-aio-key=%s", buf);
		recent_value = http_request(request);

		if(prev_value != 100 && recent_value != prev_value)
		{
			if(recent_value == 2)
			{
				printf("Turn bulbs off.\n");
				udp_send("{\"iswitch\":\"0\",\"r\":\"255\",\"g\":\"255\",\"b\":\"255\",\"bright\":\"20\",\"cmd\":\"light_ctrl\",\"effect\":\"9\",\"sn_list\":[{\"sn\":\"TEST123\"}]}");
			}
			else if(recent_value == 3)
			{
				printf("Turn bulbs on.\n");
				udp_send("{\"iswitch\":\"1\",\"r\":\"255\",\"g\":\"255\",\"b\":\"255\",\"bright\":\"20\",\"cmd\":\"light_ctrl\",\"effect\":\"9\",\"sn_list\":[{\"sn\":\"TEST123\"}]}");
			}
			else printf("Unknown value.\n");
		}

		prev_value = recent_value;
		sleep(10);
	}
	return EXIT_SUCCESS;
}
