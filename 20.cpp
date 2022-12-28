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

const int lim = 10000000;
ll seive[lim] = {0};

int main() {
    int target = 36000000 / 10;

    for (int i = 1; i < target; ++i) {
        for (int j = i; j < target; j += i) {
            seive[j] += i;
        }
    }
    for (int i = 1; i < lim; ++i) {
        if (seive[i] >= target) {
            cout << "Part 1 " << i << endl;
            break;
        }
    }
    memset(seive, 0, sizeof(seive));
    target *= 10;
    for (int i = 1; i * 11 <= target; ++i) {
        for (int j = i, cnt = 0; j * 11 < target && cnt < 50; j += i, cnt++) {
            seive[j] += i;
        }
    }
    for (int i = 1; i < lim; ++i) {
        if (seive[i] * 11 >= target) {
            cout << "Part 2 " << i << endl;
            break;
        }
    }
    return 0;
}