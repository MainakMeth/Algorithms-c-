
//MaxMin using Divide and Conquer
#include<bits/stdc++.h>
using namespace std;

void maxMin(int a[],int low,int high,int &max,int &min){

    if(low == high){
        max=a[low];
        min=a[low];
    }

    else if(low == high-1){
        if(a[low] > a[high]){
            max=a[low];
            min=a[high];
        }

        else{
            max=a[high];
            min=a[low];
        }
    }

    else{
        int max1,min1,mid;
        mid=(low+high)/2;
        maxMin(a,low,mid,max,min);
        maxMin(a,mid,high,max1,min1);
        if(max < max1){
            max = max1;
        }

        if(min > min1){
            min=min1;
        }
    }
}

int main(){
  int n;

  cout<<"Enter no of elements of Array"<<endl;
  cin>>n;
  int a[n];
  cout<<"Enter the elements of Array"<<endl;
  for(int i=0;i<n;i++)
     cin>>a[i];

  int max=INT_MIN;
  int min=INT_MAX;
  maxMin(a,0,n-1,max,min);

  cout<<"Max Ele is "<<max<<endl;
  cout<<"Min Ele is "<<min<<endl;

 return 0;

 }
