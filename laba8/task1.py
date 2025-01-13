import random

class ChainElem:
    def __init__(self, value=None, next=None):
        self.value = value
        self.next = next


class HashTableSet:
    def __init__(self, size=10):
        self.size = size  # Размер таблицы
        self.table = [None for _ in range(self.size)]  # Инициализация пустых списков (цепочек)

    def _hash(self, value):
        """Хэш-функция для вычисления индекса."""
        return hash(value * 11) % self.size

    def add(self, value):
        """Добавление элемента в множество."""
        index = self._hash(value)
        current = self.table[index]

        # Проверяем, есть ли уже значение в цепочке
        while current:
            if current.value == value:
                return  # Значение уже существует, не добавляем
            current = current.next

        # Добавляем новый элемент в начало цепочки
        new_elem = ChainElem(value, self.table[index])
        self.table[index] = new_elem

    def remove(self, value):
        """Удаление элемента из множества."""
        index = self._hash(value)
        current = self.table[index]
        prev = None

        # Ищем элемент в цепочке
        while current:
            if current.value == value:
                if prev:
                    prev.next = current.next
                else:
                    self.table[index] = current.next
                return
            prev = current
            current = current.next

    def checkIs(self, value):
        """Проверка, содержится ли элемент в множестве."""
        index = self._hash(value)
        current = self.table[index]

        while current:
            if current.value == value:
                return True
            current = current.next
        return False

    def display(self):
        """Вывод текущего состояния хэш-таблицы."""
        for i, chain in enumerate(self.table):
            print(f"Index {i}: ", end="")
            current = chain
            while current:
                print(f"{current.value} -> ", end="")
                current = current.next
            print("None")


# Пример использования
if __name__ == "__main__":
    hset = HashTableSet(size=10)  # Создаем хэш-таблицу с размером 5

    for i in range(30):
        hset.add(random.randint(10, 100))

    # hset.add(41)
    # hset.add(10)
    # hset.add(14)
    # hset.add(15)
    # hset.add(32)
    # hset.add(20)
    # hset.add(23)
    # hset.add(10)  # Повторное добавление 10 (не должно добавиться)

    hset.display()
    #
    # print("Search 15:", hset.checkIs(15))
    # print("Search 25:", hset.checkIs(25))
    #
    # hset.remove(15)
    # print("After removing 15:")
    # hset.display()
