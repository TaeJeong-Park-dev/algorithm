#include <bits/stdc++.h>
using namespace std;

map<char, int> name;
int cnt;
vector<string> squad;
string surrender = "PREDAJA";
string result = "";
int main(){    
    cin >> cnt;
    for(int i = 0; i < cnt; i++){
        string tmp;
        cin >> tmp;
        squad.push_back(tmp);
    }

    sort(squad.begin(), squad.end());

    for(string s : squad){
        name[s[0]]++;
        if(name[s[0]] == 5) result += s[0];
    }

    if (result != "") cout << result;
    else cout << surrender;
    
    return 0;
}