#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include<time.h>

int main()
{  
    int size=0;
 while(1)
 {
     size++;
    ////////////////////////////////////////////////////////
    int shmid;
    key_t key;
    int * ishm,*beginner;
    float * fshm;
    key=5660;    
    int SHMSZ=15*500*8*4;// size of segment
    
    if((shmid=shmget(key,SHMSZ,IPC_CREAT|0666))<0)
    {
     perror("shmget");
     exit(1);
    }
    
    //now attach the segment to our data space
    if((ishm=shmat(shmid,NULL,0))==(int *)-1)
    {
     perror("shmat");
     exit(1);
    }   
    
    ////put the number of the read & haplotype in shared memory segment
    
    *ishm=0;
    beginner=ishm;

        
    *beginner=size;
     
    while(*beginner!=0)
     {
        sleep(1); 
        printf("I am waiting\n") ;  
     }
    
   }
    return 0;
}
    
