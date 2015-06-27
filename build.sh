rm out.o kernel.img
arm-none-eabi-gcc -nostdlib stubStart.S -o out.o serial.c gpio.c main.c
./genBin.sh out.o
