/**
2018/10/21/ 未完成
出力部分がダメだと思う
2018/10/22/ 初D問題自力AC!
**/
#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>
#include <sstream>

using namespace std;

vector<pair<int, int>> T;

void printPairVector(){
	for(int i = 0; i < T.size(); i++){
		cout << T[i].first << " " << T[i].second << endl;
	}
}

void Round(){
	for(int i = 0; i < T.size(); i++){
        double a = (double)T[i].first;
        double aa = (double)T[i].second;
        int b;
        int bb;

        if(T[i].first % 10 < 5){
            a = (double)T[i].first / 10.0;
            b = (int)a * 10;
        }else if(5 < T[i].first % 10){
            a = (double)T[i].first / 10.0;
            b = (int)a * 10 + 5;
        }else{
            b = (int)a;
        }

        if(0 < T[i].second % 10 && T[i].second % 10 < 5){
            aa /= 10.0;
            bb = (int)aa * 10 + 5;
        }else if(5 < T[i].second % 10){
            aa /= 10.0;
            bb = (int)aa * 10 + 10;
            if(bb % 100 == 60) bb += 40;
        }else{
            bb = (int)aa;
        }
        
        T[i].first = b;
        T[i].second = bb;
	}

}

int main(){
    int N;
    

    cin >> N;
    for(int i = 0; i < N; i++){
        string s;
        cin >> s;

        stringstream ss, se;
        ss << s.substr(0, 4);
        se << s.substr(5, 8);

        int num1, num2;
        ss >> num1;
        se >> num2;
        T.push_back(make_pair(num1, num2));
    }

    Round();
    //printPairVector();

    sort(T.begin(), T.end());

    //printPairVector();

    int S = T[0].first, E = T[0].second;
    string str = to_string(S);
    while(str.size() < 4) str = "0" + str;
    cout << str << "-";
    for(int i = 1; i < N; i++){

        if(T[i].first <= E){
            if(E <= T[i].second) E = T[i].second;
            
        }else{
            
            string str1 = to_string(E);
            while(str1.size() < 4) str1 = "0" + str1;
            cout << str1 << endl;

            S = T[i].first;
            E = T[i].second;

            string str2 = to_string(S);
            while(str2.size() < 4) str2 = "0"+str2;
            cout << str2 << "-";
        }

    }

    string str3 = to_string(E);
    while(str3.size() < 4) str3 = "0" + str3;
    cout << str3 << endl;

    return 0;
}