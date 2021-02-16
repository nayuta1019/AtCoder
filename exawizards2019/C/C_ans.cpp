/**
エクサウィザーズ2019
2019/03/31/ 解説AC
二分法
O(QlogN)
**/
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

    int N, Q;
    string S;
    char T[200000], D[200000];
    cin >> N >> Q >> S;

    for(int i = 0; i < Q; i++) cin >> T[i] >> D[i];

	int L = 0;
	int R = N;
    //後ろから見ていく
	for(int i = Q - 1; i >= 0; i--){
        //N+1の場所にたどり着くゴーレムを探す
		if (R > 0 && D[i] == 'R' && S[R - 1] == T[i]) R--;
		else if (R < N && D[i] == 'L' && S[R] == T[i]) R++;
        //0の場所にたどり着くゴーレムを探す
		if (L > 0 && D[i] == 'R' && S[L - 1] == T[i]) L--;
		else if (L < N && D[i] == 'L' && S[L] == T[i]) L++;
	}

	cout << R - L << endl;

	return 0;
}
