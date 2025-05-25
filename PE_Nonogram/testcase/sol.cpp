#include <bits/stdc++.h>
using namespace std;

void result(const vector<int>& line){
    bool flag = false;
    int cnt = 0;
    for (auto &it: line){
        if (it == 1)
            cnt++;
        else if (cnt > 0){
            cout << cnt << " ";
            cnt = 0;
            flag = true;
        }
    }
    if (cnt > 0 || !flag ) cout << cnt;
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> mp(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> mp[i][j];
    for (int j = 0; j < n; j++){
        vector<int> nowCol(n);
        for (int i = 0; i < n; i++)
            nowCol[i] = mp[i][j];
        result(nowCol);
    }
    for (int i = 0; i < n; i++)
        result(mp[i]);
}
