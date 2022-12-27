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

string do_step(const string& s) {
    string res;
    char cur = '@';
    int cnt = 0;
    for (int i = 0; i < (int)s.size(); ++i) {
        if (s[i] != cur) {
            if (cur != '@') {
                res += to_string(cnt);
                res.push_back(cur);
            }
            cur = s[i];
            cnt = 1;
        } else {
            cnt += 1;
        }
    }
    res += to_string(cnt);
    res.push_back(cur);
    return res;
}
int main() {
    string current = "1113122113";
    for (int i = 0; i < 40; ++i) {
        current = do_step(current);
    }

    cout << "Part 1 " << current.size() << endl;
    for (int i = 0; i < 10; ++i) {
        current = do_step(current);
    }
    cout << "Part 2 " << current.size() << endl;
    return 0;
}