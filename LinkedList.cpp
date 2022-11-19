#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int data):data(data){}
};

class LinkedList
{
private:
   Node* head { };
   Node* tail { };
   
public:
   ~LinkedList()
   {
       while(head)
       {
           Node* current = head->next;
           delete head;
           head = current;
       }
   }
   void print()
   {
       Node* tempHead = head;
       
       while(tempHead!= nullptr)
       {
           cout<<tempHead->data<<" ";
           
           tempHead = tempHead->next;
       }
       cout<<"\n";
   }
   
   void insert_end(int data)
   {
       Node* item = new Node(data);
       
       if(head == nullptr)
       {
           head = tail = item;
       }
       else
       {
           tail->next = item;
           tail = item;
       }
   }
   
   void insert_front(int data)
   {
       Node* item = new Node(data);
       
       if(head == nullptr)
       {
           head = tail = item;
       }
       else
       {
           item->next = head;
           head = item;
       }
   }
   
   void delete_front()
   {
       Node* n = head;
       if(head->next != nullptr)
       {
           head = head->next;
           delete n;
       }
   }
   
   int Get_length()
   {
       int length = 1;
       Node* n = head;
       
       while(n->next != nullptr)
       {
           n = n->next;
           length++;
       }
       
       return length; 
   }
   
   void delete_at_index(int idx)
   {
       if(Get_length() == 1)
       {
           cout<<"There is only one node, cannot be deleted"<<endl;
           return;
       }
       
       if(idx == 0)
       {
           delete_front();
       }
       else if(idx == Get_length() - 1)
       {
           Node* last = Get_nth(idx);
           tail = Get_nth(idx - 1);
           tail->next = nullptr;
           delete last;
       }
       else if(idx < Get_length() - 1 && idx > 0)
       {
           Node* curr = Get_nth(idx);
           Node* prev = Get_nth(idx - 1);
           Node* nextN = Get_nth(idx + 1);
           prev->next = nextN;
           delete curr;
       }
       else
       {
           cout<<"invalid index"<<endl;
       }
   }
   
   void delete_with_value(int value)
   {
       int idx = Search(value);
       delete_at_index(idx);
   }
   
   void Swap_pairs()
   {
       Node* n = head;
       while(n->next != nullptr)
       {
           int n_data = n->data;
           n->data = n->next->data;
           n->next->data = n_data;
           if(n->next->next != nullptr)
           n = n->next->next;
           
           else
           n = n->next;
       }
       cout<<"swap done"<<endl;
   }
   
   void Reverse()
   {
       
   }
   
   void delete_even_pos()
   {
       
   }
   
   void insert_sorted(int value)
   {
       
   }
   
   Node* Get_tail()
   {
       Node* node = head;
       while(node->next != nullptr)
       {
           node = node->next;
       }
       return node;
   }
   
   Node* Get_nth(int n)
   {
       int count = 0;
       
       Node* tempHead = head;
       
       while(tempHead != nullptr)
       {
           if(count == n)
           {
               return tempHead;
           }
           tempHead = tempHead->next;
           count++;
       }
       return nullptr;
   }
   
   int Search(int value)
   {
       int idx = 0;
       Node* tempHead = head;
       
       while(tempHead!=nullptr)
       {
           if(tempHead->data == value)
           {
               return idx;
           }
           tempHead = tempHead->next;
           idx++;
       }
       return -1;
   }
   
   int improved_Search(int value)
   {
       int idx = Search(value);
       if(idx == 0 || idx == -1)
       //Node* current = head;
       return idx;
       
       else if(idx == 1)
       {
           Node* current = Get_nth(idx);
           head->next = current->next;
           current->next = head;
           head = current;
           return 0;
       }
       
       Node* current = Get_nth(idx);
       Node* prevNode = Get_nth(idx - 1);
       Node* prevpNode = Get_nth(idx - 2);
       
       prevNode->next = current->next;
       current->next = prevNode;
       if(prevpNode != nullptr)
       prevpNode->next = current;
       
       return idx - 1;
   }
};

int main()
{
    LinkedList l;
    
    l.insert_end(3);
    l.insert_end(4);
    l.insert_end(5);
    l.insert_end(6);
    l.insert_end(7);
    l.insert_end(8);
    
    l.print();
    
    
    l.insert_end(6);
    l.print();
    
    /*l.delete_with_value(90);
    l.print();*/
    
    l.delete_with_value(6);
    l.print();
    
    l.Swap_pairs();
    l.print();
    
    l.delete_with_value(8);
    l.print();
    
    l.Swap_pairs();
    l.print();
    
}