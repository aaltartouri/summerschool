#include <stdio.h>

int main(int argc, char *argv[])
{
   int f0 = 0, f1 = 1, f2;
  
   // initialize variables and write the while loop
   // Remember to update all variables within the loop

   int i = 2, arr[20];

   arr[0] = f0;
   arr[1] = f1;
   printf("%d %d %d\n", i, arr[0], arr[1]);
   while (i < 20) {
      arr[i] = arr[i-1] + arr[i-2]; 
      printf("%d, %d\n", i, arr[i]);
      i++;

   }

   return 0;
}
