from math import ceil
import os
import sys
import random

def oddDegrees(matrix):
    list = []
    for i in range(len(matrix)):
        temp = 0
        for j in range(len(matrix[i])):
            if matrix[i][j] == 1:
                temp += 1
        if temp % 2 != 0:
            list.append(i)
    return list

def evenDegrees(matrix): 
    list = []
    for i in range(len(matrix)):
        temp = 0
        for j in range(len(matrix[i])):
            if matrix[i][j] == 1:
                temp += 1
        if temp % 2 == 0:
            list.append(i)
    return list

n = int(sys.argv[1])
nas = float(sys.argv[2])
size = ((n*(n-1)) // 2) * nas
values = []
for i in range(n):
        temp = []
        for x in range(0, n):
            temp.append(0)
        values.append(temp)

for i in range(1, n):
    values[i-1][i] = 1
    values[i][i-1] = 1
    size -= 1
values[n-1][0] = 1
values[0][n-1] = 1
size -= 1

#dla 0.3 n/3 jest git
while size > n/3:
    stop = n-1
    x = random.randint(0, stop)
    if x < stop:
        start = x+1
        y = random.randint(start, stop)
        if values[x][y] == 0:
            values[x][y] = 1
            values[y][x] = 1
            size -= 1

print('start')
odd = oddDegrees(values)
even = evenDegrees(values)
#print(odd)
#print(even)
#print(n/3)
#print(len(odd))
while odd:
    x = random.choice(odd)
    odd.remove(x)
    y = random.choice(odd)
    odd.remove(y)
    if values[x][y] == 0:
        values[x][y] = 1
        values[y][x] = 1
    else:
        odd.append(y)
        z = random.choice(even)
        if values[x][z] == 1:
            values[x][z] = 0
            values[z][x] = 0
            even.remove(z)
            even.append(x)
            odd.append(z)

    #print(odd)
    print(len(odd))
    print(len(even))
#print('git')
'''

while size > 0:    
    stop = n-1
    x = random.randint(0, stop)
    temp = (size / n)
    print(temp)
    if x < stop:
        start = x+1
        if degreeEven(values, x):  
            y = random.randint(start, stop)
            if values[x][y] == 0:
                values[x][y] = 1
                values[y][x] = 1
                size -= 1
            y = random.randint(start, stop)
            if values[x][y] == 0:
                values[x][y] = 1
                values[y][x] = 1
                size -= 1
        else:
            y = random.randint(start, stop)
            if values[x][y] == 0:
                values[x][y] = 1
                values[y][x] = 1
                size -= 1
'''

for i in range(n):
    for j in range(n):
        print(values[i][j], end=' ')
    print('\n')

dir = os.path.dirname(os.path.abspath(__file__)) + '/data/'
data_name = dir + 'data_' + str(n) + '_' + str(nas) + '.txt'
data = open(data_name, 'w')
for row in values:
    for number in row:
        data.write(str(number) + ' ')
    data.write('\n')
data.close()