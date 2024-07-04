#include <bits/stdc++.h>
using namespace std;

string input;

int main(){
    cin >> input;
    string compare_input = input.substr();
    reverse(compare_input.begin(), compare_input.end());

    if(compare_input == input) cout << 1;
    else cout << 0;

    return 0;
}