/* 
Problem:
You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.

Example 1:

Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]

Example 2:

Input: list1 = [], list2 = []
Output: [ ]

Example 3:
Input: list1 = [], list2 = [0]
Output: [0]

Constraints:
The number of nodes in both lists is in the range [0, 50].
-100 <= Node.val <= 100
Both list1 and list2 are sorted in non-decreasing order.

Solution:
The strategy here uses a temporary dummy node as the start of the result list. The pointer Tail always points to the last node in the result list, so appending new nodes is easy. 

The dummy node gives the tail something to point to initially when the result list is empty. This dummy node is efficient, since it is only temporary, and it is allocated in the stack. The loop proceeds, removing one node from either ‘a’ or ‘b’, and adding it to the tail. When 

We are done, the result is in dummy.next. 

Complexity Analysis:
Time complexity : O(n + m)O(n+m) because exactly one of l1 and l2 is incremented on each loop iteration. Because the while loop is traversed at most once, the time complexity is linear in the combined size of the lists.
Space complexity : O(1)O(1) The iterative approach only allocates a few pointers, so it has a constant overall memory footprint.

*/
/* Link list node */
class Node
{
	public:
	int data;
	Node* next;
};

/* pull off the front node of
the source and put it in dest */
void MoveNode(Node** destRef, Node** sourceRef);

/* Takes two lists sorted in increasing
order, and splices their nodes together
to make one big sorted list which
is returned. */
Node* SortedMerge(Node* a, Node* b)
{
	/* a dummy first node to hang the result on */
	Node dummy;

	/* tail points to the last result node */
	Node* tail = &dummy;

	/* so tail->next is the place to
	add new nodes to the result. */
	dummy.next = NULL;
	while (1)
	{
		if (a == NULL)
		{
			/* if either list runs out, use the
			other list */
			tail->next = b;
			break;
		}
		else if (b == NULL)
		{
			tail->next = a;
			break;
		}
		if (a->data <= b->data)
			MoveNode(&(tail->next), &a);
		else
			MoveNode(&(tail->next), &b);

		tail = tail->next;
	}
	return(dummy.next);
}

/* UTILITY FUNCTIONS */
/* MoveNode() function takes the
node from the front of the source,
and move it to the front of the dest.
It is an error to call this with the
source list empty.

Before calling MoveNode():
source == {1, 2, 3}
dest == {1, 2, 3}

After calling MoveNode():
source == {2, 3}
dest == {1, 1, 2, 3} */
void MoveNode(Node** destRef, Node** sourceRef)
{
	/* the front source node */
	Node* newNode = *sourceRef;
	assert(newNode != NULL);

	/* Advance the source pointer */
	*sourceRef = newNode->next;

	/* Link the old dest off the new node */
	newNode->next = *destRef;

	/* Move dest to point to the new node */
	*destRef = newNode;
}


/* Function to insert a node at
the beginning of the linked list */
void push(Node** head_ref, int new_data)
{
	/* allocate node */
	Node* new_node = new Node();

	/* put in the data */
	new_node->data = new_data;

	/* link the old list off the new node */
	new_node->next = (*head_ref);

	/* move the head to point to the new node */
	(*head_ref) = new_node;
}

/* Function to print nodes in a given linked list */
void printList(Node *node)
{
	while (node!=NULL)
	{
		cout<<node->data<<" ";
		node = node->next;
	}
}

/* Driver code*/
int main()
{
	/* Start with the empty list */
    Node* res = NULL;
    Node* a = NULL;
    Node* b = NULL;
    int N,M;
    cout<<"Enter the number of elements in the first list: ";
    cin>>N;
    cout<<"Enter the number of elements in the second list: ";
    cin>>M;
    cout<<"Enter the elements of the first list: ";
    while(N--){
        int x;
        cout<<"Enter the element: ";
        cin>>x;
        push(&a, x);
    }
    cout<<"Enter the elements of the second list: ";
    while(M--){
        int x;
        cout<<"Enter the element: ";
        cin>>x;
        push(&b, x);
    }
    res = SortedMerge(a, b);
    cout<<"Merged Linked List is: ";
    printList(res);
	return 0;
}
