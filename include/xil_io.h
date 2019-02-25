#ifndef FAKE_XIL_IO_H      
#define FAKE_XIL_IO_H  

/* fake placeholder */

#ifndef XIL_IO_H

#include <asm/types.h>
#define u32 __u32

#define UINTPTR __u32

u32 Xil_In32(UINTPTR);
void Xil_Out32(UINTPTR, u32);
void xil_printf( const char *ctrl1, ...);

#endif

#endif
