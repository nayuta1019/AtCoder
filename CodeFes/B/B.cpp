#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>
#include <sstream>
 
using namespace std;
 
int main(){
    int N, X, a[110], b[110];

    cin >> N >> X;
    for(int i = 0; i < N; i++) cin >> a[i] >> b[i];

    int bmax = -1; 
    int t;
    for(int i = 0; i < N; i++){
        if(bmax <= b[i]){
            bmax = b[i];
            t = i;
        }
    }
    //cout << bmax << endl;
    //cout << t << endl;
    a[t] += X;

    int max = 0;
    for(int i = 0; i < N; i++){
        max += a[i] * b[i];
    }

    cout << max << endl;


    return 0;
}