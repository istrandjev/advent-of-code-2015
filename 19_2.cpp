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
#include <unordered_map>
#include <queue>
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

map<string, string> reversed;


int cnt(string s) {
    int res = 0;
    for (auto c : s) {
        res += isupper(c);
    }
    return res;
}

pair<string, int> compress(const string& s) {
    string c = s;
    queue<string> q;
    q.push(c);
    unordered_map<string, int> vis;
    vis[c] = 0;

    string best = c;

    while (!q.empty()) {
        string c = q.front();
        int d = vis[c];
        q.pop();
        for (int i = 0; i < (int)c.size(); ++i) {
            for (auto r: reversed) {
                if (r.first == c.substr(i, r.first.size())) {
                    string temp = c.substr(0, i) + r.second + c.substr(i + r.first.size());
                    if (vis.count(temp)) {
                        continue;
                    }
                    vis.insert({temp, d + 1});
                    q.push(temp);
                    if (cnt(temp) < cnt(best)) {
                        best = temp;
                    }
                }
            }
        }
    }
    return make_pair(best, vis[best]);
}

int main() {
    string molecule;
    string s;
    while (getline(cin, s)) {
        if (s.size() == 0) {
            break;
        }
        vector<string> l = split(s);
        reversed[l[2]] = l[0];
    }
    getline(cin, molecule);

    int pos;
    int answer = 0;
    while ((pos = molecule.find("Ar")) != string::npos) {
        auto temp = compress(molecule.substr(0, pos + 2));
        molecule = temp.first + molecule.substr(pos + 2);
        answer += temp.second;    
    }

    answer += compress(molecule).second;
    cout << answer << endl;    

    return 0;
}
