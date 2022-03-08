import sys
values = []
with open(sys.argv[1]) as file:
    val = file.read()
values = [int(x) for x in val.split()]

n = len(values)

for i in range(n):
    ll = i + 1
    rl = n
    print(i, n)
    minval = min(values[ll:rl])
    minind = values.index(minval)
    #print(values[i:n])
    #print(minval, minind)
    #input()
    temp = values[i]
    values[minind] = temp
    values[i] = minval

print(values)