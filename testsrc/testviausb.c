#include <stdio.h>
#include <errno.h>
#include <fcntl.h> 
#include <string.h>
#include <termios.h>
#include <unistd.h>
#include <errno.h>


int set_interface_attribs (int fd, int speed, int parity)
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
        tty.c_cc[VMIN]  = 1;            // read doesn't block
        tty.c_cc[VTIME] = 0;            // 0.5 seconds read timeout

        tty.c_iflag &= ~(IXON | IXOFF | IXANY); // shut off xon/xoff ctrl

        tty.c_cflag |= (CLOCAL | CREAD);// ignore modem controls,
                                        // enable reading
        tty.c_cflag &= ~(PARENB | PARODD);      // shut off parity
        tty.c_cflag |= parity;
        tty.c_cflag &= ~CSTOPB;
        tty.c_cflag &= ~CRTSCTS;

        if (tcsetattr (fd, TCSANOW, &tty) != 0)
                return -1;

        return 0;
}

int main(int argc, char ** argv)
{
	int n, i;
	unsigned char buf [2];
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

	//set_interface_attribs (fd, 115200, 0); 

	//n = read (fd, buf, sizeof(buf)); 
	//fprintf(stdout, "Reading: %X %X %d\n", buf[0], buf[1], n);
	sleep(1);
	buf[0] = (unsigned char ) 0x00;
	buf[1] = (unsigned char ) 0x10;
	write(fd, buf, (size_t) 2);
	fprintf(stdout, "Writing: %X %X \n", buf[0], buf[1]);
	//sleep(1);
	for (i= 0; i<100000; ++i)
	{
	  n = read (fd, buf, (size_t)  2); 
	  if (buf[0] != 0x80  || buf[1] != 0x80)
		  fprintf(stdout, "Reading: %X %X \n", buf[0], buf[1]);
	}

	return 0;
}



