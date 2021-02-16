/**
2018/11/19/ 自力AC
**/
#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()

inline int toInt(string s) {int v; istringstream sin(s);sin>>v; return v;}

typedef long long ll;

int main(){
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    sort(A.begin(), A.end());

    vector<int> ans(N);

    int kind = 0;
    int left = 0, right = 0;
    while(left != N){
        while(A[left] == A[right] && right < N){
            ans[kind]++;
            right++;
        }
        left = right;
        kind++;
    }

    sort(ans.begin(), ans.end());

    int res = 0;
    for(int i = 0; i < ans.size()-K; i++){
        res += ans[i];
    }

    cout << res << endl;

    return 0;
}