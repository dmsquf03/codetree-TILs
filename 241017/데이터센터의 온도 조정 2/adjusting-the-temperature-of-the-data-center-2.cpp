#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int N, C, G, H, result = -1;
vector<pair<int, int>> temperatures;

void FindMaxWorkload(){
    for(int i = -1; i < 1002; i++){ // 온도
        int sum = 0;
        for(int j = 0; j < N; j++){
            if(i < temperatures[j].first) sum += C;
            else if(i > temperatures[j].second) sum += H;
            else sum += G;
        }
        result = max(result, sum);
    }
}

int main() {
    cin >> N >> C >> G >> H;

    int ta, tb;
    for(int i = 0; i < N; i++){
        cin >> ta >> tb;
        temperatures.emplace_back(ta, tb);
    }

    FindMaxWorkload();

    cout << result;
    return 0;
}