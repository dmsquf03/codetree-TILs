#include <iostream>
#include <string>
using namespace std;

string Operator(int a, char o, int c){
    if(o == '+'){
        return to_string(a + c);
    }
    else if(o == '-'){
        return to_string(a - c);
    }
    else if(o == '/'){
        return to_string(a / c);
    }
    else if(o == '*'){
        return to_string(a * c);
    }
    else {
        cout << "false";
        exit(1);
    }
}

int main() {
    int a, c;
    char o;
    cin >> a >> o >> c;
    cout << a << " " << o << " " << c << " = " << Operator(a, o, c); 
    
    return 0;
}