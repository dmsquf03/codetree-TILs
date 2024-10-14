#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int N, M, D, S;
int result = -1;

class Cheese{
public:
    vector<pair<int, int>> people_ate;// first: 1/0(먹/안먹) second: eatT

    Cheese(){
        people_ate.resize(50, make_pair(0, 0));
    }

    void SetPeopleAte(int idx, int t){
        people_ate[idx].first = 1;
        people_ate[idx].second = t;
    }
};

class People{
public:
    int sickT = -1;

    People(){
    }

    void SetSickT(int t){
        sickT = t;
    }
};

void FindMaxNeedPill(Cheese* cheese, People* people){
    // 상한 치즈라 가정
    // 모순되면 제외
    /* 1. 해당 치즈 안 먹은 사람이 아픔
        for(사람:안 먹은 사람들)
        if(sickTime != -1)
        rotten = false
    */
    /* 2. 먹었는데 먹기 전(바로)에 아픔
        for (사람:먹은 사람들)
        if(sickTime != -1 && sickTime <= eatTime)
        rotten = false
    */
    // 치즈 중심으로 보는 중-> 치즈 먹/안먹 구분위해 치즈 안에 배열부여 (최대 50이니 가능)
    for(int i = 0; i < M; i++){ // 상한 치즈 가정
        bool rotten = true;
        int cnt = 0;
        for(int j = 0; j < N; j++){ // 전체 사람에 대해
            if(cheese[i].people_ate[j].first == 0){ // 안 먹음
                if(people[j].sickT != -1){ // 근데 아픔 -> 모순
                    rotten = false;
                    break;
                }
            }
            else{ // 먹음
                if(people[j].sickT != -1 && people[j].sickT <= cheese[i].people_ate[j].second){ // 이 치즈 먹기 전 또는 바로 아픔 -> 모순
                    rotten = false;
                    break;
                }
                cnt++;
            }
        }
        if(!rotten) continue;
        result = max(result, cnt);
    }

    // 더 합치는 방법은 없을까? 사람 중심으로 본다면?
    // 아픈 사람 -> 상한 치즈를 먹었다 -> 사람이 먹은 치즈 배열 -> 무조건 공통 치즈가 존재해야한다.
    // 결국 시간을 따져야함. 
    
}

int main(){
    cin >> N >> M >> D >> S;

    Cheese* cheese = new Cheese[M];
    People* people = new People[N];

    int p, m, t;
    for(int i = 0; i < D; i++){
        // 몇 번째 사람(p)이 몇 번째 치즈(m)를 언제 먹었는지(t)
        cin >> p >> m >> t;
        cheese[m - 1].SetPeopleAte(p - 1, t);
    }

    for(int i = 0; i < S; i++){
        // 몇 번째 사람(p)이 '확실히' 아픈지(t)
        cin >> p >> t;
        people[p - 1].SetSickT(t);
    }

    FindMaxNeedPill(cheese, people);

    cout << result;

    return 0;
}