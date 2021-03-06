import os
import time
import subprocess


algorithms = []
testdata = []
testnum = [1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000]
#testnum = [50000, 100000, 150000, 200000, 250000, 300000, 350000, 400000, 450000, 500000]
dataname = ['right', 'left', 'scatter', 'center', 'uniform']
newdata = input('generate new data? (y/n):')
if newdata == 'y':
    for num in testnum:
        cmdname = 'python ' + os.path.dirname(os.path.abspath(__file__)) + '/numgen.py ' + str(num)
        subprocess.run(cmdname, shell=True)
algdir = os.path.dirname(os.path.abspath(__file__)) + '/algorithms/'
for alg in os.listdir(algdir):
    algorithms.append(alg)
datadir = os.path.dirname(os.path.abspath(__file__)) + '/data/'
timedir = os.path.dirname(os.path.abspath(__file__)) + '/times/'

for i in algorithms:
    algcheck = input(i + ' - test this algorithm? (y/n) ')
    if algcheck == 'y':
        timename = timedir + i[:-3] + '_times.txt'
        timefile = open(timename, 'w')
        for j in dataname:
            for k in testnum:
                datafile = datadir + j + '_' + str(k) + '.txt'
                cmdname = 'python ' + algdir + i + ' ' + datafile
                start = time.time()
                subprocess.run(cmdname, shell=True)
                elapsed = j + ' ' + str(k) + ' ' + str(time.time() - start) + '\n'
                timefile.write(elapsed)
                print(i[:-3] + ' ' + j + ' ' + str(k) + ' - test complete')
        timefile.close()
