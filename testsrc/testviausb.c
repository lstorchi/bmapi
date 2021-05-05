#include <stdio.h>
#include <errno.h>
#include <fcntl.h> 
#include <string.h>
#include <termios.h>
#include <unistd.h>
#include <errno.h>

#define cmdNEWVAL   (unsigned char) 0   // 000 00000
#define cmdDVALIDH  (unsigned char) 32  // 001 00000
#define cmdDVALIDL  (unsigned char) 64  // 010 00000
#define cmdDRECVH   (unsigned char) 96  // 011 00000
#define cmdDRECVL   (unsigned char) 128 // 100 00000
#define cmdHANDSH   (unsigned char) 160 // 101 00000
#define cmdKEEP     (unsigned char) 192 // 110 00000
#define cmdMASK     (unsigned char) 224 // 111 00000

#define DIM 8

void to_binary(unsigned char n)
{
  int i, j, binarynum[DIM];

  for (i=0;i<DIM;++i)
    binarynum[i] = 0;

  i = 0;
  while (n > 0) 
  {
    binarynum[i] = n % 2;
    n = n / 2;
    i++;
  }
                                                           
  for (j = DIM - 1; j >= 0; j--)
    fprintf(stdout, "%1d", (int) binarynum[j]);
  
  fprintf(stdout, "\n");

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

int main(int argc, char ** argv)
{
  int n, i;
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
  to_binary(buf[0]);
  n = write(fd, buf, (size_t) 1);
  if (n != 1)
    return -1;

  fprintf(stdout,"Reading 2\n");
  n = read (fd, buf, sizeof(unsigned char));
  if (n != 1)
    return -1;
  fprintf(stdout,"  ");
  to_binary(buf[0]);

  fprintf(stdout,"Writing 3\n");
  buf[1] = (unsigned char ) (buf[0] & num);
  fprintf(stdout,"  ");
  to_binary(buf[0]);
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
    to_binary(buf[0]);
  }

  fprintf(stdout,"Writing 5\n");
  buf[0] = (unsigned char ) (cmdNEWVAL | (0x00));
  buf[1] = (unsigned char ) 10;
  fprintf(stdout,"  ");
  to_binary(buf[0]);
  fprintf(stdout,"  ");
  to_binary(buf[1]);
  n = write(fd, buf, (size_t) 2);

  fprintf(stdout,"Reading 6\n");
  n = read (fd, buf, sizeof(unsigned char) * 2);
  fprintf(stdout,"  ");
  to_binary(buf[0]);
  fprintf(stdout,"  ");
  to_binary(buf[1]);

  return 0;
}

