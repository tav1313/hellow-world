def sort_bubble(lst):
    for i in range(len(lst) - 1):
        print("iteration: ", i)
        j = 0
        while j < len(lst) - 1 - i:
            if lst[j] > lst[j + 1]:
                tmp = lst[j]
                lst[j] = lst[j + 1]
                lst[j + 1] = tmp
            j = j + 1

    return lst


def sort_bubble1(lst):
    for i in range(len(lst) - 1):
        for j in range(len(lst) - i - 1):
            if lst[j] > lst[j + 1]:
                lst[j], lst[j + 1] = lst[j + 1], lst[j]


def search_linear(lst, value):
    for i in enumerate(lst):
        if i[1] == value:
            return i[0]

    return None


def search_bin(lst, value):
    pass


def print_hi(name):
    # Use a breakpoint in the code line below to debug your script.
    lst = [9, 1, 6, 5, 3]
    print("linear search idx: ", search_linear(lst, 55))
    sort_bubble(lst)
    print("bubbled list: ", lst)

    lst = [9, 1, 6, 5, 3]
    sort_bubble1(lst)
    print("bubbled list1: ", lst)

    print(f'Hi, {name}')  # Press ⌘F8 to toggle the breakpoint.
    lst = [1, 4, 5, 9]
    for i, v in enumerate(lst):
        print(i, ' ', v)
    return name


# Press the green button in the gutter to run the script.
if __name__ == '__main__':
    print_hi('PyCharm')
