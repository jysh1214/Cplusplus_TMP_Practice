// g++ -std=c++17 fib.cpp

#include <iostream>
#include <limits.h>

using namespace std;

const int MAXN = 40;
//const int MAXN = 262144;
const int MOD = 1000000007;

template<unsigned int N>
struct fib{
    constexpr fib(): val(){
        val[0] = 0; val[1] = 1;
	    for (int i =2; i < N; i++)
	        val[i] = (val[i-1] + val[i-2]); //%MOD;
    }
    int val[N];
};

int main()
{
    constexpr auto fibo = fib<MAXN>();
    int n;
    cin >> n;
    if (n > MAXN){
        cout << "stackoverflow" << endl;
        return 0;
    }
    cout << fibo.val[n] << '\n';
    return 0;
}
