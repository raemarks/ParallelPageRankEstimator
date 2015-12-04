#ifndef __VERTEX_H__
#define __VERTEX_H__

#include <omp.h>
#include <string>
#include <vector>

using std::vector;

class Vertex {
	public:
		Vertex(int id);
		int GetID();
		void Visit();

		void InsertEdge(Vertex *adj);
		Vertex* GetRandomNeighbor();
		int GetNumNeighbors();
		void PrintPageRank(int totalVisits);

		void CalculatePageRank(int totalVisits);
		static double TotalPageRank;

	private:
		int id;
		int visitCounter;
		int numEdges;
		int pageRank;
		unsigned int seed;
		vector<Vertex *> edges;
		omp_lock_t lock;
};

#endif
