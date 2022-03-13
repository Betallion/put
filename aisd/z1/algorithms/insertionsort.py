import sys

values = []
with open(sys.argv[1]) as file:
    val = file.read()
values = [int(x) for x in val.split()]

n = len(values)
for i in range(1, n):
    k = values[i]
    j = i - 1
    while j >= 0 and k < values[j]:
        values[j + 1] = values[j]
        j = j - 1
    values[j + 1] = k

#print(values)