#include <iostream>
#include <string>
#include <cstdio>
#include <set>
using namespace std;

typedef long long ll;
int moves[4][2] = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };
int char_to_move[128];
int main() {
    char_to_move['^'] = 0;
    char_to_move['v'] = 2;
    char_to_move['>'] = 1;
    char_to_move['<'] = 3;

    string s;
    getline(cin, s);
    set<pair<int, int> > kids;
    pair<int, int> cur{0, 0};
    kids.insert(cur);
    for (auto c : s) {
        int l = char_to_move[c];
        cur.first += moves[l][0];
        cur.second += moves[l][1];
        kids.insert(cur);
    }
    cout << "Part 1 " << kids.size() << endl;

    pair<int, int> santa(0, 0);
    pair<int, int> robot_santa(0, 0);
    kids.clear();
    kids.insert(santa);
    for (int i = 0; i < s.size(); ++i) {
        int l = char_to_move[s[i]];
        auto do_move = [&](pair<int, int>& pos) {
            pos.first += moves[l][0];
            pos.second += moves[l][1];
            kids.insert(pos);
        };
        if (i % 2 == 0) {
            do_move(santa);
        } else {
            do_move(robot_santa);
        }
    }
    cout << "Part 1 " << kids.size() << endl;
    return 0;
}