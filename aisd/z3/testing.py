#-------------------------------------------------------------------------
#adjacency matrix algorithms

def dfs_matrix(matrix, start, visited, size):
    print(start, end=' ')
    visited[start] = True
    for i in range(size):
        if matrix[start][i] == 1 and visited[i] == False:
            dfs_matrix(matrix, i, visited, size)

def bfs_matrix(size, start, matrix):
        visited = [False] * size
        q = [start]
        visited[start] = True
        while q:
            vis = q[0]
            print(vis, end = ' ')
            q.pop(0)
            for i in range(size):
                if matrix[vis][i] == 1 and visited[i] == False:     
                    q.append(i)
                    visited[i] = True

def dfs_sort(matrix, start, visited, size, result):
    print(start, end=' ')
    visited[start] = 1
    for i in range(size):
        x = matrix[start][i]
        if x == 1 and visited[i] == 1:
            print('cykl')
            return
        if x == 1 and visited[i] == 0:
            dfs_sort(matrix, i, visited, size, result)
    result.append(start)
    visited[start] = 2
    result.reverse()
    return result

def bfs_sort(matrix, start, size):
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
    print(start, end=' ')
    visited[start] = True
    for i in range(size):
        for j in range(len(adjlist[i])):
            x = adjlist[i][j]
            if visited[x] == False:
                dfs_list(adjlist, x, visited, size)

def bfs_list(adjlist, start, size, nodes):
    visited = [False] * nodes
    q = [start]
    visited[start] = True
    while q:
        vis = q[0]
        print(vis, end = ' ')
        q.pop(0)
        for i in range(size):
            for j in range(len(adjlist[i])):
                x = adjlist[i][j]
                if visited[x] == False:     
                    q.append(x)
                    visited[x] = True

def dfs_list_sort(adjlist, start, visited, size, result):
    visited[start] = 1
    for i in range(size):
        for j in range(len(adjlist[i])):
            x = edgelist[i][j]
            if visited[x] == 1:
                print('cykl')
                return
            if visited[x] == 0:
                dfs_list_sort(edgelist, x, visited, size, result)
    result.append(start)
    visited[start] = 2
    result.reverse()
    return result

def bfs_list_sort(adjlist, start, size):
    indegree = [0] * size
    visited = []
    result = []
    for i in range(size):
        for j in range(len(adjlist[i])):
            temp = edgelist[i][j]
            indegree[temp] += 1
    for i in range(size):
        if indegree[i] == 0:
            visited.append(i)
            indegree[i] = -1
    count = 0
    while visited:
        u = visited.pop(0)
        result.append(u)
        for i in range(size):
            for j in range(len(adjlist[i])):
                temp = adjlist[i][j]
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
    print(start, end=' ')
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
        print(vis, end = ' ')
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

def bfs_edge_sort(edgelist, start, size, nodes):
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


#read adjacency matrix

matrix = []
f = open("plik.txt", "r")
for line in f:
    temp = [int(x) for x in line.split()]
    matrix.append(temp)

size, nodes = len(matrix)
visited = [False]*size

dfs_matrix(matrix, 0, visited, size)
print()
bfs_matrix(size, 0, matrix)
print()
visited = [0] * size
result = []
res = dfs_sort(matrix, 0, visited, size, result)
print(res)
print()
visited = []
result = []
res = bfs_sort(matrix, 0, size)
print(res)
print()


#lista krawedzi
edgelist = am_to_el(matrix)
size = len(edgelist)
visited = [0] * size
result = []
res = dfs_edge_sort(edgelist, 0, visited, size, result)
print(res)
print()
res = bfs_edge_sort(edgelist, 0, size, nodes)
print(res)
print()