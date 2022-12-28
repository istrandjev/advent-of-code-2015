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

vector<string> split(const string& s, char delim=' ') {
    vector<string> res;
    string cur;
    for (auto c : s) {
        if (c == delim) {
            res.push_back(cur);
            cur = "";
        } else {
            cur.push_back(c);
        }
    }
    if (s.back() != delim) {
        res.push_back(cur);
    }
    return res;
}

struct reindeer {
    int speed, time, rest;
    reindeer(int s, int t, int r) : speed(s), time(t), rest(r) {}
};


ll get_distance(const reindeer& r, int time_limit) {
    ll full_cycle = r.rest + r.time;
    ll n = time_limit / full_cycle;
    ll rem = time_limit - n * full_cycle;
    ll answer = n * r.time * r.speed;
    answer += min((ll)r.time, rem) * r.speed;
    return answer;
}
int main() {
    string s;
    vector<reindeer> a;
    ll res = 0;
    const int time_limit = 2503;
    while (getline(cin, s)) {
        vector<string> l = split(s);
        
        int speed = stoi(l[3]);
        int time = stoi(l[6]);
        int rest = stoi(l[13]);
        a.emplace_back(speed, time, rest);
        res = max(res, get_distance(a.back(), time_limit));
    }
    
    cout << "Part 1 " << res << endl;
    vector<int> points(a.size(), 0);
    for (int second = 1; second < time_limit; ++second) {
        vector<int> reindeer_dist(a.size());
        transform(all(a), reindeer_dist.begin(), [&](auto r){return get_distance(r, second);});
       
        int max_distance = *max_element(all(reindeer_dist));
        for (int i = 0; i < (int)points.size(); ++i) {
            if (reindeer_dist[i] == max_distance) {
                points[i]++;
            }
        }
    }
    cout << "Part 2 " << *max_element(all(points)) << endl;
    return 0;
}