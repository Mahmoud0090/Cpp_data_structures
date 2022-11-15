#include <iostream>
#include <cassert>
using namespace std;


class Vector
{
private:
   int* arr = nullptr;
   int size {0};
   int capacity{};
   int idx = 0;
   
public:
   Vector(int size):size(size){
       if(size<0)
       size = 1;
       capacity = size + 10;
       
       arr = new int[capacity]{};
   }
   
   void push_back(int value)
   {
       if(size == capacity)
       expand_capacity();
       
       arr[idx] = value;
       idx++;
       
       if(idx > size)
       size++;
   }
   
   void Print_elements()
   {
       for(int i = 0 ; i<size;++i)
       {
           cout<<arr[i]<<endl;
       }
   }
   
   void Insert(int idx , int value)
   {
       assert(idx < size && idx>=0);
       
       if(size == capacity)
       expand_capacity();
       
       for(int p = size - 1 ; p>= idx ; p--)
       {
           arr[p+1] = arr[p];
       }
       
       arr[idx] = value;
       ++size;
   }
   
   void Delete(int idx)
   {
       if(idx>= size)
       {
          cout<<"idx out of range"<<endl;
          return;
       }
       
       for(int i = idx ; i<=size ; i++)
       {
           arr[i] = arr[i + 1];
       }
       --size;
   }
   
   void Right_Rotate(int times)
   {
       int* newArr = new int[size];
       int count = times;
       for(int i = 0 ; i<size ;i++)
       {
           if(count>= size)
           count = 0;
           
           newArr[count] = arr[i];
           count++;
       }
       
       swap(arr , newArr);
       
       delete newArr;
   }
   
private:  
   void expand_capacity()
   {
       capacity *= 2;
       cout<<"capacity expanded to "<< capacity<<endl;
       int* arr2 = new int[capacity]{};
       for(int i = 0 ; i<size ; ++i)
       {
           arr2[i] = arr[i];
       }
       
       swap(arr, arr2);
       
       delete [] arr2;
   }
   
};

int main()
{
    Vector v(4);
    
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);
    v.push_back(7);
    v.push_back(8);
    v.push_back(9);
    v.push_back(10);
    v.push_back(11);
    v.push_back(12);
    v.push_back(13);
    v.push_back(14);
    v.push_back(15);
    v.push_back(16);
    v.push_back(17);

    v.Insert(1 , 3);
    v.Insert(2 , 65);
    v.Print_elements();
    
    
    cout<<"________________"<<endl;
    
    
    v.Right_Rotate(6);
    v.Print_elements();
    
    cout<<"__________________"<<endl;
    
    v.Delete(2);
    v.Print_elements();
    
    return 0;
}