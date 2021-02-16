#include <iostream>

using namespace std;

int main(){
    
    int x = 1 << 10; // 1024
    int y = 8 & 15; // 1000 & 1111 = 1000 (8)
    cout << x << endl;
    cout << y << endl;
}