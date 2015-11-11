//Graph data structuree
#include<iostream>

class Graph
{
public:
	typedef struct
	{
		int y;
		int weight;
		struct Edgenode* next;
	}Edgenode;
	
	void readGraph(std::istream& reader)
	{
		while( !reader.eof())
		{
			int x, y, weight;
			reader >> x >> y >> weight ;
			insertGraph(x, y, weight, mDirected);
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
		Edgenode* edge= new Edgennode(y, weight);
		edge->next = mEdges[x];
		mEdges[x] = edge;
		if(directed == false)
		{
			insertEdge(y, x, true);
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
		if(std::mEdges.size() == 0) return;
		std::vector<int> discovered(std::mEdges.size(), false);
		std::vector<int> processed(std::mEdges.size(), false );

		std::queue<int> q;
		q.enqueue(start);
		while( !q.empty() )
		{
			int v = q.dequeue();
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
					q.enqueue(y);
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
		if(mEdges.size() == 0 ) return;
		std::stack<int> s;

	}

	std::vector<Edgenode*> mEdges;
	std::vector<int> mDegree;
	int mNumOfEdges;
	bool mDirected;

	std::vector<int> mBFSParents;
	std::vector<int> mDFSParents;
};

