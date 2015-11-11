//Graph data structuree
#include<iostream>
#include<vector>
#include<queue>

class Graph
{
public:
	typedef struct Edgenode
	{
		int y;
		int weight;
		struct Graph::Edgenode* next;
        Edgenode(int v, int edgeWeight) : y(v), weight(edgeWeight), next(nullptr) {}
	}Edgenode;
	
	void readGraph(std::istream& reader)
	{
		while( !reader.eof())
		{
			int x, y, weight;
			reader >> x >> y >> weight ;
			insertEdge(x, y, weight, mDirected);
		}
	}

private:
	void initGraph(std::istream& reader)
	{
		//get number of vertices from stream
		int numOfVertices;
		bool directed;
		reader >> numOfVertices >> directed;
		mDirected = directed;
		mEdges.resize(numOfVertices);
		mDegree.resize(numOfVertices);
		mBFSParents.resize(numOfVertices);
		mDFSParents.resize(numOfVertices);
	}

	void insertEdge(int x, int y, int weight, bool directed)
	{
		Edgenode* edge = new Graph::Edgenode(y, weight);
		edge->next = mEdges[x];
		mEdges[x] = edge;
		if(directed == false)
		{
			insertEdge(y, x, weight, true);
		}
		else
		{
			mNumOfEdges++;
		}
		mDegree[x]++;
	}
	//=====================================================
	//Breadth first search and helpers
	void BFS(int start)// can start from any vertex
	{
		if(mEdges.size() == 0) return;
		std::vector<int> discovered(mEdges.size(), false);
		std::vector<int> processed(mEdges.size(), false );

		std::queue<int> q;
        q.push(start);
		while( !q.empty() )
		{
            int v = q.front();
			discovered[v]= true;
			//processVertexEarlier(v);
			Edgenode* edge = mEdges[v];
			while(edge != nullptr)
			{
				int y = edge->y;
				//edge v-->y;
				if(processed[y] == false || mDirected)
				{
					//processEdge(v, y);
				}
				if(discovered[y] == false)
				{
					q.push(y);
					discovered[y] = true;
					mBFSParents[y] = v;
				}
				edge = edge->next;
			}
		}
	}

	void processEdge()
	{
	}

	void processVertexEarlier()
	{
	}

	void DFS(int start)
	{
		//if(mEdges.size() == 0 ) return;
		//std::stack<int> s;

	}

	std::vector<Edgenode*> mEdges;
	std::vector<int> mDegree;
	int mNumOfEdges;
	bool mDirected;

	std::vector<int> mBFSParents;
	std::vector<int> mDFSParents;
};

//For testing
int main()
{

}