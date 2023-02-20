import timeit
from functools import partial
import time
import sort
import search
from list_ops import generate_list, is_list_sorted


def measure_sort_time(list_size, sort_func):
    lst = generate_list(list_size)
    start_time = time.time()
    sort_func(lst)
    end_time = time.time()
    print(f'time passed: {end_time - start_time}')


def set_time(flag):
    return time.process_time() if flag else time.time()


def measure_time1(func, is_proc_time=False, count=1, dscr=None):
    print(f'++++++++ {measure_time1.__qualname__}')
    print(f'function name: {dscr}')

    start_time = set_time(is_proc_time)

    func_ret_value = []

    for i in range(count):
        func_ret_value.append(func())

    end_time = set_time(is_proc_time)

    ret_value_length = len(func_ret_value) - 1

    if isinstance(func_ret_value[ret_value_length], list) and func_ret_value[ret_value_length]:
        print(f'is last list elm sorted: {is_list_sorted(func_ret_value[ret_value_length])}')
        print(f'the list\'s length is: {len(func_ret_value[ret_value_length])}')
    elif func_ret_value:
        print(f'func_ret_value: {func_ret_value}')

    if count != 0:
        print(f'time passed: {(end_time - start_time) / count}')
    print('--------\n')


# Press the green button in the gutter to run the script.
if __name__ == '__main__':
    # measure_sort_time(10 * 1000, sort_bubble1)
    # measure_time1(lambda: sort_bubble2(generate_list(10 * 1000)))
    # measure_time1(partial(sort_bubble1, generate_list(10 * 1000)), True)
    # measure_time1(partial(sort.sort_bubble1, generate_list(10 * 1000)), dscr='sort_bubble1')
    # measure_time1(partial(sort.sort_bubble2, generate_list(10 * 1000)), dscr='sort_bubble2', is_proc_time=True)
    # n = 1
    # timeit_result = timeit.timeit(stmt=lambda: search.search_linear(generate_list(10 * 1000), 55), number=n)
    # print(f'timeit_result {timeit_result / n}\n')
    # measure_time1(lambda: search.search_linear(generate_list(10 * 1000), 55), dscr='search_linear', count=2)
    # measure_time1(lambda: sort.sort_shaker1(generate_list(10 * 1000)), dscr='sort_shaker1', count=1)
    measure_time1(lambda: sort.comb_sort(generate_list(10 * 1000)), dscr='comb_sort')
    measure_time1(lambda: sort.insert_sort(generate_list(10 * 1000)), dscr='insert_sort')
