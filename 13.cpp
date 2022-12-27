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
map<string, int> name_to_index;
int get_index(const string& name) {
    auto it = name_to_index.find(name);
    if (it == name_to_index.end()) {
        int val = name_to_index.size();
        name_to_index.insert({name, val});
        return val;
    }
    return it->second;
}

int solve(const vector<vector <int> >& mat) {
    int n = mat.size();
    vector<int> a(n);
    iota(all(a), 0);
    int res = -10000000;
    do {
        int temp = 0;
        for (int i = 0; i < n; ++i) {
            int ni = (i + 1) % n;
            temp += mat[a[i]][a[ni]] + mat[a[ni]][a[i]];
        }
        res = max(res, temp);
    }while(next_permutation(all(a)));
    return res;
}

int main() {
    string s;
    
    vector<pair<pair<int, int>, int> > values;
    while (getline(cin, s)) {
        vector<string> tokens = split(s);
        tokens.back().pop_back();
        int i = get_index(tokens[0]);
        
        int j = get_index(tokens.back());
        int val;
        if (tokens[2] == "gain") {
            val = stoi(tokens[3]);
        } else {
            val = -stoi(tokens[3]);
        }
        values.push_back({{i, j}, val});
    }
    int n = name_to_index.size();
    vector<vector<int> > mat(n, vector<int>(n, 0));
    for (auto l : values) {
        mat[l.first.first][l.first.second] = l.second;
    }
    cout << "Part 1 :" << solve(mat) << endl;
    for (int i = 0; i < n; ++i) {
        mat[i].push_back(0);
    }
    n++;
    mat.push_back(vector<int>(n, 0));
    cout << "Part 2 :" << solve(mat) << endl;
    return 0;
}