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
        return "False";
    }
}

int main() {
    int a, c;
    char o;
    string result;
    cin >> a >> o >> c;

    result = Operator(a, o, c);
    if(result == "False"){
        cout << result;
    }
    else {
        cout << a << " " << o << " " << c << " = " << result; 
    }

    return 0;
}