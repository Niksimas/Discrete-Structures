import task1

pq = task1.Heap()
array = [10, 20, 5, 15, 30, 1, 8, 75, 16]

for i in array:
    pq.add(i)
print("Исходный массив: ", end=" ")
print(array)
print("Пирамида по массиву: ")
pq.print_tree()

sort_array = []

for i in range(0, pq.count()):
    sort_array.insert(0, pq.pop_first())

print("Отсортированный массив: ", end=" ")
print(sort_array)
