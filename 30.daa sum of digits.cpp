#include <stdio.h>
int sum[100],l=0,sum1[100],l1=0;
int s(int arr[],int n)
{
	int i,t,r,s=0;
	for(i=0;i<n;i++)
	{
		s=0;
		int j=arr[i];
		while(j!=0)
		{
			t=j%10;
			s=s+t;
			j=j/10;

		}
		sum[l]=s;
		l++;
	}
}
int main(){
	int n,i,arr[100],j;
	printf("Enter the n :-");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter the %d element:-",i+1);
		scanf("%d",&arr[i]);
	}
	s(arr,n);
	for(i=0;i<l;i++)
	{
		printf(" %d ",sum[i]);
	}
	for(i=0;i<l;i++)
	{
		int s1=0;
		for(j=i+1;j<n;j++){
		if(sum[i]==sum[j])
		{
			s1=arr[i]+arr[j];
			sum1[l1]=s1;
			l1++;
		}
	}
	}
	printf("\nSUM\n");
	int t;
	for(i=0;i<l1;i++)
	{
		printf(" %d ",sum1[i]);
	}
	for(i=0;i<l1;i++)
	{
		for(j=i+1;j<l1;j++)
		{
			if(sum1[i]>sum1[j])
			{
				t=sum1[i];
				sum1[i]=sum1[j];
				sum1[j]=t;
			}
		}
	}
	printf("\nMaximum Sum=%d",sum1[l1-1]);
}
