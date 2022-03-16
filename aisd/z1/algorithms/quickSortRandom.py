import sys
import random


values = []
with open(sys.argv[1]) as file:
    val = file.read()
values = [int(x) for x in val.split()]

def partition (listToSort, startIndex, endIndex) :

    #pivotIndex = startIndex

    pivotIndex = random.randrange (startIndex, endIndex)

    listToSort[pivotIndex], listToSort[startIndex] = listToSort[startIndex], listToSort[pivotIndex]

    pivot = listToSort [startIndex]

    bottomIndex = startIndex + 1
    topIndex = endIndex

    while True:
        while bottomIndex <= topIndex and listToSort [topIndex] >= pivot:
            topIndex = topIndex - 1

        while bottomIndex <= topIndex and listToSort [bottomIndex] <= pivot:
            bottomIndex = bottomIndex + 1

        if bottomIndex <= topIndex:
            listToSort [bottomIndex], listToSort [topIndex] = listToSort [topIndex], listToSort [bottomIndex]

        else:
            break

    listToSort [startIndex], listToSort [topIndex] = listToSort [topIndex], listToSort [startIndex]

    return topIndex


def quickSort (listToSort, startIndex = 0, endIndex = -1) :

    if endIndex == -1 :
        endIndex = len(listToSort) - 1

    if startIndex >= endIndex :
        return listToSort

    pi = partition (listToSort, startIndex, endIndex)
    listToSort = quickSort (listToSort, startIndex, pi - 1)
    listToSort = quickSort (listToSort, pi + 1, endIndex)

    return listToSort

# Odpalane przez sortedList = quickSort (unsortedList)
quickSort(values)
