/**
ABC059
2019/01/22/ 解説AC
author:Mayimg
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
    vector<int> a;
    for(int i = 0; i < n; i++){
        int t;
        cin >> t;
        a.push_back(t);
    }

    ll s1 = 0, s2 = 0, c1 = 0, c2 = 0;
    for(int i = 0; i < n; i++){
        s1 += a[i];
        s2 += a[i];
        if(i % 2 == 0 && s1 <= 0){
            c1 += abs(1 - s1);
            s1 = 1;
        }else if(i % 2 == 1 && s1 >= 0){
            c1 += abs(-1 - s1);
            s1 = -1;
        }

        if(i % 2 == 0 && s2 >= 0){
            c2 += abs(-1 - s2);
            s2 = -1;
        }else if(i % 2 == 1 && s2 <= 0){
            c2 += abs(1 - s2);
            s2 = 1;
        }
    }

    cout << min(c1, c2) << endl;

    return 0;
}