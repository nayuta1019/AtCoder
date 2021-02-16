/**
2018/11/04/ 解説用
**/
#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}


int main(){
    int N, M;
    cin >> N >> M;

    tuple<int, int, int> data[M];
    //  (Y_i, P_i, i)の配列

    for(int i = 0; i < M; i++){
        int p, y;
        cin >> p >> y;

        data[i] = make_tuple(y, p, i);
    }

    //  tupleをソートするときは第一要素がkeyとなる
    //  つまりY_iによって昇順にソートされる

    sort(data, data + M);

    int cnt[N+1];

    fill(cnt, cnt + N + 1, 0);  //0で初期化
    //  各県に今属している市の数

    pair<int, int> id[M];
    //  各市の(属する県, 県の中で誕生した順番)

    for(int i = 0; i < M; i++){
        int y, p, idx;
        tie(y, p, idx) = data[i];
        cnt[p]++;
        id[idx] = make_pair(p, cnt[p]);
    }

    for(int i = 0; i < M; i++){
        //  setwで文字数, setfillで埋める文字を指定
        //  iomanipをincludeする必要がある

        cout << setw(6) << setfill('0') << id[i].first;
        cout << setw(6) << setfill('0') << id[i].second << endl;
    }

    return 0;
}