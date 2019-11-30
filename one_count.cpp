#include <iostream>

using namespace std;

const size_t MAXN = 9999;

template <size_t N>
struct oneCount{
    constexpr oneCount(): val(){
        val[0] = 0; val[1] = 1;
        for (size_t i = 2; i < N; i++)
            val[i] = (i%2) + val[i/2];
    }
    size_t val[N];
};

int main(){
    constexpr auto f = oneCount<MAXN>();
    cout << f.val[8] << endl;
    return 0;
}