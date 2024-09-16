#include <iostream>
#include <algorithm>
using namespace std;

void FindGCD(int n, int m){
    int gcd = 0; 
    for(int i = 1; i < min(n, m) + 1; i++){
        if(n % i == 0 && m % i == 0){
            gcd = i;
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