/**
ABC069
2019/01/03/ 自力AC
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
    vector<int> x(N);
    int fourcnt = 0, twocnt = 0;
    rep(i, N){
        int a;
        cin >> a;
        if(a % 4 == 0) fourcnt++;
        if(a % 2 == 0 && a % 4 != 0) twocnt++;
    }

    if(twocnt == N){
        cout << "Yes" << endl;
        return 0;
    }

    if(1 <= twocnt && 1 <= fourcnt){
        N = N - twocnt - 1;
        fourcnt--;
    }

    if(N % 2 == 0 && N / 2 <= fourcnt){
        cout << "Yes" << endl;
        return 0;
    }else if(N % 2 == 1 && (N-1) / 2 <= fourcnt){
        cout << "Yes" << endl;
        return 0;
    }

    cout << "No" << endl;

    return 0;
}
/**
a[i]とa[i+1]の積が４の倍数であるとは

(1)a[i]が４の倍数 || a[i+1]が４の倍数　である

if(N % 2 == 0) N/2個以上が４の倍数
else (N-1)/2個以上が４の倍数

(2)a[i]*a[i+1]が４の倍数
a[i]%2 == 0 && a[i]%4 != 0
a[i]が２の倍数 && a[i+1]が２の倍数
全てが２の倍数 || 最後は４の倍数

if(1 <= fourcnt){
    N = N - twocnt - 1;
    fourcnt--;
}

**/