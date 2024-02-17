/*
Wave Sort is an Algo which Sorts an array such that -
a[i]>=a[i+1]<=a[i+2]>=a[i+3]<=a[i+4]>=...a[n]

So if we plot it in a graph it forms a wave like structure
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

void WaveSort(int *a,int n)
{
    int i,tmp;

    for(i=1 ; i<n ; i+=2)
    {
        if(a[i] > a[i-1])
        {
            tmp = a[i];
            a[i] = a[i-1];
            a[i-1] = tmp;
        }

        if(a[i] > a[i+1] && i<n-1)
        {
            tmp = a[i];
            a[i] = a[i+1];
            a[i+1] = tmp;
        }
    }
}

int main()
{
    int a[] = {7,5,2,3,8,9,4,6};
    
    /*int a[] = {15, 32, 47, 12, 83, 29, 65, 
    42, 54, 27, 36, 91, 77, 88, 59, 20, 14,
    72, 45, 31, 68, 99, 52, 10, 23, 75, 62,
    39, 84, 19, 70, 16, 53, 87, 94, 28, 76,
    66, 11, 35, 22, 61, 50, 73, 80, 96, 38,
    49, 57, 43, 18, 67, 90, 26, 81, 58, 44,
    21, 41, 60, 30, 86, 93, 97, 63, 33, 51,
    78, 17, 74, 69, 24, 55, 85, 95, 37, 48,
    82, 34, 92, 64, 79, 25, 56, 89, 40, 33};*/
    
    int n = sizeof(a)/sizeof(int);


    cout<<"\nUn-Sorted Array is - ";
    ShowArr(a,n);

    WaveSort(a,n);

    cout<<"\n\nSorted Array is - ";
    ShowArr(a,n);

    return 0;
}