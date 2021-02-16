#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>
#include <sstream>
#include <complex>

using namespace std;

int main(){
  long long int N;

  cin >> N;

  long long int F_min = INT_MAX;
  for(long long int A = 1; A <= sqrt(N); A++){

    if(N % A == 0){
      string a = to_string(A);
      string b = to_string(N / A);
      long long int f = max(a.size(), b.size());
      if(f < F_min) F_min = f;
    }

  }
  cout << F_min << endl;

	return 0;
}
