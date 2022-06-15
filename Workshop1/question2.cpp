#include<bits/stdc++.h>
using namespace std;
int find_startpos(int arr[],int n,int customer_id)
{
    int low=0;
    int high=n-1;
    int mid;
    int pos=-1;
    while(low<=high)
    {
        mid=low+(high-low)/2;
        if(arr[mid]==customer_id){
            pos=mid;
            high=mid-1;//low=mid+1;
        }
        else if(arr[mid]>customer_id)
           high=mid-1;
        else
            low=mid+1;
    }
    return pos;
}