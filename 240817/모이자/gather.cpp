#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cstdlib>
using namespace std;

int n, m = INT_MAX;
vector<int> people;

void FindMinDist(){
    int dist;
    for(int i = 0; i < n; i++){// 모이는 장소
        dist = 0;
        for(int j = 0; j < n; j++){// 집마다 사람들 이동 거리
            dist += abs(i - j) * people[j];
            // 디버깅
            // cout << "i:" << i << " j: " << j <<" dist: "<< dist << endl;
        }
        // 장소 거리끼리 비교
        if(dist < m){
            m = dist;
        }
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    // 입력
    cin >> n;
    people = vector<int> (n, 0);

    for(int i = 0; i < n; i++){
        cin >> people[i];
    }

    // 실행
    FindMinDist();

    // 출력
    cout << m;

    return 0;
}