#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int N;
        cin >> N;
        int W[1000] = {};
        int P[1000] = {};
        for (int j = 0; j<N; j++) {
            cin >> P[j] >> W[j];
        }
        vector<int> people;
        int G, maxx = -999;
        cin >> G;
        for (int j = 0; j<G; j++) {
            int tmp;
            cin >> tmp;
            people.push_back(tmp);
            maxx = max(maxx, tmp);
        }
        map<int, int>ans;
        for (int j = 0; j<N; j++) {
            int w = W[j] , p = P[j];
            for (int k = maxx; k>=w; k--) {
                ans[k] = max(ans[k], ans[k-w]+p);
            }
            ans[w] = max(p, ans[w]);
        }
        int sum = 0;
        for (int j = 0; j<people.size(); j++) {
            int maxx = -999;
            for (int k = people[j]; k>=0; k--) {
                maxx = max(maxx, ans[k]);
            }
            sum += maxx;
        }
        cout << sum << "\n";
    }
}