#ifndef __STRUCT_H__
    #define __STRUCT_H__

    #include "types.h"

typedef struct {
    char VbeSignature[4];                   // VBE Signature
    u16 VbeVersion;                         // VBE version number
    char *OEMStringPtr;                     // Pointer to OEM string
    u32 Capabilities;                       // Capabilities of video card
    u32 *VideoModePtr;                      // Pointer to supported modes
    u16 TotalMemory;                        // Number of 64kb memory blocks
    u16 OemSoftwareRev;                     // VBE implementation Software revision
    u32 OemVendorNamePtr;                   // Pointer to Vendor Name String
    u32 OemProductNamePtr;                  // Pointer to Product Name String
    u32 OemProductRevPtr;                   // Pointer to Product Revision String
    char reserved[222];                     // Pad to 256 byte block size
    char OemData[256];                      // Data Area for OEM Strings
} __attribute__ ((packed)) VBE20_INFOBLOCK;

typedef struct {
    // Mandatory information for all VBE revisions
    u16 ModeAttributes;                     // Mode attributes
    u8 WinAAttributes;                      // Window A attributes
    u8 WinBAttributes;                      // Window B attributes
    u16 WinGranularity;                     // Window granularity in k
    u16 WinSize;                            // Window size in k
    u16 WinASegment;                        // Window A segment
    u16 WinBSegment;                        // Window B segment
    void (*WinFuncPtr)(void);                // Pointer to window function
    u16 BytesPerScanLine;                   // Bytes per scanline

    // Mandatory information for VBE 1.2 and above
    u16 XResolution;                        // Horizontal resolution
    u16 YResolution;                        // Vertical resolution
    u8 XCharSize;                           // Character cell width
    u8 YCharSize;                           // Character cell height
    u8 NumberOfPlanes;                      // Number of memory planes
    u8 BitsPerPixel;                        // Bits per pixel
    u8 NumberOfBanks;                       // Number of CGA style banks
    u8 MemoryModel;                         // Memory model type
    u8 BankSize;                            // Size of CGA style banks
    u8 NumberOfImagePages;                  // Number of images pages
    u8 Reserved;                            // Reserved

    // Direct color fields
    u8 RedMaskSize;                         // Size of direct color red mask
    u8 RedFieldPosition;                    // Bit posn of lsb of red mask
    u8 GreenMaskSize;                       // Size of direct color green mask
    u8 GreenFieldPosition;                  // Bit posn of lsb of green mask
    u8 BlueMaskSize;                        // Size of direct color blue mask
    u8 BlueFieldPosition;                   // Bit posn of lsb of blue mask
    u8 RsvdMaskSize;                        // Size of direct color res mask
    u8 RsvdFieldPosition;                   // Bit posn of lsb of res mask
    u8 DirectColorModeInfo;                 // Direct color mode attributes

    // Mandatory information for VBE 2.0 and above
    u32 PhysBasePtr;                        // physical address for flat frame buffer
    u32 OffScreenMemOffset;                 // pointer to start of off screen memory
    u16 OffScreenMemSize;                   // amount of off screen memory in 1k units
    u8 Reserved2[206];                      // remainder of ModeInfoBlock
} VBE20_MODEINFOBLOCK;

#endif