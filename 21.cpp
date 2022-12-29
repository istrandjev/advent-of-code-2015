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

struct item {
    string name;
    int cost;
    int damage;
    int armor;
};
ostream& operator<<(ostream& out, const item& item) {
    out << item.name << ": cost="<< item.cost << " D=" << item.damage << " A=" << item.armor;
    return out;
}

// I decided to swap the input and the monster stats as 
// hardcoding these is much easier 
int mh = 100, md = 8, ma = 2;
bool kills(int h, int d, int a) {
    int cmh = mh;
    while (true) {
        cmh -= max(1, d - ma);
        if (cmh <= 0) {
            return true;
        }
        h -= max(1, md - a);
        if (h <= 0) {
            return false;
        }
    }
}
char buf[32];
int main() {
    string s;
    vector<item> weapons;
    vector<item> armors;
    vector<item> rings;
    while (getline(cin, s)) {
        string t;
        while (true) {
            getline(cin, t);
            if (t.size() == 0) {
                break;
            }
            int cost, damage, armor;
            if (s[0] != 'R') {
                sscanf(t.c_str(), "%s %d %d %d", buf, &cost, &damage, &armor);
            } else {
                int tmp;
                sscanf(t.c_str(), "%s %d %d %d %d", buf, &tmp, &cost, &damage, &armor);
            }
            item temp{buf, cost, damage, armor};
            if (s[0] == 'W') {
                weapons.push_back(temp);
            } else if (s[0] == 'A') {
                armors.push_back(temp);
            } else {
                rings.push_back(temp);
            }
        }
    }
    int best = 1000000000;
    int worst = 0;
    for (int wi = 0; wi < (int)weapons.size(); ++wi) {
        int c = weapons[wi].cost;
        int d = weapons[wi].damage;
        int a = weapons[wi].armor;
        for (int ai = 0; ai <= (int)armors.size(); ++ai) {
            if (ai < (int)armors.size()) {
                c += armors[ai].cost;
                d += armors[ai].damage;
                a += armors[ai].armor;
            }
            for (int ring_mask = 0; ring_mask < (1 << rings.size()); ++ring_mask) {
                if (__builtin_popcount(ring_mask) > 2) {
                    continue;
                }
                for (int ri = 0 ; ri < (int)rings.size(); ++ri) {
                    if (ring_mask & (1 << ri)) {
                        c += rings[ri].cost;
                        d += rings[ri].damage;
                        a += rings[ri].armor;
                    }
                }
                if (kills(100, d, a)) {
                    best = min(best, c);
                } else {
                    worst = max(worst, c);
                }
                for (int ri = 0 ; ri < (int)rings.size(); ++ri) {
                    if (ring_mask & (1 << ri)) {
                        c -= rings[ri].cost;
                        d -= rings[ri].damage;
                        a -= rings[ri].armor;
                    }
                }
            }
            if (ai < (int)armors.size()) {
                c -= armors[ai].cost;
                d -= armors[ai].damage;
                a -= armors[ai].armor;
            }
        }
    }
    cout << "Part 1 " << best << endl;
    cout << "Part 2 " << worst << endl;
    return 0;
}