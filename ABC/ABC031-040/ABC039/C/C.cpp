/**
2018/11/06/ 解説AC
**/
#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()

inline int toInt(string s) {int v; istringstream sin(s);sin>>v; return v;}

typedef long long ll;

string piano = "WBWBWW";

string sound[12] = {"Do", "Si", "La", "La", "So", "So", "Fa", "Fa", "Mi", "Re", "Re", "Do"};
 
int main(){
    string S;
    cin >> S;

    for(int i = 0; i < S.size() - piano.size() + 1; i++){
        string str = S.substr(i, piano.size());

        if(piano == str){
            cout << sound[i] << endl;
            return 0;
        }
    }

    return 0;
}