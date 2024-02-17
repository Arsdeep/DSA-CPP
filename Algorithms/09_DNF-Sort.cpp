/*
Dutch National Flag Algorithm (as it has 3 stripes)
Used to Sort Arrays that have 3 Types of Values
*/

#include<iostream>
using namespace std;

void ShowArr(int *a,int n)
{
    for(int i=0 ; i<n ; i++)
    {
        cout<<a[i]<<" ";
    }
}

void DNFSort(int *a,int h)
{
    int l = 0,m = 0, tmp;
    h--;

    while(m<h)
    {
        switch(a[m])
        {
            case 0:
                tmp = a[m];
                a[m] = a[l];
                a[l] = tmp;
                m++;
                l++;
                break;
            
            case 1:
                m++;
                break;

            case 2:
                tmp = a[m];
                a[m] = a[h];
                a[h] = tmp;
                h--;
                break;
        }
    }
}

int main()
{
    int a[] = {0,1,2,2,1,2,0,2,1,2,1,0,0};
    
    int n = sizeof(a)/sizeof(int);


    cout<<"\nUn-Sorted Array is - ";
    ShowArr(a,n);

    DNFSort(a,n);

    cout<<"\n\nSorted Array is - ";
    ShowArr(a,n);

    return 0;
}