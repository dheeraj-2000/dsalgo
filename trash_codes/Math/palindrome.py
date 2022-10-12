"""
    A palindrome is a word, number, phrase, or other sequence of symbols that reads the same backwards as forwards.
    Example:  madam or racecar
"""


def palindrome_checker(user_input):
    user_string = list(user_input)
    string_len = len(user_string)
    flag = False
    for i in range(string_len//2):
        if(user_string[i]==user_string[string_len-1-i]):
            flag = True
        elif(user_string==''):
            flag = False
        else:
            flag = False
    if flag:
        print("It's a palindrome")
    else:
        print("It's not a palindrome")


palindrome_word = input("Enter the word: ")
palindrome_checker(palindrome_word)
