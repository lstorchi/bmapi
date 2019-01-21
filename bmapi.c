#include <string.h>

#include "bmapi.h"

int BM_i2r(u32 * ptr, int input_id) 
{
  u32 controlreg, value, control_addr, 
      data_addr;

  if (input_id < LOWER_REG_LIMIT)
    return BMERR;

  if (input_id > UPPER_REG_LIMIT)
    return BMERR;

  control_addr = get_in_control_addr(input_id);
  data_addr = get_in_data_addr(input_id);

  value = Xil_In32(data_addr);
  memcpy((void *) ptr, (const void *) &value, 
      (size_t) BM_NUMOF_VALID_BIT);

  controlreg = Xil_In32(control_addr);
  controlreg |= 1U << BM_DATA_RECV;
  Xil_Out32 (control_addr, controlreg);

  return BMOK;
}

int BM_i2rw(u32 * ptr, int input_id)
{
  u32 controlreg, value, control_addr, 
      data_addr;
  int bitvalue;

  if (input_id < LOWER_REG_LIMIT)
    return BMERR;

  if (input_id > UPPER_REG_LIMIT)
    return BMERR;

  control_addr = get_in_control_addr(input_id);
  data_addr = get_in_data_addr(input_id);

  do
  {
    controlreg = Xil_In32(control_addr);
    bitvalue = (controlreg >> BM_DATA_VALID) & 1U;
  } while (bitvalue == 0);

  value = Xil_In32(data_addr);
  memcpy((void *) ptr, (const void *) &value, 
      (size_t) BM_NUMOF_VALID_BIT);
  
  controlreg |= 1U << BM_DATA_RECV;
  Xil_Out32 (control_addr, controlreg);

  return BMOK;
}

int BM_i2rwa(u32 * ptr, int input_id)
{
  return BM_i2rw((void *) ptr, input_id);
}

int BM_r2o(u32 * ptr, int output_id)
{
  u32 controlreg, value, control_addr, 
      data_addr;

  memcpy((void *) &value, (const void *) ptr, 
      (size_t) BM_NUMOF_VALID_BIT);

  if (output_id < LOWER_REG_LIMIT)
    return BMERR;

  if (output_id > UPPER_REG_LIMIT)
    return BMERR;

  control_addr = get_out_control_addr(output_id);
  data_addr = get_out_data_addr(output_id);

  controlreg = Xil_In32(control_addr);
  Xil_Out32 (data_addr, value);

  controlreg |= 1U << BM_DATA_VALID;
  Xil_Out32 (control_addr, controlreg);

  return BMOK;
}

int BM_r2ow(u32 * ptr, int output_id)
{
  u32 controlreg, value, control_addr,  
      data_addr;
  int bitvalue;

  memcpy((void *) &value, (const void *) ptr, 
      (size_t) BM_NUMOF_VALID_BIT);

  if (output_id < LOWER_REG_LIMIT)
    return BMERR;

  if (output_id > UPPER_REG_LIMIT)
    return BMERR;

  control_addr = get_out_control_addr(output_id);
  data_addr = get_out_data_addr(output_id);

  Xil_Out32 (data_addr, value);

  controlreg = Xil_In32(control_addr);
  controlreg |= 1U << BM_DATA_VALID;
  Xil_Out32 (control_addr, controlreg);

  do
  { // is it better to read before checking the bit ? 
    controlreg = Xil_In32(control_addr);
    bitvalue = (controlreg >> BM_DATA_RECV) & 1U;
  } while (bitvalue == 0);

  return BMOK;
}

int BM_r2owa(u32 * ptr, int output_id)
{
  u32 controlreg, value, control_addr, 
      data_addr;
  int bitvalue;

  memcpy((void *) &value, (const void *) ptr, 
      (size_t) BM_NUMOF_VALID_BIT);

  if (output_id < LOWER_REG_LIMIT)
    return BMERR;

  if (output_id > UPPER_REG_LIMIT)
    return BMERR;

  control_addr = get_out_control_addr(output_id);
  data_addr = get_out_data_addr(output_id);

  do
  { 
    controlreg = Xil_In32(control_addr);
    bitvalue = (controlreg >> BM_DATA_VALID) & 1U;
  } while (bitvalue == 1);

  Xil_Out32 (data_addr, value);

  controlreg |= 1U << BM_DATA_VALID;
  Xil_Out32 (control_addr, controlreg);

  return BMOK;
}

