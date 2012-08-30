#pragma once

#include <string>
#include <sstream>

// tree node
template<typename T>
struct ThreadBinaryTreeNode
{
	enum NodeType { NODE = 0, THREAD = 1 };
	T data;
	ThreadBinaryTreeNode<T>* left_child;
	ThreadBinaryTreeNode<T>* right_child;
	NodeType left_child_type;
	NodeType right_child_type;

	ThreadBinaryTreeNode():
	    left_child(NULL),
		right_child(NULL),
		left_child_type(NODE),
		right_child_type(NODE)	{}
		
};

// tree
// T 需要的函数
//   operator bool
//   operator =
//   operator<<  stringstream,cout
//   或opearot int等等，这个不好
template<typename T>
struct ThreadBinaryTree
{
	ThreadBinaryTreeNode<T>* root;
	enum ThreadType{PRE_ORDER,IN_ORDER,POST_ORDER};
	ThreadType thread_type;

	ThreadBinaryTree(void):root(NULL),thread_type(IN_ORDER){};
	
	// 构造二叉树
    // 先序遍历的字符串序列，用空格表示空节点
    static void CreateFromString(const std::string& str,ThreadBinaryTreeNode<T>* &binary_tree) 
    {
        std::stringstream ss(str);
        CreateFromStringStream(ss,binary_tree);
    }; 
	
	// 从stringstream中构造二叉树
    static void CreateFromStringStream(std::stringstream & ss, ThreadBinaryTreeNode<T>* &binary_tree);
	
	// 构造带头结点的线索树
	static void MakeThreadTree_InOrder(ThreadBinaryTreeNode<T>* &p,ThreadBinaryTree<T> &btree);
	// 线索化
	static void MakeThreading_InOrder(ThreadBinaryTreeNode<T>* &p, ThreadBinaryTreeNode<T>* &pre);

	// 线索化的中序遍历
	static void InOrderTraverse_Thread(ThreadBinaryTreeNode<T>* broot, bool (*visit_function_ptr)(T* ptr_data));
};

// 从先序字符串中构建
template<typename T> void ThreadBinaryTree<T>::CreateFromStringStream(
	std::stringstream &ss , 
	ThreadBinaryTreeNode<T>* &binary_tree)
{
	T data;
    ss>>data;
    if(data) // 测试值是否有效 operator bool
    {
        binary_tree = new ThreadBinaryTreeNode<T>();
        binary_tree->data = data;
        CreateFromStringStream(ss,binary_tree->left_child);
        CreateFromStringStream(ss,binary_tree->right_child);
    }
    return;
}

// 构造带头结点的中序线索树
template<typename T> void ThreadBinaryTree<T>::MakeThreadTree_InOrder(
	ThreadBinaryTreeNode<T>* &p,
	ThreadBinaryTree<T> & btree)
{
	ThreadBinaryTreeNode<T>* pre;
	btree.root = new ThreadBinaryTreeNode<T>();
	btree.root->left_child_type = ThreadBinaryTreeNode<T>::NODE;
	btree.root->right_child_type = ThreadBinaryTreeNode<T>::THREAD;
	if(!p) btree.root->left_child = btree.root; // 空树
	else
	{
		btree.root->left_child = p; pre = btree.root;
		MakeThreading_InOrder(p,pre); //?
		pre->right_child_type = ThreadBinaryTreeNode<T>::THREAD;
		pre->right_child = btree.root;
		btree.root->right_child = pre;
	}
}

// 中序线索化
template<typename T> void ThreadBinaryTree<T>::MakeThreading_InOrder(
	ThreadBinaryTreeNode<T>* &p,
	ThreadBinaryTreeNode<T>* &pre)
{
	if(p)
	{
		MakeThreading_InOrder(p->left_child,pre);
		if(!p->left_child)
		{
			p->left_child_type = ThreadBinaryTreeNode<T>::THREAD;
			p->left_child = pre;
		}
		if(!pre->right_child)
		{
			pre->right_child_type = ThreadBinaryTreeNode<T>::THREAD;
			pre->right_child = p;
		}
		pre = p;
		MakeThreading_InOrder(p->right_child,pre);
	}
}

// 线索化的中序遍历
template<typename T> void ThreadBinaryTree<T>::InOrderTraverse_Thread(
	ThreadBinaryTreeNode<T>* broot,
	bool (*visit_function_ptr)(T* ptr_data) )
{
	ThreadBinaryTreeNode<T>* p = broot->left_child;
	while(p != broot)
	{
		while(p->left_child_type == ThreadBinaryTreeNode<T>::NODE) p = p->left_child;
		visit_function_ptr(&p->data);
		while(p->right_child_type == ThreadBinaryTreeNode<T>::THREAD && p->right_child != broot)
		{
			p = p->right_child;
			visit_function_ptr(&p->data);
		}
		p = p->right_child;
	}

}

