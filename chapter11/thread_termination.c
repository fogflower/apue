#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
void * thrdfunc1(void *arg)
{
    *(int*)arg= *(int*)arg +1;
    printf("thread 1 returning\n");
    return (void*)1;
}

void *thrdfunc2(void *arg)
{
    printf("thread 2 exiting!%d is count\n",*(int*)arg);
    pthread_exit((void *)2);
}
int main()
{
    int err;
    int count =0;
    pthread_t thrd1,thrd2;
    void *retval;
    err = pthread_create(&thrd1,NULL,thrdfunc1,&count);
    if(err != 0)
    {
	perror("create thread 1 error\n");
    }

    err = pthread_create(&thrd2,NULL,thrdfunc2,&count);
    if(err!=0)
    {
	perror("create thread 2 error\n");
    }

    err = pthread_join(thrd1,&retval);
    if(err != 0)
    {
	perror("cannot join with thread 1");
    }
    printf("thread 1 return val is %ld\n",(long)retval);
    err = pthread_join(thrd2,&retval);
    if(err != 0)
    {
	perror("cannot join with thread 2");

    }
  printf("thread 2 return val is %ld\n",(long)retval);
  exit(0);
}
