#include<iostream>
using namespace std;

template<class T>
 struct node{
    T data;
    node* next;
    node(T val){
        data = val;
        next = NULL;
    }
};

template<class T>
class stack{
    node*<T> top;
    public:
    void push(T val){
        node*n = new node(val);

        
    }    
};

int main( )
  {

return 0 ;
}