#include<iostream>
using namespace std;
struct job{
	int id;
	int d;
	double p;

};
 int partitionLowPivot(struct job a[],int low,int high){

   double pivot=a[low].p;
   int left=low;
   int right=high+1;

   while(left<right){

        do{
			left++;
		}while(left<=high && a[left].p<pivot);


		do{
			right--;
		}while(a[right].p>pivot);


      if(left<right){
         swap(a[left],a[right]);
      }
   }



 swap(a[low],a[right]);



   return right;
 }

  void quickSort(struct job a[],int low,int high){
     if(low<high){
       int j=partitionLowPivot(a,low,high);
        quickSort(a,low,j-1);
        quickSort(a,j+1,high);

     }
  }
  double maxprofit(struct job a[],int n)
  {

  	quickSort(a,0,n-1);

  	double ans=0;
  	bool slot[n]={false};
  	int x[n]={0};
  	cout<<"job sequencing:";
  	for(int i=n-1;i>=0;i--)
  	{

  		for(int j=min(n,a[i].d)-1;j>=0;j--)
  		{
  			if(slot[j]==false)
  			{
  				x[j]=a[i].id;
  				cout<<a[i].id<<" ";
  				slot[j]=true;
  				ans+=a[i].p;
  				break;

			 }
		  }
	}
	cout<<endl;
	return ans;

  }
int main()
{
	int n;
	cout<<"enter the no of jobs:";
	cin>>n;
	struct job a[n];
	for(int i=0;i<n;i++)
	a[i].id=i+1;
	cout<<"enter the deadline:";
	for(int i=0;i<n;i++)
	cin>>a[i].d;
	cout<<"enter the profits:";
	for(int i=0;i<n;i++)
	cin>>a[i].p;
	cout<<endl;
	int profit=maxprofit(a,n);
	cout<<"maximum profit:"<<profit;
	cout<<endl;
	return 0;
}
