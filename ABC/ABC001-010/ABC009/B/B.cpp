/**
2018/11/04/ 初見AC
**/
#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()

inline int toInt(string s) {int v; istringstream sin(s);sin>>v; return v;}

typedef long long ll;

 
int main(){
    int N, A[100];

    cin >> N;
    for(int i = 0; i < N; i++) cin >> A[i];

    sort(A, A+N);

    int ans = A[N-1];
    for(int i = N-1; 0 <= i; i--){
        if(ans == A[i]) continue;

        ans = A[i];
        break;
    }

    cout << ans << endl;


    return 0;
}