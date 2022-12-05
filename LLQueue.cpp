#include <iostream>
#include <string>
#include <cassert>
using namespace std;

//this Queue is based on linkedList


struct Node
{
    int data;
    Node* next;
        
    Node(int data):data(data){};
};

class Queue
{
private:
    
    /*struct Node
    {
        int data;
        Node* next;
        
        Node(int data):data(data){};
    };*/
    
    Node* head;
    Node* tail;
    
    int size = 0;
    
public:

   //Queue()
   
   void enqueue(int value)
   {
       if(!head)
       {
           head = new Node(value);
           tail = head;
           tail->next = nullptr;
           size++;
           return;
       }
       
       Node* n = GetTail();
       
       n->next = new Node(value);
       
       tail = n->next;
       
       size++;
       
       tail->next = nullptr;
   }
   
   Node* GetTail()
   {
       Node* n = head;
       
       while(n->next != nullptr)
       {
           n = n->next;
       }
       return n;
   }
   
   int dequeue()
   {
       if(size == 1)
       {
           cout<<"there is only one Node is the head"<<endl;
           return 0;
       }
       Node* n = head;
       
       head = head->next;
       
       size--;
       
       return n->data;
   }
   
   int GetSize()
   {
       return size;
   }
   
   void display()
   {
       Node* n = head;
       
       while(n != nullptr)
       {
           cout<<n->data<<endl;
           n = n->next;
       }
   }
};
    
int main()
{
   Queue q;
   
   q.enqueue(10);
   q.enqueue(5);
   q.enqueue(8);
   q.enqueue(11);

   q.display();

   cout<<"+++++++++++++"<<endl;
   
   q.dequeue();
   q.display();
}