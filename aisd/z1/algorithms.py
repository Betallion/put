import random



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






def partitionRandom (listToSort, startIndex, endIndex) :

    #pivotIndex = startIndex

    pivotIndex = random.randrange (startIndex, endIndex + 1)

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

def partitionLeft (listToSort, startIndex, endIndex) :

    pivotIndex = startIndex

    #pivotIndex = random.randrange (startIndex, endIndex + 1)

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


def quickSortRandom (listToSort, startIndex = 0, endIndex = -1) :

    if endIndex == -1 :
        endIndex = len(listToSort) - 1

    if startIndex >= endIndex :
        return listToSort

    pi = partitionRandom (listToSort, startIndex, endIndex)
    listToSort = quickSortRandom (listToSort, startIndex, pi - 1)
    listToSort = quickSortRandom (listToSort, pi + 1, endIndex)

    return listToSort

def quickSortLeft (listToSort, startIndex = 0, endIndex = -1) :

    if endIndex == -1 :
        endIndex = len(listToSort) - 1

    if startIndex >= endIndex :
        return listToSort

    pi = partitionLeft (listToSort, startIndex, endIndex)
    listToSort = quickSortLeft (listToSort, startIndex, pi - 1)
    listToSort = quickSortLeft (listToSort, pi + 1, endIndex)

    return listToSort






def shellSort (listToSort) :

    length = len (listToSort)

    gap = length // 2

    while gap > 0 :
        for i in range (gap, length) :
            temp = listToSort [i]

            j = i

            while j >= gap and listToSort [j - gap] > temp :
                listToSort [j] = listToSort [j - gap]

                j = j - gap

            listToSort [j] = temp

        gap = gap // 2

    return listToSort









def selectionSort(listToSort):
    n = len(listToSort)
    for i in range(n):
        left = i
        for j in range(i + 1, n):
            if listToSort[j] < listToSort[left]:
                left = j
        listToSort[i], listToSort[left] = listToSort[left], listToSort[i]
    return listToSort

def insertionSort(listToSort):
    n = len(listToSort)
    for i in range(1, n):
        el = listToSort[i]
        j = i - 1
        while j >= 0 and el < listToSort[j]:
            listToSort[j + 1] = listToSort[j]
            j = j - 1
        listToSort[j + 1] = el
    return listToSort

def generateRandom(list, number):
    for i in range(number):
        list.append(random.randint(0, number))
    return list



def datamenu():
    print('--------------------------------------')
    print('|1)           dane rosn??ce           |')
    print('|2)           dane malej??ce          |')
    print('|3)           dane losowe            |')
    print('|4)           dane A-kszta??tne       |')
    print('|5)           dane sta??e             |')
    print('--------------------------------------')   

def algmenu():
    print('--------------------------------------')
    print('|1)    sortowanie przez wybieranie   |')
    print('|2)    sortowanie przez wstawianie   |')
    print('|3)        sortowanie Shella         |')
    print('|4)   sortowanie przez kopcowanie    |')
    print('|5)  sortowanie szybkie (lewy klucz) |')
    print('|6) sortowanie szybkie (losowy klucz)|')
    print('--------------------------------------')   

data = []
dataVal = []

while True:
    datamenu()
    dataNumber = input('Kt??re dane? ')
    dataAmount = int(input('Ile liczb? '))
    dataVal = generateRandom(dataVal, dataAmount)
    if dataNumber == '1':
        for number in sorted(dataVal):
            data.append(number)
        break
    elif dataNumber == '2':
        for number in sorted(dataVal, reverse=True):
            data.append(number)
        break
    elif dataNumber == '3':
        for number in dataVal:
            data.append(number)
        break
    elif dataNumber == '4':
        odd = []
        even = []
        for i in range(dataAmount):
            if i % 2 == 0:
                even.append(dataVal[i])
            else:
                odd.append(dataVal[i])
        for number in sorted(odd):
            data.append(number)
        for number in sorted(even, reverse=True):
            data.append(number)
        break
    elif dataNumber == '5':
        number = random.randint(0, dataAmount)
        for i in range(dataAmount):
            data.append(number)
        break
    else:
        print('Nie wybrano poprawnych danych!')

unsortedData = data.copy()

while True:
    algmenu()
    algNumber = input('Kt??ry algorytm? ')
    if algNumber == '1':
        data = selectionSort(data)
        break
    elif algNumber == '2':
        data = insertionSort(data)
        break
    elif algNumber == '3':
        data = shellSort(data)
        break
    elif algNumber == '4':
        data = heapSort(data)
        break
    elif algNumber == '5':
        data = quickSortLeft(data)
        break
    elif algNumber == '6':
        data = quickSortRandom(data)
        break
    else:
        print('Nie wybrano poprawnego algorytmu!')
    

print('Dane przed posortowaniem:')
print(unsortedData)
print('\n')
print('Dane po posortowaniu:')
print(data)