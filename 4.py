import hashlib

input = 'ckczppom'

value = 1
five_digits_found = False
while True:
    md5 = hashlib.md5(f'{input}{value}'.encode('utf-8')).hexdigest()
    if md5[:5] == '00000' and not five_digits_found:
        print('Part 1', value)
        five_digits_found = True
    if md5[:6] == '000000':
        print('Part 2', value)
        break
    value += 1
