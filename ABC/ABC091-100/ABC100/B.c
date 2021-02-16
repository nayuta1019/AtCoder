#include <stdio.h>

int main(){
  int D, N, i, ans;
  scanf("%d %d", &D, &N);

  ans = 0;
  if(D == 0){
    ans = N;
  }else if(D == 1){
    for(i = 0; i < N; i++){
      ans += 100;
    }
  }else{
    for(i = 0; i < N; i++){
      ans += 10000;
    }
  }
  printf("%d\n", ans);
  return 0;
}
