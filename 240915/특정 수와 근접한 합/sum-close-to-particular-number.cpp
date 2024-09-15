#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
using namespace std;

int s, n, result = 10000;
vector<int> nums;

void FindClosestSum(){
    int sum, diff;
    for(int i = 0; i < n - 1; i++){// 첫번째 제외 숫자 인덱스
        for(int j = i + 1; j < n; j++){// 두번째 제외 숫자 인덱스
            sum = 0;
            for(int k = 0; k < n; k++){
                if(k == i || k == j) continue;
                sum += nums[k];
            }
            diff = abs(s - sum);
            result = min(result, diff);
        }
    }
}

int main() {
    // 입력
    cin >> n >> s;

    nums = vector<int> (n);

    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    // 실행
    FindClosestSum();

    // 출력
    cout << result;

    return 0;
}