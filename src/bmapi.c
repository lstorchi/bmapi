#include <string.h>

#include "bmapi.h"

int BM_i2r(u32 * ptr, int input_id) 
{
  u32 controlreg, value, control_addr, 
      data_addr;

  if (input_id < BM_LOWER_IN_REG_LIMIT)
    return BMERR;

  if (input_id > BM_UPPER_IN_REG_LIMIT)
    return BMERR;

  data_addr = get_in_data_addr(input_id);
  value = Xil_In32(data_addr);
  memcpy((void *) ptr, (const void *) &value, 
      (size_t) REGISTER_SIZE);

#ifndef REMOVE_CONTROL_CHECK 
#ifndef BM_SPLIT_CTRL_REGISTERS
  control_addr = get_in_control_addr(input_id);
#else
  control_addr = get_in_data_recv_addr(input_id);
#endif

  controlreg = Xil_In32(control_addr);
  controlreg |= 1U << BM_DATA_RECV;

  Xil_Out32 (control_addr, controlreg);
#endif

  return BMOK;
}

int BM_i2rw(u32 * ptr, int input_id)
{

#ifdef REMOVE_CONTROL_CHECK
  
  return BM_i2r(ptr, input_id);

#else

  u32 controlreg, value, control_addr, 
      data_addr;
  int bitvalue;

  if (input_id < BM_LOWER_IN_REG_LIMIT)
    return BMERR;

  if (input_id > BM_UPPER_IN_REG_LIMIT)
    return BMERR;

#ifndef BM_SPLIT_CTRL_REGISTERS
  control_addr = get_in_control_addr(input_id);
#else
  control_addr = get_in_data_valid_addr(input_id);
#endif

  data_addr = get_in_data_addr(input_id);

  do
  {
    controlreg = Xil_In32(control_addr);
    bitvalue = (controlreg >> BM_DATA_VALID) & 1U;
  } while (bitvalue == 0);

  value = Xil_In32(data_addr);
  memcpy((void *) ptr, (const void *) &value, 
      (size_t) REGISTER_SIZE);

#ifdef BM_SPLIT_CTRL_REGISTERS
  control_addr = get_in_data_recv_addr(input_id);
#endif

  controlreg |= 1U << BM_DATA_RECV;

  Xil_Out32 (control_addr, controlreg);

  return BMOK;
#endif

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
      (size_t) REGISTER_SIZE);

  if (output_id < BM_LOWER_OUT_REG_LIMIT)
    return BMERR;

  if (output_id > BM_UPPER_OUT_REG_LIMIT)
    return BMERR;

  data_addr = get_out_data_addr(output_id);

#ifndef REMOVE_CONTROL_CHECK 
#ifndef BM_SPLIT_CTRL_REGISTERS 
  control_addr = get_out_control_addr(output_id);
#else
  control_addr = get_out_data_valid_addr(output_id);
#endif

  controlreg = Xil_In32(control_addr);
#endif

  Xil_Out32 (data_addr, value);

#ifndef REMOVE_CONTROL_CHECK 
  controlreg |= 1U << BM_DATA_VALID;

  Xil_Out32 (control_addr, controlreg);
#endif

  return BMOK;
}

int BM_r2ow(u32 * ptr, int output_id)
{

#ifdef REMOVE_CONTROL_CHECK
  
  return BM_r2o(ptr, output_id);

#else


  u32 controlreg, value, control_addr,  
      data_addr;
  int bitvalue;

  memcpy((void *) &value, (const void *) ptr, 
      (size_t) REGISTER_SIZE);

  if (output_id < BM_LOWER_OUT_REG_LIMIT)
    return BMERR;

  if (output_id > BM_UPPER_OUT_REG_LIMIT)
    return BMERR;

  data_addr = get_out_data_addr(output_id);
  Xil_Out32 (data_addr, value);

#ifndef BM_SPLIT_CTRL_REGISTERS
  control_addr = get_out_control_addr(output_id);
#else
  control_addr = get_out_data_valid_addr(output_id);
#endif

  controlreg = Xil_In32(control_addr);
  controlreg |= 1U << BM_DATA_VALID;

  Xil_Out32 (control_addr, controlreg);

#ifdef BM_SPLIT_CTRL_REGISTERS
  control_addr = get_out_data_recv_addr(output_id);
#endif

  do
  { // is it better to read before checking the bit ? 
    controlreg = Xil_In32(control_addr);
    bitvalue = (controlreg >> BM_DATA_RECV) & 1U;
  } while (bitvalue == 0);

  return BMOK;

#endif

}

int BM_r2owa(u32 * ptr, int output_id)
{

#ifdef REMOVE_CONTROL_CHECK
  
  return BM_r2o(ptr, output_id);

#else

  u32 controlreg = 0, value, control_addr, 
      data_addr;
  int bitvalue;

  memcpy((void *) &value, (const void *) ptr, 
      (size_t) REGISTER_SIZE);

  if (output_id < BM_LOWER_OUT_REG_LIMIT)
    return BMERR;

  if (output_id > BM_UPPER_OUT_REG_LIMIT)
    return BMERR;

#ifndef BM_SPLIT_CTRL_REGISTERS
  control_addr = get_out_control_addr(output_id);
#else
  control_addr = get_out_data_valid_addr(output_id);
#endif

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

#endif

}

