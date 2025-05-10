#include <iostream>
#include <vector>
#include <utility>
#include <cmath>

using namespace std;

int n, result;
int grid[20][20];
int visited[20][20];
vector<pair<int, int>> bombs;
vector<vector<pair<int, int>>> bomb_range = {{{-2, 0}, {-1, 0}, {1, 0}, {2, 0}},
{{-1, 0}, {0, -1}, {1, 0}, {0, 1}},
{{-1, -1}, {1, -1}, {1, 1}, {-1, 1}}};

bool IsInRange(int r, int c){   // r, c가 격자판 위에 있는지 확인하는 함수
    return (-1 < r && r < n && -1 < c && r < n);
}

int CountRegions(){ // 폭탄으로 터지는 지역 카운트하는 함수
    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(visited[i][j] != 0){
                cnt++;
            }
        }
    }
    return cnt;
}

void Select(int curr_num){  // 폭탄의 위치 인덱스(curr_num)에 터트릴 폭탄 종류 선택하는 함수
    if(curr_num == bombs.size() + 1){
        // 최대 지역 카운트 result에 저장
        int cnt = CountRegions();
        // cout << cnt << '\n';
        result = max(result, cnt);
        return;
    }
    int r, c;
    // cout << "현 폭탄 위치:" << curr_num << '\n';
    for(int i = 0; i < 3; i++){ // 폭탄 종류 선택
        for(int j = 0; j < 4; j++){ // 한 폭탄당 4개 지역 터짐
            // 1. 0 -> 1 변경
            r = bombs[curr_num - 1].first + bomb_range[i][j].first;
            c = bombs[curr_num - 1].second + bomb_range[i][j].second;
            if(IsInRange(r, c)){
                visited[r][c]++;
            }
        }
        // cout << i << "폭탄 선택 및 터짐" << '\n';
        // 2. 다음 재귀 함수 호출 curr_num + 1
        Select(curr_num + 1);
        // 3. 다른 분기 탐색을 위한 1번 되돌리기 (이게 왜 안됨!!!!)
        for(int j = 0; j < 4; j++){ // 한 폭탄당 4개 지역 터짐
            r = bombs[curr_num - 1].first + bomb_range[i][j].first;
            c = bombs[curr_num - 1].second + bomb_range[i][j].second;
            if(IsInRange(r, c)){
                if(visited[r][c] != 5) visited[r][c]--;
            }
        }
    }
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
            if(grid[i][j] == 1) {
                bombs.push_back({i, j});
                visited[i][j] = 5;
            }
            else visited[i][j] = 0;
        }
    }

    // Please write your code here.
    Select(1);
    cout << result;

    return 0;
}
