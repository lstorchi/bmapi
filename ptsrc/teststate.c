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

int main(int argc, char ** argv)
{
  int n, i, j, * binary;
  unsigned char buf, num, currentstate;
  char * portname = "/dev/ttyUSB1";
  
  buf = (unsigned char ) 0x00;
  num = 0x15; // 00010101
  
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
  currentstate = stateWAIT;

  while (1) // empty the buffer socat only 
  {
    n = read (fd, &buf, sizeof(unsigned char));
    switch (currentstate)
    {
      case stateWAIT:
        if (n > 0)
        {
          fprintf(stdout, "IN stateWAIT ==> ");
          dump_to_stdout(buf);
        }
        else 
        {
          buf = (unsigned char ) (cmdHANDSH | num);
          n = write(fd, &buf, sizeof(unsigned char));
          if (n == 1)
            currentstate = stateHSSENT;
        }
        break;
      case stateHSSENT:
        if (n > 0)
        {
          fprintf(stdout, "IN stateHSSENT ==> ");
          dump_to_stdout(buf);
          currentstate = stateMASKRECV;
          buf = (unsigned char ) (buf & num);
        }
        else
        {
          currentstate = stateWAIT;
        }
        break;
      case stateMASKRECV:
        buf = (unsigned char ) (buf & num);
        fprintf(stdout, "IN stateMASKRECV ==> ");
        dump_to_stdout(buf);
        n = write(fd, &buf, (size_t) 1);
        if (n != 1)
        {
          currentstate = stateWAIT;
        }
        else
        {
          unsigned char bufc;

          n = read (fd, &bufc, sizeof(unsigned char));
          if (n != 1)
          {
            currentstate = stateWAIT;
          }
          else
          {
            if (buf == bufc)
              currentstate = stateACK;
            else
              currentstate = stateWAIT;
          }
        }
    }
  }
  

  return 0;
}

