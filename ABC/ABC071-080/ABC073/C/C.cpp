#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>
#include <limits>
#include <numeric>

using namespace std;

int main(){
    int N;
    long long int A[100001];

    cin >> N;
    for(int i = 0; i < N; i++) cin >> A[i];

    sort(A, A+N);

    long long int k=0, cnt=1;
    long long int tmp = A[0];
    for(int i = 1; i < N; i++){
        if(tmp == A[i]){
            cnt++;
        }else{
            if(cnt % 2 == 1) k++;
            cnt = 1;
            tmp = A[i];
        }
        if(i == N-1) k += cnt % 2;
    }

    cout << k << endl;

    return 0;
}
