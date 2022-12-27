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

bool valid(const string& s) {
    bool three_inc = false;
    vector<char> has_pair(s.size(), 0);
    for (int i = 0; i <= s.size(); ++i) {
        if (i + 3 <= s.size() && s[i] == s[i + 1] - 1 && s[i] == s[i + 2] - 2) {
            three_inc = true;
        }
        if (s[i] == 'i' || s[i] == 'l' || s[i] == 'o') {
            return false;
        }
        if (i + 2 <= s.size() && s[i] == s[i + 1]) {
            has_pair[i] = 1;
        }
    }
    int total_pairs = 0;
    for (int i = 0; i < 7; ++i) {
        if (has_pair[i]) {
            if (i == 0 || !has_pair[i - 1]) {
                has_pair[i] = 1;
                total_pairs++;
            } else {
                has_pair[i] = 0;
            }
        }
    }
    return three_inc && total_pairs >= 2;
}

bool next_pass(string& s) {
    for (int i = (int)s.size() - 1; i >= 0; --i) {
        if (s[i] < 'z') {
            s[i]++;
            while (s[i] == 'i' || s[i] == 'l' || s[i] == 'o') {
                s[i]++;
            }
            return true;
        }
        s[i] = 'a';
    }
    return false;
}
int main() {
    string input = "hepxcrrq";
    int br = 0;
    while (!valid(input)) {
        next_pass(input);
    }
    cout << "Part 1 " << input << endl;
    next_pass(input);
    while (!valid(input)) {
        next_pass(input);
    }
    cout << "Part 2 " << input << endl;
    return 0;
}