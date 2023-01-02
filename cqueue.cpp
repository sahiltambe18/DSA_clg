#include <iostream>
#define max 10
using namespace std;

class cqueue
{
    int arr[max];
    int f, r;

public:
    cqueue()
    {
        f = r = -1;
    }
    void enqueue(int k)
    {
        if (f == -1)
        {
            f = r = 0;
            arr[f] = k;
            return;
        }
        if ((r + 1) % max == f)
        {
            cout << "queue overflowed\n";
            return;
        }
        if (r == max - 1)
        {
            r = 0;
        }
        else
        {
            r++;
        }
        arr[r] = k;
    }

    void dequeue()
    {
        if (f == -1)
        {
            cout << "queue underflowed\n";
            return;
        }
        int k = arr[f];
        if (f == max - 1)
        {
            f = 0;
        }
        if (f == r)
        {
            f = r = -1;
        }
        else
        {
            f++;
        }
        cout << "removed : " << k << endl;
    }

    void display()
    {
        int front;
        front = f;
        if (f==-1)
        {
            cout<<"queue is empty\n";
            return;
        }
        cout<<"elements : ";
        if (front > r)
        {
            while (front < max)
            {
                cout << arr[front] << " ";
                front++;
            }
            front = 0;
            while (front <= r)
            {
                cout << arr[front] << " ";
                front++;
            }
        }
        else
        {
            while (front <= r)
            {
                cout << arr[front] << " ";
                front++;
            }
        }
        cout<<endl;
    }
};

int main()
{
    cqueue q;
    int ch = 1;
    while (ch!=0)
    {
        cout<<"enter choice \n1.enque \n2.dequeue \n3.display\n";
        cin>>ch;
        switch (ch)
        {
        case 1:{
            cout<<"enter element\n";
            int i;
            cin>>i;
            q.enqueue(i);   
            break;
        }
        case 2:{
            q.dequeue();
            break;
        }
        case 3:{
            q.display();
            break;
        }
        default:
            break;
        }
    }
    

    return 0;
}