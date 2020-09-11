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
        tty.c_cc[VMIN]  = 0;            // read doesn't block
        tty.c_cc[VTIME] = 5;            // 0.5 seconds read timeout

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

int set_blocking (int fd, int should_block)
{
        struct termios tty;
        memset (&tty, 0, sizeof tty);
        if (tcgetattr (fd, &tty) != 0)
                return -1;

        tty.c_cc[VMIN]  = should_block ? 1 : 0;
        tty.c_cc[VTIME] = 5;            // 0.5 seconds read timeout

        if (tcsetattr (fd, TCSANOW, &tty) != 0)
		return -1;
}


int main(int argc, char ** argv)
{
	int n;
	unsigned char buf [2];
	char * portname = "/dev/ttyUSB1";


	if (argc == 2)
		portname = argv[1];


   	int fd = open (portname, O_RDWR | O_NOCTTY | O_SYNC);
   	if (fd < 0)
	{
		fprintf (stderr, "error %d opening %s: %s \n", errno, portname, strerror (errno));
		return 1;
	}

	set_interface_attribs (fd, B115200, 0); 
	set_blocking (fd, 0); 

	n = read (fd, buf, sizeof(buf)); 
	fprintf(stdout, "Reading: %X %d %d\n", buf[0], (unsigned int) buf[1], n);
	sleep(4);
	buf[0] = (unsigned char ) 0x00;
	buf[1] = (unsigned char ) 0x10;
	write(fd, buf, 2); 
	fprintf(stdout, "Writing: %X %d \n", buf[0], (unsigned int) buf[1]);
	sleep(4);
	n = read (fd, buf, sizeof(buf)); 
	fprintf(stdout, "Reading: %X %d %d\n", buf[0], (unsigned int) buf[1], n);
	
	return 0;
}



