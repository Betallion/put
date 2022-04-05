import os
import subprocess

programs = []
testnum = [2000, 4000, 6000, 8000, 10000, 12000, 14000, 16000, 18000, 20000]
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