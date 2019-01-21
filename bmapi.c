#include <string.h>

#include "bmapi.h"

int BM_i2r(u32 * ptr, int input_id) 
{
  u32 controlreg, value, base_offset;

  if (input_id < LOWER_REG_LIMIT)
    return BMERR;

  if (input_id > UPPER_REG_LIMIT)
    return BMERR;

  base_offset = 2 * ((u32) input_id);

  controlreg = Xil_In32(OUT_BASE + base_offset - 2);
  value = Xil_In32(OUT_BASE + base_offset - 1);
  memcpy((void *) ptr, (const void *) &value, 
      (size_t) BM_NUMOF_VALID_BIT);

  controlreg |= 1U << BM_DATA_RECV;
  Xil_Out32 (OUT_BASE + base_offset - 2, controlreg);

  return BMOK;
}

int BM_i2rw(u32 * ptr, int input_id)
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
    bitvalue = (controlreg >> BM_DATA_VALID) & 1U;
  } while (bitvalue == 0);

  value = Xil_In32(OUT_BASE + base_offset - 1);
  memcpy((void *) ptr, (const void *) &value, 
      (size_t) BM_NUMOF_VALID_BIT);
  
  controlreg |= 1U << BM_DATA_RECV;
  Xil_Out32 (OUT_BASE + base_offset - 2, controlreg);

  return BMOK;
}

int BM_i2rwa(u32 * ptr, int input_id)
{
  return BM_i2rw((void *) ptr, input_id);
}

int BM_r2o(u32 * ptr, int output_id)
{
  u32 controlreg, value, base_offset;

  memcpy((void *) &value, (const void *) ptr, 
      (size_t) BM_NUMOF_VALID_BIT);

  if (output_id < LOWER_REG_LIMIT)
    return BMERR;

  if (output_id > UPPER_REG_LIMIT)
    return BMERR;

  base_offset = 2 * ((u32) output_id);

  controlreg = Xil_In32(OUT_BASE + base_offset - 2);
  Xil_Out32 (OUT_BASE + base_offset - 1, value);

  controlreg |= 1U << BM_DATA_VALID;
  Xil_Out32 (OUT_BASE + base_offset - 2, controlreg);

  return BMOK;
}

int BM_r2ow(u32 * ptr, int output_id)
{
  u32 controlreg, value, base_offset;
  int bitvalue;

  memcpy((void *) &value, (const void *) ptr, 
      (size_t) BM_NUMOF_VALID_BIT);

  if (output_id < LOWER_REG_LIMIT)
    return BMERR;

  if (output_id > UPPER_REG_LIMIT)
    return BMERR;

  base_offset = 2 * ((u32) output_id);

  Xil_Out32 (OUT_BASE + base_offset - 1, value);

  controlreg = Xil_In32(OUT_BASE + base_offset - 2);
  controlreg |= 1U << BM_DATA_VALID;
  Xil_Out32 (OUT_BASE + base_offset - 2, controlreg);

  do
  { // is it better to read before checking the bit ? 
    controlreg = Xil_In32(OUT_BASE + base_offset - 2);
    bitvalue = (controlreg >> BM_DATA_RECV) & 1U;
  } while (bitvalue == 0);

  return BMOK;
}

int BM_r2owa(u32 * ptr, int output_id)
{
  u32 controlreg, value, base_offset;
  int bitvalue;

  memcpy((void *) &value, (const void *) ptr, 
      (size_t) BM_NUMOF_VALID_BIT);

  if (output_id < LOWER_REG_LIMIT)
    return BMERR;

  if (output_id > UPPER_REG_LIMIT)
    return BMERR;

  base_offset = 2 * ((u32) output_id);

  do
  { 
    controlreg = Xil_In32(OUT_BASE + base_offset - 2);
    bitvalue = (controlreg >> BM_DATA_VALID) & 1U;
  } while (bitvalue == 1);

  Xil_Out32 (OUT_BASE + base_offset - 1, value);

  controlreg |= 1U << BM_DATA_VALID;
  Xil_Out32 (OUT_BASE + base_offset - 2, controlreg);


  return BMOK;
}

