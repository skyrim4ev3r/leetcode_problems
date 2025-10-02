class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        res_dummy = ListNode(0)
        res_prev = res_dummy

        offset = 0
        while True:

            num1 = 0
            if l1 != None:
                num1 = l1.val
                l1 = l1.next

            num2 = 0
            if l2 != None:
                num2 = l2.val
                l2 = l2.next

            num_res = num1 + num2 + offset
            offset = 0
            if num_res >= 10:
                offset = 1
                num_res -= 10

            new_node = ListNode(num_res)
            res_prev.next = new_node
            res_prev = new_node

            if l1 == None and l2 == None:
                if offset > 0:
                    new_node = ListNode(offset)
                    res_prev.next = new_node

                break
        
        res_head = res_dummy.next
        res_dummy.next = None
        return res_head
