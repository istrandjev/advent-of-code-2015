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
#include <unordered_set>
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

map<string, vector<string> > replacements;
string molecule;

int main() {
   
    string s;
    while (getline(cin, s)) {
        if (s.size() == 0) {
            break;
        }
        vector<string> l = split(s);
        auto it = replacements.find(l[0]);
        if (it == replacements.end()) {
            replacements.insert({l[0], vector<string>(1, l[2])});
        } else {
            it->second.push_back(l[2]);    
        }
    }
    getline(cin, molecule);
    
    unordered_set<string> used;
    for (int i = 0; i < (int)molecule.size(); ++i) {
        for (int j = 1; i + j <= molecule.size() && j <= 2; ++j) {
            string ss = molecule.substr(i, j);
            auto it = replacements.find(ss);
            if (it == replacements.end()) {
                continue;
            }
            for (auto op : it->second) {
                used.insert(molecule.substr(0, i) + op + molecule.substr(i + j));
            }
        }
    }

    cout << "Part 1 " << used.size() << endl;
    return 0;
}