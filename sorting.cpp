#include<iostream>
using namespace std;

void swap(int &a,int &b){
    int temp = a;
    a=b;
    b=temp;
}

void bubble(int arr[] , int n){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n-i; j++)
        {
            if (arr[j]>arr[j+1])
            {
                swap(arr[j],arr[j+1]);
            }
            
        }
        
    }
    
}

int main( )
  {
    int n=11;
    int arr[11] = {3,6,8,5,2,6,8,1,2,4,7};
    bubble(arr ,n);
    for (auto i : arr)
    {
        cout<<i<<" ";
    }
    
return 0 ;
}