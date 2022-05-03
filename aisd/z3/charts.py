from tkinter import N, Y
import matplotlib.pyplot as plt
import os

timedir = os.path.dirname(os.path.abspath(__file__)) + '/times/'
chartdir = os.path.dirname(os.path.abspath(__file__)) + '/charts/'
testnum = [100, 200, 300, 400, 500, 600, 700, 800, 900, 1000]
algorithms = ['bfs', 'dfs', 'bfssort', 'dfssort']
algorithmNames = {'bfs': 'Przeglądanie wszerz', 'dfs': 'Przeglądanie w głąb', 'bfssort': 'Sortowanie topologiczne wszerz', 'dfssort': 'Sortowanie topologiczne w gląb'}
types = ['am', 'al', 'gel']

for i in algorithms:
    fig, ax = plt.subplots()
    for j in types:
        timeval = []
        timename = timedir + j + '_' +  i + '_times.txt'
        times = open(timename)
        for k in times:
            timeval.append(k)
        ydata = []
        for time in times:
            val = time.split()
            ydata.append(float(times[1]))
        label = j
        ax.plot(testnum, times, label=label)
    ax.set_xlabel('Liczba elementów')
    ax.set_ylabel('Czas [s]')
    title = algorithmNames[i]
    ax.set_title(title)
    ax.legend()
    chartfile = chartdir + i + '.png'
    fig.savefig(chartfile)