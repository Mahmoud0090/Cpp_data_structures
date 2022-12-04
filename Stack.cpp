#include <iostream>
#include <assert.h>
#include <string>
#include <cstring>
using namespace std;

// array based stack
class Stack
{
private:
   int size {};
   int top {}; //index of last element entered
   int* array {};
   
public:
   Stack(int size): size(size), top(-1){
       array = new int[size];
   }
   
   //push func with static array "size fixed"  
   
   /*bool push(int value)
   {
       if(Isfull()) // 
       return false;
       
       array[++top] = value;
       return true;
   }*/
   
   
   // push func with dynamic array "expanding as needed"
   void push(int value)
   {
       if(Isfull())
       expand_array_size();
       
       array[++top] = value;
   }
   
   int pop()
   {   
       assert(!Isempty());
       
       return array[top--];
   }
   
   int peek()
   {
       assert(!Isempty());
       return array[top];
   }
   
   int Isfull()
   {
       return top == size - 1;  
   }
   
   int Isempty()
   {
       return top == -1;
   }
   
   void display()
   {
       for(int i = top ; i>= 0 ; i--)
       {
           cout<<array[i]<<endl;
       }
   }
   
   void String_display()
   {  
       
      for(int i = top ; i>= 0 ; i--)
       {
           cout<<(char)array[i]<<endl;
       } 
   }
   
   void insert_at_bottom(int value)
   {
       assert(!Isfull());
       
       int idx = top + 1;
       array[idx] = array[top];
       top++;
       while(idx>0)
       {
           array[idx] = array[idx - 1];
           --idx;
       }
       
       array[0] = value;
   }
   
   void Reverse()
   {
       int idx = 0;
       for(int i = top  ; i> top/2 ; i--)
       {
           int temp = array[i]; 
           array[i] = array[idx];
           array[idx] = temp;
           idx++;
       }
   }
   
private:
   void expand_array_size()
   {
       size = size* 2;
       
       int* newArray = new int[size];
       
       for(int i = 0 ; i<size ; ++i)
       {
           newArray[i] = array[i];
       }
      
       swap(array, newArray);
       
       delete [] newArray;
   }
};

string reverse_subwords(string line)
{
    Stack s(line.size());
    for(int i = 0 ;i<line.size();i++)
    {
        s.push(line[i]);
    }
    
    for(int i = 0 ;i<line.size();i++)
    {
        line[i] = s.pop();
    }
    return line;
}

int reverse_num(int num)
{
  string s = reverse_subwords(to_string(num));
  
  int t = stoi(s);
  
  return t;
}


//this func works only with like this kind of parentheses {{()}} but not with ones like {}(){}[]
bool is_valid_parentheses(string paren)
{
    if(paren.size()%2 != 0)
    return false;
    
    if(paren[0] != '{' && paren[0] != '(' && paren[0] != '[')
    {
        return false;
    }
    
    Stack s(paren.size());
    
    int* firstHalf = new int[paren.size()/2];
    int* secondHalf = new int[paren.size()/2];
    
    for(int i = 0 ; i < paren.size(); i++)
    {
        s.push(paren[i]);
    }
    
    for(int i = 0 ; i< paren.size()/2 ; i++)
    {
        secondHalf[i] = s.pop();
    }
    
    for(int i = 0 ; i< paren.size()/2 ; i++)
    {
        firstHalf[i] = paren[i];
    }
    
    for(int i = 0 ; i< paren.size()/2 ; i++)
    {
        if((string() + (char)firstHalf[i] + (char)secondHalf[i]) != "()" && (string() + (char)firstHalf[i] + (char)secondHalf[i]) != "{}" && (string() + (char)firstHalf[i] + (char)secondHalf[i]) != "[]")
        return false;
    }
    
    return true;
}

int main()
{
   Stack s(2);
   
   s.push(5);
   //s.push(6);
   s.push(7);
   s.push(8);
   s.push(55);
   s.push(56);
   //s.insert_at_bottom(2);
   //s.insert_at_bottom(1);
   
   s.pop();
   
   s.display();
   
   cout<<"____________"<<endl;
   
   s.Reverse();
   
   s.display();
}

