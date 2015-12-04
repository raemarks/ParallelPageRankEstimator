#include <cstdio>
#include <omp.h>
#include <string>
#include "assert.h"
#include "Graph.h"

double Vertex::TotalPageRank;
int p;

using std::string;

int main(int argc, char *argv[])
{
	assert(argc >= 6);

	p = atoi(argv[1]);
	int k = atoi(argv[2]);
	double d = std::stod(argv[3]);

	omp_set_num_threads(p);

	Vertex::TotalPageRank = 0.0;

	printf("p: %d, k: %d, d: %lf, file: %s, ", p, k, d, argv[4]);

	string schedule;
#ifdef STATIC
	printf("schedule: static, ");
	schedule = "static";
#endif
#ifdef DYNAMIC
	printf("schedule: dynamic, ");
	schedule = "dynamic";
#endif
#ifdef GUIDED
	printf("schedule: guided, ");
	schedule = "guided";
#endif

	string sync;
#ifdef LOCK
	printf("sync: lock\n");
	sync = "lock";
#else
	printf("sync: atomic\n");
	sync = "atomic";
#endif

	Graph g(argv[4]);
	double runtime = g.EstimatePageRank(k, d);
	char *filename = argv[5];
	FILE *f = fopen(filename, "a+b");
	fprintf(f, "%lf,%s,%s,%s,%d,%d,%lf\n",d,argv[4],schedule.c_str(),
	    sync.c_str(),p,k,runtime);
	return 0;
}
