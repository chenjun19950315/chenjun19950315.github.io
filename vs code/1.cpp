#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include<array>
#include<forward_list>
#include <algorithm>
#include<numeric>
#include <list>
#include<iterator>
#include <map>
#include <utility>
#include <random>
#include <set>
#include <unordered_map>
#include<memory>
#include <cstring>
#include <stdlib.h>
#include <math.h>
#include <Windows.h>
#include <time.h>
#include<deque>
#include<queue>
#include<assert.h>
#include <functional>
#include <stdexcept>
#include<stack>
#include"List.h"
#include "stdio.h"
#include "conio.h"
using namespace std;
using namespace std::placeholders;
#define  _SCL_SECURE_NO_WARNINGS


long long merge(vector<int> &arr, vector<int> &help, int l, int mid, int r)
{
	long long sum = 0;
	int p = l;
	int p1 = l;
	int p2 = mid + 1;
	while (p1 <= mid &&p2 <= r)
	{
		if (arr[p1] <= arr[p2])
			help[p++] = arr[p1++];
		else
		{
			sum = sum + (mid - p1 + 1);
			help[p++] = arr[p2++];
		}
	}
	while (p1 <= mid)
		help[p++] = arr[p1++];
	while (p2 <= r)
		help[p++] = arr[p2++];
	for (int i = l; i <= r; i++)
		arr[i] = help[i];
	return sum;
}
long long mergeSort(vector<int> &arr, vector<int> &help, int l, int r)
{

	if (l >= r)
		return 0;
	int mid = l + ((r - l) >> 1);
	return mergeSort(arr, help, l, mid) + mergeSort(arr, help, mid + 1, r) + merge(arr, help, l, mid, r);
}

long long InversePairs(vector<int> data) {

	vector<int> help(data);

	if (data.size() <= 1)
		return 0;
	return (mergeSort(data, help, 0, data.size() - 1) % 1000000007);
}
long long rightMathod(vector<int> &arr)
{
	if (arr.size() <= 1)
		return 0;
	long long sum = 0;
	auto begin = arr.begin();
	auto end = arr.end();
	//sort(begin, end);
	for (auto it = begin; it != end - 1; it++)
		for (auto it1 = it + 1; it1 != end; it1++)
		{
			if (*it > *it1)
				++sum;
		}
	return sum;
}
LinkList listRerverse(LinkList head)
{
	if (head->next == nullptr)
		throw - 1;
	LinkList q, q1;
	LinkList p = nullptr;
	q = head->next;
	while (q!= nullptr)
	{
		q1 = q->next;
		q->next = p;
		p = q;
		q = q1;
	}
	head->next = p;
	return head;

}
void partition(char str[], char pivot,int length)
{
	int less = -1;
	int more = length + 1;
	int cur = 0;
	while (cur < more)
	{
		if (str[cur] == pivot)
			cur++;
		else if (str[cur] < pivot)
			swap(str[cur++] , str[++less]);
		else
			swap(str[--more],str[cur])  ;
	}
}
void listPartition1(LinkList head,char pivot)
{
	char str[100];//用一个数组来保存链表的元素，然后对元素进行荷兰国旗问题的排序，然后再将链表串起来
	int length = 0;
	LinkList p = head;
	while (p->next != nullptr)
	{
		p = p->next;
		str[length++] = p->data;
	}
	partition(str, pivot, length - 1);
	p = head;
	int i = 0;
	while (p->next != nullptr)
	{
		p = p->next;
		p->data = str[i++];	
	}	
}
//思路:设置三个链表，分别是小于，等于，大于pivot的链表，遍历整个链表，形成这三个小链表，最后串起这三个链表
void listPartition2(LinkList head, char pivot)
{
	LinkList sH = nullptr;   //小于pivot的链表头
	LinkList sT = nullptr;//小于pivot的链表尾
	LinkList qH = nullptr;   //等于pivot的链表头
	LinkList qT = nullptr;//等于pivot的链表尾
	LinkList bH = nullptr;   //大于pivot的链表头
	LinkList bT = nullptr;//大于pivot的链表尾
	LinkList p = head;
	//遍历整个链表，形成这三个小链表
	while (p->next != nullptr)
	{
		p = p->next;
		if (p->data < pivot) {
			if (sH == nullptr) {
				sH = p;
				sT = p;
			}
			else {
				sT->next = p;
				sT = p;
			}
		}

		else if (p->data == pivot) {
			if (qH == nullptr) {
				qH = p;
				qT = p;
			}
			else {
				qT->next = p;
				qT = p;
			}
		}
		else
		{
			if (bH == nullptr) {
				bH = p;
				bT = p;
			}
			else {
				bT->next = p;
				bT = p;
			}
		}
	}
	//给链表最后加结束符，如果大于的链表有数，则加在大于链表，否在判断等于的链表是否为空，不为空加在等于的链表末位，为空则判断小于的链表是否
	//为空，不为空则加在小于链表的末位

	if (bT != nullptr)
		bT->next = nullptr;
	else {
		if (qT != nullptr)
			qT->next = nullptr;
		else
			if (sT != nullptr)
				sT->next = nullptr;
	}
	
	//将三个链表串起来，注意链表为空的状态
	if (sH != nullptr)
	{
		head->next = sH;
		if (qH != nullptr)
		{
			sT->next = qH;
			if (bH != nullptr)
				qT->next = bH;
		}
		else {
			if (bH != nullptr)
				sT->next = bH;
		}
	}
	else {
		if (qH != nullptr)
		{
			head->next = qH;
			if (bH != nullptr)
				qT->next = bH;
		}
		else {
			if (bH != nullptr)
				head->next = bH;
		}
	}


}
void CreateRingList(LinkList h)
{
	char data;
	int flag = 1;
	Node *s;
	Node *r;
	r = h;

	while (flag)
	{
		cin >> data;
		if (data != '$')
		{
			s = new Node;
			s->data = data;
			r->next = s;
			r = s;

		}
		else
		{
			flag = 0;
			r->next = h->next;
		}
	}
}
//判断单链表是否有环，输入单链表头结点，如果没有返回nullptr，如果有返回第一个环节点
//思路:只需要用set（哈希函数)保存,链表中的节点，遍历链表的时候如果发现有重复的值，则该点就是环节点，否则直到链表尾都没有重复，则说明没有环
LinkList isRing(LinkList head)
{
	if (head == nullptr || head->next == nullptr || head->next->next == nullptr)
		return nullptr;
	LinkList slow = head->next;
	LinkList fast = head->next->next;
	while (fast !=  slow)
	{

		if (fast->next != nullptr && fast->next->next != nullptr)
		{
			slow = slow->next;
			fast = fast->next->next;
		}
		else
			return nullptr;
	}
	fast = head;
	while (fast != slow)
	{
		fast = fast->next;
		slow = slow->next;
	}
	return fast;
}
int ringLength(LinkList head)
{
	if (isRing(head) == nullptr)
		return 0;
	else {
		int length = 1;
		LinkList p = isRing(head);
		if (p->next == p)
			return 1;
		LinkList p1 = p->next;
		while (p1 != p)
		{
			p1 = p1->next;
			length++;

		}
		return length;

	}
}
int allRingLength(LinkList head)
{
	int allLength = 0;
	if (isRing(head) == nullptr)
	{
		LinkList p = head;
		while (p->next != nullptr)
		{
			p = p->next;
			allLength++;
		}
		return allLength;
	}

	else {
		LinkList p=head ;
		LinkList p1 = isRing(head);
		while (p->next != p1)
		{
			p = p->next;
			allLength++;
		}
		allLength = ringLength(head) + allLength;
		return allLength;
	}
}
LinkList oneIsRing(LinkList head1, LinkList head2)
{
	LinkList p1 = head1;
	LinkList p2 = head2;
	int length1 = 0;
	int length2 = 0;
	while (p1->next != nullptr)
	{
		p1 = p1->next;
		length1++;
	}
	while (p2->next != nullptr)
	{
		p2 = p2->next;
		length2++;
	}
	if (p1 != p2)   //判断两个链表的尾端是否一致，如果不一致则不相交
		return nullptr;
	else {                //否则相交，计算两个链表的长度的差值，让长的链表先next到差值，再两链表逐个比较直到找到第一个相交的点为止
		p1 = length1 > length2 ? head1 : head2;
		p2 = p1 == head1 ? head2 : head1;
		int a = abs(length1 - length2);
		while (a-- > 0)
			p1 = p1->next;
		while (p1 != p2)
		{
			p1 = p1->next;
			p2 = p2->next;
		}
		return p1;
	}
}
LinkList bothIsRing(LinkList head1, LinkList head2)
{
	LinkList loop1 = isRing(head1);
	LinkList loop2 = isRing(head2);
	if (loop1 == loop2)//三种情况详见左神初级班4-1，2:29:31
	{
		LinkList p1 = head1;
		LinkList p2 = head2;
		int length1 = 0;
		int length2 = 0;
		while (p1->next != loop1)
		{
			p1 = p1->next;
			length1++;
		}
		while (p2->next != loop2)
		{
			p2 = p2->next;
			length2++;
		}
		              //否则相交，计算两个链表的长度的差值，让长的链表先next到差值，再两链表逐个比较直到找到第一个相交的点为止
		p1 = length1 > length2 ? head1 : head2;
		p2 = p1 == head1 ? head2 : head1;
		int a = abs(length1 - length2);
		while (a-- > 0)
			p1 = p1->next;
		while (p1 != p2)
		{
			p1 = p1->next;
			p2 = p2->next;
		}
		return p1;
	}
	else {
		LinkList cur1 = loop1;
		while (cur1 != loop1)
		{
			if (cur1 == loop2)
				return cur1;
			cur1 = cur1->next;
		}
		return nullptr;

	}
}


//判断两个链表是否相交，如果相交返回相交点，否则返回空
LinkList twoLinkListisRing(LinkList head1, LinkList head2)
{
	if (head1 == nullptr || head2 == nullptr)
		return nullptr;
	if (isRing(head1) == nullptr && isRing(head2) == nullptr)
		oneIsRing(head1, head2);  //当两个链表都没有环的时候
	else if (isRing(head1) != nullptr && isRing(head2) != nullptr)
		bothIsRing(head1,head2);//当链表有一个环时
	else  //当一个有环，一个没有环的时候不可能相交
		return nullptr;
}

//已知一棵完全二叉树，求其节点的个数
//要求：时间复杂度低于O(N)，N为这棵树的节点个数
//思路:根据完全二叉树的特点，加速计算的过程，通过遍历最左的子树可以得到树的高度，遍历根节点的右子树的最左子树，可以判断
//根节点的左子树是否为满二叉树，如果为满二叉树，则计算出根节点的左子树的个数，并遍历根节点的右子树
//如果不是，则根节点的右子树为满二叉树，计算出个数，并遍历根节点的左子树
int completeTreeNum(BinTree bt)
{
	if (bt == nullptr||bt->left==nullptr) //如果是叶子节点返回1
		return 1;
	if (bt->right == nullptr)  //如果只有右子树返回2
		return 2;
	int sum = 0;
	BinTree p = bt;
	int lh=0;//记录最左子树的高度
	int rh=1;//记录根节点的右子树的最左子树的高度
	while (p != nullptr)
	{
		lh++;
		p = p->left;
	}
	p = bt->right;
	
	while (p != nullptr)
	{
		rh++;
		p = p->left;
	}
	
	if (lh > rh)
	{
		sum = sum + pow(2, rh-1);
		sum += completeTreeNum(bt->left);
	}
	else if (lh == rh)
	{
		sum = sum + pow(2, lh-1) ;
		sum += completeTreeNum(bt->right);
	}
	return sum;
}
bool com(string s1, string s2)
{
	return s1 + s2 < s2 + s1;
}
//哈夫曼树的思路，用最小堆实现，可以将其权重看成是1
int goldFold(vector<int>& str)
{
	if (str.size() == 0)
		return 0;
	if (str.size() == 1)
		return str[0];
	priority_queue<int, vector<int>, greater<int>> q{str.begin(),str.end()};
	int sum = 0;
	int t1,t2,t;
	while (q.size()>=2)
	{
		t1 = q.top();
		q.pop();
		t2 = q.top();
		q.pop();
		t = t1 + t2;
		q.push(t);
		sum = sum + t;
	}
	return sum;

}


vector<int> generateRandomArray(int size, int value)
{
	uniform_int_distribution<unsigned> u1(0, size);
	uniform_int_distribution<unsigned> u2(0, value);
	default_random_engine e(time(0));
	int n = u1(e);
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
		arr[i] = u2(e) - u2(e);
	return arr;
}
vector<int> copyArray(vector<int> &old)
{

	vector<int> newArray(old.size());
	for (int i = 0; i < old.size(); ++i)
		newArray[i] = old[i];
	return newArray;

}

void printArray(vector<int> arr)
{
	for (auto it = arr.begin(); it != arr.end(); it++)
		cout << *it << " ";
	cout << endl;
}
int rightMethod(vector<int> &arr,int k)
{
	sort(arr.begin(), arr.end());
	return arr[k];
}
vector<int> patition(vector<int> &arr, int num,int left, int right)//已知划分值
{
	
	vector<int> result;

	int less = left - 1;
	int more = right+1 ;
	int cur = left;
	while (cur <more) {
		if (arr[cur] < num)
			swap(arr[++less] , arr[cur++]);
		else if (arr[cur] == num)
			cur++;
		else
			swap(arr[--more] ,arr[cur]);
	}
	result.push_back(less);
	result.push_back(more);
	return result;
}
void printEdge(BinTree bt) {
	stack<BinTree> s;
	BinTree bt1 = bt;
	while (bt1 != nullptr) {
		s.push(bt1);
		bt1 = bt1->right;
	}
	while (!s.empty()) {
		cout << s.top()->data << endl;
		s.pop();
	}
}
void morridTraversal(BinTree bt)
{
	if (!bt)
		return ;
	BinTree cur = bt;
	BinTree mostRight;
	while(cur!=nullptr){
	if (cur->left != nullptr) {
		mostRight = cur->left;
		while (mostRight->right != nullptr&&mostRight->right != cur)
			mostRight = mostRight->right;
		if (mostRight->right == nullptr) {
			mostRight->right = cur;
			cur = cur->left;
		}
		else {
			
			//cout << cur->data << endl;
			mostRight->right = nullptr;
			printEdge(cur->left);
			cur = cur->right;
		}
	}
	else
              	cur = cur->right;
	
	}
	printEdge(bt);
}
//用indice记录下，排序后的数在排序前的位置，同时对数组进行排序
void sortTwo(vector<int> &arr, vector<int> &indice)
{
	int id;//记录要替换的位置
	int t;//设置一个临时变量
	for(int i=0;i<arr.size()-1;i++){
		id = i;
		for (int j = i + 1; j < arr.size(); j++) {
			if (arr[j] < arr[id])
				id = j;
		}
		t = arr[i];
		arr[i] = arr[id];
		arr[id] = t;

		t = indice[id];
		indice[id] = i;
		indice[i]=t;
		}
}
//构造返回值类型
class returnData
{
public:
	returnData(BinTree maxBSTHead, int maxBSTSize, int max1, int min1) :maxBSTHead(maxBSTHead), maxBSTSize(maxBSTSize), maxValue(max1), minValue(min1) {};
	~returnData() {};


	BinTree maxBSTHead;
	int maxBSTSize;
	int maxValue;
	int minValue;
};
returnData process(BinTree x)
{
	if (x == nullptr)
		return{ nullptr,0,INT_MIN,INT_MAX };
	returnData leftData = process(x->left);
	returnData rightData = process(x->right);
	int p1 = leftData.maxBSTSize;
	int p2 = rightData.maxBSTSize;
	int p3 = 0;
	if (x->left == leftData.maxBSTHead&&x->right == rightData.maxBSTHead&&
		x->data > leftData.maxValue&&x->data < rightData.minValue)
		p3 = p1 + p2 + 1;
	//构造返回值
	int maxBSTSize = max(max(p1, p2), p3);
	int maxValue = max(max(x->data, leftData.maxValue), rightData.maxValue);
	int minValue = min(min(x->data, leftData.minValue), rightData.minValue);
	BinTree maxBSTHead = maxBSTSize == p3 ? x : (maxBSTSize == p2 ? rightData.maxBSTHead : leftData.maxBSTHead);
	return{ maxBSTHead ,maxBSTSize ,maxValue ,minValue };

}
int getMaxBSTSize(BinTree head)
{
	return process(head).maxBSTSize;
}
int main()
{
	BinTree head = createBinTree();
	cout << getMaxBSTSize(head) << endl;
	
	return 0;
}

