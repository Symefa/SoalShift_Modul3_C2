#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

int weapontoint(char *weapon);
char *inttoweapon(int x);

void main()
{
  int *value;
        key_t key = 1234;

        int shmid = shmget(key, sizeof(int), IPC_CREAT | 0666);
        value = shmat(shmid, NULL, 0);

        *value = 10;

        printf("Program 1 : %d\n", *value);

        sleep(5);

        printf("Program 1: %d\n", *value);
        shmdt(value);
        shmctl(shmid, IPC_RMID, NULL);
}

int weapontoint(char *weapon)
{

}

char *inttoweapon(int x)
{
  
}
