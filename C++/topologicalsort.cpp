#include <iostream>
using namespace std;
int n,visit[100],index=-1;

struct node;
struct edge;

struct node
{
    int info;
    int indeg;
    node *next;
    edge *adj;
} *front = NULL,*last = NULL;

struct edge
{
    node *dest;
    edge *link;
};

struct toposort
{
    int data;  
    toposort *next;
} ;

class topsort
{
    struct toposort *beg,*t,*end;
    public:
    topsort()
    {
        beg=NULL;
        end=NULL;
    }

    void insert_in_queue(int);
    void display_queue();
    void topological_sort();
}obj;

//Function to insert node
void insert()
{
    node *newnode = new node;
    if (newnode == NULL)
    {
        cout << "\n OVERFLOW";
        return;
    }
    cout << "\n DATA: ";
    cin >> newnode->info;
    newnode->indeg=0;
    newnode->next = NULL;
    newnode->adj = NULL;
    if (front == NULL)
    {
        front = newnode;
        last = newnode;
    }    
    else
    {
        last->next=newnode;
        last = newnode;
    }
}

//Function to return location of a item
node *search(int item)
{
    node *p;
    p = front;
    while (p != NULL)
    {
        if (p->info == item)
            return p;
        else
            p = p->next;
    }
    return NULL;
}

//Function to search and return prev node
node *search_prev(int item)
{
    node *p;
    p = front;
    while(p !=NULL)
    {
        if(p->next->info == item)
            return p;
        else
            p= p->next;    
    }
    return NULL;
}

//Function to insert edge
void edge_insert(int a, int b)
{
    node *loca, *locb;
    loca = search(a);
    locb = search(b);
    if (loca == NULL || locb == NULL)
    {
        cout << "\n EDGE NOT INSERTED!";
        return;
    }
    else
    {
        edge *p = new edge;
        p->dest = locb;
        p->link = loca->adj;
        loca->adj = p;
        locb->indeg = locb->indeg+1;
        cout << "\n EDGE INSERTED SUCCESSFULLY!";
    }
}

//Function to delete edge
void delete_edge(int a, int b)
{
    node *loca, *locb;
    loca = search(a);
    locb = search(b);
    if (loca == NULL || locb == NULL)
    {
        cout << "\n INCORRECT VERTICES \n";
        return;
    }
    edge *ptr = loca->adj;
    edge *save;
    while (ptr != NULL)
    {
        if (ptr->dest == locb && ptr == loca->adj)
        {
            loca->adj = loca->adj->link;
            return;
        }

        else if (ptr->dest == locb)
        {
            save->link = ptr->link;
            return;
        }
        else
        {
            save = ptr;
            ptr = ptr->link;
        }
    }
    cout << "\n NO EDGE AVAILABLE BETWEEN " << a <<" AND "<< b << "\n";
}

//Function to delete node
void del_node(int item)
{
    node* ptr;
    edge* p;
    ptr = search(item);
    if(ptr==NULL)
    {
        cout<<"NODE NOT FOUND";
    }

    p = ptr->adj;
    while (p != NULL)              //Reducing indegree related to the the deleted node
    {
        p->dest->indeg = p->dest->indeg - 1;
        p = p->link;
    }

    ptr=front;
    while(ptr!=NULL)               //Deleting edges contained in the node
    {
        p = ptr->adj;
        while(p!=NULL)
        {
            if(p->dest->info==item)
            {
                delete_edge(ptr->info,p->dest->info);
            }
            p = p->link;
        }
        ptr = ptr->next;
    }

    ptr = search(item);
    if(ptr == front)
    {
        front = front->next;
    }
    else
    {
        ptr = search_prev(item);      //Deleting Node
        if(ptr!=NULL)
        {
            ptr->next = ptr->next->next;
        }
    }
}
void display()
{
    node *ptr = front;
    edge *p;
    cout << "\n NODE LIST IS AS FOLLOWS: \n ";
    while (ptr != NULL)
    {
        cout << ptr->info;
        if (ptr->next != NULL)
            cout << "->";
        ptr = ptr->next;
    }
    ptr = front;
    cout << "\n\n GRAPH IS AS FOLLOWS: \n";
    while (ptr != NULL)
    {
        p = ptr->adj;
        
        cout << ptr->info << "->";

        if(p==NULL)
        {
            cout<<"";
        }
        else
        {
            while (p != NULL)
            {
                cout << p->dest->info;
                cout<< " ";
                p = p->link;
            }
        }
        cout<<"\nINDEGREE OF "<< ptr->info <<" : "<<ptr->indeg;
        cout<<"\n";
        ptr = ptr->next;
    }
}

void topsort::insert_in_queue(int item)
{
    toposort *temp = new toposort;
    temp->data = item;
    temp->next = NULL;
            
    if( beg == NULL)
    {
        beg = temp;
        end = temp;
    }
    else
    {
        end->next=temp;
        end=temp;
    }
}

void topsort::display_queue()
{
    t = beg;
    cout<<"\n TOPOLOGICAL SORT: ";
    while(t!=NULL)
    {
        cout<<t->data<<" ";
        t = t->next;
    }
}

int visited(int item)
{
    int flag = 0;
    for(int i=0;i<=index;i++)
    {
        if(visit[i]==item)
        {
            flag=1;
            break;
        }
    }

    return flag;

}

void topsort::topological_sort()
{
    node *ptr;
    edge *p;
    ptr=front;

    if(front == NULL)
    {
        return;
    }
    while(ptr!=NULL)
    {
        if(ptr->indeg==0)
        {
            insert_in_queue(ptr->info);
            index++;
        }
        ptr = ptr->next;
    }
    t = beg;
    int i=0;
    while(t!=NULL)
    {
        if(!visited(t->data))
        {
            visit[i]=t->data;
            del_node(t->data);
        }   
        i++;
        t = t->next; 
    }
    topological_sort();

}


int main()
{
    int i;
    int a, b;
    char reply;
    cout << "\n ENTER NUMBER OF NODES: ";
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cout << "\n NODE " << i + 1;
        insert();
    }
    do
    {
        cout << "\n ENTER PAIR OF VERTEX BETWEEN WHICH YOU WANT TO INSERT EDGE:";
        cout << "\n V(FROM):";
        cin>>a;
        cout << "\n V(DEST):";
        cin>>b; 
        edge_insert(a, b);
        cout << "\n INSERT ANOTHER EDGE(Y/N): ";
        cin >> reply;
        if (reply == 'N'||reply == 'n')
            break;
    } while (1);
    display();

    obj.topological_sort();
    obj.display_queue();
    
    return 0;
}