#include <iostream>
#include <string>
#include <cstdio>
#include <set>
#include <map>
using namespace std;

typedef long long ll;

set<char> vowels{'a', 'e', 'i', 'o', 'u'};
set<string> bad{"ab", "cd", "pq", "xy"};
bool nice(const string& s) {
    int vowels_cnt = 0;
    bool has_repeated = false;
    for (int i = 0; i < (int)s.size(); ++i) {
        vowels_cnt += vowels.count(s[i]); 
        if (i > 0) {
            if (s[i] == s[i - 1]) {
                has_repeated = true;
            }
            if (bad.count(s.substr(i - 1, 2))) {
                return false;
            }
        }
    }
    return vowels_cnt >= 3 && has_repeated;
}
bool nicer(const string& s) {
    bool has_repeated = false;
    bool has_double = false;
    map<string, int> pairs;
    for (int i = 0; i < (int)s.size(); ++i) {
        if (i > 1) {
            if (s[i] == s[i - 2]) {
                has_repeated = true;
            }
        }
        auto it = pairs.find(s.substr(i, 2));
        if (it != pairs.end() && it->second < i - 1) {
            has_double = true;
        }
        pairs.insert({s.substr(i, 2), i});
    }
    return has_double && has_repeated;
}

int main() {
    string s;
    int res = 0;
    int res2 = 0;
    while (getline(cin, s)) {
        res += nice(s);
        res2 += nicer(s);
    }
    cout << "Part 1 " << res << endl;
    cout << "Part 2 "<< res2 << endl;
    return 0;
}