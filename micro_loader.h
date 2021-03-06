
// // Posted by Karri
// unsigned char micro_loader_fb68_stage1[52]={
//  0xff, 0x81, 0xca, 0x33, 0xbe, 0x80, 0xa2, 0xc4, 0x6d, 0x98, 0xfe, 0x8d, 0xbc, 0x66, 0xc0, 0x7a,
//  0x09, 0x50, 0x23, 0x28, 0x18, 0xc8, 0x06, 0x70, 0x58, 0x4f, 0x1b, 0xe1, 0xc7, 0x90, 0x08, 0xcd,
//  0x1a, 0x6e, 0x5a, 0x45, 0x32, 0xd7, 0x6d, 0xc6, 0x8a, 0xe5, 0xd8, 0x5c, 0xa0, 0xe8, 0x4f, 0x7a,
//  0x5f, 0x73, 0x8d, 0x22
// };

// new by private mail Sep 2017
unsigned char micro_loader_fb68_stage1[52]={
    0xff, 0xd9, 0x4a, 0xf6, 0x06, 0xf3, 0x67, 0xbe,
    0xaf, 0x9c, 0xe6, 0x58, 0x0e, 0xc0, 0x1a, 0x52,
    0x29, 0x17, 0x2a, 0x01, 0x5e, 0x83, 0x22, 0x49,
    0x10, 0xe5, 0xe5, 0xf2, 0xb9, 0x22, 0xec, 0xe5,
    0x9f, 0x32, 0x76, 0xa2, 0x2f, 0x14, 0xfb, 0x5c,
    0x14, 0xec, 0xa5, 0x5d, 0x49, 0x84, 0x1a, 0x1d,
    0x38, 0xea, 0xd3, 0x31
};

// and the secondary loader that follows the encrypted loader

unsigned char micro_loader_fb68_stage2[128+12+11]={
 0xa2, 0x00, 0xa0, 0x08, 0xad, 0xb2, 0xfc, 0x95, 0x26, 0xe8, 0x88, 0xd0,
 0xf7, 0xa5, 0x26, 0x85, 0x2e, 0x20, 0xca, 0xfb, 0xa5, 0x28, 0x49, 0xff, 0xa8, 0xa5, 0x27, 0x49,
 0xff, 0xaa, 0x20, 0xa1, 0xfb, 0xa5, 0x2a, 0xa6, 0x2b, 0x85, 0x31, 0x86, 0x32, 0xa5, 0x2d, 0x49,
 0xff, 0xa8, 0xa5, 0x2c, 0x49, 0xff, 0xaa, 0x20, 0xac, 0xfb, 0x6c, 0x2a, 0x00, 0xe8, 0xd0, 0x03,
 0xc8, 0xf0, 0x57, 0x20, 0xbf, 0xfb, 0x80, 0xf5, 0xe8, 0xd0, 0x03, 0xc8, 0xf0, 0x4c, 0x20, 0xbf,
 0xfb, 0x92, 0x31, 0xe6, 0x31, 0xd0, 0xf1, 0xe6, 0x32, 0x80, 0xed, 0xad, 0xb2, 0xfc, 0xe6, 0x2f,
 0xd0, 0x38, 0xe6, 0x30, 0xd0, 0x34, 0x48, 0xda, 0x5a, 0xa5, 0x1a, 0x29, 0xfc, 0xa8, 0x09, 0x02,
 0xaa, 0xa5, 0x2e, 0xe6, 0x2e, 0x38, 0x80, 0x0b, 0x90, 0x04, 0x8e, 0x8b, 0xfd, 0x18, 0xe8, 0x8e,
 0x87, 0xfd, 0xca, 0x8e, 0x87, 0xfd, 0x2a, 0x8c, 0x8b, 0xfd, 0xd0, 0xec, 0xa5, 0x1a, 0x8d, 0x8b,
 0xfd, 0x64, 0x2f, 0xa9, 0xfc, 0x85, 0x30, 0x7a, 0xfa, 0x68, 0x60
};

// After the secondary loader you need one directory entry:
//
// 00       = block number
// d3 00 = offset $00d3
// 88       = dummy byte
// 00 02 = start address in RAM $0200
// 07 10 = length of binary to load $1007
// 
// Then you just append your binary code you want to load.
// 
// You can change the start address and length to match your code.
// 
// The last  fc in the secondary loader should be different for different cart types.
// 
// fe = 128k cart
// fc = 256k cart
// f8 = 512k cart


// 52 bytes encrypted miniloader that will load the secondary loader to $F000

// Posted by Karri
unsigned char micro_loader_f000_stage1[52]={
	0xFF, 0x7A, 0xBF, 0xC9, 0x06, 0x98, 0xDB, 0x36, 0x88, 0xA4, 0x85, 0x4C, 0x5F, 0xD4, 0x92, 0xE1,
	0xF6, 0x72, 0x3B, 0xB7, 0x57, 0x99, 0x2A, 0xD8, 0x7F, 0x7C, 0x00, 0x5C, 0x68, 0x15, 0x20, 0xDD,
	0x18, 0xE1, 0x88, 0xE4, 0x37, 0x6C, 0x8B, 0x73, 0x3A, 0xA9, 0x10, 0xF2, 0x84, 0x12, 0xEF, 0x14,
	0x50, 0xA2, 0xF5, 0x08
};

// 151 bytes secondary loader that will be read starting at $F000

unsigned char micro_loader_f000_stage2[151]={
 0xa2, 0x00, 0xa0, 0x08, 0xad, 0xb2, 0xfc, 0x95, 0x26, 0xe8, 0x88, 0xd0,
 0xf7, 0xa5, 0x26, 0x85, 0x2e, 0x20, 0x62, 0xf0, 0xa5, 0x28, 0x49, 0xff, 0xa8, 0xa5, 0x27, 0x49,
 0xff, 0xaa, 0x20, 0x39, 0xf0, 0xa5, 0x2a, 0xa6, 0x2b, 0x85, 0x31, 0x86, 0x32, 0xa5, 0x2d, 0x49,
 0xff, 0xa8, 0xa5, 0x2c, 0x49, 0xff, 0xaa, 0x20, 0x44, 0xf0, 0x6c, 0x2a, 0x00, 0xe8, 0xd0, 0x03,
 0xc8, 0xf0, 0x57, 0x20, 0x57, 0xf0, 0x80, 0xf5, 0xe8, 0xd0, 0x03, 0xc8, 0xf0, 0x4c, 0x20, 0x57,
 0xf0, 0x92, 0x31, 0xe6, 0x31, 0xd0, 0xf1, 0xe6, 0x32, 0x80, 0xed, 0xad, 0xb2, 0xfc, 0xe6, 0x2f,
 0xd0, 0x38, 0xe6, 0x30, 0xd0, 0x34, 0x48, 0xda, 0x5a, 0xa5, 0x1a, 0x29, 0xfc, 0xa8, 0x09, 0x02,
 0xaa, 0xa5, 0x2e, 0xe6, 0x2e, 0x38, 0x80, 0x0b, 0x90, 0x04, 0x8e, 0x8b, 0xfd, 0x18, 0xe8, 0x8e,
 0x87, 0xfd, 0xca, 0x8e, 0x87, 0xfd, 0x2a, 0x8c, 0x8b, 0xfd, 0xd0, 0xec, 0xa5, 0x1a, 0x8d, 0x8b,
 0xfd, 0x64, 0x2f, 0xa9, 0xfc, 0x85, 0x30, 0x7a, 0xfa, 0x68, 0x60
};

// 8 bytes first directory entry. It will be loaded into ZP RAM
// 
// 00 d3 00 88 00 02 f2 0f
// 
// At this point the memory is free from 0200 to EFFF. So you can now load quite a big chunk in RAM.
