/**
2018/11/05/ 初見AC
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    int N;
    vector< pair<int, int> > a;

    cin >> N;
    for(int i = 0; i < N; i++){
        int x;
        cin >> x;
        a.push_back(make_pair(x, i+1));
    }

    sort(a.begin(), a.end(), greater< pair<int, int> >() );

    for(int i = 0; i < N; i++){
        cout << a[i].second << endl;
    }

    return 0;
}
