#include <iostream>
using namespace std;

int Operator(int a, char o, int c){
    if(o == '+'){
        return a + c;
    }
    else if(o == '-'){
        return a - c;
    }
    else if(o == '/'){
        return a / c;
    }
    else{
        return a * c;
    }
}

int main() {
    int a, c;
    char o;
    cin >> a >> o >> c;
    cout << a << " " << o << " " << c << " = " << Operator(a, o, c); 
    
    return 0;
}