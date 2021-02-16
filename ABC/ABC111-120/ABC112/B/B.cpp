#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>
#include <sstream>

using namespace std;

int main(){
    int N, T, c[110], t[110];

    cin >> N >> T;
    for(int i = 0; i < N; i++) cin >> c[i] >> t[i];
    

    int ans=INT_MAX, min;
    bool flag = false;
    for(int i = 0; i < N; i++){
        if(t[i] <= T){
            min = c[i];

            if(min < ans) ans = min;
            flag = true;
        }
        
    }
    if(flag) cout << ans << endl;
    else cout << "TLE" << endl; 

	return 0;
}