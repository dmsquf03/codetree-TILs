#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, k, result = 0;
vector<int> bucket;

void FindMaxCandy(){
    int sum;
    for(int i = k; i < 101 - k + 1; i++){// 중심점 c 인덱스
        sum = 0;
        for(int j = i - k; j < i + k + 1; j++){
            sum += bucket[j];
        }
        // cout << "i:" << i << " sum: " << sum << " result: " << result << endl;
        result = max(result, sum);
    }
}

int main() {
    // 입력
    cin >> n >> k;

    bucket = vector<int> (101, 0);

    int idx, cnt;
    for(int i = 0; i < n; i++){
        cin >> cnt >> idx;
        bucket[idx] += cnt;
    }

    // 실행
    FindMaxCandy();

    // 출력
    cout << result;
    return 0;
}