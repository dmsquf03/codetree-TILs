#include <iostream>
#include <vector>

using namespace std;

int n, answer = 0;
vector<int> result;

void IsBeautifulNum(){ // result가 아름다운 수이면 answer 증가시키는 함수
    bool valid = true;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < result[i]; j++){
            if(result[i + j] != result[i]){
                valid = false;
                break;
            }
        }
        i += result[i] - 1;
    }
    if(valid){
        /* for(int i = 0; i < n; ++i){
            cout << result[i];
        }
        cout << '\n'; */
        answer++;
    }
}

void Repeat(int curr_num){  // curr_num번 자리에 1~4를 선택하는 함수
    if(curr_num == n + 1){
        IsBeautifulNum();
        return;
    }
    for(int i = 1; i <= 4; i++){
        result.push_back(i);
        Repeat(curr_num + 1);
        result.pop_back();
    }
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;

    // Please write your code here.
    Repeat(1);
    cout << answer;

    return 0;
}
