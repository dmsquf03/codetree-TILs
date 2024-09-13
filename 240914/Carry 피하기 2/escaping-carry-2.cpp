#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<int> nums;
int max_v = 0, n;

void FindNoCarryMax(){
    // 서로 다른 3개 숫자 고르기
    // 각 자리별 숫자 더하기 10 넘으면 pass
    // 아니면 3개 다 더한 값 sum에 저장
    // max_v와 sum 비교 후 갱신
    int ans = -1;
    for(int i = 0; i < n - 2; i++)
        for(int j = i + 1; j < n - 1; j++)
            for(int k = j + 1; k < n; k++) {
				bool carry = false;
				
				//일의 자리에서 carry가 발생하는 경우
                if(nums[i] % 10 + nums[j] % 10 + nums[k] % 10 >= 10)
					carry = true;
				
				//십의 자리에서 carry가 발생하는 경우
                if(nums[i] % 100 / 10 + nums[j] % 100 / 10 + nums[k] % 100 / 10 >= 10)
					carry = true;
				
				//백의 자리에서 carry가 발생하는 경우
                if(nums[i] % 1000 / 100 + nums[j] % 1000 / 100 + nums[k] % 1000 / 100 >= 10)
					carry = true;
				
				//천의 자리에서 carry가 발생하는 경우
                if(nums[i] % 10000 / 1000 + nums[j] % 10000 / 1000 + nums[k] % 10000 / 1000 >= 10)
					carry = true;
				
				if(carry == false)
					max_v = max(max_v, nums[i] + nums[j] + nums[k]);
			}
}

int main() {
    // 입력
    cin >> n;
    nums.resize(n);

    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    // 실행
    FindNoCarryMax();

    // 출력
    cout << max_v;
    return 0;
}