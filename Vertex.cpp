#include <iostream>
#include <time.h>

#include "OmpConstants.h"
#include "Vertex.h"

#if 0
class Vertex {
	public:
		Vertex(int id);
		int GetID();
		void Visit();

		unordered_map<Vertex *, int>& getEdges();
		void insertEdge(Vertex *adj, int weight);

	private:
		int id;
		int visitCounter;
};
#endif

Vertex::Vertex(int id)
{
	this->id = id;
	visitCounter = 0;
	numEdges = 0;
	seed = time(NULL);
	omp_init_lock(&lock);
}

int
Vertex::GetID()
{
	return id;
}

Vertex*
Vertex::GetRandomNeighbor()
{
	if (numEdges == 0)
	{
		//std::cout << "0 edges! My id: " << id << std::endl;
		return nullptr;
	}
	int offset = rand_r(&seed) % numEdges;
	return edges[offset];
}

int
Vertex::GetNumNeighbors()
{
	return numEdges;
}

void
Vertex::Visit()
{
#ifdef LOCK
	omp_set_lock(&lock);
#else
#pragma omp atomic
#endif
	visitCounter+=1;

#ifdef LOCK
	omp_unset_lock(&lock);
#endif
}


void
Vertex::InsertEdge(Vertex *adj)
{
	if (adj == nullptr) {
		std::cout << "Null adjacent vertex!" << std::endl;
		exit(1);
	}
	edges.push_back(adj);
	numEdges++;
}

void
Vertex::PrintPageRank(int totalVisits)
{
	Vertex::TotalPageRank += ((double)visitCounter)/totalVisits;
	std::cout << "Id: " << id << ", page rank: " <<
	    ((double)visitCounter)/totalVisits << std::endl;
}

void
Vertex::CalculatePageRank(int totalVisits)
{
	pageRank = ((double)visitCounter)/totalVisits;
}
