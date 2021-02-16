#include <cstdio>
#include <iostream>

using namespace std;

typedef long long ll;

string s;
int N;
ll m, a, r, c, h;
ll D[5];

int P[10] = {0 ,0 ,0 ,0 ,0 ,0 ,1 ,1 ,1 ,2};
int Q[10] = {1 ,1 ,1 ,2 ,2 ,3 ,2 ,2 ,3 ,3};
int R[10] = {2 ,3 ,4 ,3 ,4 ,4 ,3 ,4 ,4 ,4};

int main (){

    scanf ("%d", &N);
    for(int i = 0; i < N ;i++){
        cin >> s;
        if( s[0]== 'M') m++;
        if( s[0]== 'A') a++;
        if( s[0]== 'R') r++;
        if( s[0]== 'C') c++;
        if( s[0]== 'H') h++;
    }

    D[0] = m, D[1] = a, D[2] = r, D[3] = c, D[4] = h;
    ll res = 0;
    for (int d = 0; d < 10; d++) res += D[ P[d] ] * D[ Q[d] ] * D[ R[d] ];

    printf ("%lld \n", res);

    return 0;
}