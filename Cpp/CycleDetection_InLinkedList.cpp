#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// ! Definition for a node of linked list
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

// ! Definition for a linked list
class LinkedList
{
public:
    Node *head;
    LinkedList()
    {
        this->head = NULL;
    }
    void insert(int data)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            return;
        }
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    void print()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    void isCycle()
    {
        Node *slow = head;
        Node *fast = head;
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                cout << "Cycle is present" << endl;
                return;
            }
        }
        cout << "Cycle is not present" << endl;
    }
};

int main()
{
    // ! let's first create a linked linked list.
    LinkedList *list = new LinkedList();
    list->insert(1);
    list->insert(2);
    list->insert(3);
    list->insert(4);
    list->insert(5);
    list->insert(6);
    list->insert(7);

    // printing the list before adding a cyle
    cout << "Linked list before adding a cycle" << endl;
    list->print();
    // adding a cycle in the linked list for testing purpose.
    // ! for now the linked list is something like below
    // 1-> 2-> 3-> 4-> 5-> 6-> 7-> 4 -> 5 -> 6-> 7-> 4 and so on.. beccause of the cycle.
    list->head->next->next->next->next->next->next->next = list->head->next->next->next;

    // now we call Floyd Marshal's cycle finding algorithm to find the cycle in the linked list.
    list->isCycle();
    return 0;
}

// HOW THE ALGO WORKS
// Basically we have a slow pointer that moves one step at a time and a fast pointer that moves two steps at a time.
// If there exists a cycle then there is a guarantee that the slow pointer and the fast pointer will meet at some point.
// If they meet then exit the loop and return true.
// Else if one of them becomes null then return false. 