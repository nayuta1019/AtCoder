/**
2018/11/03/ 初見AC
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    string S;
    int N;

    cin >> S >> N;

    int cnt = 1;
    for(int i = 0; i < S.size(); i++){
        for(int j = 0; j < S.size(); j++){
            if(cnt == N){
                 
                cout << S[i];
                cout << S[j] << endl;
                return 0;
            }
            cnt++;
        }
    }

    return 0;
}
