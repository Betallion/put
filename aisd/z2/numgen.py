import os
import sys

n = int(sys.argv[1])
values = []
for i in range(n):
    values.append(i)

dir = os.path.dirname(os.path.abspath(__file__)) + '/data/'
data_name = dir + 'data_' + str(n) + '.txt'
data = open(data_name, 'w')
for number in values:
    data.write(str(number) + ' ')
data.close()