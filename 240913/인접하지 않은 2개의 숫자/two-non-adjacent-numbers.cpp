#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, max_v = 0;
vector<int> num;

void FindMaxSum(){
    int sum = 0;
    for(int i = 0; i < n - 1; i++){// 첫번째
        for(int j = i + 2; j < n; j++){// 두번째 (인접X)
           sum = num[i] + num[j];
           max_v = max(sum, max_v); 
        }
    }
}

int main() {
    // 입력
    cin >> n;
    num = vector<int> (n);

    for(int i = 0; i < n; i++){
        cin >> num[i];
    }

    // 실행
    FindMaxSum();

    // 출력
    cout << max_v;
    return 0;
}