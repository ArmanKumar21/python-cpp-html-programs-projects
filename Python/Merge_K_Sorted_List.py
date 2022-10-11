# There are a bunch of different solutions for this problem, let us discuss solution, using heaps here. We need to iterate over k lists and on each step to choose the minimum element among k candidates, think of it as extention of classical merge stage in merge sort. If each time we find this minimum element, using lists, overall complexity will be O(nk), where n is total number of elements in all lists. However we can do better: we create heap with the following tuples as elements:

#     First value of tuple is our value of nodes, because we want to sort using these values
#     Second value of tuple is index in lists, form where we choose this element. Why we need this? Because when we will merge this element, we need to go to the next element in the corresponding list.

# Now, let us discuss main steps of algorithm:

#     Create dummy node in linked list, which will help us to deal with border cases, such as empty lists and so on.
#     curr is current element in linked list where are in now.
#     Put all starts of k linked lists to heap (actually there can be less than k, because some of lists can be empty)
#     Extract val, ind element from our heap: it will be current minumum element, and attach it to the end of constucted merged least so far, move curr iterator to the right.
#     If we still did not reach the end of current list, move one step to the right in this list and put new candidate to heap.
#     Return dummy.next.

# Complexity: time complexity is O(n log k), because we have O(n) steps, where we put and remove from heap, which have at most k elements. Space complexity is O(n): because we need to return newly constructed linked list.

class Solution:
    def mergeKLists(self, lists):
        dummy = curr = ListNode(0)
        heap = []
        for ind, el in enumerate(lists):
            if el: heappush(heap, (el.val, ind))
                
        while heap:
            val, ind = heappop(heap)
            curr.next = ListNode(val)
            curr = curr.next
            if lists[ind].next:
                lists[ind] = lists[ind].next
                heappush(heap, (lists[ind].val, ind))
                
        return dummy.next


