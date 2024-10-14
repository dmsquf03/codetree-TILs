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
                // cout << "i:" << i << " j:" << j << " cnt:" << cnt << endl;
            }
        }
        if(!rotten) continue;
        result = max(result, cnt);
    }
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