#include <stdio.h>
#include <limits.h>
// 그래프의 정점 개수 
#define V 8

typedef int bool;
#define true 1
#define false 0

// 최단 경로 트리에 포함되어 있지 않은 정점들 중 
// 최단인 정점 번호를 반환하는 함수
int choose(int distance[], bool set[]){
	// min 초기화
	int min = INT_MAX, min_index;

	for (int v = 0; v < V; v++)
		if (set[v] == false && distance[v] <= min)
			min = distance[v], min_index = v;

	return min_index;
}

// source 정점에서 target 정점까지의 최소 거리 경로 출력하는 함수
// parent[] 사용
void print_path(int parent[], int target){
	// 기저 조건 : target 정점이 source 정점일 때
	if (parent[target]==-1) return;
	print_path(parent, parent[target]);
	printf("%d ", target);
}

// Funtion that implements Dijkstra's single source shortest path
// algorithm for a graph represented using adjacency matrix
// representation
void dijkstra(int graph[V][V], int src){
	int distance[V]; // distance[i] : src부터 i까지의 최단 경로의 가중치 합
	bool set[V]; // set[i] == true, 정점 i가 최단 경로 트리에 포함되어
	int parent[V]; // 최단 경로 트리를 저장하는 배열
  int i;
	// 초기화
  for (i = 0; i < V; i++){
		parent[i] = -1;
		distance[i] = INT_MAX;
		set[i] = false;
	}

	distance[src] = 0; // src부터 src까지의 최단 경로의 가중치 합은 항상 0이다.

	// 모든 정점들에 대해 최단 경로를 찾는다.
	for (int count = 0; count < V-1; count++){
		// Pick the minimum distanceance vertex from the set of
		// vertices not yet processed. u is always equal to src
		// in first iteration.
		int u = choose(distance, set);

		// Mark the picked vertex as processed
		set[u] = true;

		// Update distance value of the adjacent vertices of the
		// picked vertex.
		for (int v = 0; v < V; v++)

			// Update distance[v] only if is not in set, there is
			// an edge from u to v, and total weight of path from
			// src to v through u is smaller than current value of
			// distance[v]
			if (!set[v] && graph[u][v] &&
				distance[u] + graph[u][v] < distance[v])
			{
				parent[v] = u;
				distance[v] = distance[u] + graph[u][v];
			} 
	}
}

int main()
{
	int graph[V][V] = {
    {    0,    0,    0,    0,    0,    0,    0,    0},
		{  300,    0,    0,    0,    0,    0,    0,    0},
		{ 1000,  800,    0,    0,    0,    0,    0,    0},
		{    0,    0, 1200,    0,    0,    0,    0,    0},
		{    0,    0,    0, 1500,    0,  250,    0,    0},
		{    0,    0,    0, 1000,    0,    0,  900, 1400},
		{    0,    0,    0,    0,    0,    0,    0, 1000},
		{ 1700,    0,    0,    0,    0,    0,    0,    0},
	};
  int start = 4, end = 0;
	dijkstra(graph, start);
  print_path(start, end);
	return 0;
}

