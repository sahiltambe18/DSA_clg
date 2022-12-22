#include <iostream>
using namespace std;

struct node
{
    char data;
    node *next;
    node(char val)
    {
        data = val;
        next = NULL;
    }
};
class stack
{
private:
    node *top;

public:
    stack()
    {
        top = NULL;
    }
    void push(char val)
    {
        node *n = new node(val);
        n->next = top;
        top = n;
    }
    char Top()
    {
        if (top == NULL)
        {
            cout << "stack empty" << endl;
            return 'x';
        }
        char x = top->data;
        top = top->next;
        return x;
    }
    bool isempty()
    {
        if (top == NULL)
        {
            return 1;
        }
        return 0;
    }
    char topdata(){
        return top->data;
    }
};

int precedence(char x)
{
    if (x == '(')
        return 0;
    if (x == '+' || x == '-')
        return 1;
    if (x == '*' || x == '/')
        return 2;
    return 3;
}

void infi_post(char infi[], char post[])
{
    stack st;
    int j = 0;
    for (int i = 0; infi[i] != '\0'; i++)
    {
        char token = infi[i];
        if (token == '(')
        {
            st.push(token);
        }
        else
        {
            if (isalnum(token))
            {
                post[j] = token;
                j++;
            }
            else
            {
                if (token == ')')
                {
                    while (char x = st.Top() != '(')
                    {
                        post[j] = x;
                        j++;
                    }
                }
                else
                {
                    while (st.isempty() != 1 && precedence(token) <= precedence(st.topdata()))
                {
                    post[j] = st.Top();
                    j++;
                }
                }
                st.push(token);
            }
        }
    }
    while (!st.isempty())
    {
        post[j] = st.Top();
        j++;
    }
    post[j] = '\0';
    
}

int main()
{
    char post[20] , infi[20];
    cout<<"enter infi\n";
    cin>>infi;
    infi_post(infi , post);
    for (auto i : post)
    {
        cout<<i;
    }
    
    

    return 0;
}