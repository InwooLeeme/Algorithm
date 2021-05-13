// 6749번 : Next in line

#include <stdio.h>

int main(){
  int a;
  int b = 0;
  scanf("%d %d",&a,&b);
  printf("%d",b+(b-a));
  return 0;
}