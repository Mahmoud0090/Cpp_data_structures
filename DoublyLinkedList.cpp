#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* next;
    Node* prev;
    
    Node(int data):data(data){};
};

class DoublyLinkedList
{
private:
   Node* head;
   Node* tail;
   int length = 0;
   
public:
   void Print()
   {
       Node* n = head;
       
       while(n != nullptr)
       {
           cout<<n->data<<endl;
           n = n->next;
       }
   }

   int GetLength()
   {
       return length;
   }
 
   void insert_End(int value)
   {
       Node* newNode = new Node(value);
       
       if(!head)
       {
           head = tail = newNode;
       }
       
       else
       {
           Link(tail , newNode);
           tail = newNode;
       }
       
       length++;
   }
   
   void insert_Front(int value)
   {
       Node* newNode = new Node(value);
       
       if(!head)
       {
           head = tail = newNode;
       }
       else
       {
           Link(newNode , head);
           head = newNode;
       }
       
       length++;
   }
   
   void Link(Node* first , Node* second)
   {
       if(first)
       {
           first->next = second;
       }
       if(second)
       {
           second->prev = first;
       }
   }
   
   void insert_Sorted(int value)
   {
       if(head != nullptr && value<= head->data)
       {
           insert_Front(value);
       }
       else if(value >= tail->data)
       {
           insert_End(value);
       }
       else
       {
           for(Node* curr = head ; curr ; curr = curr->next)
           {
               if(value <= curr->data)
               {
                   Node* n = new Node(value);
                   curr->prev->next = n;
                   n->prev = curr->prev;
                   n->next = curr;
                   curr->prev = n;
                   
                   break;
               }
           }
       }
       
       length++;
   }
   
   void delete_front()
   {
       if(!head || length == 1)
       {
           return;
       }
       
       Node* n = head;
       
       head = head->next;
       
       delete(n);
       
       length--;
   }
   
   void delete_end()
   {
       if(length == 1)
       {
           return;
       }
       
       Node* n = tail->prev;
       delete(tail);
       tail = n;
       tail->next = nullptr;
       
       length--;
   }
   
   Node* delete_and_link(Node* curr)
   {
       Node* ret = curr->prev;
       
       Link(curr->prev , curr->next);
       
       delete(curr);
       
       length--;
       
       return ret;
   }
   
   void delete_node_with_key(int value)
   {
       if(length == 0)
       return;
       
       if(value == head->data)
         delete_front();

       
       else
       {
           for(Node* curr = head ; curr ; curr = curr->next)
           {
               if(value == curr->data)
               {
                   curr = delete_and_link(curr);
                   if(curr->next == nullptr)
                       tail = curr;
                   break;    
               }
           }
       }
   }
   
   void delete_all_nodes_with_key(int value)
   {
       
   }
   
};

int main()
{
    DoublyLinkedList dl;
    
    dl.insert_Front(5);
    
    dl.insert_End(8);
    dl.insert_End(10);
    dl.insert_End(12);
    dl.insert_End(14);
    dl.insert_End(16);
    dl.insert_End(20);
    
    dl.insert_Sorted(9);
    
    int l = dl.GetLength();
    
    cout<<l<<endl;
    
    cout<<")))((((((((((("<<endl;
    
    dl.Print();
    
    dl.delete_front();
    cout<<")))((((((((((("<<endl;
    dl.Print();
    
    dl.delete_front();
    cout<<")))((((((((((("<<endl;
    dl.Print();
    
    dl.delete_end();
    cout<<")))((((((((((("<<endl;
    dl.Print();
    
    cout<<"OOOOOOOOOOOOOOOOOO"<<endl;
    
    dl.delete_node_with_key(9);
    dl.Print();
    
    int y = dl.GetLength();
    cout<<y<<endl;
}