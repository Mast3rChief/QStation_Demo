#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "http.h"
#include "udp.h"

int main(int argc, char *argv[])
{
	if(argc < 2)
	{
		printf("Usage ./main MD1AC44200003128\n");
		return EXIT_FAILURE;
	}

	int 	prev_value = 100;
	int 	recent_value = 1;
	FILE*	stream;
	char	request[1024], buf[1024], json[1024];

	stream = fopen("config.ini", "r");
	fread(buf, sizeof(char), sizeof(buf), stream);
	fclose(stream);

	printf("Bulb: %s\n", argv[1]);

	while(1)
	{
		sprintf(request, "https://io.adafruit.com/api/feeds/qstation?x-aio-key=%s", buf);
		recent_value = http_request(request);

		if(prev_value != 100 && recent_value != prev_value)
		{
			if(recent_value == 2)
			{
				printf("Turn bulb off.\n");
				sprintf(json, "{\"iswitch\":\"0\",\"r\":\"255\",\"g\":\"255\",\"b\":\"255\",\"bright\":\"20\",\"cmd\":\"light_ctrl\",\"effect\":\"9\",\"sn_list\":[{\"sn\":\"%s\"}]}", argv[1]);
				udp_send(json);
			}
			else if(recent_value == 3)
			{
				printf("Turn bulb on.\n");
				sprintf(json, "{\"iswitch\":\"1\",\"r\":\"255\",\"g\":\"255\",\"b\":\"255\",\"bright\":\"20\",\"cmd\":\"light_ctrl\",\"effect\":\"9\",\"sn_list\":[{\"sn\":\"%s\"}]}", argv[1]);
				udp_send(json);
			}
			else printf("ERROR: Unknown value.\n");
		}

		prev_value = recent_value;
		sleep(10);
	}
	return EXIT_SUCCESS;
}
