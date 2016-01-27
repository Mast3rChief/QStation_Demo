#Q Station C Demo

This is a litte Belleds Q Station demo program written in C. It connects your Belleds Q Station with your [Adafruit.io](https://io.adafruit.com/) interface. You can turn one of your bulbs on / off (for now). You need to add an on / off switch wich is connected to a feed named "qstation" in your [Adafruit.io](https://io.adafruit.com/) interaface.

##Instructions

### Build System

1. Install build depencies (See https://wiki.openwrt.org/doc/howto/buildroot.exigence for more information)

	```bash
	sudo apt-get install git-core subversion mercurial build-essential libssl-dev libncurses5-dev unzip gawk
	```

2. Clone OpenWRT from github (Do the following things as non root user!)

	```bash
	git clone -b attitude_adjustment https://github.com/openwrt/openwrt.git
	```

3. Enter OpenWRT dir

	```bash
	cd openwrt
	```

4. Update and install packages

	```bash
	./scripts/feeds update -a
	./scripts/feeds install -a
	```

4. Check prerequisites and prepare toolchain buidling (prereq will show you missing depencies)

	```bash
	make defconfig
	make prereq
	make menuconfig
	```

5. Now check the system and build toolchain options in menuconfig

	```
	Target System: Atheros (AR7xx/AR9xx)
	[*] Build the OpenWRT based Toolchain
	```

6. Build the toolchain (this will take up to three hours!)

	```bash
	make V=99
	```

7. Back to your user dir

	```bash
	cd ..
	```

8. Clone the source code from github with git

	```bash
	git clone https://github.com/Mast3rChief/QStation_Demo.git
	```

9. Enter QStation Demo dir

	```bash
	cd QStation_Demo
	```

10. Compile everything

	```bash
	make main
	```

11. Check file information of the compilied main program

	```bash
	file main
	```
	
13. The output should look something like this:

	```bash
	main: ELF 32-bit MSB executable, MIPS, MIPS32 rel2 version 1...
	```

### Belleds Q Station

1. Copy the program to your QStation and create the config.ini with your Adafruit.io API key. For example download it from your webserver. We use the tmp dir for testing only!

	```bash
	cd /tmp
	mkdir QStation_Demo
	cd QStation_Demo
	scp user@ip:/home/user/QStation_Demo/* .
	vim config.ini
	# press i for insert mode
	# paste your AIO API Key (No spaces)
	# press escape and :wq to exit vim
	```

2. Run the program and have fun

	```bash
	./main MD1AC44200003128
	```

##Screenshots

![Screenshot of the running program](http://i.imgur.com/TF28BXN.jpg)

##Credits

* [Belleds Homepage](http://www.belleds.com/en/)

* [QStation API Documentation](https://github.com/BelledsQ/QStation_API)

* [QStation OpenWRT Fork](https://github.com/BelledsQ/BelledsQ_EVB)
