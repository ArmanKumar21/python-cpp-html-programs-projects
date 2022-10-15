
def getRangoli(n):
    r = []
    letters = [chr(ord('a') + x) for x in range(26)]
    hold = curr = n - 1
    for i in range(n):
        line = ''
        for j in range(2 * n - 1):
            if j % 2 == 1:
                line += '-'
            else:
                num = (2 * n - 2 - j) // 2 + curr
                if num <= hold:
                    line += letters[num]
                else:
                    line += '-'
        line = line + line[:-1][::-1]
        curr -= 1
        r.append(line)
    for i in range(n - 2, -1, -1):
        r.append(r[i][:])
    return r

n = int(input())
r = getRangoli(n)
for l in r:
    print(l)