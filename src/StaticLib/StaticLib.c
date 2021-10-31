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
	if (l == NULL || p == NULL)
		return;
	if (l->header == NULL || l->footer == NULL)
	{
		p->pNext = l->header;
		l->header = p;
		l->footer = p;
	}
	else
	{
		p->pNext = l->header;
		l->header = p;
		p->pNext->pPrev = p;

	}
}

// 末尾にデータを追加
void push_back(list* l, node* p)
{
	if (l->footer == NULL || l->header == NULL)
	{
		p->pPrev = l->footer;
		l->header = p;
		l->footer = p;
	}
	else
	{
		p->pPrev = l->footer;
		l->footer = p;
		p->pPrev->pNext = p;
	}
}

// pのノードを削除
void remove_node(list* l, node* p)
{
	if (p == l->header && p == l->footer)
	{
		l->header = NULL;
		l->footer = NULL;
	}
	else if (p == l->header)
	{
		p->pNext->pPrev = NULL;
		l->header = p->pNext;

	}
	else if (p == l->footer)
	{
		p->pPrev->pNext = NULL;
		l->footer = p->pPrev;
	}
	else
	{
		p->pPrev->pNext = p->pNext;
		p->pNext->pPrev = p->pPrev;
	}
}

// pの次のノードを削除
void remove_next(list* l, node* p)
{
	if (p->pNext == NULL)
		return;

	if (p->pNext == l->footer)
	{
		p->pNext = NULL;
		l->footer = p;
	}
	else
	{
		p->pNext->pNext->pPrev = p;
		p->pNext = p->pNext->pNext;
	}
}

// pの前のノードを削除
void remove_prev(list* l, node* p)
{
	if (p->pPrev == NULL)
		return;

	if (p->pPrev == l->header)
	{
		p->pPrev = NULL;
		l->header = p;
	}
	else
	{
		p->pPrev->pPrev->pNext = p;
		p->pPrev = p->pPrev->pPrev;
	}
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
