/*
The AlgoLib library is a powerful collection of utility functions designed
to simplify array manipulation, sorting, and searching in C++. With a variety of
different algorithms, it lets users to handle arrays in their desired way.

Whether you need to sort elements, search for specific values,
or perform array-related operations, AlgoLib provides a suite of reliable
and optimized functions to streamline your tasks.

Key Features:------------------------------------------------------------------------------------------------

|Array Manipulation: ShowArr(arr,size) -> enables you to inspect the array's contents with ease.
|                    SwapVal(arr,index1,index2) -> Swaps the values in the specified Indexes

|Sorting Algorithms: RecursionSort(arr,size);
|                    SelectionSort(arr,size);
|                    BubbleSort(arr,size);
|                    InsertionSort(arr,size);
|                    QuickSort(arr,size);
|                    MergeSort(arr,size);
|                    CountSort(arr,size);
|                    DNFSort(arr,size);                    -- For Arrays with 0,1,2 values
|                    WaveSort(arr,size);                   -- For Sorting in Alternate Values

|Searching Algorithms: LinearSearch(arr,size,target)       -- Character Array Searching Available aswell
|                      Binary Search(arr,size,target)

|Compatibility: The AlgoLib library adheres to the standards of modern C++
|               and guarantees compatibility with major C++ compilers and platforms.
|               Seamlessly integrate the library into your existing C++ projects,
|               regardless of the target platform. It provides cross-platform
|               support, enabling you to leverage its capabilities on various
|               operating systems, including Windows, macOS, and Linux.
|
-------------------------------------------------------------------------------------------------------------
Made by - Wolfey
Contact @Wolfey#8093 on Discord for more info...
*/

#include<iostream>

//Displays all the elements of the Array
void ShowArr(int *arr,int size)
{
    for(int i=0 ; i<size ; i++)
    {
        std::cout<<arr[i]<<" ";
    }
    return;
}

//Swaps the two Values of the array
void SwapVal(int *arr,int index1,int index2)
{
    int tmp = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = tmp;
    return;
}

//Uses Recursion To Sort the Array - OG By Wolfey
void RecursionSort(int *arr, int size, int i = 0)
{
    if(i<size-1)
    {
        if(arr[i]>arr[i+1])
        {
            SwapVal(arr,i,i+1);
            if(i>0)
                return RecursionSort(arr,size,i-1);
        }
        return RecursionSort(arr,size,i+1);
    }
}

//Searches an element in the Integer array and returns it's index, returns -1 if element not present
int LinearSearch(int *arr,int size,int target)
{
    for(int i=0 ; i<size ; i++)
        if(arr[i]==target)
            return i;
    return -1;
}


//Searches an element in the Character array and returns it's index, returns -1 if element not present
int LinearSearch(char *arr, char target)
{
    for(int i=0 ; arr[i]!='\0' ; i++)
        if(arr[i]==target)
            return i;
    return -1;
}

//Searches an element in a Sorted array and returns it's index, returns -1 if element not present
int BinarySearch(int *arr,int size,int target)
{
    int l = 0,m;
    size--;

    while(l<=size)
    {
        m = (l+size)/2;

        if(arr[m]==target)
            return m;

        if(arr[m]<target)
            l = m+1;
        else
            size = m-1;
    }
    return -1;
}

//Uses Selection Sort Algorithm To Sort the Array
void SelectionSort(int *arr,int size)
{
    int i,j,tmp;
    for(i=0;i<size-1;i++)
    {
        for(j=i+1;j<size;j++)
        {
            if(arr[j]<arr[i])
                SwapVal(arr,i,j);
        }
    }
    return;
}


//Uses Bubble Sort Algorithm To Sort the Array
void BubbleSort(int *arr,int size)
{
    int i,j,tmp;
    for(i=size-1;i>0;i--)
    {
        for(j=0;j<i;j++)
        {
            if(arr[j]>arr[j+1])
                SwapVal(arr,j,j+1);
        }
    }
    return;
}

//Uses Insertion Sort Algorithm To Sort the Array
void InsertionSort(int *arr,int size)
{
    int i,j,tmp;

    for(i=1 ; i<size ; i++)
    {
        tmp=arr[i];
        for(j = i-1 ; j>=0 && arr[j]>tmp ; j--)
        {
            arr[j+1] = arr[j];
        }
        arr[j+1] = tmp;
    }
    return;
}

//Puts an element in an array in its correct position and returns its index (Part of QuickSort Algorithm) 
int pivot(int* a, int l, int h)
{
    int p = l;
    int tmp;

    while (l < h) {
        while (a[l] <= a[p] && l < h)
        {
            l++;
        }
        while (a[h] > a[p]) {
            h--;
        }

        if (l < h) {
            SwapVal(a,l,h);
        }
    }

    SwapVal(a,p,h);

    return h;
}

//Uses Quick Sort Algorithm To Sort the Array
void QuickSort(int *arr,int size,int l=0)
{
    if(l<size-1)
    {
        int p = pivot(arr,l,size-1);
        QuickSort(arr,p,l);
        QuickSort(arr,size,p+1);
    }
}

//Merges 2 sorted part of arrays to form a single bigger sorted array (Part of MergeSort Algorithm)
void merge(int *a,int low,int mid,int high)
{
    int b[1000], m=mid+1, l=low, k=0;

    while(l<=mid && m<=high)
        if(a[l]<a[m])
            b[k++] = a[l++];
        else
            b[k++] = a[m++];

    while(l<=mid)
        b[k++] = a[l++];

    while(m<=high)
        b[k++] = a[m++];

    for(int l = low , k = 0; l<=high ; l++,k++)
        a[l] = b[k];
}

//Uses Merge Sort Algorithm To Sort the Array
void MergeSort(int *arr,int size,int l=0)
{
    if(l<size-1)
    {
        int m = (l+size-1)/2;
        MergeSort(arr,m+1,l);
        MergeSort(arr,size,m+1);
        merge(arr,l,m,size-1);
    }
}

//Uses Count Sort Algorithm To Sort the Array (Warning - Space Complexity Scales with Array Size)
void CountSort(int *arr,int size)
{
    int i,j, l = arr[0];

    for(i=1 ; i<size ; i++)
        if(arr[i] > l)
            l = arr[i];

    int* tmp = new int[l + 1]();

    for(i = 0 ; i<size ; i++)
        tmp[arr[i]] += 1;

    for(i=0,j=0 ; i<l+1 ; i++)
    {
        while(tmp[i]>0)
        {
            arr[j++] = i;
            tmp[i]--;
        }
    }
    delete[] tmp;
    return;
}

//Uses Dutch National Flag Sort Algorithm To Sort the Array of 0,1,2
void DNFSort(int *arr,int size)
{
    int l = 0,m = 0, tmp;
    size--;

    while(m<size)
    {
        switch(arr[m])
        {
            case 0:
                SwapVal(arr,m,l);
                m++;
                l++;
                break;
            
            case 1:
                m++;
                break;

            case 2:
                SwapVal(arr,m,size);
                size--;
                break;
        }
    }
}

//Uses Wave Sort Algorithm To Sort the Array in Alternating Order
void WaveSort(int *arr,int size)
{
    int i,tmp;

    for(i=1 ; i<size ; i+=2)
    {
        if(arr[i] > arr[i-1])
            SwapVal(arr,i,i-1);

        if(arr[i] > arr[i+1] && i<size-1)
            SwapVal(arr,i,i+1);
    }
}