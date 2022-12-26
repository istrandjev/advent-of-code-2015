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

char buf1[64], buf2[64];
map<string, int> cities_to_index;
int get_city(const string& s) {
    auto it = cities_to_index.find(s);
    if (it == cities_to_index.end()) {
        int index = cities_to_index.size();
        cities_to_index.insert({s, index});
        return index;
    } 
    return it->second;
}
int main() {
    
    string s;
    vector<pair<pair<int, int>, int> > input; 
    while (getline(cin, s)) {
        int d;
        sscanf(s.c_str(), "%s to %s = %d", buf1, buf2, &d);
        
        int i1 = get_city(buf1);
        int i2 = get_city(buf2);
        input.push_back({{i1, i2}, d});
    }
    int n = cities_to_index.size();
    vector<vector<int> > mat(n, vector<int>(n , 0));
    for (auto l : input) {
        mat[l.first.first][l.first.second] = mat[l.first.second][l.first.first] = l.second;
    }

    vector<int> a(n); 
    iota(all(a), 0);
    int best = 1000000000;
    int worst = 0;
    do {
        int res = 0;
        for (int i = 0; i < n - 1; ++i) {
            res += mat[a[i]][a[i + 1]];
        }
        best = min(res, best);
        worst = max(worst, res);
    } while (next_permutation(all(a)));
    cout << "Part 1 " << best << endl;
    cout << "Part 2 " << worst << endl; 
    return 0;
}