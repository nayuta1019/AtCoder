/**
2018/10/20/ 未完成
**/
#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>
#include <sstream>

using namespace std;

int main(){
    long long int Q, A[51], B[51], C[51];
    cin >> Q;

    for(int i = 0; i < Q; i++){
        cin >> A[i] >> B[i] >> C[i];
    }

    for(int q = 0; q < Q; q++){

        if(C[q] % 2 == 1){
            cout << "No" << endl;
            continue;
        }

        if(A[q] % 2 == 0){
            if(B[q] % 2 == 0){
                cout << "Yes" << endl;
            }else{
                if(10 <= C[q]){
                    cout << "Yes" << endl;
                }else{
                    cout << "No" << endl;
                }
            }
        }else{
            if(B[q] % 2 == 0){
                if(10 <= B[q] || 100 <= C[q]){
                    cout << "Yes" << endl;
                }else{
                    cout << "No" << endl;
                }
            }else{
                if(110 <= C[q]){
                    cout << "Yes" << endl;
                }else if(10 <= B[q]){
                    if( (B[q]-10) * 10 <= C[q]){
                        cout << "Yes" << endl;
                    }else{
                        cout << "No" << endl;
                    }
                    
                }else{
                    if(100 <= B[q]*10 + C[q]){
                        cout << "Yes" << endl;
                    }else{
                        cout << "No" << endl;
                    }

                }

                
            }

        }

    }

    return 0;
}