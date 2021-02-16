/**
2018/10/31/ 初見AC
**/
#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()

inline int toInt(string s) {int v; istringstream sin(s);sin>>v; return v;}

typedef long long ll;
 
int main(){
    int N;

    cin >> N;

    int sum = 0;
    for(int i = 1; i <= 9; i++){
        for(int j = 1; j <= 9; j++){
            sum += i*j;
        }
    }
        
    int dif = sum - N;

    for(int i = 1; i <= 9; i++){
        for(int j = 1; j <= 9; j++){
            if(dif == i*j) printf("%d x %d\n", i, j);
        }
    }

    return 0;
}