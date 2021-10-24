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
	if (l == NULL || p == NULL) return;

	if (l->header == NULL) {
		l->footer = p;
	}
	else {
		l->header->pPrev = p;
	}
	p->pNext = l->header;
	p->pPrev = NULL;
	l->header = p;
}

// 末尾にデータを追加
void push_back(list* l, node* p)
{
	if (l == NULL || p == NULL) return;

	if (l->footer == NULL) {
		l->header = p;
	}
	else {
		l->footer->pNext = p;
	}
	p->pPrev = l->footer;
	p->pNext = NULL;
	l->footer = p;
}

// pのノードを削除
void remove_node(list* l, node* p)
{
	if (l == NULL || p == NULL) return;
	
	if (p->pPrev == NULL) {
		l->header = p->pNext;
	}
	else {
		p->pPrev->pNext = p->pNext;
	}
	if (p->pNext == NULL) {
		l->footer = p->pPrev;
	}
	else {
		p->pNext->pPrev = p->pPrev;
	}

	// 今後、問題が起きないように情報を消去
	p->pNext = NULL;
	p->pPrev = NULL;
}

// pの次のノードを削除
void remove_next(list* l, node* p)
{
	if (l == NULL || p == NULL || p->pNext == NULL) return;

	remove_node(l, p->pNext);
}

// pの前のノードを削除
void remove_prev(list* l, node* p)
{
	if (l == NULL || p == NULL || p->pPrev == NULL) return;

	remove_node(l, p->pPrev);
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
