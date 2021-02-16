#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

int main(){
    int N, a[110];

    cin >> N;
    for(int i = 0; i < N; i++) cin >> a[i];

    int C[9]={0};
    for(int i = 0; i < N; i++){
        if(a[i] < 400) C[0]++;
        else if(a[i] < 800) C[1]++;
        else if(a[i] < 1200) C[2]++;
        else if(a[i] < 1600) C[3]++;
        else if(a[i] < 2000) C[4]++;
        else if(a[i] < 2400) C[5]++;
        else if(a[i] < 2800) C[6]++;
        else if(a[i] < 3200) C[7]++;
        else C[8]++;
    }

    int cmin=0, cmax=0;
    for(int i = 0; i < 8; i++){
        if(0 < C[i]){
            cmin++; cmax++;
        }
    }

    cmax += C[8];
    if(cmin == 0) cmin = 1;

    cout << cmin << " " << cmax << endl;


    return 0;
}
