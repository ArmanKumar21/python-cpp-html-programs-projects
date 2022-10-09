arr = [1,2,3,4]

def find_index(arr: list, key):
    if key in arr:
        return arr.index(key)
    else:
        return -1