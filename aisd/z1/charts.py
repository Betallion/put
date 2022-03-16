from tkinter import N, Y
import matplotlib.pyplot as plt
import os

sortnames = {'selectionSort': 'Sortowanie przez wybieranie', 'insertionSort': 'Sortowanie przez wstawianie', 'shellSort': 'Sortowanie Shella', 'heapSort': 'Sortowanie przez kopcowanie', 'quickSortLeft': 'Sortowanie szybkie (lewy)', 'quickSortRandom': 'Sortowanie szybkie (losowy)', 'quickRandom': 'Sortowanie szybkie (losowy)', 'quickLeft': 'Sortowanie szybkie (lewy)'}
datanames = {'right': 'dane rosnące', 'left': 'dane malejące', 'scatter': 'dane losowe', 'center': 'dane A-kształtne', 'uniform': 'dane stałe'}
algorithms = []
timedir = os.path.dirname(os.path.abspath(__file__)) + '/times/'
algdir = os.path.dirname(os.path.abspath(__file__)) + '/algorithms/'
chartdir = os.path.dirname(os.path.abspath(__file__)) + '/charts/'
for alg in os.listdir(algdir):
    algorithms.append(alg)
for tim in os.listdir(timedir):
    checktim = input(tim + ' - draw file? (y/n) ')
    if checktim == 'y':
        timeval = []
        timefile = open(timedir+tim, 'r')
        for line in timefile:
            timeval.append(line)
        begin = 0
        yavg = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
        for i in range(5):
            xdata = []
            ydata = []
            for j in range(begin, begin+10, 1):
                val = timeval[j].split()
                xdata.append(int(val[1]))
                ydata.append(float(val[2]))
                yavg[j - i * 10] += float(val[2])
                #print(xdata, ydata)
            fig, ax = plt.subplots()
            ax.plot(xdata, ydata)
            ax.set_xlabel('Liczba elementów')
            ax.set_ylabel('Czas [s]')
            ax.set_title(sortnames[tim.split('_')[0]] + ' - ' + datanames[val[0]])
            chartfile = chartdir + tim.split('_')[0] + '/' + tim.split('_')[0] + '_' + val[0] + '.png'
            fig.savefig(chartfile)
            begin += 10
        yavg = [val/5 for val in yavg]
        fig, ax = plt.subplots()
        ax.plot(xdata, yavg)
        ax.set_xlabel('Liczba elementów')
        ax.set_ylabel('Czas [s]')
        ax.set_title(sortnames[tim.split('_')[0]] + ' - dane uśrednione')
        chartfile = chartdir + tim.split('_')[0] + '/' + tim.split('_')[0] + '_avg.png'
        fig.savefig(chartfile)