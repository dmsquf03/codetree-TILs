#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int X, Y, result = 0;

void FindMaxSum(){
    for(int i = X; i < Y + 1; i++){
        string a = to_string(i);
        int sum = 0;
        for(int j = 0; j < a.length(); j++){
            sum += a[j] - '0';
        }
        result = max(result, sum);
    }
}

int main() {
    cin >> X >> Y;
    FindMaxSum();
    cout << result;
    return 0;
}