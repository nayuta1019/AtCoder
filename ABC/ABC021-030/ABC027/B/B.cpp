/**
ABC027
2018/12/30/ 解説自力AC
**/
#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()

inline int toInt(string s) {int v; istringstream sin(s);sin>>v; return v;}

typedef long long ll;

int main(){
    int n, total=0;
    cin >> n;
    vector<int> a(n);
    rep(i, n){
        int x;
        cin >> x;
        a[i] = x;
        total += x;
    }
    

    int ave;
    if(total % n != 0){
        cout << -1 << endl;
        return 0;
    }else{
        ave = total / n;
    }

    int left = 0, ans = 0;
    rep(i, n-1){
        left += a[i];
        if( left != ave*(i+1) ) ans++;
    }

    cout << ans << endl;

    return 0;
}