rm out.o kernel.img
arm-none-eabi-gcc -nostdlib stubStart.S -o out.o serial.c main.c
./genBin.sh out.o
