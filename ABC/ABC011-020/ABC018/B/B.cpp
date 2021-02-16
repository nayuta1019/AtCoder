/**
2018/12/05/ 自力AC
**/
#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()

inline int toInt(string s) {int v; istringstream sin(s);sin>>v; return v;}

typedef long long ll;

int main(){
    string s;
    int n;
    cin >> s >> n;
    
    for(int i = 0; i < n; i++){
        int l, r;
        cin >> l >> r;
        string left, mid, right;
        left = s.substr(0, l-1);
        mid = s.substr(l-1, r-l+1);
        right = s.substr(r, s.size()-r);
        //cout << "left = "  << left << endl;
        //cout << "mid = "  << mid << endl;
        //cout << "right = "  << right << endl;
        reverse(mid.begin(), mid.end());
        s = left + mid + right;
    }

    cout << s << endl;

    return 0;
}