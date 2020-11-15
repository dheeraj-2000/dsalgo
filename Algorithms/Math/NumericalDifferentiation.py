from math import sin


def differentiate(f, a, h=1e-6):
    """
    Returns a derivative of the passed function f(x) at a given value a using the concept of Right Hand and Left Hand derivative approximation.

    f = univariate function f(x) 
    a = value at which derivative should be calculated f'(x=a)
    h = the tolerance h, which is a value very close to zero but not zero.

    For more details view :
    http://archives.math.utk.edu/visual.calculus/2/definition.12/#:~:text=A%20function%20f%20is%20differentiable,of%20these%20derivatives%20are%20equal.
    https://stackoverflow.com/questions/12915317/how-to-find-derivative-of-a-function-using-c/59128217#59128217
    https://i.stack.imgur.com/3NG5q.jpg

    """

    return (f(a+h)-f(a-h))/(2*h)

# test for self created functions

# simple functions


def linear(x):
    return 2*x+1
    #derivative is 2


print(differentiate(linear, 2))
# 2.000000000279556

print(differentiate(linear, 100))
# 1.9999999949504854


def quadratic(x):
    return x**2+4*x+24
    #derivative is 2*x+4


print(differentiate(quadratic, 6))
# derivative is 2*x+4 = 2*6+4 = 16
# 16.000000002236447


def complicated(x):
    return 89*x**5 + 44*x**3+x


print(differentiate(complicated, 0))
#derivative is 1
# 1.000000000044


def trigonometricsine(x):
    return sin(x)


print(differentiate(trigonometricsine, 0))
#derivative is 1
# 0.9999999999998334

# Hence it can differentiate any simple function very easily
