/**
2018/11/07/ 解説用
mapを使った書き方
**/
#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    map<int, int> m;
    for(int i = 0; i < n; i++) m[a[i]] = 0;

    int cnt = 0;
    for(auto &p : m) p.second = cnt++;

    for(int i = 0; i < n; i++) cout << m[a[i]] << endl;

    return 0;
}