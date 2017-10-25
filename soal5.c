#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>

int status=0;
void *find(void *arg);

int main(int argc, char *argv[])
{
  pthread_t tid[argc];
  char needle[100];

	for(int i=1;i<argc;i++)
  {
    while(status!=0);
    status=1;
	  strcpy(needle,argv[i]);
	  pthread_create(&(tid[i]), NULL , &find ,(void *) &needle);
  }

  for(int i=1;i<argc;i++)
  {
    pthread_join(tid[i],NULL);
  }

  return 0;
}

void *find(void *arg)
{
  int n = 0;
  FILE *source;
  char haystack[100], needle[100];

  strcpy(needle,(char *)arg);
  status = 0;

  source = fopen("Novel.txt","r");
  while(fscanf(source,"%s",haystack)!=EOF) {
		if(strstr(haystack,needle)!=NULL) n++;
	}

  printf("Kata %s: %d\n",needle,n);
  fclose(source);
}
