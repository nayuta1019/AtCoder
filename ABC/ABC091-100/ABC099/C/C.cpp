// 2018/10/13/実装済みコード(まだ理解してない)
// 2018/10/17 少し理解した
#include <iostream>
#include <cstdio>

using namespace std;

int main(){
    int N;
    scanf ("%d", &N);

    int res = N ;
    for(int i = 0; i <= N ; i++){
        int cnt = 0;
        int t = i;
        while (t > 0){
            cnt += t % 6;
            t /= 6;
        }
        t = N - i;
        while (t > 0){
            cnt += t % 9;
            t /= 9;
        }
        if (res > cnt) res = cnt;
    }

    printf ("%d\n", res);


    return 0;
}