#pragma once

#include <string>
#include <sstream>
#include <stack>

// ��������ṹ�Ķ�����
template<typename T>
struct LineBinaryTreeNode
{
	T data;
	LineBinaryTreeNode<T>* left_child;
	LineBinaryTreeNode<T>* right_child;
    
    // ���������
    // ����������ַ������У��ÿո��ʾ�սڵ�
    static void CreateFromString(const std::string& str,LineBinaryTreeNode<T>* &binary_tree) 
    {
        std::stringstream ss(str);
        CreateFromStringStream(ss,binary_tree);
    }; 
	
	// ��stringstream�й��������
    static void CreateFromStringStream(std::stringstream & ss, LineBinaryTreeNode<T>* &binary_tree) {}

    // ����
    // ����������ݹ�
    static void PreOrderTraverse(LineBinaryTreeNode<T>* &binary_tree, bool (*visit_function_ptr)(T* ptr_data)) 
    {
        if (binary_tree)
        {
            visit_function_ptr(&binary_tree->data);
            PreOrderTraverse(binary_tree->left_child,visit_function_ptr);
            PreOrderTraverse(binary_tree->right_child,visit_function_ptr);
        }
		else
		{
			/*T temp(0);
			visit_function_ptr(&temp);*/
		}
        return;
    };

    // ����������ǵݹ�
    static void PreOrderTraverse_stack(LineBinaryTreeNode<T>* &binary_tree, bool (*visit_function_ptr)(T* ptr_data)) 
    {
        std::stack<LineBinaryTreeNode<T>* > node_stack;
        LineBinaryTreeNode<T>* p = binary_tree;
        
        while(p || !node_stack.empty() )
        {
            if(p)
            {
                visit_function_ptr(&p->data);
                node_stack.push(p->right_child);
                p = p->left_child;
            }
            else
            {
                p = node_stack.top(); node_stack.pop();        
            }
        }
        return;
    };

    // ����������ݹ�
    static void InOrderTraverse(LineBinaryTreeNode<T>* &binary_tree, bool (*visit_function_ptr)(T* ptr_data))
    {
        if (binary_tree)
        {
            InOrderTraverse(binary_tree->left_child,visit_function_ptr);
            visit_function_ptr(&binary_tree->data);
            InOrderTraverse(binary_tree->right_child,visit_function_ptr);
        }
        return;
    };
    // ����������ݹ�
    static void InOrderTraverse_stack(LineBinaryTreeNode<T>* &binary_tree, bool (*visit_function_ptr)(T* ptr_data))
    {
        std::stack<LineBinaryTreeNode<T>* > node_stack;
        LineBinaryTreeNode<T>* p = binary_tree;
        while(p || !node_stack.empty())
        {
            if(p)
            {
                node_stack.push(p);
                p = p->left_child;
            }
            else
            {
                p = node_stack.top();node_stack.pop();
                visit_function_ptr(&p->data);
                p = p->right_child;
            }
        }
    };

    // ����������ݹ�
    static void PostOrderTraverse(LineBinaryTreeNode<T>* &binary_tree, bool (*visit_function_ptr)(T* ptr_data))
    {
        if (binary_tree)
        {
            
            PostOrderTraverse(binary_tree->left_child,visit_function_ptr);
            PostOrderTraverse(binary_tree->right_child,visit_function_ptr);
			visit_function_ptr(&binary_tree->data);
        }
        return;
    };

    // ����������ǵݹ�
    static void PostOrderTraverse_stack(LineBinaryTreeNode<T>* &binary_tree, bool (*visit_function_ptr)(T* ptr_data))
    {
        std::stack<LineBinaryTreeNode<T>* > node_stack;
        LineBinaryTreeNode<T>* p = binary_tree;
        LineBinaryTreeNode<T>* pre = NULL;
        while(p || !node_stack.empty())
        {
            if(p)
			{
				node_stack.push(p);
				p = p->left_child;
			}
			else
			{
				p = node_stack.top();
				if(p->right_child && p->right_child != pre)
				{
					p = p->right_child;
				}
				else
				{
					p = pre = node_stack.top();
					visit_function_ptr(&p->data);
					node_stack.pop();
					p = NULL;
				}
			}
        }
    };
};

// int ���͵��ػ�
template<> void LineBinaryTreeNode<int>::CreateFromStringStream(std::stringstream & ss, LineBinaryTreeNode<int>* &binary_tree)
{
    int data;
    ss>>data;
    if(data)
    {
        binary_tree = new LineBinaryTreeNode<int>();
        binary_tree->data = data;
        binary_tree->left_child = NULL;
        binary_tree->right_child = NULL;
        CreateFromStringStream(ss,binary_tree->left_child);
        CreateFromStringStream(ss,binary_tree->right_child);
    }
    return;
}

// TODO: ������
template<typename T>
struct LineBinaryTree
{
	enum ChildType{LEFT,RIGHT};
	LineBinaryTreeNode<T>* root;

	LineBinaryTree():root(NULL){}

	// ���������
    // ����������ַ������У��ÿո��ʾ�սڵ�
    void CreateFromString(const std::string& str) 
    {
        std::stringstream ss(str);
        CreateFromStringStream(ss,root);
    }; 
	
	// ��stringstream�й��������
    static void CreateFromStringStream(std::stringstream & ss, LineBinaryTreeNode<T>* &binary_tree);

	// ����
    // ����������ݹ�
    void PreOrderTraverse( bool (*visit_function_ptr)(T* ptr_data)) 
    {
		LineBinaryTreeNode<T>::PreOrderTraverse(root,visit_function_ptr);
    };

	void InOrderTraverse( bool (*visit_function_ptr)(T* ptr_data)) 
    {
		LineBinaryTreeNode<T>::InOrderTraverse(root,visit_function_ptr);
    };

	void PostOrderTraverse( bool (*visit_function_ptr)(T* ptr_data)) 
    {
		LineBinaryTreeNode<T>::PostOrderTraverse(root,visit_function_ptr);
    };

	// ��������,t�ǿ���������Ϊ��
	bool InsertChild(LineBinaryTreeNode<T>* p, ChildType child_type, LineBinaryTree<T>* t);

	// ɾ������
	bool DeleteChildren(LineBinaryTreeNode<T>* p, ChildType child_type, LineBinaryTreeNode<T>* &r);

	// ɾ���ڵ㣿

};

// 
template<typename T> 
void LineBinaryTree<T>::CreateFromStringStream(std::stringstream &ss, LineBinaryTreeNode<T> *&binary_tree)
{
	int data;
    ss>>data;
    if(data)
    {
        binary_tree = new LineBinaryTreeNode<int>();
        binary_tree->data = data;
        binary_tree->left_child = NULL;
        binary_tree->right_child = NULL;
        CreateFromStringStream(ss,binary_tree->left_child);
        CreateFromStringStream(ss,binary_tree->right_child);
    }
    return;
}

// ����
template<typename T> 
bool LineBinaryTree<T>::InsertChild(LineBinaryTreeNode<T>* p, ChildType child_type, LineBinaryTree<T>* t)
{
	if(p && t && t->root && t->root->right_child == NULL)
	{
		if(child_type == LEFT)
		{
			t->root->right_child = p->left_child;
			p->left_child = t->root;
		}
		else
		{
			t->root->right_child = p->right_child;
			p->right_child = t->root;
		}
	}
	return true;
}

// ɾ��
template<typename T> 
bool LineBinaryTree<T>::DeleteChildren(LineBinaryTreeNode<T>* p, ChildType child_type, LineBinaryTreeNode<T>* &r)
{
	if(p)
	{
		if(child_type == LEFT)
		{
			if(p->left_child)
			{
				r = p->left_child;
				p->left_child = NULL;
			}
			else
				return false;
		}
		else
		{
			if(p->right_child)
			{
				r = p->right_child;
				p->right_child = NULL;
			}
			else
				return false;
		}
		return true;
	}
	else
		return false;
}
	