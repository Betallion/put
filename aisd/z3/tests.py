import os
import time
import subprocess


algorithms = ['bfs', 'dfs', 'bfssort', 'dfssort']
types = ['am', 'al', 'el']
testdata = []
testnum = [100, 200, 300, 400, 500, 600, 700, 800, 900, 1000]
newdata = input('generate new data? (y/n):')
if newdata == 'y':
    for num in testnum:
        cmdname = 'python ' + os.path.dirname(os.path.abspath(__file__)) + '/matrix.py ' + str(num)
        subprocess.run(cmdname, shell=True)

datadir = os.path.dirname(os.path.abspath(__file__)) + '/data/'
timedir = os.path.dirname(os.path.abspath(__file__)) + '/times/'

for i in types:
    for j in testnum:
        datafile = datadir + 'data_' + str(j) + '.txt'
        cmdname = 'python ' + os.path.dirname(os.path.abspath(__file__)) + '/program.py ' + datafile + ' ' + i + ' ' + str(j)
        subprocess.run(cmdname, shell=True)