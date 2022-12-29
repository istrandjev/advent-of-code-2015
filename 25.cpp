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

const ll mod = 33554393;
const ll mul = 252533;

int get(int row, int column) {
    row--;
    column--;
    int s = row + column;
    int before = (s * (s + 1)) / 2;
    before += column;
    return before;
}
int main() {
    ll c = 20151125;
    int index = get(2978, 3083);
    for (int i = 0; i < index; ++i) {
        c = (c * mul) % mod;
    }
    cout << c << endl;
    return 0;
}