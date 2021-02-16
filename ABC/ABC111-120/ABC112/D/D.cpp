#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>
#include <sstream>

using namespace std;

int main(){
    int N, M;
    cin >> N >> M;
    
    for(long int i = M / N; 1 <= i; i--){
        if(M % i == 0){
            cout << i << endl;
            return 0;
        }

    }
}