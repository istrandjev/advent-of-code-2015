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

// hlf r sets register r to half its current value, then continues with the next instruction.
// tpl r sets register r to triple its current value, then continues with the next instruction.
// inc r increments register r, adding 1 to it, then continues with the next instruction.
// jmp offset is a jump; it continues with the instruction offset away relative to itself.
// jie r, offset is like jmp, but only jumps if register r is even ("jump if even").
// jio r, offset is like jmp, but only jumps if register r is 1 ("jump if one", not odd).

ll values[256] = {0};
int next_command(const vector<vector<string> >& commands, int ci) {
    const vector<string>& c = commands[ci];
    if (c[0] == "hlf") {
        values[c[1][0]] /= 2;
        return ci + 1;
    } else if (c[0] == "tpl") {
        values[c[1][0]] *= 3;
        return ci + 1;
    } else if (c[0] == "inc") {
        values[c[1][0]]++;
        return ci + 1;
    } else if (c[0] == "jmp") {
        return ci + stoi(c[1]);
    } else if (c[0] == "jie") {
        int val = values[c[1][0]];
        return val % 2 == 0 ? ci + stoi(c.back()): ci + 1;
    } else if (c[0] == "jio") {
        int val = values[c[1][0]];
        return val == 1 ? ci + stoi(c.back()): ci + 1;
    } else {
        cout << "Unknown command " << c[0] << endl;
        exit(1);
    }
}
int main() {

    string s;
    vector<vector<string> > commands;
    while (getline(cin, s)) {
        vector<string> operands = split(s);
        commands.push_back(operands);
    }
    int ci = 0;
    while (ci >= 0 && ci < (int)commands.size()) {
        ci = next_command(commands, ci);
    }
    cout << "Part 1 " << values['b'] << endl;
    values['a'] = 1;
    values['b'] = 0;
    ci = 0;
    while (ci >= 0 && ci < (int)commands.size()) {
        ci = next_command(commands, ci);
    }
    cout << "Part 2 " << values['b'] << endl;
    return 0;
}