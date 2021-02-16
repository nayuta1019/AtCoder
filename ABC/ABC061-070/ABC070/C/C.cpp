#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>
#include <limits>
#include <numeric>

using namespace std;

long long gcd(long long a, long long b){
    if(b == 0) return a;
    return gcd(b, a % b);
}

long long lcm(long long a, long long b){
    long long g = gcd(a,b);
    return a / g * b;
}

int main(){
    int N;
    long int T[110];

    cin >> N;
    for(int i = 0; i < N; i++) cin >> T[i];

    long int x = 1;
    for(int i = 0; i < N; i++) x = lcm(x, T[i]);
    

    cout << x << endl;

    return 0;
}
