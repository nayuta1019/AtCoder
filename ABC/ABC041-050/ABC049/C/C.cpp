#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>
#include <sstream>

using namespace std;
 
int main() {
    string S;
    string str[4] = {"dream", "dreamer", "erase", "eraser"};

    cin >> S;

    reverse(S.begin(), S.end());
    for (int i = 0; i < 4; ++i) reverse(str[i].begin(), str[i].end());

    bool can = true;
    for (int i = 0; i < S.size();) {
        bool can2 = false;
        for (int j = 0; j < 4; ++j) {
            string d = str[j];

            if (S.substr(i, d.size()) == d) {
                can2 = true;
                i += d.size();
            }
        }
        
        if (!can2) {
            can = false;
            break;
        }
    }

    if (can) cout << "YES" << endl;
    else cout << "NO" << endl;


	return 0;
}