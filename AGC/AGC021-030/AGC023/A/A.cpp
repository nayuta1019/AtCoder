#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>
#include <sstream>
#include <map>
 
using namespace std;
 
int main(){
    int N;
    
    cin >> N;

    map<long, long> mp;
    mp[0] = 1;
    long long sum = 0;

    for(int i = 0; i < N; i++){
        int A;
        cin >> A;
        sum += A;
        mp[sum]++;
    }
 
    long long ans = 0;
    for(auto x : mp){
        if(x.second > 1) ans += (x.second * (x.second - 1) / 2);
    }
    cout << ans << endl;

    return 0;
}