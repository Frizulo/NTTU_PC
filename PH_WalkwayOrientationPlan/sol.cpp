//uva12319
#include<iostream>

using namespace std;

int v[105][105];
int fv[105][105];

int main(){
    
    int n;
    int A, B;
    int c, temp = 't';
    int f;
    int max;
    cin >> n;
    while (n != 0){
        for (int i = 0; i < 105; ++i)
            for (int j = 0; j < 105; ++j)
                v[i][j] = fv[i][j] = 65535;
        while(getchar() != '\n');
        for (int i = 0; i < 103; ++i)
            v[i][i]=fv[i][i]=1;
        for (int i = 1; i <= n; ++i){
            cin >> c;
            temp = cin.get();
            while(temp != '\n'){
                cin >> temp;
                v[c][temp]=1;
                temp = cin.get();
            }
        }
        for (int i = 1; i <= n; ++i){
            cin >> c;
            temp = cin.get();
            while(temp != '\n'){
                cin >> temp;
                fv[c][temp]=1;
                temp = cin.get();
            }
        }
        cin >> A;
        cin >> B;
        for (int k = 1; k <= n; ++k)
            for (int i = 1; i <= n; ++i)
                for (int j = 1; j <= n; ++j){
                    if (v[i][j] > v[i][k] + v[k][j])
                        v[i][j] = v[i][k] + v[k][j];
                    if (fv[i][j] > fv[i][k] + fv[k][j])
                        fv[i][j] = fv[i][k] + fv[k][j];
                }
        f = 1;
        max = 0;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j){
                if (fv[i][j] > v[i][j] * A + B)
                    f = 0;
                if (max < v[i][j] && v[i][j] != 65535)
                    max = v[i][j];
            }
        if (f)
            cout << "Yes" << ' ' << max << endl;
        else
            cout << "No" << ' ' << max << endl;
        cin >> n;
    }
}