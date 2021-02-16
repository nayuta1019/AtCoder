/**
2018/10/28/ 初見AC
出力をしっかり確認！！
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    int txa, tya, txb, tyb, T, V;

    cin >> txa >> tya >> txb >> tyb >> T >> V;

    int n;

    cin >> n;

    bool flag = false;
    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;

        float dist1, dist2;

        dist1 = sqrt( (txa - x)*(txa - x) + (tya - y) * (tya - y) );
        dist2 = sqrt( (txb - x)*(txb - x) + (tyb - y) * (tyb - y) );

        if(dist1 + dist2 <= (T * V) ) flag = true;

    }

    if(flag) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}
