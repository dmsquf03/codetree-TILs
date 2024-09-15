#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, k, result = 0;
vector<int> nums;

void FindMaxSum(){
    int sum;
    for(int i = 0; i < n - k + 1; i++){// 시작
        sum = 0;
        for(int j = 0; j < k; j++){// 합
            sum += nums[i + j];
        }
        result = max(result, sum);
    }
}

int main() {
    // 입력
    cin >> n >> k;

    nums = vector<int> (n);

    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    // 실행
    FindMaxSum();

    // 출력
    cout << result;
    return 0;
}