import sys

values = []
with open(sys.argv[1]) as file:
    val = file.read()
values = [int(x) for x in val.split()]

def makeHeap (listToSort, length, heapIndex) :

    largest = heapIndex
    left = 2 * heapIndex + 1
    right = 2 * heapIndex + 2

    if left < length and listToSort [largest] < listToSort [left] :
        largest = left

    if right < length and listToSort [largest] < listToSort [right] :
        largest = right

    if largest != heapIndex :
        listToSort [heapIndex], listToSort [largest] = listToSort [largest], listToSort [heapIndex]

        makeHeap (listToSort, length, largest)

def heapSort (listToSort) :

    listInstance = listToSort.copy ()

    n = len (listInstance)

    for i in range (len (listInstance) // 2 - 1, -1, -1):
        makeHeap (listInstance, n, i)

    for i in range (n - 1, 0, -1) :
        listInstance [i], listInstance [0] = listInstance [0], listInstance [i]
        makeHeap (listInstance, i, 0)

    return listInstance

# Odpalane przez sortedList = heapSort (unsortedList)
heapSort(values)