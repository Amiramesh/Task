/*
A bag contains n balls of 3 colors(black,blue and red), each color ball is 
of different weight(black - 0.25 kg, blue - 0.5 kg, red, 0.75). You are required 
to make a sum of m with the balls such that your sack contains minimum number of balls. 
Please write a code(in your preferred language) to solve the same. 
Also, mention additional methods of solving the problem if you think there are any.
Note: this task is to test your thinking.
*/
#include<bits/stdc++.h>
using namespace std;
int minBalls(float arr[],int n,float m)
{
	int s=0;
	int mid=0;
	int e=n-1;
	/* fmod() is used to calculate modulus of  two floating numbers; 
	e.g(if m  not completely divisible by 0.25 (blue ball weight) means there is no possibility of getting sum=m 
	so function return -1 */
    if(fmod(m,0.25)!=0) 
    return -1;
	// Approach-1:-this is used to sort the array e.g only 3 types of colors are there so ,this can sort in o(n);
	while(mid<=e)
	{
		if(arr[mid]==0.25)
		{
			swap(arr[mid],arr[s]);
			mid++;
			s++;
		}
		else if(arr[mid]==0.5)
		{
			mid++;
		}
		else
		{
			swap(arr[mid],arr[e]);
			e--;
		}
	}
	/*for(int k=0;k<n;k++)
	{
		cout<<arr[k]<<" ";
	}*/
	float sum=0;
	int i=n-1;
	int cntBalls=0;
	while(i>=0)
	{
		if(sum+arr[i]<=m)
		{
			sum+=arr[i];
			cntBalls++;
		}
		if(sum==m)
		{
			break;
		}
		i--;
	}
	if(sum!=m)
	 return -1;
	return cntBalls;
	
}
int main()
{
	int n;
	cin>>n;
	float arr[n];
	for(int i=0;i<n;i++)
	cin>>arr[i];
	float m;
	cin>>m;
	/*test case: n=9,
	 arr[]={0.5 0.75 0.25 0.75 0.75 0.25 0.5 0.5 0.5};
	 m=3,4.25,0.2,6;
	 */
	cout<<minBalls(arr,n,m);
	
	// if output  is -1 means it is not possible to get sum=m;
	/*Approach 2 : As there are  only three colors so cntBlack=0,cntBlue=0,cntRed=0;
	for(int i=0;i<n;i++)
	{ if(arr[i]==0.25)
	   cntBlack++;
	   else if(arr[i]==0.5)
	   cntBlue++;
	   else
	   cntRed++;
    }
int i=0;
while(cntBlack>0)
{
arr[i++]=0.25;
cntBlack--;
}
similary for others;  Timecomplexity o(n) */
/* Approach 3: using sort(arr,arr+n,greater<int>()) sort array in descending order after that applay same approach of 1;c*/

}
