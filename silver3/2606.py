import sys

result = 0

n = int(sys.stdin.readline())
connect = int(sys.stdin.readline())

graph = [[] for _ in range(n + 1)]
visited = [False for _ in range(n + 1)]

for _ in range(connect):
    x, y = map(int, sys.stdin.readline().split())
    graph[x].append(y)
    graph[y].append(x)


def dfs(x):
    visited[x] = True

    for i in graph[x]:
        if visited[i] == False:
            dfs(i)


dfs(1)
print(visited.count(True) - 1)
