#include <stdio.h>
#include <pthread.h>

int wait1 = 1;
int wait2 = 1;
int turn = 0;
int tebak = 0;

int mine1[16];
int guess1[4];
int score1=0;
int filled1=0;
char name1[30];

int mine2[16];
int guess2[4];
int score2=0;
int filled2=0;
char name2[30];

void *player1(void* arg)
{
  while(1)
  {
    if (turn == 0)
    {
      int input = 0;

      printf("%s turn!\n", name1);

      while(1)
      {
        printf("masukkan banyak ranjau yang akan diisi:\n");
        scanf("%d", &input);
        if (input > 4)
        {
          printf("tidak boleh lebih dari 4 !\n");
        }
        else if (input+filled1>16)
        {
          printf("anda tidak memiliki sisa ruang yang cukup\n");
        }
        else
        {
          break;
        }
      }

      for (int i = 0; i<input; i++)
      {
        while (1) {
          int x;
          printf("masukkan tempat yang mau anda isi\n");
          scanf("%d", &x);
          if (mine1[x] == 1)
          {
            printf("tempat sudah terisi ranjau lain!\n");
          }
          else
          {
            mine1[x] = 1;
            filled1++;
          }
        }
      }

      for(int i = 0; i < 4; i++)
      {
        int x;
        printf("tebak posisi ranjau lawan:\n");
        scanf("%d", &x);
        if (mine2[x]==1)
        {
          score1++;
        }
        else
        {
          score2++;
        }
      }
      turn = 1;
    }
  }
  wait1=0;
}

void *player2(void* arg)
{
  while(1)
  {
    if (turn == 1)
    {
      int input = 0;

      printf("%s turn!\n", name2);

      while(1)
      {
        printf("masukkan banyak ranjau yang akan diisi:\n");
        scanf("%d", &input);
        if (input > 4)
        {
          printf("tidak boleh lebih dari 4 !\n");
        }
        else if (input+filled2>16)
        {
          printf("anda tidak memiliki sisa ruang yang cukup\n");
        }
        else
        {
          break;
        }
      }

      for (int i = 0; i<input; i++)
      {
        while (1) {
          int x;
          printf("masukkan tempat yang mau anda isi\n");
          scanf("%d", &x);
          if (mine2[x] == 1)
          {
            printf("tempat sudah terisi ranjau lain!\n");
          }
          else
          {
            mine2[x] = 1;
            filled2++;
          }
        }
      }

      for(int i = 0; i < 4; i++)
      {
        int x;
        printf("tebak posisi ranjau lawan:\n");
        scanf("%d", &x);
        if (mine1[x]==1)
        {
          score2++;
        }
        else
        {
          score1++;
        }
      }
      turn = 0;
    }
  }
  wait2=0;
  }
}


int main()
{

return 0;
}
