#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, b, result = -1;
vector<int> price;

void FindMaxStudent(){
    int psum, student;
    sort(price.begin(), price.end());
    for(int i = 0; i < n; i++){// 할인 받을 학생
        psum = 0, student = 0;
        for(int j = 0; j < n; j++){
            if(psum > b) break;
            if(j == i) psum += price[j] / 2;
            psum += price[j];
            student++;
        }
        result = max(result, student);
    }
}

int main() {
    cin >> n >> b;
    price = vector<int> (n, 0);
    for(int i = 0; i < n; i++){
        cin >> price[i];
    }

    FindMaxStudent();

    cout << result;
    return 0;
}