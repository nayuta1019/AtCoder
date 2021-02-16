/**
2018/10/28/ 未完成
**/
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>
#include <sstream>

using namespace std;

int main(){
	int N;
    vector<int> A, B, C;

    cin >> N;
    for(int i = 0; i < N; i++){
        int x;
        cin >> x;
        A.push_back(x);
    }

    for(int i = 0; i < N; i++){
        int x;
        cin >> x;
        B.push_back(x);
    }

    for(int i = 0; i < N; i++){
        int x;
        cin >> x;
        C.push_back(x);
    }
    
    
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
	sort(C.begin(), C.end());

    int res = 0;
    for(int i = 0; i < N; i++){
        int a = A[i];
        for(int j = 0; j < N; j++){
            int b = B[j];
            if(b < a) continue;

            for(int k = 0; k < N; k++){
                int c = C[k];
                if(c < a || c < b) continue;

                //cout << "i = " << i << " j = " << j << " k = " << k << endl;
                res += C.size() - k;
                //cout << res << endl;
                break;
            }

            
        }

    }

    cout << res << endl;

	return 0;
}