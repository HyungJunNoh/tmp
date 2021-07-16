#include <stdio.h>

int main() {

  int n = 8888;

  int *a = new int[n];

  for (int  i = 0; i < n; i++)
    a[i] = i;

  for (int  i = 0; i < n; i++)
    a[i] +=  2;

  for (int i = 0; i < n; i++) {
     if (i < 5) {
       printf("%d \n", *(a+i));
       printf("haha \n");
     }
   }
  delete[] a;

  return 0;
}
