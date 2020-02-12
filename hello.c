#include <stdio.h>

int main(void)
{
  int a[3] = {10, 20, 30};
  int i = 2;
  int *p = &i;


  printf("%d %p %d\n", i, &i, *p);
  return 0;
}
