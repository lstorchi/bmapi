#include <string.h>

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
  memcpy(ptr, (const void *) &value, sizeof(u32));

  controlreg |= 1U << DATA_RECV;
  Xil_Out32 (OUT_BASE + base_offset - 2, controlreg);

  return BMOK;
}

int BM_i2rw(void * ptr, int input_id)
{
  u32 controlreg, value, base_offset;
  int bitvalue;

  if (input_id < LOWER_REG_LIMIT)
    return BMERR;

  if (input_id > UPPER_REG_LIMIT)
    return BMERR;

  base_offset = 2 * ((u32) input_id);

  do
  {
    controlreg = Xil_In32(OUT_BASE + base_offset - 2);
    bitvalue = (controlreg >> DATA_VALID) & 1U;
  } while (bitvalue == 0);

  value = Xil_In32(OUT_BASE + base_offset - 1);
  memcpy(ptr, (const void *) &value, sizeof(u32));
  
  controlreg |= 1U << DATA_RECV;
  Xil_Out32 (OUT_BASE + base_offset - 2, controlreg);

  return BMOK;
}

int BM_i2rwa(void * ptr, int input_id)
{
  return BM_i2rw(ptr, input_id);
}

int BM_r2o(void * ptr, int output_id)
{
  u32 controlreg, value, base_offset;

  memcpy((void *) &value, (const void *) ptr, 
      sizeof(u32));

  if (output_id < LOWER_REG_LIMIT)
    return BMERR;

  if (output_id > UPPER_REG_LIMIT)
    return BMERR;

  base_offset = 2 * ((u32) output_id);

  controlreg = Xil_In32(OUT_BASE + base_offset - 2);
  Xil_Out32 (OUT_BASE + base_offset - 1, value);

  controlreg |= 1U << DATA_VALID;
  Xil_Out32 (OUT_BASE + base_offset - 2, controlreg);

  return BMOK;
}

int BM_r2ow(void * ptr, int output_id)
{
  u32 controlreg, value, base_offset;
  int bitvalue;

  memcpy((void *) &value, (const void *) ptr, 
      sizeof(u32));

  if (output_id < LOWER_REG_LIMIT)
    return BMERR;

  if (output_id > UPPER_REG_LIMIT)
    return BMERR;

  base_offset = 2 * ((u32) output_id);

  Xil_Out32 (OUT_BASE + base_offset - 1, value);

  controlreg = Xil_In32(OUT_BASE + base_offset - 2);
  controlreg |= 1U << DATA_VALID;
  Xil_Out32 (OUT_BASE + base_offset - 2, controlreg);

  do
  { // is it better to read before checking the bit ? 
    controlreg = Xil_In32(OUT_BASE + base_offset - 2);
    bitvalue = (controlreg >> DATA_RECV) & 1U;
  } while (bitvalue == 0);

  return BMOK;
}

int BM_r2owa(void * ptr, int output_id)
{
  u32 controlreg, value, base_offset;
  int bitvalue;

  memcpy((void *) &value, (const void *) ptr, 
      sizeof(u32));

  if (output_id < LOWER_REG_LIMIT)
    return BMERR;

  if (output_id > UPPER_REG_LIMIT)
    return BMERR;

  do
  { 
    controlreg = Xil_In32(OUT_BASE + base_offset - 2);
    bitvalue = (controlreg >> DATA_VALID) & 1U;
  } while (bitvalue == 1);

  base_offset = 2 * ((u32) output_id);

  Xil_Out32 (OUT_BASE + base_offset - 1, value);

  controlreg |= 1U << DATA_VALID;
  Xil_Out32 (OUT_BASE + base_offset - 2, controlreg);


  return BMOK;
}

