#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAX_VERTICES 8
#define TRUE 1
#define FALSE 0

int weight[MAX_VERTICES][MAX_VERTICES] = {
  {   0,    0,    0,    0,    0,    0,    0,    0}, 
  { 300,    0,    0,    0,    0,    0,    0,    0}, 
  {1000,  800,    0,    0,    0,    0,    0,    0}, 
  {   0,    0, 1200,    0,    0,    0,    0,    0}, 
  {   0,    0,    0, 1500,    0,  250,    0,    0}, 
  {   0,    0,    0, 1000,    0,    0,  900, 1400}, 
  {   0,    0,    0,    0,    0,    0,    0, 1000}, 
  {1700,    0,    0,    0,    0,    0,    0,    0}
}; 
char *cities[] = {
  "Los Angeles", "San Francisco", "Denbur", "Chicago", 
  "Boston", "New York", "Miami", "New Orleans"
};
int distance[MAX_VERTICES]; // 시작 정점으로부터의 최단 경로 거리
int found[MAX_VERTICES]; // 방문한 정점 표시
int parent[MAX_VERTICES];
// 최단 경로에 포함되지 않은 정점들 중에서 최단 거리를 갖는 정점을 찾는 함수.
int choose(int distance[], int found[]){
  int i, min = 0, minpos;
  for(i=0;i<MAX_VERTICES;i++){
    if(found[i] == FALSE && distance[i] <= min){
      min = distance[i], minpos = i;
    }
  }
  return minpos;
}
void print_path(int parent[], int j){
  if(parent[j]==-1) return;
  print_path(parent, parent[j]);
  printf("%13s[%d]->", cities[j], j);
}
void print_solution(int src, int distance[], int parent[]){
  int i;
  for(i=0;i<MAX_VERTICES;i++){
    printf("\n%13s[%d]=>%13s[%d] : %4d\n%13s[%d]->", cities[src], src, cities[i], i, distance[i], cities[src], src);
    print_path(parent, i);
  }
}
// Dijkstra 최단 경로 알고리즘, 인접 행렬 표현 방식의 그래프를 위한 함수.
void shortest_path(int start){
  int i, u, w;
  for(i=0;i<MAX_VERTICES;i++){ // Initialization.
    parent[i] = -1;
    distance[i] = INT_MAX/2;
    found[i] = FALSE;
  }
  distance[start] = 0;
  for(i=0;i<MAX_VERTICES-1;i++){
    u = choose(distance, found);
    found[u] = TRUE;
    for(w=0;w<MAX_VERTICES;w++)
      if(!found[w] && weight[u][w] != 0 && distance[u]+weight[u][w] < distance[w]){
        parent[w] = u;
        distance[w] = distance[u]+weight[u][w];
      }
  }
}

int main(){
  int start = 4;
  shortest_path(start);
  print_solution(start, distance, parent);
  return 0;
}
