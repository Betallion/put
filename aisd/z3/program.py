import time
import sys
import os

#-------------------------------------------------------------------------
#adjacency matrix algorithms

def dfs_matrix(matrix, start, visited, size):
    #print(start, end=' ')
    visited[start] = True
    for i in range(size):
        if matrix[start][i] == 1 and visited[i] == False:
            dfs_matrix(matrix, i, visited, size)

def bfs_matrix(matrix, start, size):
        visited = [False] * size
        q = [start]
        visited[start] = True
        while q:
            vis = q[0]
            #print(vis, end = ' ')
            q.pop(0)
            for i in range(size):
                if matrix[vis][i] == 1 and visited[i] == False:     
                    q.append(i)
                    visited[i] = True

def dfs_sort_matrix(matrix, start, visited, size, result):
    #print(start, end=' ')
    visited[start] = 1
    for i in range(size):
        x = matrix[start][i]
        if x == 1 and visited[i] == 1:
            print('cykl')
            return
        if x == 1 and visited[i] == 0:
            dfs_sort_matrix(matrix, i, visited, size, result)
    result.append(start)
    visited[start] = 2
    result.reverse()
    return result

def bfs_sort_matrix(matrix, start, size):
    indegree = [0] * size
    visited = []
    result = []
    for i in range(size):
        temp = 0
        for j in range(size):
            if matrix[j][i] == 1:
                temp += 1
        indegree[i] = temp
    for i in range(size):
        if indegree[i] == 0:
            visited.append(i)
            indegree[i] = -1
    count = 0
    while visited:
        u = visited.pop(0)
        result.append(u)
        for i in range(size):
            if matrix[u][i] == 1 and indegree[i] > 0:
                indegree[i] -= 1
            if indegree[i] == 0:
                visited.append(i)
                indegree[i] = -1
        count += 1
    if count != size:
        print('cykl')
        return
    else:
        result.reverse()
        return result
    

#-------------------------------------------------------------------------
#adjacency list algorithms


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

def dfs_list(adjlist, start, visited, size):
    #print(start, end=' ')
    visited[start] = True
    for j in range(len(adjlist[start])):
        x = adjlist[start][j]
        if visited[x] == False:
            dfs_list(adjlist, x, visited, size)
        



def bfs_list(adjlist, start, size, nodes):
    visited = [False] * nodes
    q = [start]
    visited[start] = True
    while q:
        vis = q[0]
        #print(vis, end = ' ')
        q.pop(0)
        for j in range(len(adjlist[vis])):
            x = adjlist[vis][j]
            if visited[x] == False:     
                q.append(x)
                visited[x] = True

def dfs_list_sort(adjlist, start, visited, size, result):
    visited[start] = 1
    for j in range(len(adjlist[start])):
        x = adjlist[start][j]
        if visited[x] == 1:
            print('cykl')
            return
        if visited[x] == 0:
            dfs_list_sort(adjlist, x, visited, size, result)
        
    result.append(start)
    visited[start] = 2
    result.reverse()
    return result

def bfs_list_sort(adjlist, size):
    indegree = [0] * size
    visited = []
    result = []
    for i in range(size):
        for j in range(len(adjlist[i])):
            temp = adjlist[i][j]
            indegree[temp] += 1
    for i in range(size):
        if indegree[i] == 0:
            visited.append(i)
            indegree[i] = -1
    count = 0
    while visited:
        u = visited.pop(0)
        result.append(u)
        for j in range(len(adjlist[u])):
            temp = adjlist[u][j]
            if indegree[temp] > 0:
                indegree[temp] -= 1
            if indegree[temp] == 0:
                visited.append(temp)
                indegree[temp] = -1
            
        count += 1   
    if count != size:
        print('cykl')
        return
    else:
        result.reverse()
        return result

#-------------------------------------------------------------------------
#edge list algorithms

def am_to_el(matrix):
    size = len(matrix)
    edgelist = []
    for i in range(size):
        for j in range(size):
            if matrix[i][j] == 1:
                temp = [i, j]
                edgelist.append(temp)
    return edgelist

def dfs_edge(edgelist, start, visited, size):
    #print(start, end=' ')
    visited[start] = True
    for i in range(size):
        x = edgelist[i][1]
        if edgelist[i][0] == start and visited[x] == False:
            dfs_edge(edgelist, x, visited, size)

def bfs_edge(edgelist, start, size, nodes):
    visited = [False] * nodes
    q = [start]
    visited[start] = True
    while q:
        vis = q[0]
        #print(vis, end = ' ')
        q.pop(0)
        for i in range(size):
            x = edgelist[i][1]
            if edgelist[i][0] == vis and visited[x] == False:     
                q.append(x)
                visited[x] = True

def dfs_edge_sort(edgelist, start, visited, size, result):
    visited[start] = 1
    for i in range(size):
        x = edgelist[i][1]
        if edgelist[i][0] == start:
            if visited[x] == 1:
                print('cykl')
                return
            if visited[x] == 0:
                dfs_edge_sort(edgelist, x, visited, size, result)
    result.append(start)
    visited[start] = 2
    result.reverse()
    return result

def bfs_edge_sort(edgelist, size, nodes):
    indegree = [0] * nodes
    visited = []
    result = []
    for i in range(size):
        temp = edgelist[i][1]
        indegree[temp] += 1
    for i in range(nodes):
        temp = edgelist[i][1]
        if indegree[i] == 0:
            visited.append(i)
            indegree[i] = -1
    count = 0
    while visited:
        u = visited.pop(0)
        result.append(u)
        for i in range(size):
            if edgelist[i][0] == u:
                temp = edgelist[i][1]
                if indegree[temp] > 0:
                    indegree[temp] -= 1
                if indegree[temp] == 0:
                    visited.append(temp)
                    indegree[temp] = -1
        count += 1   
    if count != nodes:
        print('cykl')
        return
    else:
        result.reverse()
        return result




#-------------------------------------------------------------------------
#tests

def amtest(matrix, alg, num):
    timedir = os.path.dirname(os.path.abspath(__file__)) + '/times/'
    bfsname = timedir + alg + '_bfs_times.txt'
    dfsname = timedir + alg + '_dfs_times.txt'
    bfssortname = timedir + alg + '_bfssort_times.txt'
    dfssortname = timedir + alg + '_dfssort_times.txt'
    bfsfile = open(bfsname, 'a')
    dfsfile = open(dfsname, 'a')
    bfssortfile = open(bfssortname, 'a')
    dfssortfile = open(dfssortname, 'a')
    
    size = len(matrix)
    visited = [False]*size
    #print('dfs am')
    start = time.time()
    dfs_matrix(matrix, 0, visited, size)
    elapsedDfs = str(num) + ' ' + str(time.time() - start) + '\n'
    dfsfile.write(elapsedDfs)
    #print()

    #print('bfs am')
    start = time.time()
    bfs_matrix(matrix, 0, size)
    elapsedBfs = str(num) + ' ' + str(time.time() - start) + '\n'
    bfsfile.write(elapsedBfs)
    #print()
    
    visited = [0] * size
    result = []
    #print('dfs sort am')
    start = time.time()
    res = dfs_sort_matrix(matrix, 0, visited, size, result)
    elapsedDfsSort = str(num) + ' ' + str(time.time() - start) + '\n'
    dfssortfile.write(elapsedDfsSort)
    #print(res)
    #print()
    
    visited = []
    result = []
    #print('bfs sort am')
    start = time.time()
    res = bfs_sort_matrix(matrix, 0, size)
    elapsedBfsSort = str(num) + ' ' + str(time.time() - start) + '\n'
    bfssortfile.write(elapsedBfsSort)
    #print(res)
    #print()

    bfsfile.close()
    dfsfile.close()
    bfssortfile.close()
    dfssortfile.close()

def altest(matrix, nodes, alg, num):
    timedir = os.path.dirname(os.path.abspath(__file__)) + '/times/'
    bfsname = timedir + alg + '_bfs_times.txt'
    dfsname = timedir + alg + '_dfs_times.txt'
    bfssortname = timedir + alg + '_bfssort_times.txt'
    dfssortname = timedir + alg + '_dfssort_times.txt'
    bfsfile = open(bfsname, 'a')
    dfsfile = open(dfsname, 'a')
    bfssortfile = open(bfssortname, 'a')
    dfssortfile = open(dfssortname, 'a')

    adjlist = am_to_al(matrix)
    size = len(adjlist)
    
    visited = [False] * nodes
    result = []
    #print('dfs al')
    start = time.time()
    dfs_list(adjlist, 0, visited, size)
    elapsedDfs = str(num) + ' ' + str(time.time() - start) + '\n'
    dfsfile.write(elapsedDfs)
    #print()

    #print('bfs al')
    start = time.time()
    bfs_list(adjlist, 0, size, nodes)
    elapsedBfs = str(num) + ' ' + str(time.time() - start) + '\n'
    bfsfile.write(elapsedBfs)
    #print()

    visited = [0] * nodes
    result = []
    #print('dfs sort al')
    start = time.time()
    res = dfs_list_sort(adjlist, 0, visited, size, result)
    elapsedDfsSort = str(num) + ' ' + str(time.time() - start) + '\n'
    dfssortfile.write(elapsedDfsSort)
    #print(res)
    #print()

    #print('bfs sort al')
    start = time.time()
    res = bfs_list_sort(adjlist, size)
    elapsedBfsSort = str(num) + ' ' + str(time.time() - start) + '\n'
    bfssortfile.write(elapsedBfsSort)
    #print(res)
    #print()

    bfsfile.close()
    dfsfile.close()
    bfssortfile.close()
    dfssortfile.close()

def eltest(matrix, nodes, alg, num):
    timedir = os.path.dirname(os.path.abspath(__file__)) + '/times/'
    bfsname = timedir + alg + '_bfs_times.txt'
    dfsname = timedir + alg + '_dfs_times.txt'
    bfssortname = timedir + alg + '_bfssort_times.txt'
    dfssortname = timedir + alg + '_dfssort_times.txt'
    bfsfile = open(bfsname, 'a')
    dfsfile = open(dfsname, 'a')
    bfssortfile = open(bfssortname, 'a')
    dfssortfile = open(dfssortname, 'a')

    edgelist = am_to_el(matrix)
    size = len(edgelist)

    visited = [False] * nodes
    result = []
    #print('dfs el')
    start = time.time()
    dfs_edge(edgelist, 0, visited, size)
    elapsedDfs = str(num) + ' ' + str(time.time() - start) + '\n'
    dfsfile.write(elapsedDfs)
    #print()

    #print('bfs el')
    start = time.time()
    bfs_edge(edgelist, 0, size, nodes)
    elapsedBfs = str(num) + ' ' + str(time.time() - start) + '\n'
    bfsfile.write(elapsedBfs)
    #print()

    visited = [0] * nodes
    result = []
    #print('dfs sort el')
    start = time.time()
    res = dfs_edge_sort(edgelist, 0, visited, size, result)
    elapsedDfsSort = str(num) + ' ' + str(time.time() - start) + '\n'
    dfssortfile.write(elapsedDfsSort)
    #print(res)
    #print()

    #print('bfs sort el')
    start = time.time()
    res = bfs_edge_sort(edgelist, size, nodes)
    elapsedBfsSort = str(num) + ' ' + str(time.time() - start) + '\n'
    bfssortfile.write(elapsedBfsSort)
    #print(res)
    #print()

    bfsfile.close()
    dfsfile.close()
    bfssortfile.close()
    dfssortfile.close()

#read adjacency matrix

datafile = sys.argv[1]
alg = sys.argv[2]
num = int(sys.argv[3])


matrix = []
f = open(datafile, "r")
for line in f:
    temp = [int(x) for x in line.split()]
    matrix.append(temp)

nodes = len(matrix)

if alg == 'am':
    amtest(matrix, alg, num)

if alg == 'al':
    altest(matrix, nodes, alg, num)

if alg == 'el':
    eltest(matrix, nodes, alg, num)

print(alg, num, 'testing done')