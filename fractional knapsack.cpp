#include<iostream>
using namespace std;
struct item{
	double w,p;

};
 int partitionLowPivot(struct item a[],double x[],int low,int high){

   double pivot=x[low];
   int left=low;
   int right=high+1;

   while(left<right){

        do{
			left++;
		}while(left<=high && x[left]<pivot);


		do{
			right--;
		}while(x[right]>pivot);


      if(left<right){
         swap(x[left],x[right]);
         swap(a[left],a[right]);
      }
   }


 swap(x[low],x[right]);
 swap(a[low],a[right]);



   return right;
 }

  void quickSort(struct item a[],double x[],int low,int high){
     if(low<high){
       int j=partitionLowPivot(a,x,low,high);
        quickSort(a,x,low,j-1);
        quickSort(a,x,j+1,high);

     }
  }
  double knapsack(struct item a[],int size,int n)
  {
  	double x[n];
  	for(int i=0;i<n;i++)
  	x[i]=a[i].p/a[i].w;
  	quickSort(a,x,0,n-1);

  	double ans=0;
  	for(int i=n;i>=0;i--)
  	{
  		if(a[i].w>size)
  		{
  			ans+=(size/a[i].w)*a[i].p;
  			break;
		}
		else
		{
			ans+=a[i].p;
			size=size-a[i].w;
		}
	}
	return ans;

  }
int main()
{
	int size;
	cout<<"enter the capacity of knapsack:";
	cin>>size;
	int n;
	cout<<"enter the no of items:";
	cin>>n;
	struct item a[n];
	cout<<"enter the weights:";
	for(int i=0;i<n;i++)
	cin>>a[i].w;
	cout<<"enter the profits:";
	for(int i=0;i<n;i++)
	cin>>a[i].p;
	cout<<"maximum profit:"<<knapsack(a,size,n);
	cout<<endl;
	return 0;
}
