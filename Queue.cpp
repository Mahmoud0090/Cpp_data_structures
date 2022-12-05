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
    
    void enqueue(int value)
    {
       assert(!isFull());
       array[rear] = value;
       rear = next(rear);
       added_element++;
    }
    
    int dequque()
    {
        assert(!isEmpty());
        int value = array[front];
        front = next(front);
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
   Queue q(10);
   
   q.enqueue(4);
   q.enqueue(5);
   
   q.display();
   
   q.enqueue(6);
   q.enqueue(7);
   
   q.display();
}
