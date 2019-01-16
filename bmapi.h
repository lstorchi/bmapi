#ifndef __BM_API_INC__
#define __BM_API_INC__

#include <asm/types.h>

#ifndef OUT_BASE 
#define OUT_BASE 0x00000000
#endif

#ifndef u32
#define u32 __u32
#endif

#ifndef Xil_In32
u32 Xil_In32( u32 );
#endif

#ifndef Xil_Out32
void Xil_Out32(u32, u32); 
#endif

#define BMERR -1
#define BMOK 0

#define UPPER_REG_LIMIT 128
#define LOWER_REG_LIMIT 1

#define DATA_VALID 0
#define DATA_RECV 1

int BM_i2r(void * ptr, int input_id);
int BM_i2rw(void * ptr, int input_id);   
int BM_i2rwa(void * ptr, int input_id);

int BM_r2o(void * ptr, int output_id);
int BM_r2ow(void * ptr, int output_id);
int BM_r2owa(void * ptr, int output_id);

#endif
