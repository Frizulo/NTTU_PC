#include <bits/stdc++.h>
using namespace std;
int main(){
    int h1, m1, h2, m2;
    while (cin >> h1 >> m1 >> h2 >> m2)
    {
        if( h1 == h2 && m1 == m2 ) {
            cout << "Time to do something!!" << endl;
            break;
        }
        int first, second;
        if (h1 == 0) 
            first = (24*60) + m1;
        else 
            first = (60*h1) + m1;
        if (h2 == 0) 
            second = (24*60) + m2;
        else 
            second = (60*h2) + m2;
        if (second < first) second += (60*24);
        int ans = second - first;
        cout << "Ring in ";
        if (ans / 60)
            cout << (ans / 60) << " hr ";
        if  (ans % 60)
            cout << (ans % 60) << " min";
        cout << endl;
    }
}