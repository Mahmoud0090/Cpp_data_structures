#include <iostream>
#include <string>
using namespace std;

//linkedList based stack

class Stack
{
private:
    struct Node
    {
      int data {};
      Node* next {};
      
      Node(int data):data(data){}
    };
    
    Node* head{};

public:
    
    // the new node will be always the head so that we can retrieve it easily "LIFO" 
    void push(int value)
    {
       Node* newNode = new Node(value);
       newNode->next = head;
       head = newNode;
    }
    
    void pop()
    {
        Node* n = head;
        
        if(head->next == nullptr)
        return;
        
        head = head->next;
        
        delete n;
    }
    
    int peek()
    {
        return head->data;
    }
    
    void Print()
    {
        Node* n = head;
        
        while(n != nullptr)
        {
            cout<<n->data<<endl;
            n = n->next;
        }
    }
    
    void Reverse()
    {
       //Node* n = head;
       Node* temp = head->next;
       Node* l = nullptr;
       
       head->next = l;
       
       while(temp != nullptr)
       {
           l = head;

           head = temp;
           
           temp = temp->next;

           head->next = l;
       }
    }
    
    void delete_middle()
    {
        
    }
};

int main()
{
   Stack s;
   
   s.push(1);
   s.push(2);
   s.push(3);
   s.push(4);
   s.push(5);
   s.push(6);
   s.push(7);
   s.push(8);
   s.push(9);
   s.push(10);
   s.push(11);
   s.push(12);
   s.push(13);
   s.push(14);
   
   s.Print();
   
   //s.Reverse();
   
   cout<<"__________________"<<endl;
   
   s.Reverse();
   
   s.Print();
   
}