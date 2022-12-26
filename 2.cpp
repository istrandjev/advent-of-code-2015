#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

typedef long long ll;
int main() {
    int a, b, c;
    ll res = 0;
    ll ribbon = 0;
    while (scanf("%dx%dx%d", &a, &b, &c) != EOF) {
        
        res += 2LL * (a*b + b*c + c*a);
        res += min(a*b, min(b*c, c*a));
        ribbon += 2LL * min(a + b, min(b + c, c + a));
        ribbon += (ll)a * (ll)b * (ll)c;
    }
    cout << "part 1 " << res << endl;
    cout << "part 2 " << ribbon << endl;
    return 0;
}