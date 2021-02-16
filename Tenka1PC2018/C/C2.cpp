/**
2018/10/27/ 未完成
**/
#include <bits/stdc++.h>

using namespace std;

int main(){

    long long int N, A[100000];

    cin >> N;
    for(int i = 0; i < N; i++) cin >> A[i];

    sort(A, A+N);

    long long int f[N], b[N];
    long long int psize = 0;
    for(int i = 0; i < N / 2 ; i++){
        f[psize] = A[i];
        psize++;
    }

    long long int qsize = 0;
    for(int i = N - 1; N / 2 <= i; i--){
        b[qsize] = A[i];
        qsize++;
    }

    long long int ans[N+1], p = 0, q = 0;
    //cout << psize << " " << qsize << endl;
    for(int i = 0; i < N; i++){
        //cout << "i = " << i << endl;
        if(i == 0){
            ans[i] = b[qsize-1];
            qsize--;
            i++;
        }
        
        
        if(q < qsize){
            ans[i] = b[q];
            q++;
            i++;
        }

        if(p < psize){
            ans[i] = f[p];
            p++;
            
        }
    }

    long long int res = 0;
    for(int i = 0; i < N-1; i++){
        res += abs(ans[i] - ans[i+1]);
    }




    /**
    for(int i = 0; i < psize; i++) cout << f[i] << " ";
    cout << endl;
    for(int i = 0; i < qsize; i++) cout << b[i] << " ";
    cout << endl;
    for(int i = 0; i < N; i++) cout << ans[i] << " ";
    cout << endl;
    **/

    cout << res << endl;
    


    return 0;
}