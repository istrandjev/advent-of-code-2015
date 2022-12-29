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

vector<int> a;
int mem[32][600];
ll mem2[32][600][10];
int inf = 100000;
int solve(int idx, int lft) {
    if (lft == 0) {
        return mem[idx][lft] = 0;
    }
    if (idx >= a.size()) {
        return mem[idx][lft] = inf;
    }
    if (mem[idx][lft] != -1) {
        return mem[idx][lft];
    }
    int best = solve(idx + 1, lft);
    if (a[idx] <= lft) {
        int temp = solve(idx + 1, lft - a[idx]);
        if (temp != inf && temp + 1 < best) {
            best = temp + 1;
        }
    }
    return mem[idx][lft] = best;
}
ll solve2(int idx, int lft, int total) {
    ll& res = mem2[idx][lft][total];
    if (lft == 0) {
        if (total == 0) {
            return res = 1;
        } else {
            return res = 0;
        }
    }
    if (idx >= a.size()) {
        return res = 0;
    }
    if (res != -1) {
        return res;
    }
    ll best = solve2(idx + 1, lft, total);
    if (a[idx] <= lft && total > 0) {
        ll temp = solve2(idx + 1, lft - a[idx], total - 1);
        if (temp != 0 && (best == 0 || temp * a[idx] < best)) {
            best = temp * a[idx];
        }
    }
    return res = best;
}

int main() {
    int v;
    int s = 0;
    while (cin >> v) {
        a.push_back(v);
        s += v;
    }
    memset(mem, -1, sizeof(mem));
    int min_cnt = solve(0, s / 3);
    memset(mem2, -1, sizeof(mem2));
    cout << "Part 1 " << solve2(0, s / 3, min_cnt) << endl;
    memset(mem, -1, sizeof(mem));
    min_cnt = solve(0, s / 4);
    memset(mem2, -1, sizeof(mem2));
    cout << "Part 2 " << solve2(0, s / 4, min_cnt) << endl;

    return 0;
}