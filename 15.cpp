#include <iostream>
#include <string>
#include <cstdio>
#include <set>
#include <map>
#include <vector>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <numeric>
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long ll;

vector<string> split(const string& s, char delim=' ') {
    vector<string> res;
    string cur;
    for (auto c : s) {
        if (c == delim) {
            res.push_back(cur);
            cur = "";
        } else {
            cur.push_back(c);
        }
    }
    if (s.back() != delim) {
        res.push_back(cur);
    }
    return res;
}

struct ingredient {
    string name;
    int properties[5];
};

int main() {
    vector<ingredient> a;
    string s;
    while (getline(cin, s)) {
        vector<string> l = split(s);
        ingredient temp;
        temp.name = l[0];
        for (int i = 0; i < 5; ++i) {
            if (i != 4) {
                l[i * 2 + 2].pop_back();
            }
            temp.properties[i] = stoi(l[i * 2 + 2]);
        }
        a.push_back(temp);
    }
    ll best = 0;
    ll best2 = 0;
    int c[4];
    for (c[0] = 0; c[0] <= 100; ++c[0]) {
        for (c[1] = 0; c[0] + c[1] <= 100; ++c[1]) {
            for (c[2] = 0; c[0] + c[1] + c[2] <= 100; ++c[2]) {
                c[3] = 100 - c[0] - c[1] - c[2];

                ll temp = 1;
                for (int i = 0 ; i < 4; ++i) {
                    ll prop = 0;
                    for (int j = 0; j < 4; ++j) {
                        prop += c[j] * a[j].properties[i];
                    } 
                    prop = max(prop, 0LL);
                    temp *= prop;
                }
                ll cal = 0;
                for (int j = 0; j < 4; ++j) {
                    cal += c[j] * a[j].properties[4];
                }
                best = max(best, temp);
                if (cal == 500) {
                    best2 = max(best2, temp);
                }
            }
        }
    }
    cout << "Part 1 " << best << endl;
    cout << "Part 2 " << best2 << endl;
    return 0;
}