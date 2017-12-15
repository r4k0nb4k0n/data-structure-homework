#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#define MIN(x, y) (x<y)?(x):(y)
#define MAX_VERTICES 8
#define INF INT_MAX/2
#define TRUE 1
#define FALSE 0

int weight[MAX_VERTICES][MAX_VERTICES] = {
  {   0,  INF,  INF,  INF,  INF,  INF,  INF,  INF}, 
  { 300,    0,  INF,  INF,  INF,  INF,  INF,  INF}, 
  {1000,  800,    0,  INF,  INF,  INF,  INF,  INF}, 
  { INF,  INF, 1200,    0,  INF,  INF,  INF,  INF}, 
  { INF,  INF,  INF, 1500,    0,  250,  INF,  INF}, 
  { INF,  INF,  INF, 1000,  INF,    0,  900, 1400}, 
  { INF,  INF,  INF,  INF,  INF,  INF,    0, 1000}, 
  {1700,  INF,  INF,  INF,  INF,  INF,  INF,    0}
}; 
char *cities[] = {
  "로스엔젤레스", "샌프란시스코", "덴버", "시카고", 
  "보스턴", "뉴욕", "마이애미", "뉴올리언즈"
};
int distance[MAX_VERTICES] = {0}; // 시작 정점으로부터의 최단 경로 거리
int found[MAX_VERTICES] = {0}; // 방문한 정점 표시
int parent[MAX_VERTICES] = {0};
// 최단 경로에 포함되지 않은 정점들 중에서 최단 거리를 갖는 정점을 찾는 함수.
int choose(int distance[], int n, int found[]){
  int i, min, minpos;
  min = INT_MAX;
  minpos = -1;
  for(i=0;i<n;i++){
    if(distance[i] < min && !found[i]){
      min = distance[i];
      minpos=i;
    }
  }
  return minpos;
}
void print_path(int parent[], int j){
  if(parent[j]==-1) return;
  print_path(parent, parent[j]);
  printf("%s[%d] ", cities[j], j);
}
void print_solution(int src, int distance[], int n, int parent[]){
  int i;
  for(i=0;i<MAX_VERTICES;i++){
    printf("\n%d -> %d \t %d\t", src, i, distance[i]);
    print_path(parent, i);
  }
}
// Dijkstra 최단 경로 알고리즘을 인접 행렬 표현 방식의 그래프를 위한 함수.
void shortest_path(int start, int n){
  int i, u, w;
  for(i=0;i<n;i++){
    parent[i] = -1;
    distance[i] = weight[start][i];
    found[i] = FALSE;
  }
  found[start] = TRUE; // 시작 정점 방문 표시
  distance[start] = 0;
  for(i=0;i<n;i++){
    u = choose(distance, n, found);
    found[u] = TRUE;
    for(w=0;w<n;w++)
      if(!found[w] && distance[u]+weight[u][w] < distance[w]){
        parent[w] = u;
        distance[w] = distance[u]+weight[u][w];
      }
  }
}

int main(){
  int start = 4, i;
  shortest_path(start, MAX_VERTICES);
  for(i=0;i<MAX_VERTICES;i++)
    printf("%12s부터 %14s까지 => %d\n", cities[start], cities[i], distance[i]);
  print_solution(start, distance, MAX_VERTICES, parent);
  return 0;
}
