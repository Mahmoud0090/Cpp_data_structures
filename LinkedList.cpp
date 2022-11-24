#include <iostream>
#include <vector>
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
   
   void Swap_head_and_tail_data()
   {
       Node* tail = Get_tail();
       int tail_data = tail->data;
       tail->data = head->data;
       head->data = tail_data;
   }
   
   void Remove_last_occurance(int key)
   {
       Node* n = head;
       int count = 0;
       int idx = -1;
       int lastKeyidx = 0;
       while(n != nullptr)
       {
           idx++;
           //cout<<idx<<endl;
           if(n->data == key)
           {
               count++;
               lastKeyidx = idx;
           }
           n = n->next;
       }
       
       /*Node* t = Get_tail();
       if (t->data == key)
       {
           lastKeyidx = Get_length() - 1;
       }*/
       if(count>1)
       {
           delete_at_index(lastKeyidx);
       }
   }
   
   int max()
   {
       int max = 0;
       Node* n = head;
       while(n->next != nullptr)
       {
           if(n->data >= max)
           {
               max = n->data;
           }
           n = n->next;
       }
       return max;
   }
   
   void Arrange_odd_even()
   {
       Node* n = head;
       head = head->next;
       Node* h = head;
       Node* hptr = nullptr;
       Node* nptr = nullptr;
       //cout<<h->data<<endl;
       //cout<<h->next<<endl;
       while(h != nullptr)
       {
           //cout<<h->data<<endl;
           
           if(h->next == nullptr)
           break;
           
           h->next = h->next->next;
           h = h->next->next;
           
           hptr = h;
           
       }
       
       hptr->next = n;
       
       cout<<"++++++++++++++"<<endl;
        while(n != nullptr)
       {
           //cout<<n->data<<endl;
           //if(n->next->next != nullptr)
           
           if(n->next == nullptr)
           break;
           
           n->next = n->next->next;
           n = n->next->next;
           
           
           nptr = n;
           /*if(n->next->next == nullptr)
           break;*/
       }
       nptr->next = nullptr;
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
    
    l.insert_end(4);
    l.insert_end(7);
    l.insert_end(7);
    l.insert_end(7);
    l.insert_end(10);
    l.insert_end(8);
    
    l.print();
    
    
    /*l.insert_end(6);
    l.print();*/
    
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
    
    l.insert_end(6);
    l.print();

    l.insert_end(13);
    l.print();
    
    l.insert_end(6);
    l.print();
    
    /*l.insert_front(6);
    l.print();*/
    
    l.insert_front(6);
    l.print();
    
    l.Remove_last_occurance(7);
    l.print();
    
    l.Remove_last_occurance(7);
    //l.print();
    
    l.Remove_last_occurance(6);
    l.print();
    
    l.Arrange_odd_even();
    l.print();
}