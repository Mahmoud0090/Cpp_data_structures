#include <iostream>
#include <string>
#include <cassert>
using namespace std;

//this Queue is based on circular array

class Queue
{
    int size {0};
    int front {0};
    int rear {0};
    int added_element {0};
    int* array {};

public:

    Queue(int s)
    {
        size = s;
        array = new int[size];
    }
    
    int next(int pos)
    {
        //the below commented line be used instead of below lines
        //return (pos + 1) % size;
        //below lines are more faster than modules operator so used in industry
        ++pos;
        if(pos == size)
        pos = 0;
        
        return pos;
    }
    
    int prev(int pos)
    {
        --pos;
        if(pos < 0)
        pos = size - 1;
        
        return pos;
    }
    
    void enqueue_rear(int value)
    {
       assert(!isFull());
       array[rear] = value;
       rear = next(rear);
       added_element++;
    }
    
    void enqueue_front(int value)
    {
       assert(!isFull());
       front = prev(front);
       array[front] = value;
       added_element++;
    }
    
    int dequque_front()
    {
        assert(!isEmpty());
        int value = array[front];
        front = next(front);
        --added_element;
        return value;
    }
    
    int dequeue_rear()
    {
        assert(!isEmpty());
        rear = prev(rear);
        int value = array[rear];
        --added_element;
        return value;
    }
    
    bool isFull()
    {
        return added_element == size;
    }
    
    bool isEmpty()
    {
        return added_element == 0;
    }
    
    void display()
    {
        cout<<"front : "<<front<<" rear : "<<rear<<endl;
        if(isFull())
        cout<<"is full"<<endl;
        
        else if(isEmpty())
        {
            cout<<"is empty"<<endl;
            return;
        }
        
        for(int curr = front , step = 0 ; step<added_element ; ++step , curr = next(curr))
        {
            cout<<array[curr]<<" ";
        }
        cout<<"\n\n";
    }
    
};

int main()
{
   Queue q(4);
   
   /*q.enqueue_rear(4);
   q.enqueue_rear(5);
   
   q.display();
   
   q.enqueue_rear(6);
   q.enqueue_rear(7);
   
   q.display();
   
   q.dequque_front();
   q.display();*/
   
   q.enqueue_front(9);
   q.display();
   
   q.enqueue_front(3);
   q.display();
   
   q.enqueue_front(6);
   q.display();
   
   q.enqueue_front(8);
   q.display();
   
   q.dequeue_rear();
   
   q.display();
}