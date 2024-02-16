#include<iostream>
using namespace std;

int BinarySearch(int *a,int h,int t)
{
    int l = 0,m;
    h--;

    while(l<=h)
    {
        m = (l+h)/2;
        if(a[m]==t)
        {
            return m;
        }
        if(a[m]<t)
            l = m+1;
        else
            h = m-1;
    }
    return -1;
}

int main()
{
    int a[] = {1,5,7,11,34,57,63,91,102};
    int n = sizeof(a)/sizeof(int);
    int t = 34;

    cout<<"Target "<<t<<" found at index - "<<BinarySearch(a,n,t);

    return 0;
}