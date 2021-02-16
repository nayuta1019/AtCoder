#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>
#include <sstream>
 
using namespace std;

int findSumOfDigits(int n) {
  int sum = 0;
  while (n > 0) {
    sum += n % 10;
    n /= 10;
  }
  return sum;
}
 
int main(){
    int N;

    cin >> N;

    int ans = INT_MAX;
    for(int a = 1; a < N; a++){
        int b = N - a;
        int digitsum = findSumOfDigits(a) + findSumOfDigits(b);

        if(digitsum < ans) ans = digitsum;
    }

    cout << ans << endl;

    return 0;
}