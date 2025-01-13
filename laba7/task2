import math
import time
from prettytable import PrettyTable


def discrete_log_brute_force(base, result, mod):
    k = 0
    for exp in range(mod):
        k += 1
        if pow(base, exp, mod) == result:
            return k, exp
    return k, None


def baby_step_giant_step(base, result, mod):
    n = int(math.sqrt(mod)) + 1
    value_table = {}
    k = 0
    # Этап "Шаг младенца"
    for i in range(n):
        k += 1
        value = pow(base, i, mod)
        value_table[value] = i

    # Этап "Шаг великана"
    k += 1
    factor = pow(base, n * (mod - 2), mod)


    current = result
    for j in range(n):
        k += 1
        if current in value_table:
            return k, j * n + value_table[current]
        current = (current * factor) % mod
    return k, None



def generate_table():
    table = PrettyTable()
    table.field_names = ["Mod", "Количество операций", "Количество операций (шаги)", "Время (сек) полн", "Время (сек) шаги"]

    base, res, mod = 3, 359, 500  # Примерные входные данные
    # base, res, mod = 8, 2, 10  # Примерные входные данные

    for step in range(15):

        start_time = time.time()
        count_p, result_p = discrete_log_brute_force(base, res, mod*step+1)
        end_time = time.time()

        poln_time = end_time - start_time
        # table.add_row(["полного перебора", count, "{:.10f}".format(poln_time), result])


        start_time = time.time()
        count, result = baby_step_giant_step(base, res, mod*step+1)
        end_time = time.time()

        BsGs_time = end_time - start_time
        table.add_row([mod*step, count_p, count, "{:.10f}".format(poln_time), "{:.10f}".format(BsGs_time)])

    print(table)


if __name__ == "__main__":
    generate_table()
