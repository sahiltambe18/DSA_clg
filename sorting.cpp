#include <iostream>
#include <string.h>
using namespace std;

struct student
{
    char name[20];
    int roll;
    float sgpa;
};

void swap(student &a, student &b)
{
    student temp = a;
    a = b;
    b = temp;
}

void create(student s[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "enter roll number : ";
        cin >> s[i].roll;
        cout << "\nenter name : ";
        cin >> s[i].name;
        cout << "\nenter sgpa : ";
        cin >> s[i].sgpa;
    }
}

void display(student s[], int n)
{
    cout << "roll no "
         << "\t"
         << "name "
         << "\t"
         << "marks " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << s[i].roll << "\t" << s[i].name << "\t" << s[i].sgpa << endl;
    }
}

void bubblesort(student s[], int n)
{
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            if (s[j].roll > s[j + 1].roll)
            {
                student temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }
}

void insertion(student s[], int n)
{
    for (int i = 1; i < n; i++)
    {
        student current = s[i];
        int j = i - 1;
        while (j >= 0 && strcmp(s[j].name, current.name) > 0)
        {
            student temp = s[j];
            s[j] = s[j + 1];
            s[j + 1] = temp;
            j--;
        }
        s[j + 1] = current;
    }
}

// int partition(student s[], int l, int u)
// {
//     int i = l, j = u - 1;
//     student current = s[l];
//     while (i < j)
//     {
//         while (s[i].sgpa >= current.sgpa)
//         {
//             i++;
//         }
//         while (s[j].sgpa < current.sgpa)
//         {
//             j--;
//         }
//         if (i < j)
//         {
//             swap(s[i], s[j]);
//         }
//     }
//     swap(s[l], s[j]);
//     return j;
// }

int partition(student s[], int l, int u)
{
    u--;
    int p, q;
    student pi = s[l];
    p = l;
    q = u;
    while (p < q)
    {
        while (pi.sgpa <= s[p].sgpa)
        {
            p++;
        }
        while (pi.sgpa > s[q].sgpa)
        {
            q--;
        }
        if (p < q)
        {
            swap(s[p], s[q]);
        }
    }

    swap(s[l], s[q]);
    return q;
}

void quicksort(student s[], int l, int u)
{
    if (l < u)
    {
        int pi = partition(s, l, u);
        quicksort(s, l, pi - 1);
        quicksort(s, pi + 1, u);
    }
}

void linear_search(student s[],int n){
    float key;
    cout<<"Enter SGPA of student.";
    cin>>key;
    for(int i=0;i<n;i++){
        if(s[i].sgpa==key){
            cout<<s[i].roll<<" \t"<<s[i].name<<"\t"<<s[i].sgpa<<endl;
        }
    }
}

void binary_search(student s[],int n){
    insertion(s,n);
    int mid;
    char temp[20];
    int l ,u;
    l = 0;
    u=n;
    cout<<"Enter name:";
    cin>>temp;
    while (l<=u)
    {
        mid = (l+u)/2;
        if(strcmp(s[mid].name , temp)==0){
            cout<<s[mid].roll<<"\t"<<s[mid].name<<"\t"<<s[mid].sgpa;
            return;
        }
        else if (strcmp(s[mid].name , temp)>0)
        {
            u = mid-1;
        }
        else{
            l = mid+1;
        }
        
    }
    
}

int main()
{
    int n;
    student s[10];
    cout << "enter student entries\n";
    cin >> n;
    create(s, n);
    // bubblesort(s, n);
    // display(s, n);
    // insertion(s, n);
    // display(s, n);
    // quicksort(s, 0, n);
    display(s, n);
    binary_search(s,n);
    cout<<"mavshi chi gand";

    return 0;
}