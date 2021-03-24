#include <stdio.h>

int main()
{
  int k, a, b, x;
  printf("vvedite a\t");
  scanf("%d", &a);
  printf("vvedite b\t");
  scanf("%d", &b);
  printf("vvedite x\t");
  scanf("%d", &x);
  double k=(a*b)/x
  if (a*b<x)
    printf("%d\t", k);
  else
      if (a*b==x)
        printf("Ravni\t");
      else
        printf("%f\t", ((a*b)-x));
  return 0;
}
