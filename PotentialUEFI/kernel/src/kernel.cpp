#include <stdint.h>
#include "BasicRenderer.h"
#include "cstr.h"
#include "efiMemory.h"

struct BootInfo{
    Framebuffer* framebuffer;
    PSF1_FONT* psf1_Font;
    void* mMap;
    uint64_t mMapSize, mMapDescSize;
};

extern "C" void _start(BootInfo* bootInfo) {
    BasicRenderer newRenderer = BasicRenderer(bootInfo->framebuffer, bootInfo->psf1_Font);

    uint64_t mMapEntries = bootInfo->mMapSize / bootInfo->mMapDescSize;

    for(int i = 0; i < mMapEntries; i++) {
        EFI_MEMORY_DESCRIPTOR* desc = (EFI_MEMORY_DESCRIPTOR*)((uint64_t)bootInfo->mMap + (i * bootInfo->mMapDescSize));
        newRenderer.Print(EFI_MEMORY_TYPE_STRINGS[desc->type]);
        newRenderer.Color = 0xffff00ff;
        newRenderer.Print(" ");
        newRenderer.Print(to_string(desc->numPages * 4096 / 1024));
        newRenderer.Print(" KB");
        newRenderer.Color = 0xffffffff;
        newRenderer.CursorPosition = {0, newRenderer.CursorPosition.Y + 16};
    }

    return ;
}