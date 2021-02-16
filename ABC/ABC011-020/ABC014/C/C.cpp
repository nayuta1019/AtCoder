/**
2018/11/02/ 解説AC
累積和。配列の要素が大きくなった時はstaticをつけるかグローバルで定義する
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    int n;
    static int arr[1000002]={0};
    cin >> n;

    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;

        arr[a]++;
        arr[b+1]--;
    }

    for(int i = 0; i < 1000001; i++){
        arr[i+1] = arr[i+1] + arr[i];
    }

    sort(arr, arr+1000001);

    
    cout << arr[1000000] << endl;

    return 0;
}