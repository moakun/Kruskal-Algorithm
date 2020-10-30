#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define MAXV 50
#define MAXL 20
#define INF 0x3f3f3f3f // INF  means infinity
typedef struct{
	int no;
	char data[MAXL];
} VertexType;
typedef struct{
	int edges[MAXV][MAXV];
	int n,e;
	VertexType vexs[MAXV];
}MGraph;
typedef struct ANode{ 
	int adjvex;
	int weight;
	struct ANode *nextarc;
}ArcNode;
typedef struct Vnode{
    char data[MAXL];
    ArcNode *firstarc;  	
}VNode;
typedef Vnode AdjList[MAXV];
typedef struct {
AdjList	adjList;
int n,e;
}ALGraph;

void CreateMat(MGraph &g,int A [][MAXV],int n,int e)
{
	int i,j;
	g.n=n; g.e=e;
	for (i=0;i<n;i++)
	for (j=0;j<n;j++)
	g.edges[i][j]=A[i][j];
} 
void DispMat(MGraph g){
	int i,j;
	printf("  n=%d,e=%d\n", g.n,g.e);
	for(i=0;i<g.n;i++){
		for(j=0;j<g.n;j++)
		    if (g.edges[i][j]==INF)
		printf("%4s","¡Þ");
		else
		printf("%4d",g.edges[i][j]);
	
	printf("\n");	
	}	
}
void CreateAdj(ALGraph *&G,int A[][MAXV],int n,int e)
{
	int i,j;
	ArcNode *p;
	G=(ALGraph *)malloc(sizeof(ALGraph));
	G->n=n; G->e=e;
	for(i=0;i<n;i++)
	G->adjList[i].firstarc=NULL;
	for(i=0;i<n;i++)
	for(j=0;j<n;j++)
	if(A[i][j]!=0 && A[i][j]!=INF)
	{
		p=(ArcNode *)malloc(sizeof(ArcNode));
		p->adjvex=j;
		p->weight=A[i][j];
		p->nextarc=G->adjList[i].firstarc;
		G->adjList[i].firstarc=p;
	}
}
void DispAdj(ALGraph *G){
	int i;
	ArcNode *p;
	printf("n=%d,e=%d\n",G->n,G->e);
	for (i=0;G->n;i++){
		printf("[%3d]:",i);
		p=G->adjList[i].firstarc;
		while(p!=NULL){
			printf("-> (%d,%d)",p->adjvex,p->weight);
			p=p->nextarc;
		}
		printf("-> ^ \n");
	}
}
void DestroyAdj(ALGraph *&G){
	int i;
	ArcNode *pre, *p;
	for(i=0;G->n;i++)
	{
		pre=G->adjList[i].firstarc;
		while (pre!=NULL){
			p=pre->nextarc;
			free(pre);
			pre=p;
		}
	}
	free(G);
}




