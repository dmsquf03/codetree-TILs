#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int n, result = 0;
vector<pair<int, int>> lines;

bool IsOverlap(int a, int b, int c){
    int overlap[101] = {0};
    for(int i = 0; i < n; i++){ // 모든 선분에 대해
        if(i == a || i == b || i == c) continue; // 제외 선분
        for(int j = lines[i].first; j < lines[i].second + 1; j++){ // 시작~끝까지 1 더함
            overlap[j]++;
            if(overlap[j] > 1) return true;
        }
    }
    return false;
}

void CountDiffCase(){
    for(int i = 0; i < n - 2; i++){
        for(int j = i + 1; j < n - 1; j++){
            for(int k = j + 1; k < n; k++){
                if(IsOverlap(i, j, k)) continue;
                result++;
            }
        }
    }
}

int main() {
    cin >> n;

    int a, b;
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        lines.emplace_back(a, b);
    }

    CountDiffCase();

    cout << result;

    return 0;
}