#include <iostream>
using namespace std;
class BMF
{
	public:
	int vertex, edge;
	int graph[100][3];
	BMF(int v,int e)
	{
		vertex=v;
		edge=e;
	}
	void input()
	{
		cout << "Enter edges in the format (u v weight) where u and v are vertices:\n";
        for (int i = 0; i < edge; i++)
		{
            cin >> graph[i][0] >> graph[i][1] >> graph[i][2];
        }
	}
	void Shortest_Path(int s,int t)
	{
		int* dist= new int[vertex];
		for (int i = 0; i < vertex; i++)
		{
    		dist[i] = INT_MAX;
    	}
        dist[s] = 0;
		for (int i = 1; i < vertex; i++)
		{
           for (int j = 0; j < edge; j++)
			{
            	int u = graph[j][0];
                int vd = graph[j][1];
                int weight = graph[j][2];
				if (dist[u] != INT_MAX && dist[u] + weight < dist[vd])
				{
                	dist[vd] =dist[u] + weight;
                }
             }
         	
    	}
    	
		cout << "Shortest path from " << s <<" to "<<t<< " is: ";
        if (dist[t]==INT_MAX)
		{
			cout<<"No path exist\n";
		}
		else 
		{
			cout<<dist[t]<<endl;
		}
	}
	
};
int main() 
{
    int vertex, edge, source,target;
    cout << "Enter the number of vertices: ";
    cin >> vertex;
    cout << "Enter the number of edges: ";
    cin >> edge;
    BMF b(vertex, edge);
    b.input();
    cout << "Enter the source vertex: ";
    cin >> source;
	cout << "Enter the target vertex: ";
    cin >> target;
    b.Shortest_Path(source,target);
	return 0;
}

	

