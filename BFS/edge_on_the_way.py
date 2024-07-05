import heapq


def search(n, graph, start):
    dist = [float('inf')] * (n + 1)
    dist[start] = 0
    pq = [(0, start)]
    while pq:
        current_dist, node = heapq.heappop(pq)
        if current_dist > dist[node]:
            continue
        for neighbor, weight in graph[node]:
            distance = current_dist + weight
            if distance < dist[neighbor]:
                dist[neighbor] = distance
                heapq.heappush(pq, (distance, neighbor))
    return dist


def main():
    n, m = map(int, input().split())

    graph = [[] for _ in range(n + 1)]
    for _ in range(m):
        u, v = map(int, input().split())
        graph[u].append((v, 1))
        graph[v].append((u, 1))

    t = int(input())

    queries = []
    for _ in range(t):
        u, v, a, b = map(int, input().split())
        queries.append((u, v, a, b))

    results = []
    all_dist = {i: search(n, graph, i) for i in range(1, n + 1)}

    for u, v, a, b in queries:
        dist_u = all_dist[u]
        dist_v = all_dist[v]

        if (dist_u[a] + 1 + dist_v[b] == dist_u[v]) or (dist_u[b] + 1 + dist_v[a] == dist_u[v]):
            results.append("YES")
        else:
            results.append("NO")

    for result in results:
        print(result)


if __name__ == "__main__":
    main()
