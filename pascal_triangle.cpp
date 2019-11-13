// g++ -std=c++17 pascal_triangle.cpp
// constexpr std::vector has been approved for C++20

#include <iostream>
#include <array>

using namespace std;

const unsigned int MAXN = 33;

template<unsigned int N>
struct pascal_triangle{
    // pascal triangle layer = {1, last_layer, 1}
    constexpr pascal_triangle(): layer(){
        layer[1] = {1};
        for (unsigned int i=2; i<N; i++){
            layer[i][0] = 1;
            for (unsigned int j=1; j<i-1; j++)
                layer[i][j] = (layer[i-1][j-1] + layer[i-1][j]);
            layer[i][i-1] = 1;
        }
    }
    array<int, N> layer[N];
};

int main(){
    int n;
    constexpr auto psc = pascal_triangle<MAXN>();
    cin >> n;

    if (n > MAXN){
        cout<< "stackoverflow" << endl;
        return 0;
    }
   
    for (int i = 1; i <= n; i++){
        for (int j = 0; j < i; j++){
            cout << psc.layer[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
