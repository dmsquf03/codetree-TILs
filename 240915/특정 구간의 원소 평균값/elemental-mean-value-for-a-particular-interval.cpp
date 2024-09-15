#include <iostream>
#include <vector>
using namespace std;

int n, result = 0;
vector<int> nums;

void FindMeanExistCnt(){
    int sum, m;
    for(int i = 0; i < n; i++){// 구간 시작 인덱스
        for(int j = i; j < n; j++){// 구간 끝 인덱스
            sum = 0;
            for(int k = i; k < j + 1; k++){
                sum += nums[k];
            }
            if(sum % (j - i + 1) != 0) continue;
            m = sum / (j - i + 1);
            for(int k = i; k < j + 1; k++){
                if(m == nums[k]){
                    result++;
                    break;
                }
            }
        }
    }
}

int main() {
    // 입력
    cin >> n;
    nums = vector<int> (n);

    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    // 실행
    FindMeanExistCnt();

    // 출력
    cout << result;
    return 0;
}