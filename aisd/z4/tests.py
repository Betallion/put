import os
import time
import subprocess



nas = [0.3, 0.7]
testnum = [100, 250, 500, 1000, 1500, 2000, 2500, 3000, 4000, 5000]


datadir = os.path.dirname(os.path.abspath(__file__)) + '/data/'
timedir = os.path.dirname(os.path.abspath(__file__)) + '/times/'

for i in nas:
    for j in testnum:
        datafile = datadir + 'data_' + str(j) + '_' + str(i) + '.txt'
        filename = timedir + str(i) + '_euler_times.txt'
        timefile = open(filename, 'a')
        cmd = 'python testing.py ' + datafile
        start = time.time()
        subprocess.run(cmd)
        elapsed = str(j) + ' ' + (time.time() - start) + '\n'
        timefile.write(elapsed)
        
    timefile.close()