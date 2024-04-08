import sys

n = int(sys.stdin.readline())
a, b = map(int, sys.stdin.readline().split())
m = int(sys.stdin.readline())

graph = []
visited = []

for i in range(n + 1):
    graph.append([])
    visited.append(False)

for i in range(m):
    x, y = map(int, sys.stdin.readline().split())
    graph[x].append(y)
    graph[y].append(x)


def dfs(x, result):
    global flag
    visited[x] = True

    if x == b:
        flag = True
        print(result)
        return result

    for i in graph[x]:
        if visited[i] == False:
            dfs(i, result + 1)


flag = False
dfs(a, 0)
if flag == False:
    print(-1)
