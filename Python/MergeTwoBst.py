# Program to merge two BSTs

# Structure of a BST Node
from ctypes import sizeof


class Node:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None


# Funtion to merge two BSTs
def mergeTwoBST(root1, root2):
    res = []
    s1, s2 = [], []

    while root1 or root2 or s1 or s2:
        while root1:
            s1.append(root1)
            root1 = root1.left

        while root2:
            s2.append(root2)
            root2 = root2.left

        if not s2 or (s1 and s1[-1].val <= s2[-1].val):
            root1 = s1[-1]
            del s1[-1]
            res.append(root1.val)
            root1 = root1.right

        else:
            root2 = s2[-1]
            del s2[-1]
            res.append(root2.val)
            root2 = root2.right

    return res


# Function to build a BST from the given array;
def insert(root, key):
    if root is None:
        return Node(key)
    else:
        if root.val == key:
            return root
        elif root.val < key:
            root.right = insert(root.right, key)
        else:
            root.left = insert(root.left, key)
    return root


def inorder(root):
    if root:
        inorder(root.left)
        print(root.val)
        inorder(root.right)


# Driver program to test above functions
if __name__ == '__main__':
    bst1 = [5, 3, 6, 2, 4]
    bst2 = [2, 1, 3, 7, 6]
    root1 = Node(bst1[0])
    root2 = Node(bst2[0])
    for a in range(1, len(bst1)):
        insert(root1, bst1[a])
    for a in range(1, len(bst2)):
        insert(root2, bst2[a])
    # inorder(root1)
    # inorder(root2)
    ans = mergeTwoBST(root1, root2)
    print(ans)
