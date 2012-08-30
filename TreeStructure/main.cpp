#include "stdafx.h"

#include "binary_tree.h"
#include "thread_binary_tree.h"

#include <iostream>
#include <sstream>
using namespace std;

struct MyNum
{
	MyNum(void){ data = 0; }
	MyNum(int a) { data = a; }
	int data;
	operator bool(void)
	{
		if(data) return true;
		else return false;
	}

	operator int(void)
	{
		return data;
	}

	bool print(MyNum* num)
	{
		cout<<int(*num)<<" ";
		return true;
	}

};

stringstream& operator>>(stringstream& ss, MyNum& num)
{
	int s;
	ss>>s;
	num = s;
	return ss;
}

bool print_MyNum(MyNum * num)
{
	cout<<int(*num)<<" ";
	return true;
}

bool print_int(int* data)
{
    cout<<*data<<" ";
    return true;
}

int _tmain(int argc, _TCHAR* argv[])
{
	LineBinaryTreeNode<int>* lbt = NULL;
    LineBinaryTreeNode<int>::CreateFromString("1 2 4 8 0 11 0 0 0 5 0 9 0 0 3 6 0 0 7 10 0 0 12 13 0 0 14 0 0",lbt);
    cout<<"Pre Order:"<<endl;
    LineBinaryTreeNode<int>::PreOrderTraverse(lbt,print_int);
    cout<<endl;
    cout<<"Pre Order stack:"<<endl;
    LineBinaryTreeNode<int>::PreOrderTraverse_stack(lbt,print_int);
    cout<<endl;
    cout<<"In Order:"<<endl;
    LineBinaryTreeNode<int>::InOrderTraverse(lbt,print_int);
    cout<<endl;
    cout<<"In Order Stack:"<<endl;
    LineBinaryTreeNode<int>::InOrderTraverse_stack(lbt,print_int);
    cout<<endl;
    cout<<"Post Order:"<<endl;
    LineBinaryTreeNode<int>::PostOrderTraverse(lbt,print_int);
    cout<<endl;
    cout<<"Post Order stack:"<<endl;
    LineBinaryTreeNode<int>::PostOrderTraverse_stack(lbt,print_int);
    cout<<endl;
	cout<<"=================="<<endl;
	ThreadBinaryTreeNode<MyNum>* tlbt = NULL;
    ThreadBinaryTree<MyNum>::CreateFromString("1 2 4 8 0 11 0 0 0 5 0 9 0 0 3 6 0 0 7 10 0 0 12 13 0 0 14 0 0",tlbt);
	ThreadBinaryTree<MyNum> thbitree;
	ThreadBinaryTree<MyNum>::MakeThreadTree_InOrder(tlbt,thbitree);
	cout<<"In Order Thread:"<<endl;
	ThreadBinaryTree<MyNum>::InOrderTraverse_Thread(thbitree.root,print_MyNum);
	cout<<endl;
	
	cout<<"===================="<<endl;
	LineBinaryTree<int> line_bin_tree;
    line_bin_tree.CreateFromString("1 2 0 0 0");
	cout<<"Print:"; line_bin_tree.PreOrderTraverse(print_int);cout<<endl;
	
	LineBinaryTree<int> line_bin_tree_add;
    line_bin_tree_add.CreateFromString("1 2 0 0 0");
	LineBinaryTreeNode<int>* p = line_bin_tree.root->left_child;
	line_bin_tree.InsertChild(p,LineBinaryTree<int>::LEFT,&line_bin_tree_add);
	cout<<"After Print:"; line_bin_tree.PreOrderTraverse(print_int);cout<<endl;
	LineBinaryTreeNode<int>* r = NULL;
	line_bin_tree.DeleteChildren(p,LineBinaryTree<int>::LEFT,r);
	cout<<"After Del:"; line_bin_tree.PreOrderTraverse(print_int);cout<<endl;
    system("pause");
	return 0;
}

