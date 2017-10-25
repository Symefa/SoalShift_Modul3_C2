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

return 0;
}
