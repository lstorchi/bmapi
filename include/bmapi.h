#ifndef __BM_API_INC__
#define __BM_API_INC__

#ifndef OUT_BASE 
#define OUT_BASE 0x00000000
#endif

#include "xil_io.h"
#include "bm_defined.h"

#define BMERR -1
#define BMOK 0

u32 get_in_control_addr (int id); 
u32 get_in_data_addr (int id);

u32 get_out_control_addr (int id); 
u32 get_out_data_addr (int id);

u32 get_in_data_valid_addr (int id);
u32 get_out_data_valid_addr (int id);

u32 get_in_data_recv_addr (int id);
u32 get_out_data_recv_addr (int id);

int BM_i2r(u32 * ptr, int input_id);
int BM_i2rw(u32 * ptr, int input_id);   
int BM_i2rwa(u32 * ptr, int input_id);

int BM_r2o(u32 * ptr, int output_id);
int BM_r2ow(u32 * ptr, int output_id);
int BM_r2owa(u32 * ptr, int output_id);

#endif
