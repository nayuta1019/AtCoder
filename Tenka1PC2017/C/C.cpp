/**
2018/10/27/ 解説AC
**/
#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>
#include <sstream>
#include <bitset>
#include <queue>

using namespace std;

int main(){
    long long int N, h, n, w;

    cin >> N;

    for(h = 1; h <= 3500; h++){
        for(n = 1; n <= 3500; n++){
            w = 4 * h * n - N * n - N * h;
            if(0 < w && N*h*n % w == 0){
                w = N*h*n / w;
                printf("%lld %lld %lld\n", h, n, w);
                return 0;
            }
            
        }
    }
    
    return 0;
    
}