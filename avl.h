#ifndef FAYT_AVL_H_
#define FAYT_AVL_H_

#define AVL_META(TYPE) \
	TYPE *right; \
	TYPE *left; \
	int height; \

#define AVL_LR(TABLE_ROOT, NODE) ({ \
	__label__ _out; \
	int _ret = 0; \
	if((NODE) == NULL) { \
		_ret = -1; \
		goto _out; \
	} \
	typeof(NODE) *tmp = (NODE)->right; \
	(NODE)->right = tmp->left; \
	tmp->left = (NODE); \
	(NODE)->height = (NODE)->right->height > (NODE)->left->height ? \
		(NODE)->right->height : (NODE)->left->height; \
	tmp->height = tmp->left->height > tmp->right->height ? \
		tmp->left->height : tmp->right->height; \
_out: \
	_ret; \
})

#define AVL_RR(TABLE_ROOT, NODE) ({ \
	__label__ _out; \
	int _ret = 0; \
	if((NODE) == NULL) { \
		_ret = -1; \
		goto _out; \
	} \
	typeof(NODE) *tmp = (NODE)->left; \
	(NODE)->right = tmp->right; \
	tmp->right = (NODE); \
	(NODE)->height = (NODE)->right->height > (NODE)->left->height ? \
		(NODE)->right->height : (NODE)->left->height; \
	tmp->height = tmp->left->height > tmp->right->height ? \
		tmp->left->height : tmp->right->height; \
_out: \
	_ret; \
})

#define AVL_INSERT(TABLE_ROOT, BASE, NODE) ({ \
	__label__ _out; \
	int _ret = BST_GENERIC_INSERT(TABLE_ROOT, BASE, NODE); \
	if(_ret == -1) goto _out; \
_out: \
	_ret; \
})

#endif
