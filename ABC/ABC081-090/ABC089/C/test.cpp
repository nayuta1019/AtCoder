#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>
#include <sstream>
 
using namespace std;

int main(){
    int N;
    string S[10];
    cin >> N;
    for(int i = 0; i < N; i++) cin >> S[i];

    long long int cnt[5] = {0};
    for(int i = 0; i < N; i++){
        if(S[i][0] == 'M') cnt[0]++;
        else if(S[i][0] == 'A') cnt[1]++;
        else if(S[i][0] == 'R') cnt[2]++;
        else if(S[i][0] == 'C') cnt[3]++;
        else if(S[i][0] == 'H') cnt[4]++;
    }

    for(int i = 0; i < 5; i++) cout << cnt[i] << endl;

    for(int i = 0; i < N; i++) cout << S[i][0] << endl;

    return 0;
}