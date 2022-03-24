import sys

values = []
with open(sys.argv[1]) as file:
    val = file.read()
values = [int(x) for x in val.split()]

n = len(values)
for i in range(1, n):
    el = values[i]
    j = i - 1
    while j >= 0 and el < values[j]:
        values[j + 1] = values[j]
        j = j - 1
    values[j + 1] = el

#print(values)