import os
import time
import subprocess



def execute(cmd):
    popen = subprocess.Popen(cmd, stdout=subprocess.PIPE, universal_newlines=True)
    for stdout_line in iter(popen.stdout.readline, ""):
        yield stdout_line 
    popen.stdout.close()
    return_code = popen.wait()
    if return_code:
        raise subprocess.CalledProcessError(return_code, cmd)



algorithms = ['bfs', 'dfs', 'bfssort', 'dfssort']
types = ['am', 'al', 'gel']
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
        bfsname = timedir + i + '_bfs_times.txt'
        dfsname = timedir + i + '_dfs_times.txt'
        bfssortname = timedir + i + '_bfssort_times.txt'
        dfssortname = timedir + i + '_dfssort_times.txt'
        bfsfile = open(bfsname, 'w')
        dfsfile = open(dfsname, 'w')
        bfssortfile = open(bfssortname, 'w')
        dfssortfile = open(dfssortname, 'w')

        #run process properly
        times = []
        for path in execute(['a.exe', datafile, i]):
            times.append(path[:-1])

        elapsedBfs = str(j) + ' ' + times[0] + '\n'
        bfsfile.write(elapsedBfs)

        start = time.time()

        elapsedDfs = str(j) + ' ' + times[1] + '\n'
        dfsfile.write(elapsedDfs)
        
        start = time.time()

        elapsedSort = str(j) + ' ' + times[2] + '\n'
        bfssortfile.write(elapsedSort)

        start = time.time()

        elapsedSort = str(j) + ' ' + times[3] + '\n'
        dfssortfile.write(elapsedSort)
        
    bfsfile.close()
    dfsfile.close()
    bfssortfile.close()
    dfssortfile.close()