import random
import os
n = int(input())
values = []
for i in range(n):
    values.append(random.randint(0, n))

dir = os.path.dirname(os.path.abspath(__file__)) + '/'
uniform_name = dir + 'uniform_' + str(n) + '.txt'
scatter_name = dir + 'scatter_' + str(n) + '.txt'
right_name = dir + 'right_' + str(n) + '.txt'
left_name = dir + 'left_' + str(n) + '.txt'
center_name = dir + 'center_' + str(n) + '.txt'

uniform = open(uniform_name, 'w')
scatter = open(scatter_name, 'w')
right = open(right_name, 'w')
left = open(left_name, 'w')
center = open(center_name, 'w')

uniform.write((str(random.randint(0, n)) + ' ')*n)

for number in values:
    scatter.write(str(number) + ' ')

for number in sorted(values):
    right.write(str(number) + ' ')

for number in sorted(values, reverse=True):
    left.write(str(number) + ' ')

odd = []
even = []
for i in range(n):
    if i % 2 == 0:
        even.append(values[i])
    else:
        odd.append(values[i])
for number in sorted(odd):
    center.write(str(number) + ' ')
for number in sorted(even, reverse=True):
    center.write(str(number) + ' ')

uniform.close()
scatter.close()
right.close()
left.close()
center.close()