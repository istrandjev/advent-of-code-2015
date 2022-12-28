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

map<string, int> known{
    {"children", 3},
    {"cats", 7},
    {"samoyeds", 2},
    {"pomeranians", 3},
    {"akitas", 0},
    {"vizslas", 0},
    {"goldfish", 5},
    {"trees", 3},
    {"cars", 2},
    {"perfumes", 1}
};


set<string> smaller{"cats", "trees"};
set<string> bigger{"pomeranians", "goldfish"};
bool is_match2(const string& p, int val) {
    if (smaller.count(p)) {
        return known[p] < val;
    } else if (bigger.count(p)) {
        return known[p] > val;
    }
    return known[p] == val;
}
int main() {
    string s;
    while (getline(cin, s)) {
        vector<string> l = split(s);
        l[1].pop_back();
        int number = stoi(l[1]);
        bool match = true;
        bool match2 = true;
        for (int i = 0; i < 3; ++i) {
            string prop = l[2 + i * 2];
            prop.pop_back();
            if (i != 2) {
                l[3 + i * 2].pop_back();
            }
            int val = stoi(l[3 + i * 2]);
            if (known[prop] != val) {
                match = false;
            }
            if (!is_match2(prop, val)) {
                match2 = false;
            }
        }
        if (match) {
            cout << "Part 1 " << number << endl;
        }
        if (match2) {
            cout << "Part 2 " << number << endl;
        }
    }   
    return 0;
}