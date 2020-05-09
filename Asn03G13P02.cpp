#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
void print(int a[],int n)
{
    cout<<"sorted heap is:";
	for(int i=1;i<=n;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
}
void print_1(int a[],int n)
{
    cout<<"minimum heap sort:";
	for(int i=1;i<=n;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
}


void heapify(int arr[],int ind,int n)
{
	int val=arr[ind];
	int lval;
	int rval;
	int minval;
	//child of i;
	int j=2*ind;
	while(j<=n)
	{
		lval=INT_MAX;
		rval=INT_MAX;

		if(j<=n)
		lval=arr[j];

		if(j+1<=n)
		rval=arr[j+1];

		if(lval<rval)
		{
			minval=lval;
		}
		else
		{
			minval=rval;
			j=j+1;
		}

		if(val<minval)
		break;

		if(val>=minval)
		arr[j/2]=minval;
		j=2*j;
	}
	arr[j/2]=val;
}

void heapsort(int a[],int n)
{

	for(int i=n;i>1;i--)
	{
		swap(a[1],a[i]);
		heapify(a,1,i-1);
	}
}

int main(int argc,char* argv[])
{
	int n,x=1;
	string str;
	int temp;
	vector<int> te;
	//cin>>str;//
	stringstream ss(argv[x++]);
	while(ss>>temp)
	{
		te.push_back(temp);
		if(ss.peek()==',')
		ss.ignore();
	}
	n=te.size()+1;
	int arr[n]={0};
	for(int i=1;i<n;i++)
	{
		arr[i]=te[i-1];
	}
	cout<<endl;
	n=n-1;
	for(int i=n/2;i>=1;i--)
	{
		heapify(arr,i,n);
	}
    print(arr,n);
	heapsort(arr,n);
	print_1(arr,n);
	return 0;
}
