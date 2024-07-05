def isCyclicUtil(v, visited, parent, adj):
    visited[v] = True
    for neighbor in adj[v]:
        if not visited[neighbor]:
            if isCyclicUtil(neighbor, visited, v, adj):
                return True
        elif parent != neighbor:
            return True
    return False


def isCyclic(adj, n):
    visited = [False] * n
    for i in range(n):
        if not visited[i]:
            if isCyclicUtil(i, visited, -1, adj):
                return True
    return False


def isConnected(adj, n):
    visited = [False] * n
    stack = []
    stack.append(0)
    visited[0] = True

    while stack:
        u = stack.pop()
        for v in adj[u]:
            if not visited[v]:
                stack.append(v)
                visited[v] = True

    return all(visited)


def isTree(adj, n):
    return isConnected(adj, n) and not isCyclic(adj, n)


def main():
    n = int(input())
    adj = [[] for _ in range(n)]

    for i in range(n):
        row = list(map(int, input().split()))
        for j in range(n):
            if row[j] == 1:
                adj[i].append(j)

    if isTree(adj, n):
        print("YES")
    else:
        print("NO")


if __name__ == "__main__":
    main()
