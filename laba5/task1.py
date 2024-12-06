import random
import networkx as nx
from collections import deque
import matplotlib.pyplot as plt
from prettytable import PrettyTable

title_pt = ["Очередь", "Посещенные вершины", "Новая вершина", "Рассматриваемая связь", "Каркас"]


class AbcDataMass:

    def remove(self):
        pass

    def add(self, item):
        pass

    def get(self):
        pass

    def getList(self) -> list:
        pass

    def count(self):
        pass


class Stack (AbcDataMass):
    def __init__(self):
        self.stack = []

    def get(self):
        return self.stack.pop()

    def remove(self):
        self.stack.pop()

    def add(self, item):
        self.stack.append(self.stack.append(item))

    def getList(self):
        return list(self.stack)

    def count(self):
        return len(self.stack)


class Queue (AbcDataMass):
    def __init__(self):
        self.queue = deque([])

    def get(self):
        return self.queue.popleft()

    def remove(self):
        self.queue.pop()

    def add(self, item):
        self.queue.append(item)

    def getList(self):
        return list(self.queue)

    def count(self):
        return len(self.queue)


def generate_random_edge_list(num_nodes, max_edges_per_node=None):
    """
    Генерирует случайный граф в виде списка рёбер.

    :param num_nodes: Количество вершин в графе.
    :param max_edges_per_node: Максимальное количество рёбер для каждой вершины (если None, определяется автоматически).
    :return: Список рёбер графа.
    """
    edges = set()  # Используем множество, чтобы избежать дублирующихся рёбер
    max_edges_per_node = max_edges_per_node or num_nodes - 1

    for node in range(num_nodes):
        # Выбираем случайное количество рёбер для текущей вершины
        num_edges = random.randint(1, max_edges_per_node)

        # Выбираем случайных соседей для текущей вершины
        neighbors = random.sample(range(num_nodes), k=num_edges)

        for neighbor in neighbors:
            if neighbor != node:  # Исключаем петли
                edge = tuple(sorted((node, neighbor)))  # Сортируем, чтобы (0, 2) и (2, 0) считались одним ребром
                edges.add(edge)

    return list(edges)


# Функция для визуализации графа с подсветкой
def visualize_graph(G, pos, visited, queue, current_node=None, tree_edges=None, current_edge=None):
    plt.clf()

    # Цвета вершин
    node_colors = [
        "yellow" if node == current_node else "green" if node in visited else "lightblue"
        for node in G.nodes
    ]

    # Цвета рёбер
    edge_colors = []
    for edge in G.edges:
        if edge == current_edge or edge[::-1] == current_edge:  # Текущая рассматриваемая связь
            edge_colors.append("yellow")
        elif edge in tree_edges or edge[::-1] in tree_edges:  # Рёбра, входящие в каркас
            edge_colors.append("green")
        else:
            edge_colors.append("black")  # Остальные рёбра

    # Рисуем граф
    nx.draw(
        G, pos, with_labels=True, node_color=node_colors, edge_color=edge_colors, font_weight="bold"
    )

    # Рисуем очередь/стек (ниже графа)
    plt.title(f"Очередь/Стек: {list(queue)}")
    plt.pause(1)


#
# # Функция обхода в ширину
# def bfs(G, start):
#     visited = set()
#     queue = deque([start])
#     tree_edges = []
#     pos = nx.spring_layout(G)
#
#     # Инициализация таблицы
#     table = PrettyTable(title_pt)
#
#     while queue:
#         current = queue.popleft()
#         if current not in visited:
#
#             visited.add(current)
#
#             for neighbor in G.neighbors(current):
#                 new_nod = "-"
#                 new_edges = "-"
#                 if neighbor not in visited:
#                     if neighbor not in queue:
#                         new_nod = neighbor
#                         queue.append(neighbor)
#                     if not ((current, neighbor) in tree_edges or (neighbor, current) in tree_edges):
#                         new_edges = (current, neighbor)
#                         tree_edges.append((current, neighbor))  # Добавляем новую связь в каркас
#
#                 # Обновляем таблицу и визуализацию
#                 table.add_row(
#                     [
#                         f"{', '.join([str(i) for i in list(queue)]) if len(queue) > 0 else ""}",
#                         f"{''.join(['+' if v in visited else '-' for v in G.nodes])}",
#                         new_nod,
#                         f"{current}-{neighbor}",
#                         new_edges
#                     ])
#                 visualize_graph(G, pos, visited, queue, current, tree_edges, (current, neighbor))
#                 print(table)
#
#
#
# # Функция обхода в глубину
# def dfs(G, start):
#     visited = set()
#     stack = [start]
#     tree_edges = []
#     pos = nx.spring_layout(G)
#
#     # Инициализация таблицы
#     table = PrettyTable(title_pt)
#
#     while stack:
#         current = stack.pop()
#         if current not in visited:
#             visited.add(current)
#
#             for neighbor in G.neighbors(current):
#                 new_nod = "-"
#                 new_edges = "-"
#                 if neighbor not in visited and neighbor not in stack:
#                     new_nod = neighbor
#                     stack.append(neighbor)
#                 print((current, neighbor), tree_edges)
#                 if not ((current, neighbor) in tree_edges or (neighbor, current) in tree_edges):
#                     new_edges = (current, neighbor)
#                     tree_edges.append((current, neighbor))  # Добавляем новую связь в каркас
#
#                 # Обновляем таблицу и визуализацию
#                 table.add_row([
#                     f"{current}{', ' + ', '.join([str(i) for i in list(stack)]) if len(stack) > 0 else ""}",
#                     f"{''.join(['+' if v in visited else '-' for v in G.nodes])}",
#                     new_nod,
#                     f"{current}-{neighbor}",
#                     new_edges
#                 ])
#                 visualize_graph(G, pos, visited, stack, current, tree_edges, (current, neighbor))
#                 print(table)
#


def search(G, data: AbcDataMass, start):
    visited = set()
    tree_edges = []
    pos = nx.spring_layout(G)

    data.add(start)

    # Инициализация таблицы
    table = PrettyTable(title_pt)

    while data:
        current = data.get()
        if current not in visited:
            visited.add(current)

            for neighbor in G.neighbors(current):
                new_nod = "-"
                new_edges = "-"
                if neighbor not in visited and neighbor not in data.getList():
                    new_nod = neighbor
                    data.add(neighbor)
                if not ((current, neighbor) in tree_edges or (neighbor, current) in tree_edges):
                    new_edges = (current, neighbor)
                    tree_edges.append((current, neighbor))  # Добавляем новую связь в каркас

                # Обновляем таблицу и визуализацию
                table.add_row([
                    f"{current}{', ' + ', '.join([str(i) for i in data.getList()]) if data.count() > 0 else ""}",
                    f"{''.join(['+' if v in visited else '-' for v in G.nodes])}",
                    new_nod,
                    f"{current}-{neighbor}",
                    new_edges
                ])
                visualize_graph(G, pos, visited, data.getList(), current, tree_edges, (current, neighbor))
                print(table)




# Основная программа
if __name__ == "__main__":
    G = nx.Graph()
    G.add_edges_from([(0, 2), (1, 5), (1, 6), (1, 7), (2, 0), (2, 3), (2, 4), (2, 6), (3, 2), (3, 5), (4, 2), (4, 7), (5, 3), (5, 1), (6, 2), (6, 1), (7, 4), (7, 1)])
    # G.add_edges_from(generate_random_edge_list(7, 2))

    print("Выберите алгоритм:")
    print("1: Обход в ширину")
    print("2: Обход в глубину")
    choice = int(input("Ваш выбор: "))

    # start_node = 0
    start_node = int(input("Введите начальную вершину: "))

    if choice == 1:
        search(G, Queue(), start_node)
    elif choice == 2:
        search(G, Stack(), start_node)
    else:
        print("Неверный выбор!")
