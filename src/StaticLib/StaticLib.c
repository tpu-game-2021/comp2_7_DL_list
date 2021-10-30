#define WIN32_LEAN_AND_MEAN             // Windows ヘッダーからほとんど使用されていない部分を除外する
#include "Windows.h"                    // Windows API の機能定義

#include "../include/lib_func.h"


// ノードを初期化
void initialize_node(node* p, int val)
{
	p->pNext = NULL;
	p->pPrev = NULL;
	p->data = val;
}

// リストを初期化
void initialize_list(list* l)
{
	l->header = NULL;
	l->footer = NULL;
}


// 先頭にデータを追加
void push_front(list* l, node* p)
{
	if (l->header == NULL)
	{
		l->header = p;
		l->footer = p;
		return;
	}
	p->pNext = l->header;
	l->header->pPrev = p;
	l->header = p;
	
}

// 末尾にデータを追加
void push_back(list* l, node* p)
{
	if (l->footer == NULL)
	{
		l->header = p;
		l->footer = p;
		return;
	}
	p->pPrev = l->footer;
	l->footer->pNext = p;
	l->footer = p;
}

// pのノードを削除
void remove_node(list* l, node* p)
{
	if (p == l->header && p == l->footer) 
	{
		l->footer = NULL;
		l->header = NULL;
		p = NULL;
		return;
	}
	if (p == l->header)
	{
		l->header = p->pNext;
		p->pNext->pPrev = NULL;
		p = NULL;
		return;
	}
	if (p == l->footer)
	{
		l->footer = p->pPrev;
		p->pPrev->pNext = NULL;
		p = NULL;
		return;
	}
	p->pPrev->pNext = p->pNext;
	p->pNext->pPrev = p->pPrev;
	p = NULL;
}

// pの次のノードを削除
void remove_next(list* l, node* p)
{
	if (p->pNext == NULL) 
	{
		return;
	}
	
	node* pn = p->pNext;
	p->pNext = p->pNext->pNext;
	if (pn == l->footer)
	{
		l->footer = p;
		pn = NULL;
		return;
	}
	p->pNext->pPrev = p;
	pn = NULL;
}

// pの前のノードを削除
void remove_prev(list* l, node* p)
{
	if (p->pPrev == NULL)
	{
		return;
	}
	node* pr = p->pPrev;
	p->pPrev = p->pPrev->pPrev;
	if (pr == l->header)
	{
		l->header = p;
		pr = NULL;
		return;
	}
	p->pPrev->pNext = p;
	pr = NULL;
}


// pの次のノードを取得
node* get_next(list* l, node* p)
{
	if (!p) return NULL;
	return p->pNext;

	return NULL;
}

// pの前のノードを取得
node* get_prev(list* l, node* p)
{
	if (!p) return NULL;
	return p->pPrev;

	return NULL;
}
