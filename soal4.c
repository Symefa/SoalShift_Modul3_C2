#include <stdio.h>
#include <pthread.h>


int t[3];
int status;
pthread_t tid[3];

void *faktorial(void *arg)
{
  int top=t[0], result=1;
	while(top>0)
  {
	 result*=top;
   top--;
  }
  printf("Hasil %d! = %d\n", t[0], result);
}

void *faktoriall(void *arg)
{
  int top=t[1], result=1;
	while(top>0)
  {
	 result*=top;
   top--;
  }
  printf("Hasil %d! = %d\n", t[1], result);
}

void *faktorialll(void *arg)
{
  int top=t[2], result=1;
	while(top>0)
  {
	 result*=top;
   top--;
  }
  printf("Hasil %d! = %d\n", t[2], result);
}

int main()
{

  scanf("%d %d %d", &t[0],&t[1],&t[2]);

    pthread_create(&(tid[0]),NULL,&faktorial,NULL);
    pthread_create(&(tid[0]),NULL,&faktoriall,NULL);
    pthread_create(&(tid[0]),NULL,&faktorialll,NULL);
  for (int i = 0; i<3; i++)
  {
    pthread_join(tid[i],NULL);
  }
return 0;
}
