#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int result = INT_MAX;
vector<int> people (6);

void FindMinDiff(){
    int t1, t2, t3, sum = 0, diff;
    for(int i = 0; i < 5; i++){
        sum += people[i];
    }

    for(int i = 0; i < 5; i++){// 1팀 1명
        for(int j = 0; j < 5; j++){// 2팀 1
            if(j == i) continue;
            for(int k = j + 1; k < 5; k++){// 2팀 2
                if(k == i) continue;
                t1 = people[i];
                t2 = people[j] + people[k];
                t3 = sum - t1 - t2; 
                if(t1 == t2 || t1 == t3 || t2 == t3) continue;
                diff = max(max(t1, t2), max(t1, t3)) - min(min(t1, t2), min(t1, t3));
                result = min(result, diff);
            }
        }
    }
    if(result == INT_MAX) result = -1;
}

int main() {
    // 입력
    for(int i = 0; i < 5; i++){
        cin >> people[i];
    }

    // 실행
    FindMinDiff();

    // 출력
    cout << result;
    return 0;
}