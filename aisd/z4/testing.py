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
    for i in range(len(x)):
        if adjlist[x][i] == y:
            adjlist[x].pop(i)
    for i in range(len(y)):
        if adjlist[y][i] == x:
            adjlist[y].pop(i)

def dfs_euler(adjlist, start, visited, result):
    visited.append(start)
    for i in range(len(adjlist[start])):
        if adjlist[start][i] not in visited:
            remove_edge(start, adjlist[start][i])
            dfs_euler(adjlist, adjlist[start[i]], visited, result)
    result.append(start)

def eulerian_cycle(adjlist):
    deg = [0] * len(adjlist)
    for i in range(len(adjlist)):
        deg[i] += len(adjlist[i])
        for j in range(len(adjlist[i])):
            deg[adjlist[i][j]] += 1
    for i in deg:
        if i % 2 != 0:
            return
    visited = []
    result = []
    dfs_euler(adjlist, 0, visited, result)
    print(result)
    return result








#read adjacency matrix

matrix = []
f = open("plik.txt", "r")
for line in f:
    temp = [int(x) for x in line.split()]
    matrix.append(temp)