#include <iostream>
#include <algorithm>
using namespace std;

void FindGCD(int n, int m){
    int gcd = 1, cn = n, cm = m, small = min(n, m); 
    for(int i = 2; i < small; i++){
        if(cn % i == 0 && cm % i == 0){
            gcd *= i;
            cn /= i;
            cm /= i;
            i--;
        }
    }
    cout << gcd;
}

int main() {
    int n, m;
    cin >> n >> m;
    FindGCD(n, m);
    return 0;
}