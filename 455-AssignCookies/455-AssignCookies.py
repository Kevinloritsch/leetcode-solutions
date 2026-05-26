# Last updated: 5/26/2026, 1:24:04 PM
1class Solution:
2    def findContentChildren(self, g: List[int], s: List[int]) -> int:
3        # smallest greed factor get satisfied first 
4        # sort s and g in increasing order 
5        g.sort()
6        s.sort()
7        l = 0
8        m = 0
9        while l < len(g) and m < len(s):
10            if s[m] >= g[l]:
11                l += 1
12            m += 1
13        return l