// g++ -std=c++17 fac.cpp -o fac

#include <iostream>
#include <limits.h>

using namespace std;

const size_t MAXN = 13;

template<size_t N>
struct fac
{
    constexpr fac(): val()
    {
        val[1] = 1;
	    for (size_t i =2; i < N; i++)
	        val[i] = (val[i-1] * i);
    }
    size_t val[N];
};

int main(){
    size_t n;
    constexpr auto f = fac<MAXN>();
    cin >> n;
    cout << f.val[n] << '\n';
    return 0;
}