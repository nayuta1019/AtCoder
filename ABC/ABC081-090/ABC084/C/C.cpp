/**
2018/10/21/ 解説AC
駅 j に開通式開始 t 秒後に到着したとき、駅 j + 1 に向かう列車に乗れるのが開通式開始何秒後かを考えると、次のようになります。
・t < Sj ならば開通式開始 Sj 秒後
・そうでなく、t ％ Fj = 0 ならば開通式開始 t 秒後
・そうでないなら、開通式開始 t + Fj − (t ％ Fj ) 秒後
これに従い、全ての駅 i から出発する場合に対してシミュレーションしてみると、O(N2) となり、解くことができます。
**/
#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>
#include <sstream>

int N, C[500], S[500], F[500];

using namespace std;

int main(){

    scanf ("%d", &N);
    for(int i = 0; i < N - 1; i++) scanf("%d%d%d", &C[i], &S[i], &F[i]);

    for(int i = 0; i < N; i++){
        int t = 0;
        for(int j = i; j < N - 1; j++){
            if(t < S [j]) t = S[j];
            else if (t % F[j] == 0);
            else t = t + F[j] - t % F[j];
            t += C[j];
        }

        printf ("%d\n", t);

    }

    return 0;
}