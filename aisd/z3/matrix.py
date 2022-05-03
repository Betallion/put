import os
import sys
import random

n = int(sys.argv[1])
size = ((n*(n-1)) // 2) // 2
values = []
for i in range(n):
        temp = []
        for x in range(0, i+1):
            temp.append(0)
        #if i+2 <= n:
            #temp.append(1)
            #size -= 1
        for j in range(i+1, n):
            temp.append(0)
        values.append(temp)

while size > 0:
    stop = n-1
    x = random.randint(0, stop)
    if x < stop:
        start = x+1
        y = random.randint(start, stop)
        if values[x][y] == 0:
            values[x][y] = 1
            size -= 1

dir = os.path.dirname(os.path.abspath(__file__)) + '/data/'
data_name = dir + 'data_' + str(n) + '.txt'
data = open(data_name, 'w')
for row in values:
    for number in row:
        data.write(str(number) + ' ')
    data.write('\n')
data.close()