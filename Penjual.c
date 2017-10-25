#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>

char senjata[6][8];

senjata[0][0]="MP4A1";
senjata[1][0]="PM2-V1";
senjata[2][0]="SPR-3";
senjata[3][0]="SS2-V5";
senjata[4][0]="SPG1-V3";
senjata[5][0]="MINE";

int jml_senjata[6];




void main(){
 	key_t key = 1234;
    int *value;

    int shmid = shmget(key, 6*sizeof(int), IPC_CREAT | 0666);
    value = shmat(shmid, NULL, 0);

	int pilihan,stock;
	int status=1;
	char masuk[8];

	printf("1. Lihat Stok Senjata\n");
	printf("2. Tambah Stok Senjata\n");

	while(status){
		scanf("%d", &pilihan);
		if(pilihan==1){
			if(jml_senjata[0][0]>0) printf("MP4A1 %d\n", jml_senjata[0]);
			if(jml_senjata[1][0]>0) printf("PM2-V1 %d\n", jml_senjata[1]);
			if(jml_senjata[2][0]>0) printf("SPR-3 %d\n", jml_senjata[2]);
			if(jml_senjata[3][0]>0) printf("SS2-V5 %d\n", jml_senjata[3]);
			if(jml_senjata[4][0]>0) printf("SPG1-V3 %d\n", jml_senjata[4]);
			if(jml_senjata[5][0]>0) printf("MINE %d\n", jml_senjata[5]);
		}
		else if(pilihan==2){
			scanf("%s %d", &masuk, &stock);
			if(!strcmp(masuk, "MP4A1")) jml_senjata[0]=+stock;
			else if(!strcmp(masuk, "PM2-V1")) jml_senjata[1]=+stock;
			else if(!strcmp(masuk, "SPR-3")) jml_senjata[2]=+stock;
			else if(!strcmp(masuk, "SS2-V5")) jml_senjata[3]=+stock;
			else if(!strcmp(masuk, "SPG1-V3")) jml_senjata[4]=+stock;
			else if(!strcmp(masuk, "MINE")) jml_senjata[5]=+stock;
			else printf("Unavailable\n");
		}
		else{
			status=0;
		}

	}
	shmdt(value);
	shmctl(shmid, IPC_RMID, NULL);
}