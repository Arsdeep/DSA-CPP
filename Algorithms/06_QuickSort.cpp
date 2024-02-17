#include<iostream>
using namespace std;

void ShowArr(int *a,int n)
{
    for(int i=0 ; i<n ; i++)
    {
        cout<<a[i]<<" ";
    }
}

int pivot(int* a, int l, int h) {
    int p = l;
    int tmp;

    while (l < h) {
        while (a[l] <= a[p] && l < h) {
            l++;
        }
        while (a[h] > a[p]) {
            h--;
        }

        if (l < h) {
            tmp = a[l];
            a[l] = a[h];
            a[h] = tmp;
        }
    }

    tmp = a[p];
    a[p] = a[h];
    a[h] = tmp;

    return h;
}


void QuickSort(int *a,int h,int l=0)
{
    if(l<h-1)
    {
        int p = pivot(a,l,h-1);
        QuickSort(a,p,l);
        QuickSort(a,h,p+1);
    }
}

int main()
{
    int a[] = {1,3,5,2,5,7,3,6,7,3,3,4,1,2};
    
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

    QuickSort(a,n);

    cout<<"\n\nSorted Array is - ";
    ShowArr(a,n);

    return 0;
}