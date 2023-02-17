# UEFI Application
Simple EFI Application to say Hello, World. Will be adding more

gnu-efi - Environment for creating UEFI applications<br/>
OVMFBin - Contains binaries required for UEFI to be started on QEMU instead of the default BIOS<br/>
kernel - Storage for kernel, will contain image file for QEMU.

## Instructions for running UEFI

Go to gnu-efi/bootloader and compile and link the main.c file to get main.efi
```./CompLink.sh```

Next make a directory named "bootloader" in x86_64 and copy your main.efi to there. You can do this through terminal/command line or through the file system. If someone can read and understand the Makefile better than I can and put this in that would be greatly appreciated. Otherwise, I'll find a time to do it. 

Direct yourself to PotentialUEFI/kernel, create a new directory called bin, direct to it, and create an image of at least 64 MB (The img file once built takes up 33.6 MB, but you can make it larger if you wish). 
```qemu-img create MyOS.img <size of image> \\ e.g. 1G, 256M, etc.```

Now, run ```make buildimg``` to build the image with the parameters (take a look in the Makefile on how they are made) and say ```make run``` to run it. 

QEMU should display "Hello, World!". If not, contact me on Discord. 
