#include <bits/stdc++.h>
using namespace std;
enum { P, U, I };
map<char, double> sign = { {'m', 1e-3}, {'k', 1e3}, {'M', 1e6} };

double Value(string::const_iterator& it){
    double value = 0.0;
    bool negative = false;
    if (*it == '-') {
        negative = true;
        ++it;
    }
    // 整數部分
    while(isdigit(*it)){
        value = value * 10 + (*it - '0');
        ++it;
    }
    // 小數部分
    if(*it == '.'){
        ++it;
        double fraction = 0.1;
        while(isdigit(*it)){
            value += (*it - '0') * fraction;
            fraction *= 0.1;
            ++it;
        }
    }
    // 科學記號單位轉換
    if(sign.count(*it)){
        value *= sign[*it];
        ++it;
    }
    if (negative) value = -value;
    return value;
}

double extract(const string& line, const string& key) {
    size_t pos = line.find(key + "=");
    if (pos == string::npos) return -1.0;
    auto it = line.begin() + pos + 2; // 跳過 "X="
    double val = Value(it);
    // check 單位結尾
    if (*it == 'W' || *it == 'V' || *it == 'A') {
        return val;
    }
    return -1.0;
}

int main() {
    int T;
    cin >> T;
    cin.ignore();
    string line;
    for(int Cas = 1; Cas <= T; Cas++){
        getline(cin, line);
        double val[3] = {-1, -1, -1};
        val[P] = extract(line, "P");
        val[U] = extract(line, "U");
        val[I] = extract(line, "I");
        cout << "Problem #" << Cas << endl;
        if(val[P] < 0)
            printf("P=%.2fW\n", val[U] * val[I]);
        else if(val[U] < 0)
            printf("U=%.2fV\n", val[P] / val[I]);
        else if(val[I] < 0)
            printf("I=%.2fA\n", val[P] / val[U]);
        cout << endl;
    }
}
