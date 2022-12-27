import json

def solve(d, ignore_red=False):
    if isinstance(d, int):
        return d
    elif isinstance(d, dict):
        res = 0
        if ignore_red and 'red' in d.values():
            return 0
        for k, v in d.items():
            if isinstance(k, int):
                res += k
            res += solve(v, ignore_red)
        return res
    elif isinstance(d, list):
        res = 0
        for v in d:
            res += solve(v, ignore_red)
        return res 
    return 0

with open('12.in') as f:
    data = json.load(f)

print(solve(data))
print(solve(data, ignore_red=True))