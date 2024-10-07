#include <iostream>
#include <string>
using namespace std;

int a, b, result = 0;

void CntOnJunSu(){
    for(int i = a; i < b + 1; i++){
        if(i % 2 == 0) continue;
        string temp = to_string(i);
        if(temp[temp.length() - 1] == '5') continue;
        if(i % 3 == 0 && i % 9 != 0) continue;
        result++;
    }
}

int main() {
    cin >> a >> b;

    CntOnJunSu();

    cout << result;
    return 0;
}