#include <iostream>
using namespace std;

void PrintRect(int n){
    int num = 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << num << " ";
            num++;
            if(num == 10) num = 1;
        }
        cout << endl;
    }
}

int main() {
    int n;
    cin >> n;
    PrintRect(n);
    return 0;
}