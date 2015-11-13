//Graph data structuree
#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<queue>
#include<string>

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
        char buffer[256];
        bool foundDataSection = false;
        while (reader.good())
        {
            reader.getline(buffer, 256);
            if (buffer[0] == '#' && buffer[1] == 'd' && buffer[2] == 'a' && buffer[3] == 't' && buffer[4] == 'a')
            {
                foundDataSection = true;
                break;
            }
        }
        if (!foundDataSection)
            return;
        initGraph(reader);
        if (mEdges.size() == 0) 
            return;
		while( reader.good())
		{
            reader.getline(buffer, 256);
            std::stringstream strStream(buffer);
			int x, y, weight;
            strStream >> x >> y >> weight;
			insertEdge(x, y, weight, mDirected);
		}
	}

    void printGraph()
    {
        size_t vCount = 0;
        for (auto v : this->mEdges)
        {
            std::cout << "Edges for Vertex[" << vCount << "]";
            while (v != nullptr)
            {
                std::cout << "-->" << v->y;
                v = v->next;
            }
            std::cout << " ||" << std::endl;
            vCount++;
        }
    }

    void BFS(int start)// can start from any vertex
    {
        size_t size = mEdges.size();

        if (size == 0) return;
        mBFSParents.resize(size, -1);
        mDiscovered.resize(size, false);	
		mProcessed.resize(size, false);	

        std::queue<int> q;
        q.push(start);
        while (!q.empty())
        {
            int v = q.front();
            q.pop();
            mDiscovered[v] = true;
            //processVertexEarlier(v);
            Edgenode* edge = mEdges[v];
            while (edge != nullptr)
            {
                int y = edge->y;
                //edge v-->y;
                if (mProcessed[y] == false || mDirected)
                {
                    processEdge(v, y);
                }
                if (mDiscovered[y] == false)
                {
                    q.push(y);
                    mDiscovered[y] = true;
                    mBFSParents[y] = v;
                }
                edge = edge->next;
            }
        }
    }
	
	void DFS(int start)//depth first search, which can start from any vertex
	{
        size_t size = mEdges.size();
		if (size == 0) return;

        mDFSParents.resize(size);
        mDiscovered.resize(size);
        mProcessed.resize(size );
        mDFSEntryTime.resize(size);
        mDFSExitTime.resize(size);
        for (size_t i = 0; i < mDFSParents.size(); i++)
        {
            mDFSParents[i] = -1;
            mDiscovered[i] = false;
            mProcessed[i] = false;
            mDFSEntryTime[i] = -1;
            mDFSExitTime[i] = -1;
        }
		
		mDFSTimeClick = 0;
		mDiscovered[start ] = true;
		DFSHelper(start);
	}
private:
	void initGraph(std::istream& reader)
	{
		//get number of vertices from stream
		int numOfVertices = -1;
		bool directed;
        char buffer[256];
        reader.getline(buffer, 256);
        std::stringstream strStream(buffer);
        strStream >> numOfVertices >> directed;
        if (numOfVertices > 0)
        {
			mDirected = directed;
			mEdges.resize(numOfVertices, 0);
			mDegree.resize(numOfVertices, 0);
        }
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
	

	void processEdge(int start, int end)
	{
        std::cout << "Process edge[ " << start << "," << end << " ]" << std::endl;
	}

	void processVertexEarlier()
	{
	}

	void processVertexLater()
	{
	
	}

	void DFSHelper(int start)
	{
		Edgenode* v = mEdges[start];
		mDFSTimeClick++;
		mDFSEntryTime[start] = mDFSTimeClick;
		//Process vertex earlier(start)
		while(v != nullptr)
		{
            int y = v->y;
			if(mDiscovered[y] == false)
			{
                processEdge(start, y);
                mDiscovered[y] = true;
                mDFSParents[y] = start;
                DFSHelper(y);
			}
			else if(mProcessed[start] == false || mDirected == false)
				//process edge(start, y);
			v = v->next;
		}
		//Process vertex later(start);
		mProcessed[start] = true;
		mDFSExitTime[start] = mDFSTimeClick;
	}

	std::vector<Edgenode*> mEdges;
	std::vector<int> mDegree;
	int mNumOfEdges;
	bool mDirected;
	
	std::vector<bool> mDiscovered;	//<! to tell if a vertex is visited by BFS/DFS
	std::vector<bool> mProcessed;	//<! to tell if all edges of a vertex are processed by BFS/DFS

	std::vector<int> mBFSParents;	//<! parent data for BFS
	
	std::vector<int> mDFSParents;  	//<! parent data for DFS
	std::vector<int> mDFSEntryTime;	//<! Entry time on each vertex
	std::vector<int> mDFSExitTime;	//<! Exist time on each vertex
	size_t			mDFSTimeClick;
	
};

//For testing
int main()
{
    //Construct a graph
    std::ifstream reader("D:\\Harry\\GitHub\\algorithms\\testdata.txt", std::ifstream::in);
    Graph g;
    g.readGraph(reader);
    reader.close();
    g.printGraph();

    g.BFS(1);
    g.DFS(1);
    return 0;
}
