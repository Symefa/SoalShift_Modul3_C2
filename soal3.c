#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int status = 1;

int kepiting = 100;
int signal1= 0;

int lohan = 100;
int signal2 = 0;

void *kepitings(void * arg);
void *lohans(void *arg);

int main()
{
  pthread_t tid[2];
  pthread_create(&tid[0],NULL,&kepitings,NULL);
  pthread_create(&tid[1],NULL,&lohans,NULL);
  int n;
  while(status!=0){
   printf("feed 1. kepiting , 2. lohan : ");
   scanf("%d",&n);
   switch (n) {
    case 1:
      while(signal1!=0){}
   	  signal1=1;
   	  if(status!=0) kepiting+=10;
   	  if(kepiting>100) status=0;
     	signal1=0;
    break;
    case 2:
      while(signal2!=0){}
   	  signal2=1;
   	  if(status!=0) lohan+=10;
   	  if(lohan>100) status=0;
   	  signal2=0;
    break;
    default:
      printf("Salah command!\n");
    break;
     }
  }
return 0;
}

void *kepitings(void * arg)
{
  while (status!=0)
  {
    sleep(20);
    while (signal1!=0){}
    signal1 = 1;
    kepiting -= 10;

    if (kepiting<=0)
    {
      status = 0;
    }
    signal1 = 0;
    printf("\nkepiting %d", kepiting);
  }
}

void *lohans(void *arg)
{
  while (status!=0)
  {
    sleep(10);
    while (signal2!=0){}
    signal2 = 1;
    lohan -= 15;

    if (lohan<=0)
    {
      status = 0;
    }
    signal2 = 0;
    printf("\nlohan %d", lohan);
  }
}
