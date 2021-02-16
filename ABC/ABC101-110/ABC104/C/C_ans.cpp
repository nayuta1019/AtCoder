/**
2018/11/16/ 解説用
**/
#include <iostream>

using namespace std;

int main(){
    int D, G, p[11], c[11];
    cin >> D >> G;
    for(int i = 0; i < D; ++i) cin >> p[i] >> c[i];
    
    int ans = 1e9;
    // mask < 2^D
    for(int mask = 0; mask < (1 << D); ++mask){
        int s = 0, num = 0, rest_max = -1;
        for(int i = 0; i < D; ++i){
            int check = mask >> i & 1;
            //cout << "mask = " << mask << " : " << "i = " << i << endl; 
            //cout << "mask >> i & 1 = " << check << endl;
            //cout << endl;
            if(mask >> i & 1){
                s += 100 * (i+1) * p[i] + c[i];
                num += p[i];
            }else{
                rest_max = i;
            }
        }
        if(s < G){
            int s1 = 100 * (rest_max + 1);
            int need = (G - s + s1 - 1) / s1;
            if(need >= p[rest_max]){
                continue;
            }
            num += need;
        }
        ans = min(ans, num);
    }

    cout << ans << endl;
}