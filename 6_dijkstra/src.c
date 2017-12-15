#include <stdio.h>
#include <limits.h>
// 그래프의 정점 개수 
#define V 8
typedef int bool;
#define true 1
#define false 0

int distance[V]; // distance[i] : src부터 i까지의 최단 경로의 가중치 합
bool set[V]; // set[i] : i가 최단 경로 트리에 포함되는지의 여부
int parent[V]; // 최단 경로 트리를 저장하는 배열
char *cities[] = {
  "Los Angeles", "San Francisco", "Denver", "Chicago", 
  "Boston", "New York", "Miami", "New Orleans"
};
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
	printf("%s[%d] ", cities[target], target);
}

void dijkstra(int graph[V][V], int src){
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
		// 아직 처리되지 않은 정점들로부터 최단 거리인 정점을 고른다.
		// u는 항상 처음 반복에서의 src와 같다.
		int u = choose(distance, set);
		// 고른 정점을 처리된 것으로(최단 경로 트리에 포함되는 것으로) 표시한다.
		set[u] = true;
		// 고른 정점에 인접한 정점들의 거리값을 갱신한다.
		for (int v = 0; v < V; v++)
			// 다음과 같은 조건들이 모두 충족되면 distance[v](고른 정점에 인접한 정점들의 거리값)을 갱신한다.
			// 아직 최단 경로 트리에 포함되지 않는다.
			// u에서 v로 가는 간선이 있다.
			// 현재 distance[v]의 값보다 src부터 u를 통과하여 v로 가는 가중치의 합이 더 작다.
			if (!set[v] && graph[u][v] && distance[u] + graph[u][v] < distance[v]){
				parent[v] = u;
				distance[v] = distance[u] + graph[u][v];
			} 
	}
}

int main(){
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
	printf("From %s[%d] to %s[%d]\n", cities[start], start, cities[end], end);
	printf("+ Shortest distance => %d\n", distance[end]);
	printf("+ Shortest path => %s[%d] ", cities[start], start);
	print_path(parent, end); printf("\n");
	return 0;
}
