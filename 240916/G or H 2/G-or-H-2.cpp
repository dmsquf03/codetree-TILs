#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

int n, result = 0;
vector<pair<int, char>> people;

void FindMaxSize(){
    int size = 0, g, h;
    sort(people.begin(), people.end());
    for(int i = 0; i < n - 1; i++){// 구간 시작
        for(int j = i + 1; j < n; j++){// 구간 끝
            g = 0, h = 0;
            for(int k = i; k < j + 1; k++){
                if(people[k].second == 'G') g++;
                else if(people[i].second == 'H') h++;
            }
            if(g != 0 && g == h){
                size = people[j].first - people[i].first;
                result = max(result, size);
            }
        }
    }
}

int main() {
    // 입력
    cin >> n;
    
    int idx;
    char c;
    for(int i = 0; i < n; i++){
        cin >> idx >> c;
        people.emplace_back(idx, c);
    }

    // 실행
    FindMaxSize();

    // 출력
    cout << result;
    return 0;
}