#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/fcntl.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

const char *random_dev_name = "/dev/urandom";
int main(int argc, char **argv)
{
    int fd = 0;
    int err = 0;
    int random = 0;
    int num_random = 1000000; //1 million

    if (argc == 1)
    {
	fprintf (stderr, "Going to generate 1 million random numbers.\n");
	fprintf (stderr, "If you want to generate specific number of random numbers,"
		" provide that as argument in program");
    }
    else if (argc == 2)
    {
	num_random = atoi(argv[1]);
	if (num_random > 0)
	{
	    fprintf(stderr, "Going to generate %d random numbers.\n", num_random);
	}
	else
	{
	    fprintf(stderr, "Invalid argument passed.\n");
	    err = EINVAL;
	    goto exit;
	}
    }

    fd = open (random_dev_name, O_RDONLY);
    if (fd == -1)
    {
	fprintf(stderr, "Failed to open random device %s. err = %d (%s)\n",
		random_dev_name, errno, strerror(errno));
	err = errno;
	goto exit;
    }

    do
    {
	err = read (fd, (void *)&random, sizeof (random));
	if (err != sizeof (int))
	{
	    fprintf(stderr, "Failed to read from random device. err = %d (%s)\n",
		    errno, strerror(errno));
	    err = errno;
	    goto exit;
	}
	printf("%d\n", random);
    } while (--num_random > 0);
    err = 0;

exit:

    if (fd > 0)
    {
	close (fd);
    }
    return err;
}
