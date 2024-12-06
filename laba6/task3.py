from task1 import Heap

import networkx as nx
import matplotlib.pyplot as plt
from collections import defaultdict


class UnionFind:
    def __init__(self, n):
        self.parent = list(range(n))
        self.rank = [0] * n

    def find(self, u):
        if self.parent[u] != u:
            self.parent[u] = self.find(self.parent[u])  # сжатие пути
        return self.parent[u]

    def union(self, u, v):
        root_u = self.find(u)
        root_v = self.find(v)
        if root_u != root_v:
            if self.rank[root_u] > self.rank[root_v]:
                self.parent[root_v] = root_u
            elif self.rank[root_u] < self.rank[root_v]:
                self.parent[root_u] = root_v
            else:
                self.parent[root_v] = root_u
                self.rank[root_u] += 1
            return True
        return False


def kruskal_algorithm(graph):
    edges = []
    nodes = list(graph.keys())

    # Собираем все рёбра из графа
    for u in graph:
        for weight, v in graph[u]:
            if (v, u, weight) not in edges:  # Добавляем только одно направление
                edges.append((u, v, weight))

    # Сортируем рёбра по весу с помощью пирамиды
    heap = Heap(is_min_heap=True)
    for edge in edges:
        heap.add(edge)

    uf = UnionFind(len(nodes))
    mst = []
    total_weight = 0

    # Проходим по отсортированным рёбрам
    while heap.count() > 0:
        u, v, weight = heap.pop_first()

        u_index = nodes.index(u)
        v_index = nodes.index(v)

        # Если рёбро не образует цикл, добавляем его в MST
        if uf.union(u_index, v_index):
            mst.append((u, v, weight))
            total_weight += weight

    return mst, total_weight


def prim_algorithm(graph, start_vertex):
    heap = Heap(is_min_heap=True)
    visited = set()
    mst = []
    total_weight = 0

    visited.add(start_vertex)
    for weight, neighbor in graph[start_vertex]:
        heap.add((weight, start_vertex, neighbor))

    while heap.count() > 0:
        weight, u, v = heap.pop_first()

        if v not in visited:
            visited.add(v)
            mst.append((u, v, weight))
            total_weight += weight

            for next_weight, neighbor in graph[v]:
                if neighbor not in visited:
                    heap.add((next_weight, v, neighbor))

    return mst, total_weight


def visualize_graph(graph, mst):
    G = nx.Graph()
    mst_graph = nx.Graph()

    # Добавляем все ребра графа
    for node, edges in graph.items():
        for weight, neighbor in edges:
            G.add_edge(node, neighbor, weight=weight)

    # Добавляем только ребра MST
    for u, v, weight in mst:
        mst_graph.add_edge(u, v, weight=weight)

    pos = nx.spring_layout(G)  # Позиции для узлов графа

    # Рисуем исходный граф
    plt.figure(figsize=(12, 6))
    plt.subplot(1, 2, 1)
    nx.draw(G, pos, with_labels=True, node_color="lightblue", edge_color="gray", node_size=500, font_size=10)
    nx.draw_networkx_edge_labels(G, pos, edge_labels={(u, v): f"{d['weight']}" for u, v, d in G.edges(data=True)})
    plt.title("Исходный граф")

    # Рисуем MST
    plt.subplot(1, 2, 2)
    nx.draw(G, pos, with_labels=True, node_color="lightblue", edge_color="gray", node_size=500, font_size=10, alpha=0.4)
    nx.draw(mst_graph, pos, with_labels=True, node_color="lightgreen", edge_color="red", node_size=500, font_size=10)
    nx.draw_networkx_edge_labels(mst_graph, pos, edge_labels={(u, v): f"{d['weight']}" for u, v, d in mst_graph.edges(data=True)})
    plt.title("Минимальное остовное дерево")

    plt.show()


# Пример данных графа
graph = defaultdict(list, {
    'A': [(4, 'C')],
    'C': [(4, 'A')],

    'B': [(1, 'F'), (6, 'D')],
    'D': [(6, 'B'), (3, 'F')],
    'F': [(7, 'B'), (5, 'D')]
})

# Вычисляем MST
mst, total_weight = prim_algorithm(graph, 'A')

# Выводим MST и его вес
print("Минимальное остовное дерево:")
for u, v, weight in mst:
    print(f"{u} - {v}, вес: {weight}")
print(f"Общий вес MST: {total_weight}")

# Визуализация
visualize_graph(graph, mst)

print('\n\n\n')
mst, total_weight = kruskal_algorithm(graph)

# Выводим MST и его вес
print("Минимальное остовное дерево:")
for u, v, weight in mst:
    print(f"{u} - {v}, вес: {weight}")
print(f"Общий вес MST: {total_weight}")

# Визуализация
visualize_graph(graph, mst)
