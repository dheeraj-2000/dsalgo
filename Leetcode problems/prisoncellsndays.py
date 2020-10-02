class Solution:
    def prisonAfterNDays(self, cells: List[int], N: int) -> List[int]:
        N = N % 14
        if N == 0:
            N = 14
        for i in range(N):
            cells = [0] + [cells[0] ^ cells[2] ^ 1] + [cells[1] ^ cells[3] ^ 1] + [cells[2] ^ cells[4] ^ 1] + [cells[3] ^ cells[5] ^ 1] + [cells[4] ^ cells[6] ^ 1] + [cells[5] ^ cells[7] ^ 1] + [0]
        return cells