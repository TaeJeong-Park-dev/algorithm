#include <bits/stdc++.h>
using namespace std;

int n = 9;
int k = 7;
vector<vector<int>> save_combi;

void combi(int start, vector<int> b){
    if(b.size() == k){
        // 여기에 저장하는 코드를 넣고 싶다.
        save_combi.push_back(b);
    }
    for(int i = start + 1; i < n; i++){
        b.push_back(i);
        combi(i, b);
        b.pop_back();
    }

    return;
}

int main(){
    vector<int> result;
    vector<int> s(9); // 벡터의 크기를 9로 설정
    for(int i = 0; i < 9; i++){
        cin >> s[i];
    }
    sort(s.begin(), s.end());
    
    // 범위가 좁기 때문에(9까지 밖에 없다.) brute force로 접근가능.
    // 큰 수부터 쌓아서 찾아보기.
    vector<int> b;
    combi(-1, b);

    vector<vector<int>> temp = save_combi;

    for(vector<int> i : temp){
        int sum = 0;
        vector<int> a;
        for(int j : i){
            sum += s[j];
            a.push_back(s[j]);
        }

        if(sum == 100){
            result = a;
        }
    }

    for(int i : result) cout << i << '\n';
}
