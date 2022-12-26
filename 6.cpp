#include <iostream>
#include <string>
#include <cstdio>
#include <set>
#include <map>
#include <vector>
using namespace std;

typedef long long ll;

const string TURN_ON = "turn on"; 
const string TURN_OFF = "turn off";
const string TOGGLE = "toggle";

char lamps[1000][1000] = {0};
int lamps2[1000][1000] = {0};
typedef int (*lamp_operation)(int);

int main() {
    string s;
    vector<string> commands{TURN_ON, TURN_OFF, TOGGLE};
    map<string, lamp_operation> actions;
    actions[TURN_ON] = [](int x) {return 1;};
    actions[TURN_OFF] = [](int x) {return 0;};
    actions[TOGGLE] = [](int x) {return x ^ 1;};

    map<string, lamp_operation> actions2;
    actions2[TURN_ON] = [](int x) {return x + 1;};
    actions2[TURN_OFF] = [](int x) {return max(0, x - 1);};
    actions2[TOGGLE] = [](int x) {return x + 2;};

    while (getline(cin, s)) {
        int x0, y0, x1, y1;

        for (auto command : commands) {
            if (s.substr(0, command.size()) == command) {
                sscanf(s.c_str(), (command + " %d,%d through %d,%d").c_str(), &x0, &y0, &x1, &y1);
                for (int i = min(x0, x1); i <= max(x0, x1); ++i) {
                    for (int j = min(y0, y1); j <= max(y0, y1); ++j) {
                        lamps[i][j] = actions[command](lamps[i][j]);
                        lamps2[i][j] = actions2[command](lamps2[i][j]);
                    }
                }
            }    
        }    
    }
    int result = 0;
    int result2 = 0;
    for (int i = 0; i < 1000; ++i) {
        for (int j = 0; j < 1000; ++j) {
            result += lamps[i][j];
            result2 += lamps2[i][j];
        }
    }
    cout << "Part 1: " << result << endl;
    cout << "Part 2: " << result2 << endl;
    return 0;
}