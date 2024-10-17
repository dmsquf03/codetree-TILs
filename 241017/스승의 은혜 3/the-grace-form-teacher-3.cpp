#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

int N, B, result = -1;
vector<tuple<int, int, int>> prices;

void FindMaxStudent(){
    vector<tuple<int, int, int>> copy = prices;

    for(int i = 0; i < N; i++){ // 할인 선물 선택
        int sum = 0, num = 0;
        copy = prices;
        get<0>(copy[i]) = get<1>(copy[i]) / 2 + get<2>(copy[i]);
        sort(copy.begin(), copy.end());
        for(int j = 0; j < N; j++){
            sum += get<0>(copy[j]);
            if(sum > B) break;
            num++;
        }
        result = max(result, num);
    }
}

int main() {
    cin >> N >> B;

    int p, s;
    for(int i = 0; i < N; i++){
        cin >> p >> s;
        prices.emplace_back(p + s, p, s);
    }

    FindMaxStudent();

    cout << result;
    return 0;
}