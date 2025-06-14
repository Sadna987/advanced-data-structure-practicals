#include<iostream>
#include<fstream>
using namespace std;

template <class t>
class Quicksort
{
	t A[1000];
	int num;
	public:
	Quicksort(int n) {
	num=n;
	}
	void input(int n);
	int partition(int p,int r);
	void randomized_qsort(int p,int r);
	int randomized_partition(int p, int r);
	void output(int n);
	int comparisons; 
};
template <class t>
void Quicksort <t>:: input(int n)
{
	for (int i=1; i<=n; i++) 
	{
	A[i]=rand()%1000;
	}
}
template <class t>
int Quicksort <t>::randomized_partition(int p, int r)
{
	int i;
	i=p + (rand() % (r - p + 1));
	swap(A[r],A[i]);
	return partition(p,r);
}
template <class t>
int Quicksort <t>:: partition(int p,int r)
{
	int x=A[r];
	int i=p-1;
	int j;
	for (j=p; j<=r-1; j++)
	{
		comparisons++; 
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
void Quicksort <t>:: randomized_qsort(int p,int r)
{
	if (p<r)
	{
		int q=randomized_partition(p,r);
		randomized_qsort(p,q-1);
		randomized_qsort(q+1,r);
	}
}

template <class t>
void Quicksort <t>:: output(int n)
{
for (int i=1; i<=n; i++)
{
	cout<<A[i]<<" ";
}
cout<<endl<<endl;
}

int main()
{
	int k=1;
	int n=30;
	ofstream fout;
	fout.open("qsort.csv");
	Quicksort<int> ob(n);
	while(k<=20)
	{
		cout<<k<<" ITERATIONS "<<endl;
		cout<<"\n UNSORTED"<<endl;
		ob.input(n);
		cout<<"No. of elements : "<<n<<endl;
		cout<<"Before Sorting "<<endl<<endl;
		ob.output(n);
		ob.comparisons=0;
		ob.randomized_qsort(1,n);
		cout<<"After Sorting"<<endl<<endl;;
		ob.output(n);
		fout<<n<<','<<ob.comparisons<<'\n';
		n+=30;
		k++;
		cout<<"\n";
	}
	fout.close();
	return 0;
}

