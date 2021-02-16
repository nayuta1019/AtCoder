#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>
#include <sstream>
 
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
    long long int N, M;
    string S, T;

    cin >> N >> M >> S >> T;

    long long int L = lcm(N, M);

    //cout << L << endl;

    long long int L_N = L / N;
    long long int L_M = L / M;

    //cout << L_N << endl;
    //cout << L_M << endl;

    if(L_N == L_M && S != T){
        cout << "-1" << endl;
        return 0;
    }

    if(S[0] != T[0]){
        cout << "-1" << endl;
        return 0;
    }

    long long int L_NM = lcm(L_N, L_M);
    long long int tmp = L_NM;

    if(L < L_NM+1){
        cout << L << endl;
        return 0;
    }

    while(tmp < L){
        long long int ss = tmp / L_N;
        long long int tt = tmp / L_M;
        if(N <= ss || M <= tt){
            cout << "-1" << endl;
            return 0;
        }
        if(S[ss] != T[tt]){
            cout << "-1" << endl;
            return 0;
        }
        tmp += L_NM;
    }

    cout << L << endl;

    return 0;
}