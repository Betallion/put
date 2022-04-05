from tkinter import N, Y
import matplotlib.pyplot as plt
import os

timedir = os.path.dirname(os.path.abspath(__file__)) + '/times/'
chartdir = os.path.dirname(os.path.abspath(__file__)) + '/charts/'
#testnum = [1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000]
testnum = [2000, 4000, 6000, 8000, 10000, 12000, 14000, 16000, 18000, 20000]


#create
createBstTimes = []
createAvlTimes = []

createBst = open(timedir+'bst_create.txt')
createAvl = open(timedir+'avl_create.txt')
for line in createBst:
    createBstTimes.append(float(line))
for line in createAvl:
    createAvlTimes.append(float(line))
fig, ax = plt.subplots()
#ax2 = ax.twinx()
bstlabel = 'BST'
ax.plot(testnum, createBstTimes, label=bstlabel)
avllabel = 'AVL'
ax.plot(testnum, createAvlTimes, label=avllabel)
ax.set_xlabel('Liczba elementów')
ax.set_ylabel('Czas [s]')
ax.set_title('Tworzenie drzewa')
ax.legend()
#ax2.legend()
chartfile = chartdir + 'createChart.png'
fig.savefig(chartfile)

#max
maxBstTimes = []
maxAvlTimes = []
maxBst = open(timedir+'bst_max.txt')
maxAvl = open(timedir+'avl_max.txt')
for line in maxBst:
    maxBstTimes.append(float(line))
for line in maxAvl:
    maxAvlTimes.append(float(line))
fig, ax = plt.subplots()
bstlabel = 'BST'
ax.plot(testnum, maxBstTimes, label=bstlabel)
avllabel = 'AVL'
ax.plot(testnum, maxAvlTimes, label=avllabel)
ax.set_xlabel('Liczba elementów')
ax.set_ylabel('Czas [s]')
ax.set_title('Maksymalny element')
ax.legend()
chartfile = chartdir + 'maxChart.png'
fig.savefig(chartfile)

#inorder
inorderBstTimes = []
inorderAvlTimes = []
inorderBst = open(timedir+'bst_inorder.txt')
inorderAvl = open(timedir+'avl_inorder.txt')
for line in inorderBst:
    inorderBstTimes.append(float(line))
for line in inorderAvl:
    inorderAvlTimes.append(line)
fig, ax = plt.subplots()
bstlabel = 'BST'
ax.plot(testnum, inorderBstTimes, label=bstlabel)
avllabel = 'AVL'
ax.plot(testnum, inorderAvlTimes, label=avllabel)
ax.set_xlabel('Liczba elementów')
ax.set_ylabel('Czas [s]')
ax.set_title('Wypisywanie in order')
ax.legend()
chartfile = chartdir + 'inorderChart.png'
fig.savefig(chartfile)

#balance
balanceBstTimes = []
balanceBst = open(timedir+'bst_balance.txt')
for line in balanceBst:
    balanceBstTimes.append(float(line))
fig, ax = plt.subplots()
bstlabel = 'BST'
ax.plot(testnum, balanceBstTimes, label=bstlabel)
ax.set_xlabel('Liczba elementów')
ax.set_ylabel('Czas [s]')
ax.set_title('Równoważenie')
ax.legend()
chartfile = chartdir + 'balanceChart.png'
fig.savefig(chartfile)