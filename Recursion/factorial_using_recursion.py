from tkinter import N


def factorial(n):
    if n >1 :
        return n* factorial(n-1)
    else:
        return 1

n = int(input("Enter a non-negative number: "))

result =  factorial(n)
print(f"Fctorial of {n} = {result}")