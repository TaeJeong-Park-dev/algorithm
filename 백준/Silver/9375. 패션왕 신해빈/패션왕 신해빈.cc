#include <bits/stdc++.h>
using namespace std;

int test_case;

int main() {
    cin >> test_case;
    for (int i = 0; i < test_case; i++) {
        int cnt;
        cin >> cnt;
        map<string, int> clothes;

        for (int j = 0; j < cnt; j++) {
            string item, category;
            cin >> item >> category;
            if (clothes.find(category) == clothes.end()) {
                clothes[category] = 1;
            } else {
                clothes[category] += 1;
            }
        }

        int result = 1;
        for (auto a : clothes) {
            result *= (a.second + 1);
        }
        cout << result - 1 << endl; // 개행 추가
    }
    return 0;
}
