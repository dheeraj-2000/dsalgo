'''
208. Implement Trie (Prefix Tree)
A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently store and retrieve keys in a dataset of strings. There are various applications of this data structure, such as autocomplete and spellchecker.

Implement the Trie class:

Trie() Initializes the trie object.
void insert(String word) Inserts the string word into the trie.
boolean search(String word) Returns true if the string word is in the trie (i.e., was inserted before), and false otherwise.
boolean startsWith(String prefix) Returns true if there is a previously inserted string word that has the prefix prefix, and false otherwise.


'''
from collections import defaultdict
class Trie:

    def __init__(self):
        self.child = defaultdict(Trie)
        self.isword = False
        

    def insert(self, word: str) -> None:
        curr = self
        for i in word:
            curr = curr.child[i]
            
        curr.isword = True
            
        

    def search(self, word: str) -> bool:
        curr = self
        for i in word:
            if i not in curr.child:
                return False
            curr = curr.child[i]
        return curr.isword
        

    def startsWith(self, prefix: str) -> bool:
        curr = self
        for i in prefix:
            if i not in curr.child:
                return False
            curr = curr.child[i]
        return True
            
            
        
        


# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)
