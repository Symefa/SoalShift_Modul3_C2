#include <stdio.h>
#include <pthread>


int t[3];
int status;
pthread_t tid[3];

void *faktorial(void *arg)
{
  int *x = (int *)arg;
  int top=t[x], result=1;
	while(top>0)
  {
	 result*=top;
   top--;
  }
}

int main()
{
  int x[3] = {0,1,2};
  scanf("%d %d %d", &t[0],&t[1],&t[2]);

  for (int i = 0; i<3; i++)
  {
    pthread_create(&(tid[0]),NULL,&faktorial,(void *)x[i]);
  }
  for (int i = 0; i<3; i++)
  {
    pthread_join(tid[a],NULL);
  }
return 0;
}
