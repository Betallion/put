import os
import time
import subprocess

algorithms = []
testdata = []
testnum = [1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000] #any more than that and it's going to process it for eternity
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
    timename = timedir + i + '_times.txt'
    timefile = open(timename, 'w')
    for j in dataname:
        for k in testnum:
            datafile = datadir + j + '_' + str(k) + '.txt'
            cmdname = 'python ' + algdir + i + ' ' + datafile
            start = time.time()
            subprocess.run(cmdname, shell=True)
            elapsed = j + ' ' + str(k) + ' ' + str(time.time() - start) + '\n'
            timefile.write(elapsed)
            print(i + ' ' + j + ' ' + str(k) + ' - test complete')
    timefile.close()

#generate charts