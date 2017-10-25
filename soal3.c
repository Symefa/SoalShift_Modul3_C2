#include <stdio.h>
#include <pthread.h>

int status = 1;

int kepiting = 100;
int signal1= 0;

int lohan = 100;
int signal2 = 0;

void *kepitings(void * arg);
void *lohans(void *arg);

int main()
{

return 0;
}

void *kepitings(void * arg)
{
  while (status!=0)
  {
    sleep(10);
    while (signal1!=0){}
    signal1 = 1;
    kepiting -= 10;

    if (kepiting<=0)
    {
      status = 0;
    }
    signal1 = 0;
  }
}

void *lohans(void *arg)
{

}
