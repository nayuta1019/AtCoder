/**
2018/10/27/ 自力AC
long long にする！
**/
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>
#include <sstream>

using namespace std;

int main(){
	int N, M;

    cin >> N >> M;

    if(1 < abs(N-M)){
        cout << "0" << endl;
        return 0;
    }

    long long int ans = 1, s = 1, t = 1;
    while(s <= N && t <= M){
        ans = (ans * s) % (1000000000+7);
        ans = (ans * t) % (1000000000+7);
        s++; t++;
    }

    if(N == M){
        ans = (ans * 2) % (1000000000+7);
    }else if(N < M){
        ans = (ans * M) % (1000000000+7);
    }else{
        ans = (ans * N) % (1000000000+7);
    }

    cout << ans << endl;

	return 0;
}