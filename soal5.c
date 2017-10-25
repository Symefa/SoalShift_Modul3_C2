#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>

int status=0;
void *find(void *arg);

int main()
{

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
