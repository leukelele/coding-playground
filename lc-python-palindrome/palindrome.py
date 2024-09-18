class Solution(object):
    def isPalindrome(self, s):
        string = (''.join(i for i in s if i.isalnum())).lower()
        if (string == string[::-1]):
            return True
        else:
            return False

    ex1 = "A man, a plan, a canal: Panama"
    print(isPalindrome("example1", ex1))

    ex2 = "race a car"
    print(isPalindrome("example2", ex2))

    ex3 = " "
    print(isPalindrome("example3", ex3))
