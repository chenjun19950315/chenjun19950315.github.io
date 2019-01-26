
#ifndef CIRCLE_H
#define CIRCLE_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include<numeric>
#include <list>
#include<iterator>
#include <map>
#include <utility>
#include <set>
#include <unordered_map>
#include<memory>
#include <cstring>
#include <stdlib.h>
#include <math.h>
#include <Windows.h>
#include <time.h>
using namespace std;
const int MAXSIZE = 10000;


//树结构
//二叉树，链式存储
typedef int TreeElementType;
typedef struct TNode* BinTree;
struct TNode {
	TreeElementType data;
	BinTree left;
	BinTree right;
};
//创建二叉树
BinTree createBinTree();
//层序遍历
void LevelorderTraversal(BinTree BT);
//中序遍历，递归
void InorderTraversal(BinTree BT);
//中序遍历，非递归
void InorderTraversal1(BinTree BT);
//先序遍历
void PreorderTraversal(BinTree BT);
//先序遍历,非递归
void PreorderTraversal1(BinTree BT);
//后序遍历
void PostTraversal(BinTree BT);
//后序遍历,非递归
void PostTraversal1(BinTree BT);
//输出树中的叶子节点,只需在遍历的时候碰到叶子节点就输出
void PreorderTraversalLeaves(BinTree BT);
//得到树的高度
int GetHeight(BinTree BT);

//二叉搜索树
//查找，递归，输入要查找的二叉搜索树和元素，如果找到，返回对应元素的地址，否则返回NULL
BinTree searchBiTreeNode(BinTree BT, TreeElementType key);
//查找，非递归，输入要查找的二叉搜索树和元素，如果找到，返回对应元素的地址，否则返回NULL
BinTree searchBiTreeNode1(BinTree BT, TreeElementType key);
//查找出搜索二叉树的最大值，并返回最大值的地址
BinTree searchMaxBiTreeNode(BinTree BT);
//查找出搜索二叉树的最小值，并返回最大值的地址
BinTree searchMinBiTreeNode(BinTree BT);
//搜索二叉树的插入操作,返回插入成功后的根节点
BinTree BiTreeInsert(BinTree BT,TreeElementType key);
//搜索二叉树的删除操作,返回插入成功后的根节点
BinTree BiTreeDelete(BinTree BT, TreeElementType key);

//最大堆
#define HEAPMAXDATA 10000
#define HEAPMINDATA -10000
typedef int HeapElementType;
struct HeapNode
{
	HeapElementType *data;
	int size;
	int capacity;
};

typedef HeapNode * Heap;
typedef Heap MaxHeap,MinHeap;
//创建一个空的最大堆，容量为maxsize,下标从1开始，0存放哨兵
bool HeapIsFull(MaxHeap h);
bool HeapIsEmpty(MaxHeap h);
void HeapDisplay(MaxHeap h);

//最大堆的操作
MaxHeap CreateMaxHeap(int maxsize);
bool MaxHeapInsert(MaxHeap h, HeapElementType data);
void MaxPerDown(MaxHeap h, int p);
HeapElementType MaxHeapDelete(MaxHeap h);
//对于一个无序的堆，对其进行快速建堆，比直接插入速度快
void BuildMaxHeap(MaxHeap h);
//最小堆的操作
MinHeap CreateMinHeap(int maxsize);
bool MinHeapInsert(MinHeap h, HeapElementType data);
HeapElementType MinHeapDelete(MinHeap h);
//对于一个无序的堆，对其进行快速建堆，比直接插入速度快
void MinPerDown(MinHeap h, int p);
void BuildMinHeap(MinHeap h);

//####哈夫曼树#######//
typedef struct HTNode * HuffmanTree;
struct HTNode
{
	int weight;
	HuffmanTree left;
	HuffmanTree right;
};
//建立哈夫曼树，用最小堆建立
HuffmanTree BuildHuffman(MinHeap h);

//#########集合，集合##################
#define MAXN 1000
typedef int SetType[MAXN];
void BuildSet(int set[],int a[],int n);//将是一个集合a的元素并入set集合中
int SetFind(int set[], int x);//在集合中查找元素x所属的集合
void SetUnion(int set[], int x1, int x2);//将x1,x2所在的集合合并

//顺序存储的单链表
struct SeqList {
	int elem[MAXSIZE];
	int last;
};
void Init(SeqList *l);//初始化一个单链表，初始化10个数
int Locate(SeqList l,int num);//输入要查找的数num,成功则返回数的位置，失败返回0
void Print(SeqList l);//打印单链表的数
int Insert(SeqList *l, int locate, int num);  //输入插入的位置locate和要插入的数num，返回1为插入成功，0为失败;
int Del(SeqList *l, int locate); //输入插入的位置locate，返回1为删除成功，0为删除失败; 
void merge(SeqList *l1, SeqList *l2, SeqList *l3);//合并两个单链表




//链式存储的单链表
typedef struct Node
{
	char data;
	struct Node *next;
}Node, *LinkList;

void InitList(LinkList H);
void DisplayList(LinkList h);
void CreateFromTail(LinkList h);//尾插法，单链表的逻辑顺序与输入元素顺序相同
Node *Get(LinkList h, int i);//查找，按序号查找
Node *Locate(LinkList h, char c);//查找，按值查找
int InsList(LinkList h, int i, char c);//插入,
void InsSlist(LinkList h, char c);//将元素插入有序表，插入后同样有序
bool DelList(LinkList h, int);//删除，并返回判断
void DelLlist(LinkList h, int i,int k);//删除，删除自第i个元素开始的k个元素
int ListLength(LinkList h);//计算长度
void Difference(LinkList la, LinkList lb);//两个集合之差
void reverseList(LinkList h);//逆转单链表
LinkList mergeList(LinkList la, LinkList lb);//两个有序链表的合并合并后仍有序


//建立双向链表
typedef struct DNode
{
	char data;
	DNode *prior;
	DNode *next;
}DNode,*DoubleList;
void InitList(DoubleList *H);


//多项式
typedef struct Polynode
{
	int coef;
	int exp;
	struct Polynode *next;
}Polynode,*Polylist;

//建立多项式链表
void DisplayPolylist(Polylist h);//展示多项式
Polylist polycreate();//创建多项式
void polyadd(Polylist polya, Polylist polyb);//多项式相加


//顺序栈
#define TURE 1
#define FALSE 0
#define Stack_Size 500
typedef BinTree StackElementType;
typedef struct
{
	StackElementType elem[Stack_Size];
	int top;
}SeqStack;
void InitStack(SeqStack *s);//初始化顺序栈
int IsEmpty(SeqStack *s);//判断是否为空
int IsFull(SeqStack *s);//判断是否为满
int push(SeqStack *s, StackElementType e);//进栈
StackElementType pop(SeqStack *s);//出栈
StackElementType Getpop(SeqStack *s);//取栈顶元素
void MediuToBack(string s);//中缀变后缀

//共享栈
#define M 100
typedef struct
{
	int elem[M];
	int top[2];//定义两个栈顶指示器
}DqStack;
void DisplayDq(DqStack *s);//输出栈
void InitStack(DqStack *s);//初始化共享栈
int push(DqStack *s, int e,int i);//进栈
int pop(DqStack *s,  int i);//出栈
int Getpop(DqStack *s, int i);//出栈
void Conversion(int N, int d);//num为要转化的数，d为要转化的进制

//括号匹配
void BracketMatch(string &s);//括号匹配
int Match(char c1, char c2);//括号匹配辅助函数

//表达式求值，无括号
void CompuerNum();

//运算符比较,简化版，-,+和*
int Compare(char c1, char c2);
int Change(string s);//字符转化为数字


//fib递归
void Hanoi(int n,char x,char y,char z);
int Fib(int n);
int Fib1(int n);//非递归


//队列
typedef BinTree QueueElementType;
typedef struct Node1 {
	QueueElementType data;
	struct Node1 *next;
}LinkQueueNode;
typedef struct {
	LinkQueueNode *front;
	LinkQueueNode *rear;
}LinkQueue;
bool IsEmptyQueue(LinkQueue *q);
int InitQueue(LinkQueue *q);
int EnterQueue(LinkQueue *q, QueueElementType x);
QueueElementType DeleteQueue(LinkQueue *q);
//循环队列
#define MAXSIZE 100
typedef struct
{
	int  element[MAXSIZE];
	int front;
	int rear;
}SeqQueue;
void InitQueue(SeqQueue *q);
int EnterQueue(SeqQueue *q,int x);
int DeleteQueue(SeqQueue *q, int &x);
int IsEmpty(SeqQueue *q);
int GetHead(SeqQueue*q, int &x);
void Triangle(int row);




//字符串
typedef struct
{
	char ch[MAXSIZE];
	int len;
}sstring;
int StrInsert(sstring *s, int pos, sstring *t);
int StrDelete(sstring *s, int pos, int len);
int StrCopy(sstring *s, sstring *t);
int StrEmpty(sstring *s);
int StrCompany(sstring *s,sstring *t);
int SteLen(sstring *s);
int StrCat(sstring *s, sstring *t);
int StrString(sstring *s, sstring *t,int pos, int len);
int StrIndex(sstring *s, int pos, sstring *t);





//排序
typedef int ElementType;
//简单选择排序
void SimpleSelectionSort(ElementType a[],int N);
//堆排序
void percDown(ElementType a[], int p, int N);
void HeapSort(ElementType a[], int N);
//直接插入排序
void InsertionSort(ElementType a[], int N);
//希尔排序
void ShellSort(ElementType a[], int N);
//冒泡排序
void BubbleSort(ElementType a[], int N);
//快速排序
int median3(ElementType a[], int left, int right);
void QSort(ElementType a[], int left, int right);
void QuickSort(ElementType a[], int N);
//归并排序
void Merge(ElementType a[], ElementType temp[], int left, int right, int rightEnd);
void MSort(ElementType a[],ElementType temp[], int left, int rightEnd);
void MergeSort(ElementType a[], int N);
//基数排序
#define MaxDigit 4
#define Radix 10


//散列查找,开放地址法
#define MAXTABLESIZE 10000
typedef int ElementType;
typedef int Index;
typedef Index Position1;
typedef enum{legitimate,Empty,Deleted} EntryType;

struct HashEntry {
	ElementType data;
	EntryType info;
};
typedef HashEntry cell;
struct TblNode {
	int TableSize;
	cell *cells;
};
typedef TblNode* HashTable;
bool isPrime(int n);
int nextPrime(int tableSize);//返回不小于tableSizede 素数
HashTable CreateHash(int TableSize);
Position1 Find(HashTable H, ElementType key);
bool Insert(HashTable H, ElementType key);
bool Delete(HashTable H, ElementType key);

//分离链接法


//查找
//顺序查找,有哨兵
int SequentialSearch(SeqList *l, int k);
//二分查找
int BinarySearch(SeqList *l, int k);

//图

#define MaxVertexNum 100 //最大顶点数
#define INFINITY 65535 //设置一个无穷大的值,表示两顶点间没有边

typedef int Vertex;  
typedef int WeightType;
typedef char DataType;
struct GNode {
	int nv;//顶点数
	int ne;//边数
	WeightType G[MaxVertexNum][MaxVertexNum];  //邻接矩阵
//	DataType Data[MaxVertexNum];   //存顶点的数据
};
typedef struct GNode *ptrToGNode;
typedef ptrToGNode MGraph;

struct ENode
{
	Vertex v1, v2;
	WeightType Weight;
};
typedef struct ENode *ptrToENode;
typedef ptrToENode Edge;
MGraph CreateGraph(int VertexNum);
void DisplayMGraph(MGraph Graph);
void InsertEdge(MGraph Graph,Edge E);
MGraph BuildGraph();
void Visit(Vertex V);
void DFS(MGraph Graph, Vertex V);
//单源最短路径Dijkstra
Vertex FindMinDist(MGraph Graph, int dist[], int collected[]);
void Dijkstra(MGraph Graph, Vertex s, int dist[], int path[]);
//多源最短路径
void Floyd(MGraph Graph, int D[MaxVertexNum][MaxVertexNum], int path[MaxVertexNum][MaxVertexNum]);
//最小生成树,MST为邻接矩阵表示的最小生成树,返回总权重
Vertex FindMinDistTree(MGraph Graph, int dist[]);
WeightType prim(MGraph Graph, MGraph MTS);



//马拉车算法及应用
void addSpecialChar(string &arr);
int manacgher(string &arr);
string	palindromic_sequence(string &arr);
#endif
