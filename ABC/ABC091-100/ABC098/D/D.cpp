/**
2018/11/07/ 解説AC
しゃくとり法。
条件 : (sum ^ a[right]) == (sum + a[right])
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
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    ll res = 0;
    int right  = 0;
    int sum = 0;

    for(int left = 0; left < n; left++){
        while(right < n && (sum ^ a[right]) == (sum + a[right]) ){
            sum += a[right];
            right++;
        }

        res += right - left;

        if(left == right) right++;
        else sum -= a[left];
    }

    cout << res << endl;

    return 0;
}