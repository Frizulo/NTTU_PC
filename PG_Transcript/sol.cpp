#include <bits/stdc++.h>
using namespace std;
struct stu{
    string name;
    int total;
    int C, E, M; // chinese, English, Math
};
bool cmp(const stu &a, const stu &b){
    if(a.total == b.total)
        return a.name < b.name;
    return a.total > b.total;
}
   
int main(){
    int n;
    while(cin >> n){
        vector<stu> all(n);
        for(int i = 0; i < n; i++){
            cin >> all[i].name >> all[i].C >> all[i].E >> all[i].M;
            all[i].total = all[i].C + all[i].E + all[i].M;
        }
        sort(all.begin(), all.end(), cmp);
        int rank = 0, prev = -1, same = 1;
        for(auto &it: all){
            if (it.total == prev)
                same++;
            else {
                rank += same;
                prev = it.total;
                same = 1;
            }
            cout << rank << ' ' << it.name << ' ' << it.total << ' ' << it.C << ' ' << it.E << ' ' << it.M << endl;
        }
        cout << endl;
    }
}