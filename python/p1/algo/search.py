# SEARCH
def search_linear(lst, value):
    for i in enumerate(lst):
        if i[1] == value:
            return i[0]

    return None


def search_bin(lst, value):
    pass
