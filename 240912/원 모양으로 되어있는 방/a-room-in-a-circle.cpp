#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;
int n, m_val = INT_MAX;
vector<int> room, fix_people;

void FindMinDist(){
    int t_dist, c_dist;
    // 시작 방 인덱스 for문
    for(int i = 0; i < n; i++){
        t_dist = 0, c_dist = 1;
        for(int j = i + 1; ; j++){// 해당 방 다음부터 거리 계산
            j %= n;
            t_dist += c_dist * fix_people[j];
            c_dist++;
            if(c_dist == n){
                break;
            }
        }
        m_val = min(m_val, t_dist);
        
    }

}

int main() {
    // 입력
    cin >> n;
    room = vector<int> (n, 0);
    fix_people = vector<int> (n, 0);

    for(int i = 0; i < n; i++){
        cin >> fix_people[i];
    }

    // 실행
    FindMinDist();

    // 출력
    cout << m_val;

    return 0;
}