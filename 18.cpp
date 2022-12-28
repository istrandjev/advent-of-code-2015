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

int moves[8][2] = { { -1, 0 }, { -1, 1 }, { 0, 1 }, { 1, 1 }, { 1, 0 },
        { 1, -1 }, { 0, -1 }, { -1, -1 } };

int main() {
    vector<string> a;
    string s;
    while (getline(cin, s)) {
        a.push_back(s);
    }
    int n = a.size();
    int m = a[0].size();
    
    vector<string> original = a;
    for (int it = 0; it < 100; ++it) {
        vector<string> b = a;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int cnt = 0;
                for (int l = 0; l < 8; ++l) {
                    int tx = i + moves[l][0];
                    int ty = j + moves[l][1];
                    if (tx < 0 || tx >= n || ty < 0 || ty >= m) {
                        continue;
                    }
                    if (a[tx][ty] == '#') {
                        cnt++;
                    }
                }
                if (a[i][j] == '#') {
                    b[i][j] = (cnt == 2 || cnt == 3) ? '#' : '.';
                } else {
                    b[i][j] = (cnt == 3) ? '#' : '.';
                }
            }
        }
        a = b;
    }
    int answer = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            answer += (a[i][j] == '#');
        }
    }
    cout << "Part 1 " << answer << endl;
    a = original;
    a[0][0] = a[0][m - 1] = a[n - 1][m - 1] = a[n - 1][0] = '#';
    for (int it = 0; it < 100; ++it) {
        vector<string> b = a;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int cnt = 0;
                for (int l = 0; l < 8; ++l) {
                    int tx = i + moves[l][0];
                    int ty = j + moves[l][1];
                    if (tx < 0 || tx >= n || ty < 0 || ty >= m) {
                        continue;
                    }
                    if (a[tx][ty] == '#') {
                        cnt++;
                    }
                }
                if (a[i][j] == '#') {
                    b[i][j] = (cnt == 2 || cnt == 3) ? '#' : '.';
                } else {
                    b[i][j] = (cnt == 3) ? '#' : '.';
                }
            }
        }
        a = b;
        a[0][0] = a[0][m - 1] = a[n - 1][m - 1] = a[n - 1][0] = '#';
    }
    answer = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            answer += (a[i][j] == '#');
        }
    }
    cout << "Part 2 " << answer << endl;
    return 0;
}