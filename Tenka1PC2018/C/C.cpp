/**
2018/10/27/ 未完成
**/
#include <cassert>
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <array>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int main(){

    int N, A[100000];
    bool c[100000];

    cin >> N;
    for(int i = 0; i < N; i++) cin >> A[i];

    sort(A, A+N);

    for(int i = 0; i < N; i++) c[i] = true;

    int front = 0;
    int mid = N/2;
    int back = N-1;

    int ans[N+1];
    int p = 0;
    bool flag = true;
    while(flag){
        
        if(c[mid]){
            ans[p] = A[mid];
            c[mid] = false;
            p++;
            mid++;
        }
        
        if(c[back]){
            ans[p] = A[back];
            c[back] = false;
            p++;
            back++;
        }
         
        if(c[front]){
            ans[p] = A[front];
            c[front] = false;
            p++;
            front++;
        }

        for(int i = 0; i < N; i++){
            if(c[i] == true){
                flag = true;
                break;
            }
            flag = false;
        }
    }

    int res = 0;
    for(int i = 0; i < N-1; i++){
        res += abs(ans[i] - ans[i+1]);
    }

    cout << res << endl;


    return 0;
}