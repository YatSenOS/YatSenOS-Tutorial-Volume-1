build:
	nasm -f bin mbr.asm -o mbr.bin
	nasm -f bin bootloader.asm -o bootloader.bin
	dd if=mbr.bin of=hd.img bs=512 count=1 seek=0 conv=notrunc
	dd if=bootloader.bin of=hd.img bs=512 count=5 seek=1 conv=notrunc
run:
	qemu-system-i386 -hda hd.img -serial null -parallel stdio 
clean:
	rm -fr *.bin