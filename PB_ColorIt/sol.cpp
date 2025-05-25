#include <iostream>
#include <map>
#include <vector>
using namespace std;

map<int, vector<int>>MAP;
map<int, int>walk;
int N;

int change(int c) {
    if (c == 1) c = 2;
    else c = 1;
    return c;
}

bool BFS(const vector<int>start, const int target , int color) {
    if (start.size() == 0) return true;
    vector<int>newStart;
    map<int, int>push;
    for (int i = 0; i<start.size(); i++) {
        if (walk[start[i]] == color) return false;
        walk[start[i]] = color;
        for (int j = 0; j<MAP[start[i]].size(); j++) {
            const int num = MAP[start[i]][j];
            if (walk[num] == 0 && push[num] == 0) {
                push[num]++;
                newStart.push_back(num);
            }
        }
    }
    change(color);
    return BFS(newStart, target , color);
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    while (cin >> N && N != 0) {
        MAP.clear();
        walk.clear();
        int M;
        cin >> M;
        for (int i = 0; i<M; i++) {
            int a, b;
            cin >> a >> b;
            MAP[a].push_back(b);
            MAP[b].push_back(a);
        }
        bool ok = true;
        for (int i = 0; i<N; i++) {
            if (walk[i] > 0) continue;
            vector<int>start;
            start.push_back(i);
            if (!BFS(start, i , 1)) {
                cout << "NOT BICOLORABLE.\n";
                ok = false;
                break;
            }
        }
        if (ok) cout << "BICOLORABLE.\n";
    }
}
