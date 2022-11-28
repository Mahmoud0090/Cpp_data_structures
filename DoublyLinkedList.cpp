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
       /*else if(value >= tail->data)
       {
           insert_End(value);
       }*/
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
       if(length <= 1)
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
       //Node* n = head;
       
       if(length <= 1)
       return;
       
       if(head->data == value)
       delete_front();
       
       for(Node* curr = head; curr ; curr = curr->next)
       {
           if(curr->data == value)
           {
               curr = delete_and_link(curr);
               if(curr->next == nullptr)
               tail = curr;
           }
       }
   }
   
   void delete_even_pos()
   {
       if(length<=1)
       return;
       
       Node* n = head;
       
       while(n != nullptr)
       {
           if(n->next)
           {
              Node* t = n->next;
              if(n->next->next)
              n = n->next->next;
              
              delete_and_link(t);
              
              //delete_and_link(t);
           }
           
           else
           break;
       }
   }
   
   bool is_palindrome()
   {
       Node* t = Get_tail();
       Node* n = head;
       
       int len = GetLength()/2;
       
       while(len--)
       {
           if(t->data != n->data)
           return false;
           
           t = t->prev;
           n = n->next;
       }
       return true;
   }
   
   Node* Get_tail()
   {
       Node* n = head;
       
       while(n != nullptr)
       {
           if(n->next == nullptr)
           break;
           
           n = n->next;
       }
       return n;
   }
   
   int* find_middle()
   {
       int len = GetLength();
       int *x = new int[2];
       
       if(len%2!=0)
       {
          Node* n = Getnth_node_from_head(len/2 + 1);
          x[0] = n->data;
       }
       
       else
       {
           Node* n = Getnth_node_from_head(len/2);
           x[0] = n->data;
           x[1] = n->next->data;
       }
       
       return x;
   }
   
   void swap_forward_with_backword(int k)
   {
      int len = GetLength();
      
      if(k>len)
      return;
       
      if(len%2 != 0)
      {
          if(k == (len/2) + 1)
          return;
      }
      
      if(k==1)
      {
        swap_head_tail();
        return;
      }
      
      Node* nthfromHead = Getnth_node_from_head(k);
        
      Node* nthfromtail = Getnth_node_from_tail(k);
      
      if(k == len/2 && len%2 == 0)
      {
        swap_adjacent_nodes(nthfromHead , nthfromtail);   
      }
      
      else
      {
        swap_two_nodes_in_middle(nthfromHead , nthfromtail);
      }
   }
   
   void swap_adjacent_nodes(Node* n1 , Node* n2)
   {
      n1->next = n2->next;
      n2->next->prev = n1;
      n2->next = n1;
      n2->prev = n1->prev;
      n1->prev->next = n2;
      n1->prev = n2;
   }
   
   void swap_two_nodes_in_middle(Node* n1 , Node* n2)
   {
       if(n1 == head || n1 == tail || n2 == head || n2 == tail)
       return;
       
       Node* tempnext = n1->next;
       Node* tempprev = n1->prev;
       
       n1->next = n2->next;
       n2->next->prev = n1;
       n2->prev->next = n1;
       n1->prev = n2->prev;
       
       
       n2->next = tempnext;
       tempnext->prev = n2;
       tempprev->next = n2;
       n2->prev = tempprev;
   }
   
   void swap_head_tail()
   {
      Node* n = head;
       
      
      head->prev = tail->prev;
      tail->prev->next = head;
      
      tail->next = head->next;
      head->next->prev = tail;
      
      
      tail->prev = nullptr;
      head->next = nullptr;
      
      head = tail;
      tail = n;
       //cout<<t->data<<endl;
       //cout<<n->data<<endl;
   }
   
   Node* Getnth_node_from_tail(int k)
   {
       Node* n = Get_tail();
       
       while(k>1)
       {
           if(n->prev)
           {
               n = n->prev;
               k--;
           }
           else
           break;
       }
       return n;
   }
   
   Node* Getnth_node_from_head(int k)
   {
       Node* n = head;
       
       while(k > 1)
       {
           if(n->next)
           {
             n = n->next;
             k--;
           }
           
           else
           break;
       }
       
       return n;
   }
   void Reverse()
   {
       
   }
   
};

int main()
{
    DoublyLinkedList dl;
    
    //dl.insert_Front(15515);
    
    dl.insert_End(7);
    dl.insert_End(8);
    //dl.insert_End(5);
    dl.insert_End(14);
    //dl.insert_End(5);
    dl.insert_End(29);
    dl.insert_Front(2);
    //dl.insert_Sorted(9);*/
    
    dl.Print();
    
    cout<<"______________"<<endl;
    
    
    //dl.delete_all_nodes_with_key(8);
    //dl.Print();
    
    /*dl.delete_even_pos();
    dl.Print();*/
    
    dl.swap_forward_with_backword(2);
    dl.Print();
    
    //int* x = dl.find_middle();
    //cout<<x[0]<<endl;
    //cout<<x[1]<<endl;
}

