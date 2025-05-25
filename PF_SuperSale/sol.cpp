#include <iostream>
#include <cstring>
using namespace std;
int T, N, G, MW;
int P[1005], W[1005];
int dp[35];
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--){
        cin >> N;
        for (int i = 0; i < N; i++){
            cin >> P[i] >> W[i];
        }
        cin >> G;
        int ans = 0;
        while (G--){
            cin >> MW;
            memset(dp, 0, sizeof(dp));
            for (int i = 0; i < N; i++){
                for (int j = MW; j >= W[i]; j--){
                    dp[j] = max(dp[j], dp[j - W[i]] + P[i]);
                }
            }
            int mx = 0;
            for (int i = 0; i <= MW; i++){
                mx = max(mx, dp[i]);
            }
            ans += mx;
        }
        cout << ans << "\n";
    }
    return 0;
}