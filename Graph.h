#ifndef __GRAPH_H__
#define __GRAPH_H__

#include <fstream>
#include <string>
#include <unordered_map>

#include "Vertex.h"

class Graph {
	public:
		Graph(std::string filename);

		Vertex *getVertex(int num);

		double EstimatePageRank(int k, double D);

		void PrintVertices();

		void PrintPageRanks();

	private:
		void performRandomWalk(int vertexId, int k, double D, int rank);

		Vertex *getRandomVertex(int rank);

		int numVertices;

		std::unordered_map<int, Vertex *> vertices;

		/* For fast selection of random vertices */
		std::vector<int> vertexIds;

		/* Random seeds for each rank */
		vector<unsigned int> iseeds;

		vector<struct drand48_data> dseeds;

		int totalVisits;
};

#endif
