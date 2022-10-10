    
#Function to check if brackets are balanced or not.
def ispar(self,x):
    stack = []
    dic = {'}':'{', ')':'(', ']':'[' }
    
    for brac in x:
        # push into stack if it is opening bracket.
        if brac in '[{(':
            stack.append(brac)
        # else if closing bracket, try to match it with top of stack
        # if they don't match, return False
        elif len(stack) == 0 or stack[-1] != dic.get(brac, ''):
            return False
        # if they do match simply pop from stack
        else:
            stack.pop()

    # if stack isn't empty then it had odd no. of brackets.    
    if stack:
        return False
    return True

if __name__ == '__main__':
    s = input().strip()
    if ispar(s):
        print("balanced")
    else:
        print("not balanced")