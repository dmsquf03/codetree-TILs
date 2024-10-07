#include <iostream>
#include <string>
using namespace std;

string IsYoonyear(int y){
    if(y % 4 != 0) return "false";
    if(y % 100 == 0 && y % 400 != 0) return "false";
    return "true";
}

int main() {
    int y;
    string result;
    cin >> y;
    cout << IsYoonyear(y);
    return 0;
}