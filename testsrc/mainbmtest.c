#include "bondmachineip1.h"
#include "xparameters.h"
#include "xil_io.h"
#include "bmapi.h"

// Define maximum LED value (2^8)-1 = 255
#define LED_LIMIT 255
// Define delay length
#define DELAY 50000000

/* Define the base memory address of the led_controller IP core */
#define LED_BASE XPAR_BONDMACHINEIP1_0_S00_AXI_BASEADDR


/* main function */
int main(void)
{
  /* unsigned 32-bit variables for storing current LED value */
  u32 led_val_w = 0;
  u32 led_val_r = 0;
  int i=0;

  int retval, input_id = 0, output_id = 0;
  
  xil_printf("\r\n\n--------------------------------------------\r\n");
  xil_printf("First BM IP test begin.\r\n");
  xil_printf("--------------------------------------------\r\n");
  
  /* Loop forever */
  while(1)
  {
    while(led_val_w<=LED_LIMIT)
    {
      /* Print value to terminal */
      xil_printf("Write value : %5d\r\n", led_val_w);
      /* Write value to led_controller IP core using generated driver function */
      //Xil_Out32(LED_BASE + BONDMACHINEIP1_S00_AXI_SLV_REG1_OFFSET, 
      //    (u32)(led_val_w));
      retval = BM_r2o(&led_val_w, output_id);

      //led_val_r = 
      //  Xil_In32(LED_BASE + BONDMACHINEIP1_S00_AXI_SLV_REG0_OFFSET);
      retval = BM_i2r(&led_val_r, input_id);

      xil_printf("Read value  : %5d\r\n\r\n", led_val_r);
      /* increment LED value */
      led_val_w++;
      /* run a simple delay to allow changes on LEDs to be visible */
      for(i=0;i<DELAY;i++);
    }
    /* Reset LED value to zero */
    led_val_w = 0;	
  }

  return 1;
}
