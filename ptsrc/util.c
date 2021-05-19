#include <stdio.h>
#include <math.h>
#include <errno.h>
#include <fcntl.h> 
#include <string.h>
#include <termios.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>

#include "ptinternal.h"

void dump_to_stdout (unsigned char buf)
{
  int * binary, j;

  binary = to_binary(buf);

  for (j = PTDIMBITS - 1; j >= 0; j--)
    fprintf(stdout, "%1d", (int) binary[j]);

  fprintf(stdout, " --> ");
  fprintf(stdout, "%X \n", from_binary(binary));

  free(binary);
}

int * to_binary(unsigned char val)
{
  int i, n; 
  int * binarynum;

  n = (int) sizeof(unsigned char);
  
  binarynum = (int *) malloc( PTDIMBITS * sizeof(int));
  if (binarynum != NULL)
  {
    for (i=0; i<n; ++i)
      binarynum[i] = 0;
    
    i = 0;
    while (val > 0) 
    {
      binarynum[i] = val % 2;
      val = val / 2;
      i++;
    }
  }

  return binarynum;
                                                           
}

unsigned char from_binary(int val[PTDIMBITS])
{
  int multiplier = 1, basis, expo, i;
  unsigned char bin;

  expo = 0;
  basis = 2;
  for (i = 0; i < PTDIMBITS; ++i )
  {
    bin += (pow(basis, expo)* val[i]);
    expo += 1;
  }

  return bin;
}

int set_interface_attribs (int fd, int speed, int blocking)
{
  struct termios tty;
  if (tcgetattr (fd, &tty) != 0)
          return -1;
  
  cfsetospeed (&tty, speed);
  cfsetispeed (&tty, speed);
  
  tty.c_cflag = (tty.c_cflag & ~CSIZE) | CS8;     // 8-bit chars
  						// disable IGNBRK for mismatched speed tests; otherwise receive break
  						// as \000 chars
  tty.c_iflag &= ~IGNBRK;         // disable break processing
  tty.c_lflag = 0;                // no signaling chars, no echo,
                                  // no canonical processing
  tty.c_oflag = 0;                // no remapping, no delays
  tty.c_cc[VMIN]  = blocking;            // read doesn't block
  tty.c_cc[VTIME] = 0;            // 0.5 seconds read timeout
  
  tty.c_iflag &= ~(IXON | IXOFF | IXANY); // shut off xon/xoff ctrl
  
  tty.c_cflag |= (CLOCAL | CREAD);// ignore modem controls,
                                  // enable reading
  tty.c_cflag &= ~(PARENB | PARODD);      // shut off parity
  tty.c_cflag |= 0;
  tty.c_cflag &= ~CSTOPB;
  tty.c_cflag &= ~CRTSCTS;
  
  if (tcsetattr (fd, TCSANOW, &tty) != 0)
          return -1;
  
  return 0;
}

