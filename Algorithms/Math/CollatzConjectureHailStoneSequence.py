
# collatz conjecture should not take in negative numbers


class NegativeNumberPassedError(Exception):
    """Raised when the input value is negative"""
    pass


def getNextCollatz(n):
    """
    The Hailstone sequence of numbers can be generated from a starting positive integer,   n   by:

      If   n   is     1     then the sequence ends.
      If   n   is   even then the next   n   of the sequence   = n/2
      If   n   is   odd   then the next   n   of the sequence   = (3 * n) + 1

    The (unproven) Collatz conjecture (https://en.wikipedia.org/wiki/Collatz_conjecture) is that the hailstone sequence for any starting number always terminates.

    The hailstone sequence is also known as   hailstone numbers   (because the values are usually subject to multiple descents and ascents like hailstones in a cloud).

    This sequence is also known as the Collatz sequence.

    It is currently proved that Collatz Conjecture for 2^100000-1 Is True. (https://ieeexplore.ieee.org/document/8560077)
    However there still doesn't exist a mathematical proof to this astonishing concept!


    """

    if n < 0:
        print("Please pass a positive number to the Collatz Conjecture!!")
        raise NegativeNumberPassedError

    elif n == 1:
        return "terminated"

    elif n % 2 == 0:
        return int(n/2)
    else:
        return 3*n+1


def getCollatzSequence(n0=100, max_iters=None):
    """
    Returns the complete collatz sequence as a list. 
    n0= initial value of the starting positive integer 
    max_iters = the maximum number of iterations through which the sequence will run through. If set to None, the sequence will terminate at 1.
    """
    count = 0
    returned = getNextCollatz(n0)
    sequence = [n0, returned]

    if (max_iters == None):
        while (returned != "terminated"):
            returned = getNextCollatz(returned)
            sequence.append(returned)

    else:
        while (count <= max_iters and returned != "terminated"):
            returned = getNextCollatz(returned)
            sequence.append(returned)
            count += 1

    return sequence

# Getting the outputs


help(getNextCollatz)
# getNextCollatz(-1) shows an error as programmed
seq = getCollatzSequence(n0=100, max_iters=None)
print(seq)

print(getCollatzSequence(n0=100, max_iters=5))
