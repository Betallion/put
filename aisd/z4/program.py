import sys


def am_to_al(matrix):
    size = len(matrix)
    adjacencylist = []
    for i in range(size):
        temp = []
        for j in range(size):
            if matrix[i][j] == 1:
                temp.append(j)
        adjacencylist.append(temp)
    return adjacencylist

#-------------------------------------------------------------------------
#eulerian cycle algorithm

def remove_edge(adjlist, x, y):
    adjlist[x].remove(y)
    adjlist[y].remove(x)

def add_edge(adjlist, x, y):
    adjlist[x].append(y)
    adjlist[y].append(x)

def bridge(adjlist, x, y):
    size = len(adjlist)
    removed = 0
    added = 0
    remove_edge(adjlist, x, y)
    visited = [False] * size
    removed = dfs(adjlist, x, visited)
    add_edge(adjlist, x, y)
    visited = [False] * size
    added = dfs(adjlist, x, visited)
    if removed == added:
        return False
    else:
        return True

def dfs(adjlist, start, visited):
    visited[start] = True
    n = 0
    for i in adjlist[start]:
        if visited[i] == False:
            n += dfs(adjlist, i, visited)
    return n



def euler(adjlist, start, visited, result):
    visited.append(start)
    #print(start)
    result.append(start)
    if len(adjlist[start]) == 0:
        return
    if len(adjlist[start]) == 1:
        v = adjlist[start][0]
        remove_edge(adjlist, start, v)
        euler(adjlist, v, visited, result)
        return
    for i in adjlist[start]:
        if bridge(adjlist, start, i) == False:
            remove_edge(adjlist, start, i)
            euler(adjlist, i, visited, result)
            return

def eulerian_cycle(adjlist):
    deg = [0] * len(adjlist)
    for i in range(len(adjlist)):
        deg[i] += len(adjlist[i])
        for j in range(len(adjlist[i])):
            deg[adjlist[i][j]] += 1
    for i in deg:
        if i % 2 != 0:
            print('nie ma cyklu')
            return
    visited = []
    result = []
    euler(adjlist, 0, visited, result)

    return result












#num = sys.argv[1]
num = "C:\\Users\\Kacper\\git\\put\\aisd\\z4\\data\\data_100_0.7.txt"

#read adjacency matrix

matrix = []
f = open(num)
for line in f:
    temp = [int(x) for x in line.split()]
    matrix.append(temp)

adjlist = am_to_al(matrix)
#print(adjlist)
#print(len(adjlist))
sys.setrecursionlimit(2000)
res = eulerian_cycle(adjlist)
print(res)
#print(num, 'done')