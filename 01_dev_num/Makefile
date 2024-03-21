CROSS_TCHAIN_DIR := /home/duc/beaglebone/gcc-linaro-6.5.0-2018.12-x86_64_arm-linux-gnueabihf/bin
KERNEL_DIR := /home/duc/beaglebone/bb-kernel/KERNEL
PREFIX	:= arm-linux-gnueabihf-
EXTRA_CFLAGS = -Wall
obj-m = dev_num.o

KDIR = /lib/modules/`uname -r`/build

all:
	make ARCH=arm CROSS_COMPILE=${CROSS_TCHAIN_DIR}/${PREFIX} -C ${KERNEL_DIR} M=$(PWD) modules
clean :
	make ARCH=arm CROSS_COMPILE=${CROSS_TCHAIN_DIR}/${PREFIX} -C ${KERNEL_DIR} M=$(PWD) clean
help :
	make ARCH=arm CROSS_COMPILE=${CROSS_TCHAIN_DIR}/${PREFIX} -C ${KERNEL_DIR} M=$(PWD) help
host:
	make -C $(KDIR) M=`pwd` modules
# clean:
# 	make -C $(KDIR) M=`pwd` clean