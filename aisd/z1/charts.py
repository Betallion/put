import matplotlib.pyplot as plt
import os

algorithms = []
timedir = os.path.dirname(os.path.abspath(__file__)) + '/times/'
algdir = os.path.dirname(os.path.abspath(__file__)) + '/algorithms/'
for alg in os.listdir(algdir):
    algorithms.append(alg)
for tim in os.listdir(timedir):
    timeval = []
    timefile = open(tim, 'r')
    for line in timefile:
        timeval.append(line)
    begin = 0
    for i in range(5):
        xdata = []
        ydata = []
        for j in range(begin, begin+10, 1):
            val = timeval[j].split()
            xdata.append(val[1])
            ydata.append(val[2])
            fig, ax = plt.subplots()
            ax.plot(xdata, ydata)
            ax.set_xlabel('Liczba elementów')
            ax.set_ylabel('Czas [s]')
            ax.set_title(val[0].upper())
            ax.legend()
            fig.show()