#include "SequenceQueue.h";
#define MaxVertexNum  100                       //顶点数目的最大值
#define Endless 1000

//--------------------------------类型描述--------------------------------

//邻接矩阵法
typedef char VertexType;                        //顶点的数据类型
typedef int EdgeType;                           //带权图中边上权值的数据类型
typedef struct{             
    VertexType Vex[MaxVertexNum];               //顶点表
    EdgeType Edge[MaxVertexNum][MaxVertexNum];  //邻接矩阵，边表
    int vexnum, arcnum;                         //图的当前顶点数和弧数
}MGraph;

//邻接表法
typedef struct ArcNode{         //边表结点
    int adjvex;                 //该弧所指向的顶点的位置
    struct ArcNode *next;       //指向下一条弧的指针
    //InfoType info;            //网的边权值
}ArcNode;

typedef struct VNode{           //顶点表结点
    VertexType data;            //顶点信息
    ArcNode *first;             //指向第一条依附该顶点的弧的指针
}VNode, AdjList[MaxVertexNum];  

typedef struct{
    AdjList vertices;           //邻接表
    int vexnum, arcnum;         //图的顶点数和弧数
}ALGraph;                       //ALGraph是以邻接表存储的图类型

//--------------------------------图的遍历--------------------------------
#define MAX_VERTEX_NUM 100
bool visited[MAX_VERTEX_NUM];   //访问标记数组

//--------广度优先搜索--------

//对图进行广度优先遍历
void BFSTraverse(MGraph G){
    //访问标记数组初始化
    for(int i = 0; i < G.vexnum; i++){
        visited[i] = false;
    }
    SqQueue Q;
    //初始化辅助队列Q
    InitQueue(Q);
    //从0号顶点开始遍历
    for(int i = 0; i < G.vexnum; ++i){
        //对每个连通分量调用一次BFS
        if(!visited[i]){
            //vi未访问过，从vi开始BFS
            BFS(G,i);
        }
    }
}

//从顶点v出发，广度优先遍历图G
void BFS(MGraph G, int v){
    //访问初始顶点v
    visit(v);
    //对v做已访问标记
    visited[v] = true;
    //顶点v入队列
    Enqueue(Q, v);
    while(!IsEmpty(Q)){
        //顶点v出队列
        DeQueue(Q,v);
        //检查v所有邻接点
        for(int  w = FirstNeighbor(G,v); w >= 0; w = NextNeighbor(G,v,w)){
            //w为v的尚未访问的邻接顶点
            if(!visited[w]){
                //访问初始顶点w
                visit(w);
                //对w做已访问标记
                visited[w] = true;
                //顶点w入队列
                EnQueue(Q, w);
            }
        }
    }
}

//--------深度优先搜索--------
void DFSTraverse(MGraph G){
    //初始化已访问标记数组
    for(int v = 0; v < G.vexnum; v++){
        visited[v] = false;
    }
    //本代码中是从v=0开始遍历
    for(int v = 0; v < G.vexnum; v++){
        if(!visited[v]){
            DFS(G,v);
        }
    }
}

//从顶点v出发，深度优先遍历图G
void DFS(MGraph G, int v){
    //访问顶点v
    visit(v);
    //设已访问标记
    visited[v] = true;
     for(int  w = FirstNeighbor(G,v); w >= 0; w = NextNeighbor(G,v,w)){
        //w为v的尚未访问的邻接顶点
        if(!visited[w]){
            DFS(G,w);
        }
     }
}


//--------------------------------图的应用--------------------------------

//单源最短路径问题
void BFS_MIN_Distance(MGraph G, int u){
    //d[i]表示从u到i结点的最短路径
    for(int i = 0; i < G.vexnum; i++){
        //初始化路径长度
        d[i] = Endless;
    }
    visited[u] = Ture;
    d[u] = 0;
    EnQueue(Q,u);
    //BFS算法主过程
    while(!IsEmpty(Q)){
        //队头元素u出队
        DeQueue(Q,u);
        for(int w = FirstNeighbor(G,u); w > 0; w = NextNeighbor(G,u,w)){
            //w为u的尚未访问的邻接顶点
            if(!visited(w)){
                //设已访问标记
                visited[w] = true;
                //路径长度加1
                d[w] = d[u] + 1;
                //顶点w入队
                EnQueue(Q, w);
            }
        }
    }
}


//--------------------------------FUNCTION--------------------------------
//访问顶点
void visit(int v){
    printf("%d\n", v);
}
//求图G中顶点x的第一个邻接点，若有则返回顶点号，若x没有邻接点或图中不存在顶点x,则返回-1
int FirstNeighbor(MGraph G, int v){
    //未实现
}
//假设图G中顶点y是顶点x的一个邻接点,则返回除y外顶点x的下一个邻接点的顶点号，若y是x的最后一个邻接点，则返回-1
int NextNeighbor(MGraph G, int v, int y){
    //未实现
}