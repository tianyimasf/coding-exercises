# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
#
# Score:
# Runtime: 32 ms, faster than 100.00% of Python online submissions for Add Two Numbers.
# Memory Usage: 13.8 MB, less than 6.29% of Python online submissions for Add Two Numbers.
class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        turn linked list into integers
        add integers
        turn integer into linked list
        """
        n1 = self.listToInt(l1)
        n2 = self.listToInt(l2)
        n = n1 + n2
        return self.intToList(n)
    
    def listToInt(self, l):
        intStr = str(l.val)
        while (l.next):
            l = l.next
            valStr = str(l.val) + intStr
            intStr = valStr
        return int(intStr)
    
    def intToList(self, n):
        intStr = str(n)
        l = ListNode(int(intStr[0]))
        for i in range(1, len(intStr)):
            lprev = ListNode(int(intStr[i]), l)
            l = lprev
        return l
        