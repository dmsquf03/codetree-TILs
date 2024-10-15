#include <iostream>
#include <vector>
using namespace std;

int K, N, result = 0;
vector<vector<int>> ranking;

void CountDefiniteRanking(){
    bool possible;
    for(int i = 0; i < N; i++){ // 한 개발자
        for(int k = 0; k < N; k++){ // 다른 개발자
            possible = true;
            if(k == i) continue;
            for(int j = 0; j < K; j++){ // 모든 경기
                if(ranking[j][i] < ranking[j][k]){
                    possible = false;
                    break;
                }
            }
            if(possible) result++;
        }
    }
}

int main() {
    cin >> K >> N;

    ranking = vector<vector<int>> (K, vector<int>(N)); // 행: 경기, 열: 개발자 번호, 내용: 순위

    int temp;
    for(int i = 0; i < K; i++){ // 경기 수
        for(int j = 0; j < N; j++){ // 순위
            cin >> temp; // 개발자 번호
            ranking[i][temp - 1] = j;
        }
    }

    CountDefiniteRanking();

    cout << result;
    return 0;
}