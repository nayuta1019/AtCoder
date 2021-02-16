/**
2018/11/07/ 解説AC
しゃくとり法
**/
#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()

inline int toInt(string s) {int v; istringstream sin(s);sin>>v; return v;}

typedef long long ll;

int main(){
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    ll res = 0;
    int right = 1;
    for(int left = 0; left < n; left++){

        while( right < n && (right <= left || a[right-1] < a[right]) ){
            right++;
        }

        res += right - left;

        if(left == right) right++;

    }

    cout << res << endl;
    

    return 0;
}