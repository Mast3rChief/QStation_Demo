#Q Station C Demo

This is a litte Q Station demo program written in C. It connects your Q Station with your Adafruit.io interface. You can turn your bulbs on / off (for now).

##Instructions

1. Install build depencies

	> Follow there instructions: https://wiki.openwrt.org/doc/howto/buildroot.exigence

2. Clone OpenWRT from github (Do the following things as non root user!)

	> git clone -b attitude_adjustment https://github.com/openwrt/openwrt.git

3. Enter OpenWRT dir

	> cd openwrt

4. Update and install packages

	> ./scripts/feeds update -a
	> ./scripts/feeds install -a

4. Check prerequisites and prepare toolchain buidling

	> make defconfig
	> make prereq
	> make menuconfig

5. Now check the system and build toolchain options in menuconfig

	> Atheros AR7xx/AR9xx
	> [x] Build the OpenWRT Toolchain

6. Build the toolchain

	> make V=99 

7. Back to your user dir

	> cd ..

8. Clone the source code from github with git

	> git clone https://github.com/Mast3rChief/QStation_Demo.git

9. Enter QStation Demo dir

	> cd QStation_Demo

10. Compile everything

	> make main

11. Copy the program to your QStation and create the config.ini with your Adafruit.io API key. For example download it from your webserver.

	> cd /tmp
	> mkdir /QStation_Demo
	> wget ... or scp ...
	> vim config.ini
	> paste your AIO API Key (No spaces)

12. Run the program and have fun

	> ./main MD1AC44200003128

##Screenshots

![Screenshot of the running program](http://i.imgur.com/TF28BXN.jpg)

##Credits

* [Belleds Homepage](http://www.belleds.com/en/)

* [QStation API Documentation](https://github.com/BelledsQ/QStation_API)

* [QStation OpenWRT Fork](https://github.com/BelledsQ/BelledsQ_EVB)
