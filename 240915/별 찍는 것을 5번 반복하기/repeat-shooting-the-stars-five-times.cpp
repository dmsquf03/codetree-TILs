#include <iostream>
using namespace std;

void Print10Star(){
    for(int i = 0; i < 10; i++){
        cout << "*";
    }
    cout << endl;
}

int main() {
    Print10Star();
    Print10Star();
    Print10Star();
    Print10Star();
    Print10Star();
    return 0;
}