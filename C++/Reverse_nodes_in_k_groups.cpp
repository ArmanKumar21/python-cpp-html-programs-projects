class Solution {
public:
    void reverse(ListNode* s,ListNode* e)
    {
        ListNode* prev=NULL;
        ListNode* n=s->next;
        ListNode* curr=s;
        while(prev!=e)
        {
            curr->next=prev;
            prev=curr;
            curr=n;
            if(n!=NULL)
            {
                n=n->next;
            }
        }
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL || head->next==NULL || k==1)
        {
            return head;
        }
        ListNode* dummynode=new ListNode(-1);
        dummynode->next=head;
        ListNode* beforestart=dummynode;
        ListNode* end=head;
        //start from ith index
        int i=0;
        while(end!=NULL)
        {
            i++;
            if(i%k==0)
            {
                ListNode* start=beforestart->next;
                ListNode* temp=end->next; //5
                reverse(start,end);
                beforestart->next=end;
                beforestart=start;
                start->next=temp;
                end=temp;
            }
            else
            {
                end=end->next;
            }
        }
        return dummynode->next;
    }
};