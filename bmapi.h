#ifndef __BM_API_INC__
#define __BM_API_INC__

#ifndef OUT_BASE 
#define OUT_BASE 0x00000000
#endif

#ifndef u32
#include <asm/types.h>
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

#define BM_NUMOF_VALID_BIT 32
#define BM_DATA_VALID 0
#define BM_DATA_RECV 1

u32 get_control_addr (int input_id); 
u32 get_data_addr (int input_id);

int BM_i2r(u32 * ptr, int input_id);
int BM_i2rw(u32 * ptr, int input_id);   
int BM_i2rwa(u32 * ptr, int input_id);

int BM_r2o(u32 * ptr, int output_id);
int BM_r2ow(u32 * ptr, int output_id);
int BM_r2owa(u32 * ptr, int output_id);

#endif
