#include <iostream>
#include <cstring>
using namespace std;
 
int n, q, a[100005], bit[2][100005], b, d;
char c;
 
void update(int t, int x, int d){
    while (x <= n){
        bit[t][x] += d;
        x += x & (-x);
    }
}
int query(int t, int x){
    int ret = 0;
    while (x > 0){
        ret += bit[t][x];
        x -= x & (-x);
    }
    return ret;
}
 
int main() {
    while (cin >> n >> q){
        memset(bit, 0, sizeof(bit));
        for (int i = 1; i <= n; i++){
            cin >> a[i];
            if (a[i] == 0) update(0, i, 1);
            else if (a[i] < 0) update(1, i, 1);
        }
        for (int i = 0; i < q; i++){
            cin >> c;
            if (c == 'C'){
                cin >> b >> d;
                if (a[b] == 0) update(0, b, -1);
                else if (a[b] < 0) update(1, b, -1);
                a[b] = d;
                if (a[b] == 0) update(0, b, 1);
                else if (a[b] < 0) update(1, b, 1);
            }
            else{
                cin >> b >> d;
                if (query(0, d)-query(0, b-1)) cout << '0';
                else if ((query(1, d)-query(1, b-1)) % 2 == 1) cout << '-';
                else cout << '+';
            }
        }
        cout << "\n";
    }
}