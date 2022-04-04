import os
import time
import subprocess

programs = []
testnum = [1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000]
newdata = input('generate new data? (y/n):')
if newdata == 'y':
    for num in testnum:
        cmdname = 'python ' + os.path.dirname(os.path.abspath(__file__)) + '/numgen.py ' + str(num)
        subprocess.run(cmdname, shell=True)
prgdir = os.path.dirname(os.path.abspath(__file__)) + '/programs/'
for prg in os.listdir(prgdir):
    programs.append(prg)
datadir = os.path.dirname(os.path.abspath(__file__)) + '/data/'
for i in programs:
    for j in testnum:
        datafile = datadir + 'data_' + str(j) + '.txt'
        cmdname = prgdir + i + ' ' + datafile
        subprocess.run(cmdname, shell=True)