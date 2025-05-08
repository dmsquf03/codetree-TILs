#include <iostream>
#include <vector>

using namespace std;

int K, N;
vector<int> answer;

void PrintAnswer(){
    for(int i = 0; i < N; i++){
        cout << answer[i] << ' ';
    }
    cout << '\n';
}

void Choose(int curr_num){
    if(curr_num == N + 1){
        PrintAnswer();
        return;
    }

    for(int i = 1; i <= K; i++){
        answer.push_back(i);
        Choose(curr_num + 1);
        answer.pop_back();
    }
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cout.tie(NULL);

    cin >> K >> N;

    // Please write your code here.
    Choose(1);

    return 0;
}
