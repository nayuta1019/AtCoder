#include <iostream>
#include <climits>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <ios>
#include <iomanip>

using namespace std;

// 最大公約数
long long gcd(long long a, long long b){
    if(b == 0) return a;
    return gcd(b, a % b);
}

// 最小公倍数
long long lcm(long long a, long long b){
    long long g = gcd(a,b);
    return a / g * b;
}

int main(){

  int N, X, x[100001], y[100001]={0};

  cin >> N >> X;

  for(int i = 0; i < N; i++) cin >> x[i];

  for(int i = 0; i < N; i++) y[i] = abs(x[i] - X);

  //sort(y, y+N);
  
  int D = gcd(y[1], y[0]);
  for(int i = 2; i < N; i++) D = gcd(y[i], D);
  
  cout << D << endl;

  return 0;
}
