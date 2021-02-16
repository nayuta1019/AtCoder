#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

int A[200010];

int main(){

  int N, i;
  scanf("%d", &N);

  for(i = 1; i <= N; i++) scanf("%d", &A[i]);

  for(i = 1; i <= N; i++) A[i] -= i; // A[i] - (b + i)

  sort(A + 1, A + N + 1); // A[1]からA[N+1]までを昇順にソート

  int b = A[N / 2 + 1]; // bは配列Aの(N / 2 + 1)番目

  long long res = 0;

  for(i = 1; i <= N; i++) res += abs(A[i] - b); // 最小値を求める。abs(int)はintの絶対値を返す

  printf("%lld\n", res);

  return 0;
}
