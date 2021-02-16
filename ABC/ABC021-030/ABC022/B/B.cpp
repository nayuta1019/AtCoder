/**
ABC022
2018/12/19/ 初見AC
**/
#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()

inline int toInt(string s) {int v; istringstream sin(s);sin>>v; return v;}

typedef long long ll;

int check[100001];

int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    int ans = 0;
    for(int i = 0; i < N; i++){
        if(check[A[i]] == 0) check[A[i]]++;
        else ans++;
    }

    cout << ans << endl;

    return 0;
}