import os
import sys
import random

c = int(sys.argv[1])
n = int(sys.argv[2])

dir = os.path.dirname(os.path.abspath(__file__)) + '/data/'
data_name = dir + 'data_' + str(c) + '.txt'
data = open(data_name, 'w')
data.write(str(c) + '\n')
data.write(str(n) + '\n')
for number in range(n):
    n1 = random.randint(1, c)
    n2 = random.randint(1, c)
    data.write(str(n1) + ' ' + str(n2) + '\n')
data.close()