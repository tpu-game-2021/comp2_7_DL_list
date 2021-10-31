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
	}
	else
	{
		l->header->pPrev = p;
		p->pNext = l->header;
		l->header = p;
	}
}

// 末尾にデータを追加
void push_back(list* l, node* p)
{
	if (l->header == NULL)
	{
		l->header = p;
		l->footer = p;
	}
	else
	{
		l->footer->pNext = p;
		p->pPrev = l->footer;
		l->footer = p;
	}
}

// pのノードを削除
void remove_node(list* l, node* p)
{
	if (p->pPrev != NULL && p->pNext != NULL) //前後に要素あり
	{
		p->pPrev->pNext = p->pNext;
		p->pNext->pPrev = p->pPrev;
	}
	else if (p->pPrev == NULL && p->pNext == NULL) //前後に要素なし
	{
		l->header = NULL;
		l->footer = NULL;
	}
	else if (p->pPrev == NULL) //前だけに要素あり
	{
		l->header = p->pNext;
		p->pNext->pPrev = NULL;
	}
	else if (p->pNext == NULL) //後ろだけに要素あり
	{
		l->footer = p->pPrev;
		p->pPrev->pNext = NULL;
	}
	initialize_node(p, 0);
}

// pの次のノードを削除
void remove_next(list* l, node* p)
{
	node* temp;

	if (p->pNext == NULL) //次のノードがそもそもない
	{
		return;
	}
	else if (p->pNext->pNext != NULL) //次の次に要素あり
	{
		temp = p->pNext; //あとできちんと初期化するため

		p->pNext = p->pNext->pNext;
		p->pNext->pPrev = p;
	}
	else //次が末尾
	{
		temp = p->pNext;

		p->pNext = NULL;
		l->footer = p;
	}
	initialize_node(temp, 0);
}

// pの前のノードを削除
void remove_prev(list* l, node* p)
{
	node* temp;

	if (p->pPrev == NULL) //前のノードがそもそもない
	{
		return;
	}
	else if (p->pPrev->pPrev != NULL) //前の前に要素あり
	{
		temp = p->pPrev; //あとできちんと初期化するため

		p->pPrev = p->pPrev->pPrev;
		p->pPrev->pNext = p;
	}
	else //前が先頭
	{
		temp = p->pPrev;

		p->pPrev = NULL;
		l->header = p;
	}
	initialize_node(temp, 0);
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
