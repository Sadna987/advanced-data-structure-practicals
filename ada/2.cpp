#include<iostream>
using namespace std;

template <class t>
class Select
{
	t A[100];
	int num;
	public:
	Select(int n) 
	{
	num=n;
	}
	void input(int n);
	int partition(int p,int r);
	int randomized_select(int p,int r,int i);
	int randomized_partition(int p, int r);
};
template <class t>
void Select <t>::input(int n)
{
	for (int i=1; i<=n; i++) 
	{
	A[i]=rand()%100;
	}
	for (int i=1;i<=n;i++)
	{
	cout<<A[i]<<" ";
	}
}
template <class t>
int Select <t>::randomized_partition(int p, int r)
{
	int i;
	i=p + (rand() % (r - p + 1));
	swap(A[r],A[i]);
	return partition(p,r);
}
template <class t>
int Select <t>:: partition(int p,int r)
{
	int x=A[r];
	int i=p-1;
	int j;
	for (j=p; j<=r-1; j++)
	{
		if (A[j]<=x)
		{	 
			i++;
			swap(A[i],A[j]);
		}
	}
	swap(A[i+1],A[r]);
	return i+1;
}

template <class t>
int Select <t>:: randomized_select(int p,int r,int i)
{
	int k;
	if (p==r)
	{
		return A[p];
	}
	int q=randomized_partition(p,r);
	k=q-p+1;
	if (i==k)
	{
		return A[q];
	}
	else if (i<k)
	{
		return randomized_select(p,q-1,i);
	}
	else 
	{
		return randomized_select(q+1,r,i-k);
	}
}



int main()
{
	int i;
	int n=30;
	cout<<"Enter the value of i:";
	cin>>i;
	Select<int> ob(n);
	cout<<"\nNUMBER OF ELEMENTS IN ARRAY:"<<n<<endl;
	cout<<"\nARRAY IS:"<<endl;
	ob.input(n);
	int ith=ob.randomized_select(1,n,i);
	cout<<endl<<i<<"th Order Statistics is: "<<ith<<endl;;
	cout<<"\n";	   
	return 0;
}

