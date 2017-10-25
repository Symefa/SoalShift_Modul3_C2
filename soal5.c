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
  File *source;
  char haystack[100], needle[100];

  strcpy(needle,(char *)arg);
  status = 0;

  source = fopen("novel.txt","r");
  while(fscanf(novel,"%s",kata)!=EOF) {
		if(strstr(haystack,needle)!=NULL) n++++;
	}

  printf("Kata %s: %d\n",needle,n);
  fclose(novel);
}
