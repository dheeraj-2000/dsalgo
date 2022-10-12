"""
    An anagram is a word or phrase formed by rearranging the letters of a different word or phrase,
    typically using all the original letters exactly once.
    Example: listen - silent
"""

def anagram(input_1, input_2):
    str_1 = list(input_1.lower())
    str_2 = list(input_2.lower())
    if len(str_1) == len(str_2):
        for i in range(len(str_1)):
            for j in range(len(str_2)):
                if str_1[i]==str_2[j]:
                    str_1[i] = ''
                    str_2[j] = ''
                else:
                    continue
        join_1 = ''.join(str_1)
        join_2 = ''.join(str_2)
        if(len(join_1)==len(join_2)==0):
            print("It's an anagram --> ", input_1, "-", input_2)
        else:
            print("It's not an anagram --> ", join_1, "-", join_2)
    else:
        print("Not an Anagram")


word_1 = input("Enter the first word: ")
word_2 = input("Enter the second word: ")
anagram(word_1, word_2)

# anagram("Listen", "Silent")
# anagram("ded", "not")
