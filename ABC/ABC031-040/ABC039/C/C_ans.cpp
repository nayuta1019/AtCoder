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

string sound[12] = { "Do","", "Re","", "Mi", "Fa","", "So","", "La","", "Si" };
 
int main(){
    string S;
    cin >> S;

    int pos;
	for (int i = 0; i < S.length(); i++) {
		if (S.substr(i, 6) == "WBWBWB") {
			pos = i;
			break;
		}
	}
	pos = (5 - pos + 12) % 12;

	cout << sound[pos] << endl;

    return 0;
}