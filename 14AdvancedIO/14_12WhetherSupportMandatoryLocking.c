#include"apue.h"
#include<errno.h>
#include<fcntl.h>
#include<sys/wait.h>

int main(int argc, char **argv)
{
    int fd;
    pid_t pid;
    char buf[5];
    struct stat statbuf;

    if(argc != 2)
    {
	fprintf(stderr, "usage: %s filename \n",argv[0]);
	exit(1);
    }

}

