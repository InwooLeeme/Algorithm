#include <stdio.h>

int ret;

int main(void) {
  int n,c; scanf("%d %d", &n, &c);
  ret = c;
  while(n--){
    int m,s; 
    scanf("%d:%d",&m, &s);
    ret += (m * 60);
    ret += s;    
    ret -= c;
  }
  printf("%02d:%02d:%02d\n",ret / 3600,(ret / 60) % 60, ret % 60);
  return 0;
}