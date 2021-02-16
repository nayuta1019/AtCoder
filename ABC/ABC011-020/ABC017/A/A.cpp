/**
2018/11/03/ 初見AC
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    int s1, s2, s3, e1, e2, e3;
    cin >> s1 >> e1 >> s2 >> e2 >> s3 >> e3;

    int total = s1*e1/10 + s2*e2/10 + s3*e3/10;

    cout << total << endl;

    return 0;
}
