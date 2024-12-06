class Heap:
    def __init__(self, is_min_heap=False):
        """Инициализация кучи.
        is_min_heap=True — минимальная куча,
        is_min_heap=False — максимальная куча.
        """
        self.heap = []
        self.is_min_heap = is_min_heap

    def add(self, value):
        """Добавляет элемент в пирамиду."""
        self.heap.append(value)
        self._sift_up(len(self.heap) - 1)

    def pop_first(self):
        """Удаляет и возвращает корневой элемент (минимальный/максимальный)."""
        if not self.heap:
            return None
        if len(self.heap) == 1:
            return self.heap.pop()
        root_value = self.heap[0]
        self.heap[0] = self.heap.pop()
        self._sift_down(0)
        return root_value

    def peek(self):
        """Возвращает корневой элемент без удаления."""
        return self.heap[0] if self.heap else None

    def print_heap(self):
        """Вывод пирамиды."""
        print(self.heap)

    def _compare(self, child, parent):
        """Сравнение элементов для минимальной/максимальной кучи."""
        if self.is_min_heap:
            return child < parent  # Для Min-Heap (меньший приоритет)
        else:
            return child > parent  # Для Max-Heap (больший приоритет)

    def _sift_up(self, index):
        """Проталкивает элемент вверх для поддержания свойств пирамиды."""
        parent = (index - 1) // 2
        if index > 0 and self._compare(self.heap[index], self.heap[parent]):
            self.heap[index], self.heap[parent] = self.heap[parent], self.heap[index]
            self._sift_up(parent)

    def _sift_down(self, index):
        """Проталкивает элемент вниз для поддержания свойств пирамиды."""
        left_child = 2 * index + 1
        right_child = 2 * index + 2
        priority = index

        if left_child < len(self.heap) and self._compare(self.heap[left_child], self.heap[priority]):
            priority = left_child
        if right_child < len(self.heap) and self._compare(self.heap[right_child], self.heap[priority]):
            priority = right_child

        if priority != index:
            self.heap[index], self.heap[priority] = self.heap[priority], self.heap[index]
            self._sift_down(priority)

    def print_tree(self):
        """Вывод пирамиды в виде дерева."""
        if not self.heap:
            print("Пирамида пуста.")
            return

        import math
        levels = math.ceil(math.log2(len(self.heap) + 1))  # Количество уровней в пирамиде
        index = 0

        for level in range(levels):
            # Количество элементов на уровне: 2^level
            num_elements = 2 ** level
            level_elements = self.heap[index:index + num_elements]
            index += num_elements

            # Форматирование вывода
            indent = " " * (2 ** (levels - level - 1) - 1)  # Отступ перед уровнем
            line = indent + " ".join(map(str, level_elements)) + indent
            print(line)

    def get_first(self):
        return self.heap[0]

    def count(self):
        return len(self.heap)


if __name__ == "__main__":
    # Пример использования
    pq = Heap(is_min_heap=False)
    pq.add(2)
    pq.add(15)
    pq.add(8)
    pq.add(20)
    pq.add(19)
    pq.add(38)
    pq.add(5)
    pq.add(27)
    pq.add(1)

    print("Пирамида:")
    pq.print_tree()

    print("\nМаксимальный элемент:", pq.get_first())
    print("Удаляем максимум:", pq.pop_first())

    print("\nПирамида после удаления:")
    pq.print_tree()
