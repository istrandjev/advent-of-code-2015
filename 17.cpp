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


vector<int>  a;
ll mem[128][152];
ll mem2[128][152][52];

int solve(int index, int rem) {
    if (rem == 0) {
        return mem[index][rem] = 1;
    }
    if (index >= a.size()) {
        return mem[index][rem] = 0;
    }
    if (mem[index][rem] != -1) {
        return mem[index][rem];
    }
    ll res = solve(index + 1, rem);
    if (a[index] <= rem) {
        res += solve(index + 1, rem - a[index]);
    }
    return mem[index][rem] = res;
}
int solve2(int index, int rem, int containers) {
    if (rem == 0) {
        return mem2[index][rem][containers] = (containers == 0);
    }
    if (index >= a.size()) {
        return mem2[index][rem][containers] = 0;
    }
    if (mem2[index][rem][containers] != -1) {
        return mem2[index][rem][containers];
    }
    ll res = solve2(index + 1, rem, containers);
    if (a[index] <= rem) {
        res += solve2(index + 1, rem - a[index], containers - 1);
    }
    return mem2[index][rem][containers] = res;
}

int main() {
    int temp;
    while (scanf("%d", &temp) != EOF) {
        a.push_back(temp);
    }
    memset(mem, -1, sizeof(mem));
    memset(mem2, -1, sizeof(mem2));
    cout << "Part 1 " << solve(0, 150) << endl;
    
    for (int c = 1; c < a.size(); ++c) {
        int temp = solve2(0, 150, c);
        if (temp > 0) {
            cout << "Part 2 " << temp << endl;
            break;
        }
    }
    
    return 0;
}