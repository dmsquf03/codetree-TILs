#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <tuple>
using namespace std;

vector<string> nums;
int max_v = 0, n;

void FindNoCarryMax(){
    // 서로 다른 3개 숫자 고르기
    // 각 자리별 숫자 더하기 10 넘으면 pass
    // 아니면 3개 다 더한 값 sum에 저장
    // max_v와 sum 비교 후 갱신
    int t_sum, sum, flag;
    vector<pair<int, string>> num_lens;
    for(int i = 0; i < n - 2; i++){// 1번째
        for(int j = i + 1; j < n - 1; j++){// 2번째
            for(int k = j + 1; k < n; k++){// 3번째
                num_lens = vector<pair<int, string>>(); // 숫자, 숫자 길이
                num_lens.emplace_back(nums[i].length(), nums[i]);
                num_lens.emplace_back(nums[j].length(), nums[j]);
                num_lens.emplace_back(nums[k].length(), nums[k]);
                sort(num_lens.begin(), num_lens.end()); // 오름차순 정리
                flag = 1;
                // 1의 자리부터, 최대 자리까지
                for(int l = 0; l < num_lens[2].first; l++){// 자리별 숫자 10 넘으면 break
                    if(l < num_lens[0].first){// 다 더해야
                        sum = (num_lens[0].second[num_lens[0].first-(l+1)] - '0') + (num_lens[1].second[num_lens[1].first-(l+1)] - '0') + (num_lens[2].second[num_lens[2].first-(l+1)] - '0');
                        if(sum >= 10){
                            flag = 0;
                            break;
                        }
                    }
                    else if(l >= num_lens[0].first && l < num_lens[1].first){// 작은 숫자 빼고 
                        sum = (num_lens[1].second[num_lens[1].first-(l+1)] - '0') + (num_lens[2].second[num_lens[2].first-(l+1)] - '0');
                        if(sum >= 10){
                            flag = 0;
                            break;
                        }
                    }
                }
                if(flag){
                    t_sum = stoi(nums[i]) + stoi(nums[j]) + stoi(nums[k]);
                    max_v = max(max_v, t_sum);
                }
            }
        }
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