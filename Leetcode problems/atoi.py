class Solution:
    def myAtoi(self, s: str) -> int:
        s = s.strip()
        res = 0
        sign = '+'
        length = len(s)
        if length == 0:
            return 0
        if s[0] == '+' or s[0] == '-':
            sign = s[0]
            s = s[1:]
            length -= 1
        i = 0
        while i < length:
            if s[i].isdigit():
                res = res*10 + int(s[i])
            else:
                break
            i += 1
        if sign == '-':
            res = -res
            if res < -2147483648:
                res = -2147483648
        elif res > 2147483647:
            res = 2147483647
        return res
