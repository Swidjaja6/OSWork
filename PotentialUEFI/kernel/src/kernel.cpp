#include "kernelUtil.h"

extern "C" void _start(BootInfo* bootInfo) {

    KernelInfo kernelInfo = InitializeKernel(bootInfo);
    PageTableManager* pageTableManager = kernelInfo.pageTableManager;
    BasicRenderer newRenderer = BasicRenderer(bootInfo->framebuffer, bootInfo->psf1_Font);

    newRenderer.Print("Kernel initialized Successfully");

    for(int t = 0; t < 5000; t++) {
        GlobalAllocator.RequestPage();
    }
    newRenderer.Print(" Done");

    while(true);
}