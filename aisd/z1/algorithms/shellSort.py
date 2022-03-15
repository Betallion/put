import sys

values = []
with open(sys.argv[1]) as file:
    val = file.read()
values = [int(x) for x in val.split()]

def insertionSortBorrowed (values) :

    valuesInstance = values.copy()

    n = len(valuesInstance)
    for i in range(1, n):
        klucz = valuesInstance[i]
        j = i - 1
        while j >= 0 and klucz < valuesInstance[j]:
            valuesInstance[j + 1] = valuesInstance[j]
            j = j - 1
        valuesInstance[j + 1] = klucz

    return valuesInstance

def shellSort (listToSort) :

    startOffsets = [701, 301, 132, 57, 23, 10, 4, 1]

    offsets = []

    for startOffset in startOffsets :
        if startOffset <= len (listToSort) :
            offsets.append (startOffset)



    for offset in offsets :
    #    print ("Offset: ", offset)

        topStartIndex = min([(offset), (len(listToSort) - offset)])

        for startIndex in range (0, topStartIndex) :
           # print ("Start index: ", startIndex)

            smallList = []

            indexesList = []

            for index in range (startIndex, len (listToSort), offset) :
              #  print (Index: index)

                indexesList.append (index)

                smallList.append (listToSort[index])

            smallListSorted = insertionSortBorrowed (smallList)

            for i in range (len (indexesList)) :
                listToSort [i] = smallListSorted [i]


    return listToSort

# Odpalane przez sortedList = shellSort (unsortedList)
shellSort(values)