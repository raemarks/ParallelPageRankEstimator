g++ -std=c++11 -g -Wall -lm -fopenmp -o page_rank main.cpp Graph.cpp Vertex.cpp -DSTATIC=

rm -rf runtime_comp_scheduling.csv
touch runtime_comp_scheduling.csv
echo "d,input,scheduling,sync method,p,k,runtime" > runtime_comp_scheduling.csv
./page_rank 1 128 .2 inputs/web-NotreDame_sorted.txt runtime_comp_scheduling.csv
./page_rank 1 256 .2 inputs/web-NotreDame_sorted.txt runtime_comp_scheduling.csv
./page_rank 1 512 .2 inputs/web-NotreDame_sorted.txt runtime_comp_scheduling.csv
./page_rank 1 1024 .2 inputs/web-NotreDame_sorted.txt runtime_comp_scheduling.csv
./page_rank 1 2048 .2 inputs/web-NotreDame_sorted.txt runtime_comp_scheduling.csv

./page_rank 2 128 .2 inputs/web-NotreDame_sorted.txt runtime_comp_scheduling.csv
./page_rank 2 256 .2 inputs/web-NotreDame_sorted.txt runtime_comp_scheduling.csv
./page_rank 2 512 .2 inputs/web-NotreDame_sorted.txt runtime_comp_scheduling.csv
./page_rank 2 1024 .2 inputs/web-NotreDame_sorted.txt runtime_comp_scheduling.csv
./page_rank 2 2048 .2 inputs/web-NotreDame_sorted.txt runtime_comp_scheduling.csv

./page_rank 4 128 .2 inputs/web-NotreDame_sorted.txt runtime_comp_scheduling.csv
./page_rank 4 256 .2 inputs/web-NotreDame_sorted.txt runtime_comp_scheduling.csv
./page_rank 4 512 .2 inputs/web-NotreDame_sorted.txt runtime_comp_scheduling.csv
./page_rank 4 1024 .2 inputs/web-NotreDame_sorted.txt runtime_comp_scheduling.csv
./page_rank 4 2048 .2 inputs/web-NotreDame_sorted.txt runtime_comp_scheduling.csv

g++ -std=c++11 -g -Wall -lm -fopenmp -o page_rank main.cpp Graph.cpp Vertex.cpp -DDYNAMIC=

echo "\n" >> runtime_comp_scheduling.csv
./page_rank 1 128 .2 inputs/web-NotreDame_sorted.txt runtime_comp_scheduling.csv
./page_rank 1 256 .2 inputs/web-NotreDame_sorted.txt runtime_comp_scheduling.csv
./page_rank 1 512 .2 inputs/web-NotreDame_sorted.txt runtime_comp_scheduling.csv
./page_rank 1 1024 .2 inputs/web-NotreDame_sorted.txt runtime_comp_scheduling.csv
./page_rank 1 2048 .2 inputs/web-NotreDame_sorted.txt runtime_comp_scheduling.csv

./page_rank 2 128 .2 inputs/web-NotreDame_sorted.txt runtime_comp_scheduling.csv
./page_rank 2 256 .2 inputs/web-NotreDame_sorted.txt runtime_comp_scheduling.csv
./page_rank 2 512 .2 inputs/web-NotreDame_sorted.txt runtime_comp_scheduling.csv
./page_rank 2 1024 .2 inputs/web-NotreDame_sorted.txt runtime_comp_scheduling.csv
./page_rank 2 2048 .2 inputs/web-NotreDame_sorted.txt runtime_comp_scheduling.csv

./page_rank 4 128 .2 inputs/web-NotreDame_sorted.txt runtime_comp_scheduling.csv
./page_rank 4 256 .2 inputs/web-NotreDame_sorted.txt runtime_comp_scheduling.csv
./page_rank 4 512 .2 inputs/web-NotreDame_sorted.txt runtime_comp_scheduling.csv
./page_rank 4 1024 .2 inputs/web-NotreDame_sorted.txt runtime_comp_scheduling.csv
./page_rank 4 2048 .2 inputs/web-NotreDame_sorted.txt runtime_comp_scheduling.csv

g++ -std=c++11 -g -Wall -lm -fopenmp -o page_rank main.cpp Graph.cpp Vertex.cpp -DGUIDED=

echo "\n" >> runtime_comp_scheduling.csv
./page_rank 1 128 .2 inputs/web-NotreDame_sorted.txt runtime_comp_scheduling.csv
./page_rank 1 256 .2 inputs/web-NotreDame_sorted.txt runtime_comp_scheduling.csv
./page_rank 1 512 .2 inputs/web-NotreDame_sorted.txt runtime_comp_scheduling.csv
./page_rank 1 1024 .2 inputs/web-NotreDame_sorted.txt runtime_comp_scheduling.csv
./page_rank 1 2048 .2 inputs/web-NotreDame_sorted.txt runtime_comp_scheduling.csv

./page_rank 2 128 .2 inputs/web-NotreDame_sorted.txt runtime_comp_scheduling.csv
./page_rank 2 256 .2 inputs/web-NotreDame_sorted.txt runtime_comp_scheduling.csv
./page_rank 2 512 .2 inputs/web-NotreDame_sorted.txt runtime_comp_scheduling.csv
./page_rank 2 1024 .2 inputs/web-NotreDame_sorted.txt runtime_comp_scheduling.csv
./page_rank 2 2048 .2 inputs/web-NotreDame_sorted.txt runtime_comp_scheduling.csv

./page_rank 4 128 .2 inputs/web-NotreDame_sorted.txt runtime_comp_scheduling.csv
./page_rank 4 256 .2 inputs/web-NotreDame_sorted.txt runtime_comp_scheduling.csv
./page_rank 4 512 .2 inputs/web-NotreDame_sorted.txt runtime_comp_scheduling.csv
./page_rank 4 1024 .2 inputs/web-NotreDame_sorted.txt runtime_comp_scheduling.csv
./page_rank 4 2048 .2 inputs/web-NotreDame_sorted.txt runtime_comp_scheduling.csv
