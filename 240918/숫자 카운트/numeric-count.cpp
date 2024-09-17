#include <iostream>
#include <tuple>
#include <vector>
using namespace std;

int n, result = 0;
vector<tuple<string, int, int>> nums;

bool IsRight(int pos_n[3]){
    string s;
    int c1, c2;
    for(int i = 0; i < n; i++){
        s = get<0>(nums[i]); // b가 추측한 숫자
        c1 = 0, c2 = 0;

        // c1, c2
        for(int j = 0; j < 3; j++){
            // 해당 자리에 알맞게 위치 c1
            if(s[j] - '0' == pos_n[j]) c1++;
            // 알맞은 자리는 아님, 근데 다른 곳에 존재 c2
            else if(s[j] - '0' == pos_n[(j + 1) % 3] || s[j] - '0' == pos_n[(j + 2) % 3]) c2++;
        }

        if(c1 != get<1>(nums[i]) || c2 != get<2>(nums[i])) return false;
    }
    return true;
}

void CountPossibleNum(){
    int pos_n[3];
    for(int i = 1; i < 10; i++){// 첫 번째
        for(int j = 1; j < 10; j++){// 두 번째
            if(i == j) continue;
            for(int k = 1; k < 10; k++){// 세 번째
                if(j == k || i == k) continue;
                pos_n[0] = i, pos_n[1] = j; pos_n[2] = k;
                if((IsRight(pos_n))) result++;
                // cout << "ijk:" << i << j << k << " result:" << result << endl;
            }
        }
    }
}

int main() {
    // 입력
    cin >> n;

    string s;
    int c1, c2;
    for(int i = 0; i < n; i++){
        cin >> s >> c1 >> c2;
        nums.emplace_back(s, c1, c2);
    }

    // 실행
    CountPossibleNum();

    // 출력
    cout << result;
    return 0;
}