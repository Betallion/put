from tkinter import N, Y
import matplotlib.pyplot as plt
import os

timedir = os.path.dirname(os.path.abspath(__file__)) + '/times/'
chartdir = os.path.dirname(os.path.abspath(__file__)) + '/charts/'
testnum = [100, 200, 300, 400, 500, 600, 700, 800, 900, 1000]
algorithms = ['euler', 'hamilton', 'nonhamilton']
algorithmNames = {'bfs': 'Przeglądanie wszerz', 'dfs': 'Przeglądanie w głąb', 'bfssort': 'Sortowanie topologiczne wszerz'}
types = ['am', 'al', 'gel']


fig, ax = plt.subplots()
testnum = [25, 50, 75, 100, 125, 150, 175, 200, 225, 250]

ydata = [0.011537313461303711, 0.016846656799316406, 0.05078744888305664, 0.11021614074707031, 0.2802622318267822, 0.37159109115600586, 0.823570966720581, 1.1801457405090332, 2.0502994060516357, 3.1248157024383545]

label = '30%'
ax.plot(testnum, ydata, label=label)

ydata = [0.01311802864074707, 0.0397336483001709, 0.15755033493041992, 0.41817235946655273, 1.2492148876190186, 2.4626657962799072, 4.511933088302612, 7.166725397109985, 12.342609882354736, 16.66737198829651]
label = '70%'
ax.plot(testnum, ydata, label=label)

ax.set_xlabel('Liczba elementów')
ax.set_ylabel('Czas [s]')
title = 'Wyszukiwanie cyklu Eulera'
ax.set_title(title)
ax.legend()
chartfile = chartdir + 'euler.png'
fig.savefig(chartfile)

#---------
fig, ax = plt.subplots()
testnum = [10, 12, 14, 15, 16]


ydata = [0.0008, 0.036, 0.21, 3.1, 16.4]

ax.plot(testnum, ydata)

ax.set_xlabel('Liczba elementów')
ax.set_ylabel('Czas [s]')
title = 'Wyszukiwanie cyklu Hamiltona - grafy niehamiltonowskie'
ax.set_title(title)
ax.legend()
chartfile = chartdir + 'nonhamilton.png'
fig.savefig(chartfile)

#---------
fig, ax = plt.subplots()
testnum = [100, 250, 500, 1000, 1500, 2000, 2500, 3000, 4000, 5000]


ydata = [0.0006, 0.0008, 0.0017, 0.004, 0.0066, 0.01, 0.017, 0.03, 0.055, 0.085]
label = '30%'
ax.plot(testnum, ydata, label=label)

ydata = [0.0007, 0.001, 0.0015, 0.0038, 0.0076, 0.0129, 0.02, 0.028, 0.045, 0.075]
label = '70%'
ax.plot(testnum, ydata, label=label)

ax.set_xlabel('Liczba elementów')
ax.set_ylabel('Czas [s]')
title = 'Wyszukiwanie cyklu Hamiltona'
ax.set_title(title)
ax.legend()
chartfile = chartdir + 'hamilton.png'
fig.savefig(chartfile)