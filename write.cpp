#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdio.h>
#include <stdlib.h>

int main()
{
    int shmid;
    key_t key;
    int *ishm, *beginner;
while(1)
{    
    //get the segment named "5678" created by the server
    key=5660;
    if((shmid=shmget(key,0,06666))<0)
    {
    perror("shmget");
    exit(1);    
    }
    printf("I am here\n");
    //attach the segment to our data space
    if((ishm=shmat(shmid,NULL,0))==(int *)-1)
    {
    perror("shmat");
    exit(1);
    }
    
    beginner=ishm;
    
    while(*beginner==0)
    {
    sleep(1);
    }
    
    int size;
    size=*ishm;
    ishm++;
  
    printf("size is %d\n",size);
    
       
      *beginner=0;
}
      
      return 0;

}
