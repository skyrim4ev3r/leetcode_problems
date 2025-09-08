class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        n1, n2, n3, res = [], [], [], None
        while l1 != None:
            n1.append(l1.val)
            l1 = l1.next
        while l2 != None:
            n2.append(l2.val)
            l2 = l2.next
        i, j, ofs = 0, 0, 0
        while True:
            tmp = n1[i] + n2[j] + ofs
            ofs = 0
            if tmp > 9:
                tmp -= 10
                ofs = 1
            n3.append(tmp)
            if i==len(n1) -1 and j== len(n2) -1:
                if ofs > 0:
                    n3.append(ofs)
                break
            if i < len(n1) -1:
                i += 1
            else:
                n1[i] = 0
            if j < len(n2) -1:
                j += 1
            else:
                n2[j] = 0
        for num in reversed(n3):
            res = ListNode(num, res)
        return res
