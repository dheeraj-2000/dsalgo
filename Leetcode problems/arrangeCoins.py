import math

class Solution:
    def arrangeCoins(self, n: int) -> int:
        trow = (-1 + int(math.sqrt(1 + 4*(2*n)))) / 2
        return int(trow)

def main():
    print(Solution().arrangeCoins(5))
    print(Solution().arrangeCoins(8))

if __name__ == '__main__':
    main()
