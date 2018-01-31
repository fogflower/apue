#include<stdio.h>
#include<unistd.h>
#include"apue.h"
#include<sys/types.h>
#include<dirent.h>
void main(int argc,char **argv)
{
    DIR * dp;
    struct dirent *dip;
    if(argc!=2)
	err_quit("usage: ls directory_name");
    if((dp = opendir(argv[1]))==NULL)
	err_sys("cannot open %s",argv[1]);

    while((dip = readdir(dp))!=NULL)
    {
	printf("%s\n",dip->d_name);
    }

    closedir(dp);
    exit(0);


}
