#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

int N, M, D, S, result = 0;
vector<int> sick;

class People {
public:
    int sick_t = -1;
public:
    // 생성자
    People() {
    }

    void InputSickT(int t){
        this -> sick_t = t;
    }
};

class Cheese {
public:
    vector<pair<int, int>> eat;
public:
    // 생성자
    Cheese() {
    }

    void InputEat(int p, int t){
        eat.emplace_back(p, t);
    }
};

bool isPersonInArray(int person, int eatPersonIndex[], int num) {
    for (int i = 0; i < num; i++) {
        if (eatPersonIndex[i] == person) {
            return true;
        }
    }
    return false;
}

void FindMaxNeedPill(Cheese cheese[], People people[]){
    for(int i = 0; i < M; i++){// 상한 치즈 가정
        bool rotten = true;
        int num = cheese[i].eat.size();
        int eatPersonIndex[num];

        // 치즈를 먹은 사람들의 인덱스 수집
        for (int j = 0; j < num; j++) {
            eatPersonIndex[j] = cheese[i].eat[j].first;
        }

        // 안먹은 사람이 아픔 -> 모순
        for (int person : sick) {
            if (!isPersonInArray(person, eatPersonIndex, num)) {
                rotten = false;
                break;
            }
        }

        // 모순 -> 상한 치즈 아님 -> 제외
        for(int j = 0; j < num; j++){// 가정된 치즈 먹은 사람들
            int eatTime = cheese[i].eat[j].second;     // 치즈를 먹은 시간
            int sickTime = people[eatPersonIndex[j]].sick_t; // 그 사람이 아프기 시작한 시간
            if(sickTime != -1 && eatTime >= sickTime){// 먹기 전 또는 직후에 아픔
                rotten = false;
                break;
            }
        }
        if(!rotten) continue;
        result = max(result, num);
    }
}

int main() {
    cin >> N >> M >> D >> S;

    People* people = new People[N];
    Cheese* cheese = new Cheese[M];

    int p, m, t;
    for(int i = 0; i < D; i++){
        cin >> p >> m >> t;
        cheese[m - 1].InputEat(p - 1, t);
    }

    for(int i = 0; i < S; i++){
        cin >> p >> t;
        people[p - 1].InputSickT(t);
        sick.emplace_back(p - 1);
    }

    FindMaxNeedPill(cheese, people);

    cout << result;

    delete[] people;
    delete[] cheese;

    return 0;
}