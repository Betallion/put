import sys

values = []
with open(sys.argv[1]) as file:
    val = file.read()
values = [int(x) for x in val.split()]

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

# Odpalane przez sortedList = shellSort (unsortedList)
shellSort(values)