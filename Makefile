TOOLCHAIN_DIR=$(PWD)/../openwrt/staging_dir/toolchain-mips_r2_gcc-4.6-linaro_uClibc-0.9.33.2/bin
STAGING_DIR=$(PWD)/../openwrt/staging_dir
CC=$(TOOLCHAIN_DIR)/mips-openwrt-linux-uclibc-gcc

main: http.o http.h udp.o udp.h
	$(CC) main.c -o main http.o udp.o
http.o: http.c
	$(CC) -c http.c
udp.o: udp.c
	$(CC) -c udp.c
clean:
	rm main http.o udp.o
