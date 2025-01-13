import math
import time
from prettytable import PrettyTable


def fast_mod_exp(base, exp, mod):
    result = 1
    while exp > 0:
        if exp % 2 == 1:  # Если степень нечётная
            result = (result * base) % mod
        base = (base * base) % mod
        exp //= 2
    return result


def diffie_hellman(p, g, private_a, private_b):
    # Генерация открытых ключей
    public_a = fast_mod_exp(g, private_a, p)
    public_b = fast_mod_exp(g, private_b, p)

    # Вычисление общего секретного ключа
    secret_a = fast_mod_exp(public_b, private_a, p)
    secret_b = fast_mod_exp(public_a, private_b, p)

    return secret_a, secret_b


def measure_time_and_complexity(func, *args):
    start_time = time.time()
    result = func(*args)
    end_time = time.time()
    return end_time - start_time


def generate_table():
    table = PrettyTable()
    table.field_names = ["Метод", "Количество операций", "Время (сек)", "Результат"]

    base, exp, mod = 38465, 3576455, 10000003  # Примерные входные данные
    start_time = time.time()

    naive_mod_exp(base, exp, mod)
    end_time = time.time()
    naive_time = end_time - start_time
    table.add_row(["Наивный", exp, "{:.10f}".format(naive_time), "Рассчитано"])

    fast_time = measure_time_and_complexity(fast_mod_exp, base, exp, mod)
    table.add_row(["Быстрое возведение", exp, "{:.10f}".format(fast_time), "Рассчитано"])

    print(table)


if __name__ == "__main__":
    generate_table()
