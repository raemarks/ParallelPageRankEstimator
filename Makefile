all:
	g++ -std=c++11 -g -Wall -lm -fopenmp -o page_rank main.cpp Graph.cpp Vertex.cpp -DSTATIC=

run:
	touch junk.csv
	./page_rank 1 100 .2 inputs/web-BerkStan_sorted.txt junk.csv
	rm -rf junk.csv

test:
	./run_tests.sh

debug:
	gdb ./page_rank

send:
	rsync main.cpp Graph.cpp Graph.h OmpConstants.h Vertex.cpp Vertex.h Makefile rmarks@ssh1.eecs.wsu.edu:/net/u/rmarks/pvt/

send_wookie:
	rsync run_*.sh main.cpp Graph.cpp Graph.h OmpConstants.h Vertex.cpp Vertex.h Makefile rmarks@wookie.eecs.wsu.edu:/home/rmarks
	#rsync inputs/* rmarks@wookie.eecs.wsu.edu:/home/rmarks/inputs
