# Last updated: 5/26/2026, 1:38:24 PM
1class Solution:
2    def isPalindrome(self, x: int) -> bool:
3        # left and right pointer 
4        # when left = right and so far, word has been equal, then length is odd and word is palindrome
5        # if length is even, left will never = right
6        strx = str(x)
7
8        left = 0 
9        right = len(strx)-1
10        while left <= right:
11            if strx[left] != strx[right]:
12                return False
13            left += 1
14            right -= 1
15        
16        return True
17
18        