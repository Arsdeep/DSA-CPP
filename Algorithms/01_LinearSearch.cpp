#include<iostream>
using namespace std;

int LinearSearch(int *a,int n,int t)
{
    for(int i=0 ; i<n ; i++)
    {
        if(a[i]==t)
        return i;
    }
    return -1;
}

int LinearSearch(char *a, char t)
{
    for(int i=0 ; a[i]!='\0' ; i++)
    {
        if(a[i]==t)
        return i;
    }
    return -1;
}

int main()
{
    int a[] = {1,5,2,3,8,9,7,6};
    char b[] = {"Hello World"};
    
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
    int t = 8;
    char t2 = 'W';

    cout<<"Target "<<t<<" found at index - "<<LinearSearch(a,n,t)<<endl;
    cout<<"Target "<<t2<<" found at index - "<<LinearSearch(b,t2)<<endl;

    return 0;
}