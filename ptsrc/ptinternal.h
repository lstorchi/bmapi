#ifndef _INC_PTINTERNAL_
#define _INC_PTINTERNAL_

#define cmdNEWVAL   (unsigned char) 0   // 000 00000
#define cmdDVALIDH  (unsigned char) 32  // 001 00000
#define cmdDVALIDL  (unsigned char) 64  // 010 00000
#define cmdDRECVH   (unsigned char) 96  // 011 00000
#define cmdDRECVL   (unsigned char) 128 // 100 00000
#define cmdHANDSH   (unsigned char) 160 // 101 00000
#define cmdKEEP     (unsigned char) 192 // 110 00000
#define cmdMASK     (unsigned char) 224 // 111 00000

#define PTDIMBITS 8

int * to_binary(unsigned char);

unsigned char from_binary(int val[PTDIMBITS]);

int set_interface_attribs (int, int, int);


#endif
