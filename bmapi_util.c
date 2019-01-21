#include <string.h>

#include "bmapi.h"

u32 get_control_addr (int input_id) 
{
  u32 addr = OUT_BASE + 2 * ((u32) input_id) - 2;

  return addr;
}


u32 get_data_addr (int input_id) 
{
  u32 addr = OUT_BASE + 2 * ((u32) input_id) - 1;

  return addr;
}
