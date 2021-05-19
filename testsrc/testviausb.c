#include <stdio.h>
#include <math.h>
#include <errno.h>
#include <fcntl.h> 
#include <string.h>
#include <termios.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>

#include "../ptsrc/ptinternal.h"

int main(int argc, char ** argv)
{
  int n, i, j, * binary;
  unsigned char buf [2], num;
  char * portname = "/dev/ttyUSB1";
  
  buf[0] = (unsigned char ) 0x00;
  buf[1] = (unsigned char ) 0x00;
  
  if (argc == 2)
  	portname = argv[1];
  
  
  //int fd = open (portname, O_RDWR | O_NOCTTY | O_SYNC);
  int fd = open (portname, O_RDWR );
  if (fd < 0)
  {
  	fprintf (stderr, "error %d opening %s: %s \n", errno, portname, strerror (errno));
  	return 1;
  }

  set_interface_attribs (fd, 115200, 0);
  n = 1; 

  while (n != 0) // empty the buffer socat only 
  {
    n = read (fd, buf, sizeof(unsigned char));
  }
  
  set_interface_attribs (fd, 115200, 1); 

  fprintf(stdout,"Writing 1\n");
  num = 0x15; // 00010101
  buf[0] = (unsigned char ) (cmdHANDSH | num);
  fprintf(stdout,"  ");
  binary = to_binary(buf[0]);
  for (j = PTDIMBITS - 1; j >= 0; j--)
    fprintf(stdout, "%1d", (int) binary[j]);
  fprintf(stdout, " --> ");
  fprintf(stdout, "%X \n", from_binary(binary));

  free(binary);
  n = write(fd, buf, (size_t) 1);
  if (n != 1)
    return -1;

  fprintf(stdout,"Reading 2\n");
  n = read (fd, buf, sizeof(unsigned char));
  if (n != 1)
    return -1;
  fprintf(stdout,"  ");
  binary = to_binary(buf[0]);
  for (j = PTDIMBITS - 1; j >= 0; j--)
    fprintf(stdout, "%1d", (int) binary[j]);
  fprintf(stdout, "\n");
  free(binary);
 

  fprintf(stdout,"Writing 3\n");
  buf[1] = (unsigned char ) (buf[0] & num);
  fprintf(stdout,"  ");
  binary = to_binary(buf[0]);
  for (j = PTDIMBITS - 1; j >= 0; j--)
    fprintf(stdout, "%1d", (int) binary[j]);
  fprintf(stdout, "\n");
  free(binary);
  n = write(fd, &(buf[1]), (size_t) 1);
  if (n != 1)
    return -1;

  fprintf(stdout,"Reading 4\n");
  n = read (fd, buf, sizeof(unsigned char));
  if (n != 1)
    return -1;
  if (buf[0] == buf[1])
  {
    fprintf(stdout,"  OK ");
    binary = to_binary(buf[0]);
    for (j = PTDIMBITS - 1; j >= 0; j--)
      fprintf(stdout, "%1d", (int) binary[j]);
    fprintf(stdout, "\n");
    free(binary);
  }

  fprintf(stdout,"Writing 5\n");
  buf[0] = (unsigned char ) (cmdNEWVAL | (0x00));
  buf[1] = (unsigned char ) 10;
  fprintf(stdout,"  ");
  binary = to_binary(buf[0]);
  for (j = PTDIMBITS - 1; j >= 0; j--)
    fprintf(stdout, "%1d", (int) binary[j]);
  fprintf(stdout, "\n");
  free(binary);
 
  fprintf(stdout,"  ");
  binary = to_binary(buf[1]);
  for (j = PTDIMBITS - 1; j >= 0; j--)
    fprintf(stdout, "%1d", (int) binary[j]);
  fprintf(stdout, "\n");
  free(binary);
 
  n = write(fd, buf, (size_t) 2);

  fprintf(stdout,"Reading 6\n");
  n = read (fd, buf, sizeof(unsigned char) * 2);
  fprintf(stdout,"  ");
  binary = to_binary(buf[0]);
  for (j = PTDIMBITS - 1; j >= 0; j--)
    fprintf(stdout, "%1d", (int) binary[j]);
  fprintf(stdout, "\n");
  free(binary);
 
  fprintf(stdout,"  ");
  binary = to_binary(buf[1]);
  for (j = PTDIMBITS - 1; j >= 0; j--)
    fprintf(stdout, "%1d", (int) binary[j]);
  fprintf(stdout, "\n");
  free(binary);
 

  return 0;
}

