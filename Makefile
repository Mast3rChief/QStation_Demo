main: http.o http.h udp.o udp.h
	gcc main.c -o main http.o udp.o
http.o: http.c
	gcc -c http.c
udp.o: udp.c
	gcc -c udp.c
clean:
	rm main http.o udp.o
