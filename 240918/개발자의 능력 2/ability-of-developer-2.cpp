#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int result = INT_MAX;
vector<int> people (6);

void FinMinDiff(){
    int t1, t2, t3, sum = 0, diff;
    for(int i = 0; i < 6; i++){
        sum += people[i];
    }

    for(int i = 0; i < 6; i++){// 1팀 1
        for(int j = i + 1; j < 6; j++){// 1팀 2
            for(int k = 0; k < 6; k++){// 2팀 1
                if(k == i || k == j) continue;
                for(int l = k + 1; l < 6; l++){// 2팀 2
                    if(l == i || l == j) continue;
                    t1 = people[i] + people[j];
                    t2 = people[k] + people[l];
                    t3 = sum - t1 - t2;
                    diff = max(max(t1, t2), max(t1, t3)) - min(min(t1, t2), min(t1, t3));
                    result = min(result, diff);
                }
            }
        }
    }
}

int main() {
    // 입력
    for(int i = 0; i < 6; i++){
        cin >> people[i];
    }

    // 실행
    FinMinDiff();

    // 출력
    cout << result;
    return 0;
}