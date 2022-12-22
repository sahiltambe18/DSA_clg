#include <iostream>
#define max 10
using namespace std;

class cqueue
{
private:
    int arr[max];
    int f, r;

public:
    cqueue()
    {
        f = r = -1;
    }
    void push(int val)
    {
        if (f == -1)
        {
            f = r = 0;
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
        arr[r] = val;
    }
    void pop()
    {
        if (r == -1)
        {
            cout << "queue is empty\n";
            return ;
        }
        cout << arr[f] << " removed\n";
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
    }
    void display(){
        // int front = f;
        // if (r<front)
        // {
        //     while (front < max)
        //     {
        //         cout<<arr[front]<<" ";
        //         front++;
        //     }
        //     front = 0;
        //     while (front <= r)
        //     {
        //         cout<<arr[front]<<" ";
        //         front++;
        //     }
            
        // }
        // else{
        //     while (front <= r)
        //     {
        //         cout<<arr[front]<<" ";
        //     }
        //     cout<<endl;
            
        // }
        
        if (f == -1)
        {
            cout << "queue is empty" << endl;
            return;
        }
        cout << "elements of queue" << endl;
        int fr = f;
        if (fr <= r)
        {
            while (fr <= r)
            {
                cout << arr[fr] << " ";
                fr++;
            }
        }
        else
        {
            while (fr < max)
            {
                cout << arr[fr] << " ";
                fr++;
            }
            fr = 0;

            while (fr <= r)
            {
                cout << arr[fr] << " ";
                fr++;
            }
        }
        cout << endl;
    }
};

int main()
{
     int ch = 1;
    cqueue q;
    while (ch != 0)
    {
        cout << "enter choice" << endl;
        cout << "1.enque \n2.dequeue \n3.display \n 0 for exit";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "enter value\n";
            int val;
            cin >> val;
            q.push(val);
            break;
        case 2:
            q.pop();
            break;
        case 3:
            // q.displayCQ_forward();
            q.display();
            break;

        default:
            break;
        }
    }

    return 0;
}