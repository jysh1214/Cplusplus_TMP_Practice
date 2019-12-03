// g++ -std=c++17 main.cpp

#include <iostream>
#include <limits.h>

using namespace std;

template<size_t N>
struct Prime{
    constexpr Prime(): value(), total(){
        total = 0;
        bool is_prime[N]{};

        // Assume all numbers are prime.
        for (size_t n = 0; n < N; ++n)
            is_prime[n] = true;

        // Sieve primes starting at 2.
        for (size_t n = 2; n * n < N; ++n)
            if (is_prime[n])
            for (size_t multiple = n * n; multiple < N; multiple += n)
                is_prime[multiple] = false;

        // Count primes and record primes.
        for (size_t n = 2; n < N; ++n)
            if (is_prime[n]){
                ++total;
                value[total] = n;
            }
    }
    size_t value[N];
    size_t total;
};

int main(){
    constexpr auto p = Prime<9999>();
    cout << p.total << endl;
    for (size_t i = 1; i <= p.total; i++)
        cout << p.value[i] << endl;
    return 0;
}