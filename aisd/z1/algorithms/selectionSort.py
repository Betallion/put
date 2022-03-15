import sys

values = []
with open(sys.argv[1]) as file:
    val = file.read()
values = [int(x) for x in val.split()]
n = len(values)

for i in range(n):
    left = i
    for j in range(i + 1, n):
        if values[j] < values[left]:
            left = j
    values[i], values[left] = values[left], values[i]

#print(values)