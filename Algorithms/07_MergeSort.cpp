#include<iostream>
using namespace std;

void ShowArr(int *a,int n)
{
    for(int i=0 ; i<n ; i++)
    {
        cout<<a[i]<<" ";
    }
}

void merge(int *a,int low,int mid,int high)
{
    int b[1000], m=mid+1, l=low, k=0;

    while(l<=mid && m<=high)
    {
        if(a[l]<a[m])
            b[k++] = a[l++];
        else
            b[k++] = a[m++];
    }

    while(l<=mid)
    {
        b[k++] = a[l++];
    }

    while(m<=high)
    {
        b[k++] = a[m++];
    }

    k=0;

    for(int l = low ; l<=high ; l++,k++)
    {
        a[l] = b[k];
    }
}

void MergeSort(int *a,int h,int l=0)
{
    if(l<h-1)
    {
        int m = (l+h-1)/2;
        MergeSort(a,m+1,l);
        MergeSort(a,h,m+1);
        merge(a,l,m,h-1);
    }
}

int main()
{
    int a[] = {7,5,2,3,8,9,4,1,6};
    
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

    MergeSort(a,n);

    cout<<"\n\nSorted Array is - ";
    ShowArr(a,n);

    return 0;
}