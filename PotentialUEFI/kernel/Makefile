CFLAGS = -ffreestanding -fshort-wchar
LDFLAGS = -T kernel.ld -static -Bsymbolic -nostdlib

SRCDIR := src
OBJDIR := lib
BUILDDIR = bin
BOOTEFI := $(GNUEFI)/x86_64/bootloader/main.efi

rwildcard=$(foreach d,$(wildcard $(1:=/*)),$(call rwildcard,$d,$2) $(filter $(subst *,%,$2),$d))

SRC = $(call rwildcard,$(SRCDIR),*.c)
OBJS = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRC))
DIRS = $(wildcard $(SRCDIR)/*)

kernel: $(OBJS) link

$(OBJDIR)/%.o: $(SRCDIR)/%.c
		@ echo "[MAKE] Compiling $^..."
		@ mkdir -p $ @D
		gcc $(CFLAGS) -c $^ -o $@

link:
		@ echo !==== LINKING
		ld $(LDFLAGS) -o  $(BUILDDIR)/kernel.elf $(OBJS)


buildimg:
	# dd = duplicate data, if=/dev/zero = image file of dev/zero (limitless supply of zeros) bs = block size of 500M, count = repeat this count 32768x
	dd if=/dev/zero of=bin/MyOS.img bs=1024 count=32768
	mkfs.vfat bin/MyOS.img
	mmd -i bin/MyOS.img ::/EFI
	mmd -i bin/MyOS.img ::/EFI/BOOT
	mcopy -i bin/MyOS.img ../gnu-efi/x86_64/bootloader/main.efi ::/EFI/BOOT
	mcopy -i bin/MyOS.img startup.nsh ::
	mcopy -i bin/MyOS.img $(BUILDDIR)/kernel.elf ::

# -m = RAM e.g. 256M = 256 megabytes of RAM
# -cpu = Specifies CPU, e.g. qemu64 CPU
#  -drive = Configuration of the hard drive
#  -net = Network e.g. -net none (because we're not using network yet)
run:
	qemu-system-x86_64 -drive file=bin/MyOS.img -m 256M -cpu qemu64 -drive if=pflash,format=raw,unit=0,file="../OVMFbin/OVMF_CODE-pure-efi.fd",readonly=on -drive if=pflash,format=raw,unit=1,file="../OVMFbin/OVMF_VARS-pure-efi.fd" -net none

