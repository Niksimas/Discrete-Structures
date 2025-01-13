import math
import time
from prettytable import PrettyTable


def naive_mod_exp(base, exp, mod):
    result = 1
    k = 0
    for _ in range(exp):
        result = (result * base) % mod
        k += 1
    return k, result


def fast_mod_exp(base, exp, mod):
    result = 1
    k = 0
    while exp > 0:
        k += 1
        if exp % 2 == 1:  # Если степень нечётная
            k += 1
            result = (result * base) % mod
        base = (base * base) % mod
        exp //= 2
    return k, result


def generate_table():
    table = PrettyTable()
    table.field_names = ["Степень", "Кол-во операций (Н)", "Кол-во операций (Б)", "Время (сек) Н", "Время (сек)Б"]

    # base, exp, mod = 38465, 3576455, 10000003  # Примерные входные данные
    base, exp, mod = 2, 50, 11  # Примерные входные данные

    for i in range(15):

        # Наивный метод
        start_time = time.time()
        count_n, res = naive_mod_exp(base, exp*i, mod)
        end_time = time.time()

        naive_time = end_time - start_time

        # Быстрое возведение
        start_time = time.time()
        count_f, res = fast_mod_exp(base, exp*i, mod)
        end_time = time.time()

        fast_time = end_time - start_time

        table.add_row([exp*i, count_n, count_f, "{:.10f}".format(naive_time), "{:.10f}".format(fast_time)])

    print(table)


if __name__ == "__main__":
    generate_table()
