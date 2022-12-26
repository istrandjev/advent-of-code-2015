#include <iostream>
#include <string>
#include <cstdio>
#include <set>
#include <map>
#include <vector>
#include <cstring>
#include <cctype>

using namespace std;

typedef int (*operation)(int, int);

const string AND = "AND";
const string OR = "OR";
const string LSHIFT = "LSHIFT";
const string RSHIFT = "RSHIFT";
const string NOT = "NOT";
const string VALUE = "<value>";

struct command {
    string lhs, rhs;
    operation op;
};

set<string> two_operands{AND, OR, LSHIFT, RSHIFT};
map<string, int> values; 
map<string, command> program;
int solve(string name) {
    auto it = values.find(name);
    if (it != values.end()) {
        return it->second;
    }
    if (isdigit(name[0])) {
        int res = stoi(name);
        values[name] = res;
        return res;
    }
    command c = program[name];
    int res = c.op(solve(c.lhs), solve(c.rhs));
    values[name] = res;
    return res;
}

int main() {
    map<string, operation> operations{
        {AND, [](int x, int y){return x & y;}},
        {OR, [](int x, int y){return x | y;}},
        {RSHIFT, [](int x, int y){return x >> y;}},
        {LSHIFT, [](int x, int y){return (x << y) & ((1 << 16) - 1);}},
        {NOT, [](int x, int y){return x ^ ((1 << 16) - 1);}},
        {VALUE, [](int x, int y){return x;}}
    };
    string s;
    while (getline(cin, s)) {
        size_t arrow = s.find(" -> ");
        string x = s.substr(arrow + 4);
        
        bool found = false;
        for (auto op : operations) {
            size_t pos = s.find(op.first);
            if (pos == string::npos) {
                continue;
            }
            found = true;
            int second_operand_start = pos + op.first.size() + 1;
            string second_operand = s.substr(second_operand_start, arrow - second_operand_start);
            string first_operand = second_operand;
            
            if (two_operands.count(op.first)) {
                first_operand = s.substr(0, (int)pos - 1);
            }
            program[x] = command{first_operand, second_operand, operations[op.first]};
            break;
        }
        if (!found) {
            string operand = s.substr(0, arrow);
            program[x] = command{operand, operand, operations[VALUE]};
        }
    }
    int wire_a = solve("a");
    cout << "Part 1: "<< wire_a << endl;
    values.clear();
    string b_value = to_string(wire_a);
    program["b"] = command{b_value, b_value, operations[VALUE]};
    cout << "Part 2: "<< solve("a") << endl; 
    return 0;
}