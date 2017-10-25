#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>


void main(){
	key_t key = 1234;
    int *value;

    int shmid = shmget(key, 3*sizeof(int), IPC_CREAT | 0666);
    value = shmat(shmid, NULL, 0);

	int pilihan;
	int status=1;

	const char* senjata[6]={"MP4A1","PM2-V1","SPR-3","SS2-V5","SPG1-V3","MINE"};
	char masuk[8];
	int stock;

	printf("1. Lihat Stok Senjata\n");
	printf("2. Tambah Stok Senjata\n");
	printf("Masukka syntax: ");

	while(status){
		scanf("%d", &pilihan);
		if(pilihan==1){
			for(int i=0;i<6;i++){
				printf("%s %d\n", senjata[i], value[i]);
			}
		}
		else if(pilihan==2)	{
			scanf("%s %d", masuk, &stock);
			if(!strcmp(masuk,"MP4A1")) value[0]+=stock;
			else if(!strcmp(masuk,"PM2-V1")) value[1]+=stock;
			else if(!strcmp(masuk,"SPR-3")) value[2]+=stock;
			else if(!strcmp(masuk,"SS2-V5")) value[3]+=stock;
			else if(!strcmp(masuk,"SPG1-V3")) value[4]+=stock;
			else if(!strcmp(masuk, "MINE")) value[5]+=stock;
			else printf("Unavailable");
		}
		else{
			status=0;
		}
			
	printf("1. Lihat Stok Senjata\n");
	printf("2. Tambah Stok Senjata\n");
	printf("Masukka syntax: ");

	}
	shmdt(value);
	shmctl(shmid, IPC_RMID, NULL);
		
}