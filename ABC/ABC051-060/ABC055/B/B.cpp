#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
  long long int N, power = 1;

  cin >> N;

  for(long long int i = 1; i <= N; i++) power = i * power % (1000000000 + 7);

  cout << power << endl;

  return 0;
}
