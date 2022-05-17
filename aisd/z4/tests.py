import os
import time
import subprocess



nas = [0.3, 0.7]
#testnum = [100, 250, 500, 1000, 1500, 2000, 2500, 3000, 4000, 5000]
#testnum = [100, 200, 300, 400, 500, 600, 700, 800, 900, 1000]
testnum = [25, 50, 75, 100, 125, 150, 175, 200, 225, 250]


datadir = os.path.dirname(os.path.abspath(__file__)) + '/data/'
timedir = os.path.dirname(os.path.abspath(__file__)) + '/times/'

for i in nas:
    for j in testnum:
        datafile = datadir + 'data_' + str(j) + '_' + str(i) + '.txt'
        filename = timedir + str(i) + '_euler_times.txt'
        timefile = open(filename, 'a')
        cmd = 'python program.py ' + datafile
        #cmd = './prg ' + datafile + ' ' + str(i) + ' ' + str(j)
        start = time.time()
        subprocess.run(cmd, shell=True)
        elapsed = str(j) + ' ' + str(time.time() - start) + '\n'
        timefile.write(elapsed)
        
    timefile.close()