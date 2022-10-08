class Node:
    def __init__(self):
        self.children = {}
        self.endOfWord = False
class WordDictionary:

    def __init__(self):
        self.root = Node()

    def addWord(self, word: str) -> None:
        cur = self.root
        for c in word:
            if c not in cur.children:
                cur.children[c] = Node()
            cur = cur.children[c]
        cur.endOfWord = True

    def search(self, word: str, root = None) -> bool:
        if root is None:
            cur = self.root
        else:
            cur = root
        for c in enumerate(word):
            if c[1] == '.':
                for k in cur.children.keys():
                    if self.search(word[(c[0] + 1):], cur.children[k]):
                        return True
                return False

            else:
                if c[1] not in cur.children:
                    return False
                cur = cur.children[c[1]]
        return cur.endOfWord

