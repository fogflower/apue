#include "apue.h"
#include<stdarg.h>
#include<stdio.h>
#include<string.h>
#include<errno.h>
void err_doit(int,int,const char*,va_list);
/*与系统调用有关的错误*/
void err_sys(const char *errchar,...)
{
    va_list ap;
    va_start(ap,errchar);
    err_doit(1,errno,errchar,ap);
    va_end(ap);
    exit(1);
}
/*
 *打印一个错误消息并直接退出
 *
 */
void err_quit(const char * errchar,...)
{
    va_list ap;
    va_start(ap,errchar);
    err_doit(0,0,errchar,ap);
    va_end(ap);
    exit(1);
}
/**
 * 打印消息返回到调用者，调用者指定"errnoflag"
 * 为什么这样做？因为fmt并不知道具体的字符串的大小，所以需要打印。
 */
void err_doit(int errnoflag, int error, const char *fmt,va_list ap)
{
    char buf[MAXLINE];
    vsnprintf(buf,MAXLINE-1,fmt,ap);
    if(errnoflag)
	snprintf(buf+strlen(buf),MAXLINE-strlen(buf)-1,": %s",strerror(error));
    strcat(buf,"\n");
    fflush(stdout);	    //防止输出内容stdout和stderr再一起
    fputs(buf,stderr);
    fflush(NULL);	    //清空所有缓冲区的内容
}

