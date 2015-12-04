#include <cstdio>
#include <fstream>
#include <iostream>
#include <time.h>
#include <omp.h>

#include "OmpConstants.h"
#include "Graph.h"

#define BIG_PRIME 217645177

#if 0
class Graph {
	public:
		/* TODO: read file once, read again to get the hyperlinks. */
		Graph(string filename);
		Vertex *getVertex(int num);
	private:
		unordered_map<int, Vertex *> _vertices;
		int _numVertices;
};
#endif

using std::cout;
using std::endl;

double
Graph::EstimatePageRank(int k, double D)
{
	int v, rank = 0;
	double begin, end;
	//cout << "Num vertices: " << numVertices << endl;

	begin = omp_get_wtime();
#ifdef STATIC
	//cout << "STATIC" << endl;
	/* TODO: try this with schedule(static, numVertices/p) */
#pragma omp parallel for schedule(static, 32) private(v, rank)
#endif
#ifdef DYNAMIC
	//cout << "DYNAMIC" << endl;
	/*TODO: try this with a different chunk size */
#pragma omp parallel for schedule(dynamic, 32) private(v, rank)
#endif
#ifdef GUIDED
	//cout << "GUIDED" << endl;
#pragma omp parallel for schedule(guided, 32) private(v, rank)
#endif
	for (v = 0; v < numVertices; v++) {
		rank = omp_get_thread_num();
		performRandomWalk(v, k, D, rank);
	}
	/* End parallel section */

	totalVisits = k*numVertices;

#ifdef STATIC
	/* TODO: try this with schedule(static, numVertices/p) */
#pragma omp parallel for schedule(static, 32) private(v)
#endif
#ifdef DYNAMIC
	/*TODO: try this with a different chunk size */
#pragma omp parallel for schedule(dynamic, 32) private(v)
#endif
#ifdef GUIDED
#pragma omp parallel for schedule(guided, 32) private(v)
#endif
	for (v = 0; v < numVertices; v++) {
		vertices[vertexIds[v]]->CalculatePageRank(totalVisits);
	}
	/* End parallel section */
	end = omp_get_wtime();
	cout << "Total runtime: " << end-begin << " seconds" << endl;
	return end-begin;
}

void
Graph::performRandomWalk(int vertexId, int k, double D, int rank)
{
	double prob;
	Vertex *v = vertices[vertexIds[vertexId]];

	for (int j = 0; j < k; j++) {
		/* Increment counter */
		v->Visit();
		drand48_r(&dseeds[rank], &prob);
		if (prob <= D) {
			/* Jump randomly */
			v = getRandomVertex(rank);
		}
		else {
			/* Go from current node */
			v = v->GetRandomNeighbor();
			/* No neighbors */
			if (v == nullptr)
				v = getRandomVertex(rank);
		}
	}
}

Vertex *
Graph::getRandomVertex(int rank)
{
	int offset;
	//printf("Testing values\n");
	//printf("iseeds at rank: %d\n", iseeds[rank]);
	offset = rand_r(&iseeds[rank]) % numVertices;
	//printf("vertexIds at offset %d: %d\n", offset, vertexIds[offset]);
	//printf("vertices at vertexId[offset]: %d\n", vertices[vertexIds[offset]]->GetID());
	return vertices[vertexIds[offset]];
}

void
Graph::PrintPageRanks()
{
	Vertex::TotalPageRank = 0.0;
	for (auto it = vertices.begin(); it != vertices.end(); it++) {
		it->second->PrintPageRank(totalVisits);
	}
	std::cout << "Total page rank: " << Vertex::TotalPageRank << std::endl;
}

Graph::Graph(std::string filename)
{
	std::ifstream in(filename.c_str());
	std::string line;
	int fromId, toId;

	numVertices = 0;

	/* Create seeds for random # generation for each thread */
	for (int i = 0; i < p; i++) {
		dseeds.push_back({});
		srand48_r(time(NULL)+i*BIG_PRIME, &dseeds[i]);
		iseeds.push_back(time(NULL)+i*BIG_PRIME);
	}
	/*
	for (int i = 0; i < p; i++) {
		cout << "iseed: " << iseeds[i] << endl;
		cout << "dseed: " << dseeds[i].__x << " " << dseeds[i].__old_x
		    << dseeds[i].__c << dseeds[i].__init <<
		    dseeds[i].__a << endl;
	}
	*/

	if (!in.good()) {
		std::cout << "Filename '" << filename << "' does not exist."
		    << std::endl;
		exit(1);
	}

	/* Skip intro comments */
	do {
		std::getline(in, line);
	} while (!line.empty() && line[0] == '#');

	/* Read in vertices first */
	do {
		sscanf(line.c_str(), "%d %d", &fromId, &toId);
		auto search = vertices.find(fromId);
		if (search == vertices.end()) {
			/* Add to the map if it's not already there */
			vertices[fromId] = new Vertex(fromId);
			numVertices++;
			vertexIds.push_back(fromId);
		}
		search = vertices.find(toId);
		if (search == vertices.end()) {
			/* Add to the map if it's not already there */
			vertices[toId] = new Vertex(toId);
			numVertices++;
			vertexIds.push_back(toId);
		}
		std::getline(in, line);
	} while (!line.empty() && !in.eof());

	/* Rewind to beginning */
	in.close();
	in.open(filename.c_str());

	/* Skip intro comments */
	do {
		std::getline(in, line);
	} while (!line.empty() && line[0] == '#');

	/* Make edges between vertices */
	do {
		sscanf(line.c_str(), "%d %d", &fromId, &toId);
		vertices[fromId]->InsertEdge(vertices[toId]);
		std::getline(in, line);
	} while (!line.empty() && !in.eof());


	in.close();
}

Vertex *
Graph::getVertex(int num)
{
	return nullptr;
}

void
Graph::PrintVertices()
{
	std::cout << numVertices << std::endl;
}
