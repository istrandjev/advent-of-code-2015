#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    getline(cin, s);
    int floor = 0;
    int basement = -1;

    for (int i = 0; i < (int)s.size(); ++i) {
        char c = s[i];
        if (c == '(') {
            floor++;
        } else {
            floor--;
            if (floor == -1 && basement == -1) {
                basement = i + 1;
            }
        }
    }
    cout << "part 1 " << floor << endl;
    cout << "part 2 " << basement << endl;
    return 0;
}