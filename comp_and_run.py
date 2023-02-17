import os
'''
Sets of commands to compile and run on your system for testing. Change the commented lines for your OS
Current System: Ubuntu 20.04
'''
try: 
    os.chdir("/home/pokerfacer/SJSUOperatingSystem/PotentialUEFI/gnu-efi/") # Change based on your path and OS
    os.system("make bootloader") 
    os.chdir("/home/pokerfacer/SJSUOperatingSystem/PotentialUEFI/kernel") # Change based on your path and OS
    os.system("make kernel")
    os.system("make buildimg")
    os.system("make run")
except:
    print("Check output, something went wrong")
