#include <iostream>
#include <vector>
#include <utility>
#include <cmath>

using namespace std;

int n, result = 0;
vector<pair<int, int>> lines;
vector<int> selected;

bool IsSelectable(int idx){ // idx번째 선분을 추가로 선택할 수 있는지 검사하는 함수.
    bool valid = true, condition;
    for(int i = 0; i < selected.size(); i++){
        condition = lines[idx].first > lines[selected[i]].second || lines[idx].second < lines[selected[i]].first;
        if(!condition){
            valid = false;
            break;
        }
    }
    return valid;
}

void Choose(int curr_num){  // curr_num번째 선분 선택 결정 함수.
    if(curr_num == n){  // 마지막 선분까지 결정 완료
        int cnt = selected.size();
        result = max(result, cnt);
        /*cout << "결과: ";
        for(int i = 0; i < selected.size(); i++){
            cout << selected[i] << ' ';
        }
        cout << '\n';*/
        return;
    }
    if(IsSelectable(curr_num)){ // 선택 가능할 때 분기 진행
        // cout << curr_num << " O\n";
        selected.push_back(curr_num);
        Choose(curr_num + 1);
        selected.pop_back(); 
    }
    // cout << curr_num << " X\n";
    Choose(curr_num + 1);

    return;
}

int main() {
    int l, r;
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> l >> r;
        lines.push_back({l, r});
    }

    Choose(0);

    cout << result;

    return 0;
}