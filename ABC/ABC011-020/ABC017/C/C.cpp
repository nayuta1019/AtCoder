/**
2018/11/04/ 解説AC
いもす法
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    int N, M, arr[110000], total = 0;

    cin >> N >> M;
    for(int i = 0; i < N; i++){
        int l, r, s;
        cin >> l >> r >> s;
        arr[l] += s;
        arr[r+1] -= s;
        total += s;
    }

    for(int i = 0; i <= M; i++) arr[i+1] = arr[i] + arr[i+1];
    
    sort(arr, arr+M+2);

    cout << total - arr[2] << endl;

    return 0;
}
