import sys

res = 0
res2 = 0
for line in sys.stdin:
    line = line.strip()
    res += len(line) - len(eval(line))
    res2 += line.count('"') + line.count('\\') + 2
print('Part1 = ', res)
print('Part2 = ', res2)