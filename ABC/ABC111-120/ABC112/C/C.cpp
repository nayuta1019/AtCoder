#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>
#include <sstream>
 
using namespace std;
 
int main(){
    int N, x[110], y[110];
    long long int h[110];
 
    cin >> N;
    for(int i = 0; i < N; i++) cin >> x[i] >> y[i] >> h[i];


    for(int i = 0; i <= 100; i++){
 
        for(int j = 0; j <= 100; j++){

			int H = -1;
			for(int z = 0; z < N; z++){
				if(h[z] > 0){

					int tmp = h[z] + abs(i - y[z]) + abs(j - x[z]);
					if(H == -1){
						H = tmp;
					}else{
						if(H != tmp){
							H = -2;
							break;
						}
					}
				}
			}
			if (H == -2) continue;
 
			for(int z = 0; z < N; z++){
				if(h[z] == 0){
					int dist = abs(j - y[z]) + abs(i - x[z]);
					if (H > dist) {
						H = -2;
						break;
					}
				}
			}
 
			if (H == -2) continue;

			cout << j << " " << i << " " << H << endl;
			return 0;
            
        }
    }
    
}