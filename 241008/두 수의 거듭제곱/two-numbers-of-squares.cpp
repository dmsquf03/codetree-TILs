#include <iostream>
#include <cmath>
using namespace std;

int CalAPowerB(int a, int b){
    return pow(a, b);
}

int main() {
    int a, b;
    cin >> a >> b;

    cout << CalAPowerB(a, b);

    return 0;
}