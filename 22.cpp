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

struct spell {
    int cost;
    int damage;
    int heal;
};

struct effect {
    int cost;
    int turns;
    int armor;
    int damage;
    int mana;
};

vector<spell> spells{
    {53, 4, 0},
    {73, 2, 2}
};

vector<effect> effects{
    {113, 6, 7, 0, 0},
    {173, 6, 0, 3, 0},
    {229, 5, 0, 0, 101}
};

const int inf = 1000000000;

unordered_map<ll, int> mem;
int MONSTER_DAMAGE = 10;
int encode(int mana, int health, int e_time[3], int monster_health) {
    ll res = mana;
    res *= 101;
    res += health;
    for (int i = 0; i < 3; ++i) {
        res *= 7;
        res += e_time[i];
    }
    res *= 72;
    res += monster_health;
    return res;
}

bool hard_mode;
int solve(int mana, int health, int e_time[3], int monster_health);
int do_monster(int mana, int health, int e_time[3], int monster_health) {
    int armor = 0;
    for (int i = 0; i < effects.size(); ++i) {
        if (e_time[i] > 0) {
            armor = max(armor, effects[i].armor);
            mana += effects[i].mana;
            monster_health -= effects[i].damage;
            e_time[i] -= 1;
        }
    }
    if (monster_health <= 0) {
        return 0;
    }
    health -= MONSTER_DAMAGE - armor;
    if (health <= 0) {
        return inf;
    }
    return solve(mana, health, e_time, monster_health);
}
int solve(int mana, int health, int e_time[3], int monster_health) {
    ll kod = encode(mana, health, e_time, monster_health);
    auto it = mem.find(kod);
    if (it != mem.end()) {
        return it->second;
    }
    if (hard_mode) {
        health -= 1;
        if (health <= 0) {
            return mem[kod] = inf;
        }
    }

    int armor = 0;
    for (int i = 0; i < effects.size(); ++i) {
        if (e_time[i] > 0) {
            armor = max(armor, effects[i].armor);
            mana += effects[i].mana;
            monster_health -= effects[i].damage;
        }
    }
    if (monster_health <= 0) {
        return mem[kod] = 0;
    }
    
    
    int answer = inf;
    auto dec_time = [](int time){return max(time - 1, 0);};
    auto update_ans = [&](int temp, int cost) { 
        if (temp != inf) {
            temp += cost;
            answer = min(answer, temp);
        }
    };
    for (auto s: spells) {
        if (mana >= s.cost) {
            int new_es[3];
            for (int i = 0 ;i < 3; ++i) {
                new_es[i] = dec_time(e_time[i]);
            }
            int temp;
            if (s.damage >= monster_health) {
                temp = 0;
            } else {
                temp = do_monster(mana - s.cost, health + s.heal, new_es, monster_health - s.damage);
            }
            update_ans(temp, s.cost);
        }
    }
    for (int ei = 0; ei < (int)effects.size(); ++ei) {
        if (e_time[ei] <= 1 && mana >= effects[ei].cost) {
            int new_es[3];
            for (int i = 0 ;i < 3; ++i) {
                if (i != ei) {
                    new_es[i] = dec_time(e_time[i]);
                } else {
                    new_es[i] = effects[ei].turns;
                }
            }
            int temp = do_monster(mana - effects[ei].cost, health, new_es, monster_health);
            update_ans(temp, effects[ei].cost);
        }
    }
    return mem[kod] = answer;
}

int main() {
    int e_time[3] = {0, 0, 0};
    hard_mode = false;
    cout << "Part 1 " << solve(500, 50, e_time, 71) << endl;
    hard_mode = true;
    mem.clear();
    cout << "Part 2 " << solve(500, 50, e_time, 71) << endl;
    // cout << "Part 1 " << solve(250, 10, e_time, 14) << endl;
    // cout << "Part 2 " << worst << endl;
    return 0;
}