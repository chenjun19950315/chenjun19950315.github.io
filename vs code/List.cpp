#include "List.h"

void Init(SeqList *l)
{
	l->last = 9;
	for (int i = 0; i < 10; i++)
		l->elem[i] = i+1;
}
int Locate(SeqList l, int num)
{
	int flag = 0;
	for (int i = 0; i < l.last; i++)
	{
		if (l.elem[i] == num)
		{
			flag = 1;
			return i+1;
			break;
		}
	}
	if (flag == 0)
		return -1;
}
void Print(SeqList l)
{
	for (int i = 0; i < l.last; i++)
		cout << l.elem[i] << " ";
	cout << endl;
}
int Insert(SeqList *l, int locate, int num)
{
	if (locate<1 || locate>l->last + 2)
	{
		cout << "插入位置不正确" << endl;
		return 0;
	}
	if (l->last >= MAXSIZE)
	{
		cout << "列表已满" << endl;
		return 0;
	}
	for (int i = l->last - 1; i >= locate-1; i--)
	{
		l->elem[i + 1] = l->elem[i];
	}
	l->elem[locate-1] = num;
	l->last++;
	return 1;

}

int Del(SeqList *l, int locate)
{
	if (locate<1 || locate>l->last+1)
	{
		cout << "删除位置不正确" << endl;
		return 0;
	}
	
	for (int i = locate ; i <= l->last-1; i++)
	{
		l->elem[i-1] = l->elem[i];
	}
	
	l->last--;
	return 1;

}
void merge(SeqList *l1, SeqList *l2, SeqList *l3)
{
	int i = 0;
	int j = 0;
	int k = 0;
	while (i <= l1->last - 1 &&j <= l2->last-1)
	{
		if (l1->elem[i] <= l2->elem[j])
		{
			l3->elem[k++] = l1->elem[i++];
		

		}
		
		else
		{
			l3->elem[k++] = l2->elem[j++];
			
		}
	}
	while (i <= l1->last - 1)
	{
		l3->elem[k++] = l1->elem[i++];
	}
	while (j <= l2->last - 1)
	{
		l3->elem[k++] = l2->elem[j++];
	}
	l3->last = l1->last + l2->last;
}

//链式存储
void InitList(LinkList H)
{
    
	H->next = nullptr;
}
void DisplayList(LinkList h)
{

	
	while (h->next !=nullptr)
	{
		h = h->next;
		cout << h->data << " ";
		
		
	}
	cout << endl;
}
void CreateFromHead(LinkList h)
{
	char data;
	int flag = 1;
	Node *s;
	if (h->next == nullptr)
	{
		cin >> data;
		s = new Node;
		s->data = data;
		h->next = s;
		s->next = nullptr;

	}

	while (flag)
	{
		cin >> data;
		if (data != '$')
		{
			s = new Node;
			s->data = data;
			s->next = h->next;
			h->next = s;
		}
		else
			flag = 0;
	}
}
void CreateFromTail(LinkList h)
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
			r->next = nullptr;
		}
	}
}


Node *Get(LinkList h, int i)
{
	Node *p = h->next;
	int j = 1;
	while (p!= nullptr &&j < i)
	{
		p = p->next;
		j++;
	}
	if (j == i)
		return p;
	else
		return NULL;
}
Node *Locate(LinkList h, char c)
{
	Node *p = h;

	while (p->next != NULL)
	{
		p = p->next;
		if (p->data == c)
			return p;
	}
	return nullptr;

}
int InsList(LinkList h, int i, char c)
{
	Node *s;
	Node *p;
	p = h;
	int j = 0;
	while (p->next != NULL&&j < i - 1)
	{
		p = p->next;
		j++;
	}
	if (j != i - 1)
	{
		cout << "插入位置错误!" << endl;
		return 0;
	}
	s = new Node;
	s->data = c;
	s->next = p->next;
	p->next = s;
	return 1;
	  
}
void InsSlist(LinkList h, char c)
{
	Node *p;
	Node *s;
	Node *pre;
	pre = h;
	p = h;
	while (p->next != NULL)
	{
		
		if (p->data < c)
		{
			pre = p;
			p = p->next;
		}
		else
		{
			s = new Node;
			s->data = c;
			s->next = p;
			pre->next = s;
			break;

		}
	}
	if (p->next == NULL)
	{
		s = new Node;
		s->data = c;
		p->next = s;
		s->next = NULL;

	}
}
bool DelList(LinkList h, int i)
{
	
	Node *p;
	Node *tem;
	char t;
	p = h;
	int j = 0;
	while (p->next != NULL&&j < i - 1)
	{
		p = p->next;
		j++;
	}
	if (p->next == NULL|| j != i - 1)
	{
		cout << "删除位置错误!" << endl;
		return 0;
	}
	tem = p->next;
	t = tem->data;
	
	
	p->next =tem->next;
	free(tem);
	
	return t;

}
void DelLlist(LinkList h, int i, int k)
{
	Node *p;
	Node *s;
	Node *pre;
	p = h;
	pre = h;
	int j = 0;
	while (p!= NULL&&j<i)
	{
		
		p = p->next;
		j++;
	}
	pre = p;
	while (p!= NULL&& k > 0)
	{
		p = p->next;
		k--;
	}
	if (p == NULL)
		cout << "error" << endl;
	else
	pre->next = p->next;
}
int ListLength(LinkList h)
{
	int cnt = 0;
	Node *p;
	p = h->next;
	while (p)
	{
		p = p->next;
		++cnt;
	}
	return cnt;
}
void Difference(LinkList la, LinkList lb)
{
	Node *s1;
	Node *s2;
	Node *pre;
	Node *t;
	pre = la;
	s1= la->next;
	
	while (s1!= NULL)
	{
		s2 = lb->next;
		while (s2 != NULL && s1->data != s2->data)
			s2 = s2->next;
		if (s2 != NULL)
		{
			t = s1;
			pre->next = pre->next->next;
			s1 = s1->next;
			delete(t);

		}
		else
		{
			pre = s1;
			s1 = s1->next;
		}
	}
}

void reverseList(LinkList h)
{
	LinkList p, q, ptr;
	q= (LinkList)malloc(sizeof(Node));
	q = nullptr;
	p = ptr = h->next;
	while (p)
	{
		ptr = p->next;
		p->next = q;
		q = p;
		p = ptr;
	}
	h->next = q;
}
LinkList mergeList(LinkList la, LinkList lb)
{
	LinkList lc= new Node;
	LinkList p;
	InitList(lc);
	p = lc;

	while (la->next != nullptr && lb->next != nullptr)
	{
		
		if (la->next->data <= lb->next->data)
		{ 
			LinkList r = new Node;
			r->data = la->next->data;
			p->next = r;
			p = r;
			la = la->next;
		}
		else
		{
			LinkList r = new Node;
			r->data = lb->next->data;
			p->next = r;
			p = r;
			lb = lb->next;
		}		
	}
	while (la->next != nullptr)
	{
		LinkList r = new Node;
		r->data = la->next->data;
		p->next = r;
		p = r;
		la = la->next;
		
	}
	while (lb->next != nullptr)
	{
		LinkList r = new Node;
		r->data = lb->next->data;
		p->next = r;
		p = r;
		lb = lb->next;
	}
	p->next = nullptr;
	return lc;
}
void InitList(DoubleList *H)
{
	*H = new DNode;
	(*H)->next = nullptr;
	(*H)->prior = nullptr;
}

Polylist polycreate()
{
	Polynode *head, *rear, *s;
	int c, e;
	head = new Polynode;
	rear = head;
	cin >> c >> e;
	while (c != 0)
	{
		s = new Polynode;
		s->coef = c;
		s->exp = e;
		rear->next = s;
		rear = s;
		cin >> c >> e;
	}
	rear->next = NULL;
	return head;
}

void DisplayPolylist(Polylist h)
{
	Polynode *s;

	while (h->next != NULL)
	{
		s = h->next;
		cout <<"系数是:"<< s->coef << " "<<"指数是:"<<s->exp<<endl;
		h = h->next;

	}

}
void polyadd(Polylist polya, Polylist polyb)
{
	Polynode* s1;
	Polynode* s2;
	Polynode* pre;
	Polynode* t;
	int sum;
	pre = polya;
	s1 = polya->next;
	s2 = polyb->next;
	while (s1 != NULL&&s2 != NULL)
	{
		if (s1->exp < s2->exp)
		{
			pre->next = s1;
			pre = s1;
			s1 = s1->next;
		}
		else if (s1->exp > s2->exp)
		{
			pre->next = s2;
			pre = s2;
			s2 = s2->next;
		}
		else
		{
			sum = s1->coef + s2->coef;
			if (sum != 0)
			{
				s1->coef = sum;
				pre->next = s1;
				pre = s1;
				s1 = s1->next;
				t = s2;
				s2 = s2->next;
				delete(t);
				
			}
			else {
				t = s1;
				s1 = s1->next;
				delete(t);
				t = s2;
				s2 = s2->next;
				delete(t);


			}
			
		}
	}
	if (s1 != NULL)
	{
		pre->next = s1;
	}
	else
	{
		pre->next = s2;
	}


}
/*void MediuToBack(string s)
{
	SeqStack* op1 = new SeqStack;
	InitStack(op1);
	char t;

	for (auto & c : s)
	{
		if (c == '+' || c == '-')
		{
			if (op1->top == -1)
				push(op1, c);
			else
			{
				while (op1->top != -1)
				{
					pop(op1, t);
					cout << t << " ";
				}
				push(op1, c);
			}
		}
		else if (c == '*')
		{
			if (op1->top == -1)
				push(op1, c);
			else {
				while (op1->elem[op1->top] == '*' || op1->elem[op1->top] == '/')
				{
					pop(op1, t);
					cout << t << " ";
				}
				push(op1, c);
			}
		}
		else if (c == '/')
		{
			if (op1->top == -1)
				push(op1, c);
			else {
				while (op1->elem[op1->top] == '*' || op1->elem[op1->top] == '/')
				{
					pop(op1, t);
					cout << t << " ";
				}
				push(op1, c);
			}
		}
		else
			cout << c << " ";

	}
	while (op1->top != -1)
	{
		pop(op1, t);
		cout << t << " ";
	}
	delete op1;
}*/
//顺序栈
void InitStack(SeqStack *s)
{
	s->top = -1;
}
int IsEmpty(SeqStack *s)
{
	return(s->top == - 1 ? TURE : FALSE);
}
int IsFull(SeqStack *s)
{
	return(s->top == Stack_Size -1 ? TURE : FALSE);
}
int push(SeqStack *s, StackElementType e)
{
	if (s->top == Stack_Size - 1)
		return FALSE;
	else {
		
		s->elem[++(s->top)] = e;
		return TURE;
	}
}

StackElementType pop(SeqStack *s)
{
	StackElementType c;
	if (s->top == - 1)
	{
		cout << "栈空" << endl;
		return FALSE;
	}
	else {
		c = s->elem[s->top];
		s->top--;
		return c;
	}
}
StackElementType Getpop(SeqStack *s )
{
	StackElementType x;
	if (s->top == -1)
		return NULL;
	else {
		x = s->elem[s->top];
		return x;
	}

}
//共享栈
void InitStack(DqStack *s)
{
	s->top[0] = -1;
	s->top[1] = M;
}
int push(DqStack *s, int e, int i)
{

	if (s->top[0]+1 == s->top[1])
		return FALSE;
	else {
		switch (i)
		{
		case 0:
			s->top[0]++;
			s->elem[s->top[0]] = e;
			break;
		case 1:
			s->top[1]--;
			s->elem[s->top[1]] = e;
			break;
		default:
			return FALSE;
		}
		
		return TURE;
	}
}
void DisplayDq(DqStack *s)
{
	int i = s->top[0];
	int j = s->top[1];
	cout << "first stack:";
	while (i>= 0)
	{
		cout << s->elem[i] << " ";
		i--;

	}
	cout << endl;
	cout << "second stack:";
	while (j <=99)
	{
		cout<< s->elem[j] << " ";
		j++;

	}
	cout << endl;

}
int pop(DqStack *s, int i)
{

	if (s->top[0]==-1&&s->top[1]==M)
		return FALSE;
	else {
		switch (i)
		{
		case 0:
			s->top[0]--;
			break;
		case 1:
			s->top[1]++;
			break;
		default:
			return FALSE;
		}
		return TURE;
	}
}
int Getpop(DqStack *s, int i)
{
	int j;
	if (s->top[0] == -1 && s->top[1] == 100)
		return FALSE;
	else {
		switch (i)
		{
		case 0:
			j= s->elem[s->top[0]];
				return j;
			break;
		case 1:
			j = s->elem[s->top[1]];
			return j;
			break;
		default:
			return FALSE;
		}

	
	}
}
/*void Conversion(int N, int d)
{
	SeqStack *s;
	int x;
	int t = N;
	char c;
	s = new SeqStack;
	
	InitStack(s);
	while (N > 0) {
		x = N % d ;
		cout << "x:" << x << endl;
		push(s, x);
		N = N / d;
		cout << "N:" << N << endl;
		
	}
	cout << "数" << t << "转换成" << d << "进制" << endl;
	cout << "结果为：";
	while (!IsEmpty(s)) {
		pop(s, c);
		cout<<(int)c<<" ";
	}
	cout << endl;
	
}*/
int Match(char c1, char c2)
{
	if (c1 == '(')
	{
		if (c2 == ')')
			return 1;
		else
			return 0;

	}
	if (c1 == '{')
	{
		if (c2 == '}')
			return 1;
		else
			return 0;

	}
   if (c1 == '[')
	{
		if (c2 == ']')
			return 1;
		else
			return 0;

	}
}
int IsOperate(char c)
{
	if (c == '+' || c == '*')
		return 1;
	else
	{
		return 0;
	}
}
/*void CompuerNum()
{
	SeqStack *operand;//运算数栈
	SeqStack *operate;//运算符栈
	string s;
	int t;
	char t1;
	operand = new SeqStack;
	operate = new SeqStack;
	InitStack(operand);
	InitStack(operate);
	cout << "请输入表达式，以#结束" << endl;
	cin >> s;
	if (s[s.size() - 1 != '#'])
		cout << "输入的表达式有误:" << endl;
	for (int i = 0; i < s.size(); i++)
	{
		if (!IsOperate(s[i])) {
			t = s[i] - '0';
			push(operand, t);

		}
		else {
			if (IsEmpty(operate))
				push(operate, s[i]);
			else {
				Getpop(operate, t1);
				if (Compare(s[i], t1)) {

				}

			}

		}
	}
}*/


int Compare(char c1, char c2)
{
	
	if (c1 < c2)
		return 0;
	else
		return 1;
	
}
int Change(string s)
{
	int num;
	stringstream ss(s);
	ss >> num;
	return num;

}
void move(char x, char z)
{
	cout<<x<<"---->"<<z<<endl;
}
void Hanoi(int n, char x, char y, char z)
{
	if (n == 1)
		move(x, z);
	else
	{
		Hanoi(n - 1, x, z, y);
		move(x, z);
		Hanoi(n - 1, y, x, z);
	}

	    
}
int Fib(int n)
{
	if (n == 0 || n == 1)
		return n;
	else
		return Fib(n - 1) + Fib(n - 2);
}
int Fib1(int n)
{
	int x, y, z;
	if (n == 0 || n == 1)
		return n;
	else
	{
		x = 0;
		y = 1;
		for (int i = 2; i <= n; i++)
		{
			z = y;
			y = x + y;
			x = z;

		}
		return y;

	}
}

int InitQueue(LinkQueue *q)
{
	q->front = new LinkQueueNode;
	if (q->front != NULL)
	{
		q->rear = q->front;
		q->front->next = NULL;
		return 1;
	}
	else
		return 0;
}
bool IsEmptyQueue(LinkQueue *q)
{
	if (q->front==q->rear)
		return 1;
	else
		return 0;
}
int EnterQueue(LinkQueue *q, QueueElementType x)
{
	
	LinkQueueNode *s;
	s = new LinkQueueNode;
	if (s != NULL)
	{
		s->data = x;
		s->next = NULL;
		q->rear->next = s;
		q->rear = s;
		return 1;
	}
	else
		return 0;
}
QueueElementType DeleteQueue(LinkQueue *q)
{
	QueueElementType x=new TNode;

	if (!IsEmptyQueue(q))
	{
		LinkQueueNode *s;
		s = q->front->next;
		q->front->next = s->next;
		x = s->data;
		if (q->rear==s)
			q->front = q->rear;
		

		return x;

	}
	else
	{
		cout << "队列空" << endl;
		return 0;
	}
}
//循环列表
void InitQueue(SeqQueue *q)
{
	q->front = 0;
	q->rear = 0;
}

int EnterQueue(SeqQueue * q,int x)
{
	if ((q->rear + 1) % MAXSIZE == q->front)
		return 0;
	else
	{
		q->element[q->rear] = x;
		q->rear = (q->rear + 1) % MAXSIZE;
		return 1;
	}
}
int DeleteQueue(SeqQueue *q, int &x)
{
	if (q->front == q->rear)
		return 0;
	else
	{
		x = q->element[q->front];
		q->front = (q->front + 1) % MAXSIZE;
		return 1;
	}
}
int IsEmpty(SeqQueue *q)
{
	if (q->front == q->rear)
		return 0;
	else
		return 1;
}
int GetHead(SeqQueue*q, int &x)
{
	if ((q->rear + 1) % MAXSIZE == q->front)
		return 0;
	else
	{
		x = q->element[q->front];
		return 1;
	}
}

void Triangle(int row)
{
	SeqQueue Q;
	int temp;
	int x;
	InitQueue(&Q);
	EnterQueue(&Q, 1);
	for (int i = 2; i <= row; i++)
	{
		EnterQueue(&Q, 1);     //第i行第一个元素入队
		for (int j = 2; j < i; j++)
		{
			DeleteQueue(&Q, temp);
			cout << temp << " ";
			GetHead(&Q, x);
			temp = temp + x;
			EnterQueue(&Q, temp);
		}
		DeleteQueue(&Q, temp);
		cout << temp << endl;
		EnterQueue(&Q, 1);

		}
}

//字符串
int StrInsert(sstring *s, int pos, sstring *t)
{
	if (pos < 0 || pos >= s->len)
	{
		cout << "插入位置不合法" << endl;
		return 0;
	}
	if (s->len+t->len<=MAXSIZE)
	{
		for (int i = s->len+t->len-1;i>=t->len+pos;i--)
		{
			s->ch[i] = s->ch[i-t->len];
		}
		for (int i = 0; i < t->len; i++)
			s->ch[i + pos] = t->ch[i];
		s->len = s->len + t->len;
	}
	else if ( pos+t->len<MAXSIZE )
	{
		for (int i = MAXSIZE-1; i>=t->len+pos; i--)
			s->ch[i] = s->ch[i - t->len];
		for (int i = 0; i < t->len; i++)
			s->ch[i + pos] = t->ch[i];
		s->len = MAXSIZE;
	}
	else {
		for (int i = 0; i <MAXSIZE; i++)
			s->ch[i + pos] = t->ch[i];
		s->len = MAXSIZE;

	}
	return 0;

}
int StrDelete(sstring *s, int pos, int len)
{
	if (pos < 0 || pos >= s->len-len)
	{
		cout << "删除位置不合法" << endl;
		return 0;
	}
	else
	{
		for (int i = pos+len; i < s->len; i++)
			s->ch[i-len] = s->ch[i];
		s->len = s->len - len;
		return 1;
	}
}
int StrCopy(sstring *s, sstring *t)
{
	for (int i=0; i < t->len; i++)
	{
		s->ch[i] = t->ch[i];
	}
	s->len = t->len;
	return 1;
}
int StrEmpty(sstring *s)
{
	if (s->len == 0)
		return 1;
	else
		return 0;
}
int StrCompany(sstring *s, sstring *t)
{
	int flag = 1;
	if (s->len != t->len)
		return 0;
	else
	{
		for (int i = 0; i < s->len; i++)
		{
			if (s->ch[i] != t->ch[i])
			{
				flag = 0;
				break;
			}

		}
		if (flag == 0)
			return 0;
		else
		{
			return 1;
		}
	}
}

int SteLen(sstring *s)
{
	return s->len;
}
int StrCat(sstring *s, sstring *t)
{
	if (s->len >=MAXSIZE)
	{
		cout << "连接失败" << endl;
		return 0;
	}
	else if(s->len+t->len<MAXSIZE)
	{
		for (int i = s->len; i < s->len + t->len; i++)
		{
			s->ch[i] = t->ch[i - s->len];
		}
		s->len = s->len + t->len;
		return 1;
	}
	else
	{
		for (int i = s->len; i <MAXSIZE; i++)
		{
			s->ch[i] = t->ch[i - s->len];
		}
		s->len = MAXSIZE;
		return 1;
	}
	
}
int StrString(sstring *s, sstring *t, int pos, int len)
{
	if (pos<0 || pos>t->len || len<0 || len>t->len - pos)
	{
		cout << "error" << endl;
		s->len = 0;
		return 0;
	}
	else
	{
		for (int i = pos; i < pos + len; i++)
		{
			s->ch[i - pos] = t->ch[i];
		}
			s->len = len;
			return 1;
		
	}
}
int StrIndex(sstring *s, int pos, sstring *t)
{
	int j = 0;
	if (pos<0 || pos>MAXSIZE)
	{
		cout << "位置错误" << endl;
		return 0;
	}
	else
	{
		int i = pos; 
		int j = 0;
		while (i < s->len &&j < t->len)
			{
			if (s->ch[i] == t->ch[j])
			{
				i++;
				j++;
			}
			else
			{
				i = i - j + 1;
				j = 0;
			}

		}
		if (j >= t->len)
			return( i - j);
		else
			return 0;
	}
}

//排序

//简单选择排序
void swap(ElementType &a, ElementType&b)
{
	ElementType c;
	c = a;
	a = b;
	b = c;
}
void SimpleSelectionSort(ElementType a[], int N)
{
	for(int i=0;i<N-1;i++)
		for (int j = i + 1; j < N; j++) {
			if (a[i] > a[j])
				swap(a[i],a[j]);
		}
}

//堆排序
void percDown(ElementType a[], int p, int N)
{
	int parent, child;
	ElementType x = a[p];
	for (parent = p;( 2 * parent + 1 )< N; parent = child)
	{
		child = 2 * parent + 1;
		if ((child != N - 1) && (a[child] < a[child + 1]))
			child++;
		if (a[child] > x)
			a[parent] = a[child];
		else
			break;
	}
	a[parent] = x;
}
void HeapSort(ElementType a[], int N)
{
	for (int i = (N/2 - 1); i >= 0; i--)
	{
		percDown(a, i, N);
	}

	for (int i = N-1 ;i>0;i--)
	{
		swap(a[0], a[i]);
		percDown(a, 0, i);
	}
}

//直接插入排序
void InsertionSort(ElementType a[], int N)
{
	ElementType t;
	int j;
	for (int i = 1; i < N; i++)
	{
		t = a[i];
		for ( j = i; j > 0 && a[j-1] > t; j--) 
			a[j] = a[j - 1];

		a[j] = t;

	}

}
//希尔排序 
void ShellSort(ElementType a[], int N)
{
	int si=0, temp,i;
	int sedgewick[6] = { 1,5,19,41,109,209 };
	while (sedgewick[++si] <= N);
	si=si-1;
    
	for(int D=sedgewick[si];D>0;D=sedgewick[--si])
		for (int p = D; p < N;  p++) {
			temp = a[p];
			for ( i = p; i>=D && a[i - D] > a[i]; i = i - D)
				a[i] = a[i - D];
			a[i] = temp;
		}
}
//冒泡排序
void BubbleSort(ElementType a[], int N)
{
	int flag;
	for(int i=N-1;i>0;i--){
		flag = 0;
		for (int j = 0; j < i; j++)
		{
			if (a[j] > a[j + 1])
			{
				swap(a[j], a[j + 1]);
				flag = 1;
			}
		}
		if (flag == 0)
			break;
	}
}
//快速排序
int median3(ElementType a[], int left, int right)
{
	int center;
	center = (left + right) / 2;
	if (a[left] > a[center])
		swap(a[left], a[center]);
	if (a[left] > a[right])
		swap(a[left], a[right]);
	if (a[center] > a[right])
		swap(a[center], a[right]);
	swap(a[center], a[right - 1]);
	return a[right - 1];
}
void QSort(ElementType a[], int left,int right)
{
	//原始快速排序的终止条件
//	if (left >=right)
//		return;
//	if (right - left == 1)
//	{
//		if (a[left] > a[right])
//			swap(a[left], a[right]);
//		return;
//	}
	int cutoff = 300;  //测试结果，300会比较好
	int pivot;
	int low, high;
	pivot = median3(a, left, right);
	low = left;
	high = right - 1;
	if (right - left >= cutoff) {
		while (1) {
			while (a[++low] < pivot);
			while (a[--high] > pivot);
			if (high < low)
				break;
			else
				swap(a[low], a[high]);
		}

		swap(a[low], a[right - 1]);

		QSort(a, left, low - 1);
		QSort(a, low + 1, right);
	}
	else
		InsertionSort(a, right - left + 1);//元素太少，直接切换插入排序
}
void QuickSort(ElementType a[], int N)
{
	QSort(a, 0, N - 1);
}

//归并排序
void Merge(ElementType a[], ElementType temp[], int left, int right, int rightEnd)
{
	int leftEnd;
	int numElement;
	int t;
	leftEnd = right - 1;
	t = left;
	numElement = rightEnd - left + 1;
	while (left <= leftEnd && right <= rightEnd)
	{
		if (a[left] <= a[right])
			temp[t++] = a[left++];
		else
			temp[t++] = a[right++];
	}
	while(left <= leftEnd)
		temp[t++] = a[left++];
	while(right <= rightEnd)
		temp[t++] = a[right++];
	for (int i = 0; i < numElement; i++, rightEnd--)
		a[rightEnd] = temp[rightEnd];
}
void MSort(ElementType a[], ElementType temp[], int left, int rightEnd)
{
	int center;
	if (left < rightEnd)
	{
		center = (left + rightEnd) / 2;
		MSort(a, temp, left, center);
		MSort(a, temp, center+1, rightEnd);
		Merge(a, temp, left, center + 1, rightEnd);
		
	}
}
void MergeSort(ElementType a[], int N)
{
	ElementType *temp;
	temp = (ElementType *)malloc(N * sizeof(ElementType));
	
	if (temp != NULL) {
		cout << "ssss";
		MSort(a, temp, 0, N - 1);
		free(temp);
	}
	else
		cout << "空间不足" << endl;
}


//散列查找
bool isPrime(int n)
{
	if (n == 1)
		return 0;
	int sq = sqrt(n);
	for (int i = 2; i <= sq; i++)
	{
		if (n%i == 0)
			return 0;
	}
	return 1;
}
int nextPrime(int tableSize)
{
	int p;
	p = (tableSize % 2) ? tableSize  : tableSize+1;
	
	while (p <= MAXTABLESIZE)
	{
		if (isPrime(p))
			return p;
		else
			p = p + 2;
	}
	if (p > MAXTABLESIZE)
	{
		cout << "找不到" << endl;
		return 0;
	}
}
HashTable CreateHash(int TableSize)
{
	HashTable H;
	H = (HashTable)malloc(sizeof(TblNode));
	H->TableSize = nextPrime(TableSize);
	H->cells = (cell*)malloc(sizeof(HashEntry)*H->TableSize);
	for (int i = 0; i < H->TableSize; i++)
		H->cells[i].info = Empty;
	return H;
}
Position1 Find( HashTable H ,ElementType key)
{
	int Cnum = 0;
	int p= key % (H->TableSize);
	while (H->cells[p].info != Empty &&H->cells[p].data != key)
	{
		if (++Cnum % 2)
		{
			p = p + (Cnum+1)*(Cnum+1) / 4;
			if (p >= H->TableSize)
				p = p%H->TableSize;
		}
		else {
			p = p - Cnum*Cnum / 4;
			while (p <= H->TableSize)
				p = p + H->TableSize;
		}	
		
	}

	return p;
}


bool Insert(HashTable H, ElementType key)
{
	int p;
	p = Find(H, key);
	if (H->cells[p].info != legitimate) {
		H->cells[p].data = key;
		H->cells[p].info = legitimate;
		return 1;
	}
	else {
		cout << "键值已存在！" << endl;
		return 0;
	}
}
bool Delete(HashTable H, ElementType key)
{
	int p;
	p = Find(H, key);
	if (H->cells[p].info == legitimate)
	{
		cout << "删除成功" << endl;
		H->cells[p].info = Deleted;
		return 1;
	}
	else {
		cout << "键值不存在！" << endl;
		return 0;
	}

}
//顺序查找
int SequentialSearch(SeqList *l, int k)
{
	l->elem[0] = k;
	int i;
	for (i = l->last; l->elem[i] != k; i--);
	return i;
}
//二分查找
int BinarySearch(SeqList *l, int k)
{
	QuickSort(l->elem, l->last);
	int left =0;
	int right = l->last;
	int center;
	while (left <= right)
	{
		center = (left + right) / 2;
		if (l->elem[center] == k)
			return center;
		else if (l->elem[center] > k)
			right = center - 1;
		else
			left = center + 1;
	}
	cout << "no find" << endl;
	return -1;//没有找到，下标返回-1
}
//树结构
//二叉树，链式存储
//创建二叉树
BinTree createBinTree()
{
	BinTree BT = new TNode;
	LinkQueue *Queue = new LinkQueue;
	InitQueue(Queue);
	TreeElementType data;
	cin >> data;
	if (data != 0)
	{
		BT->data = data;
		BT->left = BT->right = NULL;
		EnterQueue(Queue, BT);
	}
	else
		return NULL;
	while(!IsEmptyQueue(Queue))
	{
		BinTree t = new TNode;
		t = DeleteQueue(Queue);
		cin >> data;
		if (data == 0)
			t->left = NULL;
		else {
			t->left = new TNode;
			t->left->data = data;
			t->left->left = t->left->right = NULL;
			EnterQueue(Queue, t->left);
		}

		cin >> data;
		if (data == 0)
			t->right = NULL;
		else {
			t->right = new TNode;
			t->right->data = data;
			t->right->left = t->right->right = NULL;
			EnterQueue(Queue, t->right);
		}

	}
	return BT;
}
void LevelorderTraversal(BinTree BT)
{
	LinkQueue *Queue = new LinkQueue;
	InitQueue(Queue);
	if (!BT)
	{
		cout << "空树" << endl;
		return;
	}
	EnterQueue(Queue, BT);
	while (!IsEmptyQueue(Queue))
	{
		BinTree t = new TNode;
		t = DeleteQueue(Queue);
		cout << t->data << " ";
		if(t->left!=NULL)
			EnterQueue(Queue, t->left);
		if (t->right != NULL)
			EnterQueue(Queue, t->right);
	}
	cout << endl;
}
void InorderTraversal(BinTree BT)
{
	if (BT)
	{
		InorderTraversal(BT->left);
		cout << BT->data;
		InorderTraversal(BT->right);
	}
}
//中序遍历，非递归
void InorderTraversal1(BinTree BT)
{
	SeqStack *s = new SeqStack;
	InitStack(s);
	while (BT || !IsEmpty(s))
	{
		while (BT)
		{
			push(s, BT);
			BT = BT->left;
		}
		if (!IsEmpty(s))
		{
			BT = pop(s);
			cout << BT->data << " ";
			BT = BT->right;
		}
	}
}
//先序遍历
void PreorderTraversal(BinTree BT)
{
	if (BT)
	{
		cout << BT->data;
		PreorderTraversal(BT->left);
		PreorderTraversal(BT->right);
	}
}
//先序遍历,非递归
void PreorderTraversal1(BinTree BT)
{
	SeqStack *s = new SeqStack;
	InitStack(s);
	while (BT || !IsEmpty(s))
	{
		while (BT)
		{
			cout << BT->data << " ";
			push(s, BT);
			BT = BT->left;
		}
		if (!IsEmpty(s))
		{
			BT = pop(s);
			BT = BT->right;
		}
	}
}
//后序遍历
void PostTraversal(BinTree BT)
{
	if (BT)
	{
		PostTraversal(BT->left);
		PostTraversal(BT->right);
		cout << BT->data;
	}

}
//后序遍历,非递归
void PostTraversal1(BinTree BT)
{
	SeqStack *s = new SeqStack;
	InitStack(s);
	int top = -1;
	int tag[MAXSIZE] ;
	while (BT || !IsEmpty(s))
	{
		if (BT)
		{
			push(s, BT);
			tag[++top]=0;
			BT = BT->left;
		}
		else {

			if (!IsEmpty(s))
			{
				while (tag[top] == 1)
				{
					BT = pop(s);
					cout << BT->data << " ";
					top--;
				}
				if (top == -1)
					break;
				BT = Getpop(s);
				tag[top] = 1;
				BT = BT->right;
			}

		}
		
	}
}
//输出树中的叶子节点
void PreorderTraversalLeaves(BinTree BT)
{
	if (BT)
	{
		if (!BT->left && !BT->right)
			cout << BT->data << " ";
		PreorderTraversalLeaves(BT->left);
		PreorderTraversalLeaves(BT->right);
	}
}
//得到树的高度
int GetHeight(BinTree BT)
{
	int LeftHeight;
	int RightHeight;
	int MaxHeight;
	if (BT)
	{
		LeftHeight = GetHeight(BT->left);
		RightHeight = GetHeight(BT->right);
		MaxHeight = (LeftHeight > RightHeight) ? LeftHeight : RightHeight;
		return (MaxHeight + 1);
	}
	else
		return 0;
}

//二叉搜索树
BinTree searchBiTreeNode(BinTree BT, TreeElementType key)
{
	if (BT)
	{
		if (BT->data == key)
			return BT;
		else if (BT->data > key)
			searchBiTreeNode(BT->left, key);
		else
			searchBiTreeNode(BT->right, key);
	}
	else
		return NULL;
}
BinTree searchBiTreeNode1(BinTree BT, TreeElementType key)
{
	while (BT)
	{
		if (BT->data == key)
			return BT;
		else if (BT->data > key)
			BT = BT->left;
		else
			BT = BT->right;
	}
	return BT;
}
BinTree searchMaxBiTreeNode(BinTree BT)
{
	if (!BT)
	{
		cout << "空树" << endl;
		return BT;
	}
	while (BT->right != NULL)
		BT = BT->right;
	return BT;
}
BinTree searchMinBiTreeNode(BinTree BT)
{
	if (!BT)
	{
		cout << "空树" << endl;
		return BT;
	}
	while (BT->left != NULL)
		BT = BT->left;
	return BT;
}
//搜索二叉树的插入操作
BinTree BiTreeInsert(BinTree BT, TreeElementType key)
{
	if (!BT)//空树
	{
		BT = new TNode;
		BT->data = key;
		BT->left = BT->right = NULL;
	}
	else {
		
		if (BT->data > key)
			BT->left=BiTreeInsert(BT->left, key);
		else if(BT->data < key)
			BT->right=BiTreeInsert(BT->right, key);
	}
	return BT;
}
//搜索二叉树的删除操作,返回插入成功后的根节点
BinTree BiTreeDelete(BinTree BT, TreeElementType key)
{
	BinTree T;
	if (!BT)
		cout << "未找到要删除的元素" << endl;
	else {
		if (BT->data > key)
			BT->left = BiTreeDelete(BT->left, key);
		else if (BT->data < key)
			BT->right = BiTreeDelete(BT->right, key);
		else{
			if (BT->left == NULL &&BT->right == NULL)
			{
				delete(BT);
				return NULL;
			}
			else if (BT->left == NULL || BT->right == NULL)
			{
				T = BT;
				if (BT->left == NULL)
					return BT->right;
				else
					return BT->left;
				delete(BT);
			}
			else
			{
				T=searchMinBiTreeNode(BT->right);
				BT->data = T->data;
				BT->right = BiTreeDelete(BT->right, BT->data);
				delete(T);
			}
	}
	}
	return BT;
}
//创建最大堆，容量为maxsize
MaxHeap CreateMaxHeap(int maxsize)
{
	MaxHeap h = new HeapNode;
	h->data = new HeapElementType[maxsize + 1];
	h->capacity = maxsize;
	h->data[0] = HEAPMAXDATA;
	h->size = 0;
	return h;
}
MinHeap CreateMinHeap(int maxsize)
{
	MaxHeap h = new HeapNode;
	h->data = new HeapElementType[maxsize + 1];
	h->capacity = maxsize;
	h->data[0] = HEAPMINDATA;
	h->size = 0;
	return h;
}
bool HeapIsFull(MaxHeap h)
{
	return(h->capacity == h->size);
}
bool HeapIsEmpty(MaxHeap h)
{
	return(h->size == 0);
}
bool MaxHeapInsert(MaxHeap h,HeapElementType data)
{
	int i;
	if (HeapIsFull(h))
	{
		cout << "堆已满，无法插入" << endl;
		return 0;
	}
	i=++h->size;
	for (; h->data[i / 2] < data; i = i / 2)
			h->data[i] = h->data[i / 2];
		h->data[i] = data;
	return 1;
}
HeapElementType MaxHeapDelete(MaxHeap h)
{
	HeapElementType max, x;
	max = h->data[1];
	x = h->data[h->size--];
	int parent;
	int child;
	if (HeapIsEmpty(h))
	{
		cout << "空堆,无法删除" << endl;
		return 0;
	}
	for (parent = 1; 2 * parent <= h->size; parent = child)
	{
		child = 2 * parent;
		if (child != h->size&&h->data[child + 1] > h->data[child])
			child = child + 1;
		if (x >= h->data[child])
			break;
		else
			h->data[parent] = h->data[child];
	}
	h->data[parent] = x;
	return max;
}
void HeapDisplay(MaxHeap h)
{
	for (int i = 1; i <= h->size; i++)
		cout << h->data[i] << " ";
	cout << endl;
}
void MaxPerDown(MaxHeap h, int p)
{
	HeapElementType x;
	x = h->data[p];
	int parent;
	int child;
	for (parent = p; 2 * parent <= h->size; parent = child)
	{
		child = 2 * parent;
		if (child != h->size&&h->data[child + 1] > h->data[child])
			child = child + 1;
		if (x >= h->data[child])
			break;
		else
			h->data[parent] = h->data[child];
	}
	h->data[parent] = x;
}
void BuildMaxHeap(MaxHeap h)
{
	for (int i = h->size / 2; i > 0; i--)
		MaxPerDown(h, i);
}
bool MinHeapInsert(MinHeap h, HeapElementType data)
{
	int i;
	if (HeapIsFull(h))
	{
		cout << "堆已满，无法插入" << endl;
		return 0;
	}
	i = ++h->size;
	for (; h->data[i / 2] > data; i = i / 2)
		h->data[i] = h->data[i / 2];
	h->data[i] = data;
	return 1;
}
HeapElementType MinHeapDelete(MinHeap h)
{
	HeapElementType min, x;
	min = h->data[1];
	x = h->data[h->size--];
	int parent;
	int child;
	if (HeapIsEmpty(h))
	{
		cout << "空堆,无法删除" << endl;
		return 0;
	}
	for (parent = 1; 2 * parent <= h->size; parent = child)
	{
		child = 2 * parent;
		if (child != h->size&&h->data[child + 1] < h->data[child])
			child = child + 1;
		if (x <= h->data[child])
			break;
		else
			h->data[parent] = h->data[child];
	}
	h->data[parent] = x;
	return min;
}
void MinPerDown(MinHeap h, int p)
{
	HeapElementType x;
	x = h->data[p];
	int parent;
	int child;
	for (parent = p; 2 * parent <= h->size; parent = child)
	{
		child = 2 * parent;
		if (child != h->size&&h->data[child + 1] < h->data[child])
			child = child + 1;
		if (x <= h->data[child])
			break;
		else
			h->data[parent] = h->data[child];
	}
	h->data[parent] = x;
}
void BuildMinHeap(MinHeap h)
{
	for (int i = h->size / 2; i > 0; i--)
		MinPerDown(h, i);
}
//####哈夫曼树#######//
//建立哈夫曼树，用最小堆建立

//#########集合，查并集##################
void BuildSet(int set[], int a[],int n)
{
	set[a[0]] = -n;//将集合a的第一个元素作为集合的名字
	for (int i = 1; i < n; i++)
	{
		set[a[i]] = a[0];
	}
}
int SetFind(int set[], int x)
{
	if (set[x] < 0)
		return x;
	else
	return set[x]= SetFind(set,set[x]);
}
void SetUnion(int set[], int x1, int x2)
{
	int root1;
	int root2;
	root1 = SetFind(set, x1);
	root2 = SetFind(set, x2);
	if (set[root1] > set[root2])
	{
		set[root2] = set[root2] + set[root1];
		set[root1] = root2;
		
	}
	else if (set[root1] < set[root2])
	{
		set[root1] = set[root1] + set[root2];
		set[root2] = root1;
		
	}
	else
		cout << "同一个集合" << endl;
}
MGraph CreateGraph(int VertexNum)
{
	MGraph Graph = new GNode;
	Graph->nv = VertexNum;
	Graph->ne = 0;
	for (int i = 0; i < Graph->nv; i++)
		for (int j = 0; j < Graph->nv; j++)
			Graph->G[i][j] = INFINITY;
	return Graph;
}
void DisplayMGraph(MGraph Graph)
{
	for (int i = 0; i < Graph->nv; i++)
	{
		for (int j = 0; j < Graph->nv; j++)
			cout << Graph->G[i][j] << " ";
		cout << endl;
	}
}
void InsertEdge(MGraph Graph, Edge E)  //无向图
{
	Graph->G[E->v1][E->v2] = E->Weight;
	Graph->G[E->v2][E->v1] = E->Weight;
//	Graph->ne++;
}
MGraph BuildGraph()
{
	MGraph Graph;
	Edge E;
	int nv;
	int ne;
	cout << "请输入图的顶点数:" << endl;
	cin >> nv;
	Graph=CreateGraph(nv);
	cout << "请输入图的边数:" << endl;
	cin >> Graph->ne;
	if (Graph->ne != 0)
	{
		E = new ENode;
		for (int i = Graph->ne; i > 0; i--)
		{
			cout << "请输入边的两个顶点及权值:" << endl;
			cin >> E->v1 >> E->v2>>E->Weight;
			InsertEdge(Graph, E);
		}
	}
	return Graph;
}
int Visited[MaxVertexNum] = { 0 };
void Visit(Vertex V)
{
	cout << "正在访问" << V <<endl;
}
void DFS(MGraph Graph, Vertex V)
{
	Visit(V);
	Visited[V] = 1;
	for (int i = 0; i < Graph->nv; i++)
	{
		if (Graph->G[V][i] != INFINITY)//对于V的每个邻接点
		{
			if(!Visited[i])
				DFS(Graph,i);
		}
	}
}
Vertex FindMinDist(MGraph Graph, int dist[], int collected[])
{
	Vertex v;
	int MinDist = INFINITY;
	for (int w = 0; w < Graph->nv; w++)
	{
		if (collected[w]==0&&dist[w] < MinDist)
		{
			MinDist = dist[w];
			v = w;
		}
	}
	if (MinDist < INFINITY)
		return v;
	else
		return -1;
}
//单源最短路径Dijkstra
void Dijkstra(MGraph Graph, Vertex s, int dist[], int path[])
{
	int collected[MaxVertexNum];
	Vertex v;
	for (int w = 0; w < Graph->nv; w++)
	{
		dist[w] = Graph->G[s][w];
		if (dist[w] < INFINITY)
			path[w] = s;
		else
			path[w] = -1;
		collected[w] = 0;
	}
	collected[s] = 1;
	dist[s] = 0;
	while (1) {
		v = FindMinDist(Graph, dist, collected);
		if (v == -1)
			break;
		collected[v] = 1;
		
		for (int w = 0; w < Graph->nv; w++)
		{
			if (collected[w] == 0 && Graph->G[v][w] != INFINITY)
			{
				if (dist[v] + Graph->G[v][w] < dist[w])
				{
					dist[w] = dist[v] + Graph->G[v][w];
					path[w] = v;
				}
			}
		}
		
	}
}
//多源最短路径
void Floyd(MGraph Graph,  int D[MaxVertexNum][MaxVertexNum], int path[MaxVertexNum][MaxVertexNum])
{
	Vertex i, j, k;
	for (i = 0; i < Graph->nv; i++)
		for (j = 0; j < Graph->nv; j++)
		{
			if (i != j)
				D[i][j] = Graph->G[i][j];
			else
				D[i][j] = 0;
			path[i][j] = -1;
		}
	for(k=0;k<Graph->nv;k++)
		for (i = 0; i < Graph->nv; i++)
			for (j = 0; j < Graph->nv; j++)
			{
				if (D[i][k] + D[k][j] < D[i][j])
				{
					D[i][j] = D[i][k] + D[k][j];
					path[i][j] = k;
				}
			}
}
Vertex FindMinDistTree(MGraph Graph, int dist[])
{
	Vertex v, w;
	WeightType MinWieght = INFINITY;
	for (v = 0; v < Graph->nv; v++)
	{
		if (dist[v] != 0 && dist[v] < MinWieght)
		{
			MinWieght = dist[v];
			w = v;
		}
	}
	if (MinWieght != INFINITY)
		return w;
	else
		return -1;
}
WeightType prim(MGraph Graph,MGraph MST)
{
	WeightType totalWeight=0, dist[MaxVertexNum];
	Vertex v, w,parent[MaxVertexNum];
	int vcount = 0;
	Edge e;
	//默认初始点为0
	for (v = 0; v < Graph->nv; v++)
	{
		dist[v] = Graph->G[0][v];
		parent[v] = 0;
	}
	//初始化邻接矩阵为包含所有顶点但没有边,和空的边
	MST = CreateGraph(Graph->nv);
	e = new ENode;
	//将初始点0收录
	dist[0] = 0;
	parent[0] = -1;
	while (1) {
		v = FindMinDistTree(Graph,dist);
		if (v == -1)
			break;
		e->v1 = parent[v];
		e->v2 = v;
		e->Weight = dist[v];
		InsertEdge(MST, e);
		totalWeight += dist[v];
		dist[v] = 0;//将v收录进最小生成树
		vcount++;
		for (w = 0; w < Graph->nv; w++)
		{
			//如果顶点未被收录并且新进顶点的领结点的话
			if (dist[w] != 0 && Graph->G[v][w] != INFINITY)
			{
				if (Graph->G[v][w] < dist[w])
				{
					dist[w] = Graph->G[v][w];
					parent[w] = v;
				}
			}
		}
	}
	if (vcount != Graph->nv)
	{
		cout << "没有最小生成树" << endl;
		return -1;
	}
	else
		return totalWeight;
}
void addSpecialChar(string &arr)
{
	if (arr.length() == 0)
		throw("string must has char");
	int size = arr.length();
	for (auto it = arr.begin(); it != arr.end(); it = it + 2)
		it = arr.insert(it, '#');
	arr = arr + "#";

}

int manacgher(string &arr)
{
	addSpecialChar(arr);
	int c = -1;
	int r = -1;
	int maxvalue = -1;
	int parr[100] = { 0 };//字符串长度不超过100
	for (int i = 0; i < arr.length(); i++) {
		parr[i] = r > i ? min(parr[2 * c - i], r - i) : 1;

		while (i + parr[i] < arr.length() && i - parr[i] >= 0) {
			if (arr[parr[i] + i] == arr[i - parr[i]])
				parr[i]++;
			else
				break;
		}
		if (parr[i] + i > r) {
			r = parr[i] + i;
			c = i;
		}
		maxvalue = max(parr[i], maxvalue);
	}

	return maxvalue - 1;
}
//马拉车算法应用:给定一个字符串，只能在字符串后面添加字符，使整个串变成回文串，保证添加的字符最短 
//思路：保证在包含最后一个字符的情况下，求出最长回文序列的长度，前面不是的字符串，逆序加到最后
string	palindromic_sequence(string &arr)
{
	string orgin_arr = arr;//保存原始字符串
	addSpecialChar(arr);
	int c = -1;
	int r = -1;

	int parr[100] = { 0 };//字符串长度不超过100
	int size = arr.length();

	for (int i = 0; (i <size); i++) {
		parr[i] = r > i ? min(parr[2 * c - i], r - i) : 1;

		while (i + parr[i] < arr.length() && i - parr[i] >= 0) {
			if (arr[parr[i] + i] == arr[i - parr[i]])
				parr[i]++;
			else
				break;
		}
		if (parr[i] + i > r) {
			r = parr[i] + i;
			c = i;
		}
		if (r == size)//如果达到最后一个字符结束
			break;
	}

	int residual = c - parr[c];//计算出逆序的字符的位置
	for (int i = residual; i >= 0; i--) {  //逆序
		if (arr[i] == '#')
			continue;
		else
			orgin_arr = orgin_arr + arr[i];
	}

	return orgin_arr;
}
