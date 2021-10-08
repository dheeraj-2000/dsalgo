from collections import deque
# import operator

class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None
        self.hd = 0

def leftview(root):
    if root is None:
        return
    leftview = []
    q = deque()
    q.append(root)
    while q:
        n = len(q)
        for j in range(n):   # iterate through all nodes at each level
            i = q.popleft()
            # 0 left n-1 then right
            if j==0:   #at each level, the first element will always be at j=0
                leftview.append(i.data)
            if i.left and i.left.data != -1:
                q.append(i.left)
            if i.right and i.right.data != -1:
                q.append(i.right)
    return leftview
  
root = Node(1)
root.left = Node(2)
root.left.left = Node(4)
root.left.right = Node(5)
root.right = Node(3)
print('Left View: ',leftview(root))
