#include "bmapi.h"

int BM_i2r(void * ptr, int input_id) 
{
  u32 controlreg, value, base_offset;

  if (input_id < LOWER_REG_LIMIT)
    return BMERR;

  if (input_id > UPPER_REG_LIMIT)
    return BMERR;

  base_offset = 2 * ((u32) input_id);

  controlreg = Xil_In32(OUT_BASE + base_offset - 2);
  value = Xil_In32(OUT_BASE + base_offset - 1);

  return BMOK;
}
