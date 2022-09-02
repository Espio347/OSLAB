#include <stdio.h>
#include <unistd.h>

int main()
{
 if(fork())
  {
    if(!fork())
      {
        fork();
        printf("\nA");
      }
    else
     printf("\nB");
  }
 else
     printf("\nC");
 return 0;
}

