#pragma once
#ifndef _STACK_MY_H_
#define _STACK_MY_H_
#include<iostream>
#include<cstdlib>
template<typename T>
struct node1
{
	T data;
	node1<T>* next = nullptr;
};

template<typename T>
class Stack_my
{
private:
	node1<T>* top;
	node1<T>* head;
	int len;

	node1<T>* op1, * op2, * op3;

public:
	Stack_my();
	~Stack_my();

	void Push(T a);//进栈
	T Top();//栈顶
	void Pop();//出栈
	bool Empty();//判空
	int Len();//元素个数


};
#endif // !_STACK_H_

template<typename T>
inline Stack_my<T>::Stack_my()
{
	top = head = nullptr;
	len = 0;
	op1 = op2 = op3 = nullptr;
}

template<typename T>
inline Stack_my<T>::~Stack_my()
{
	op1 = top;
	while (op1)
	{
		op2 = op1;
		op1 = op1->next;
		delete op2;
	}
}

template<typename T>
inline void Stack_my<T>::Push(T a)
{
	op1 = new node1<T>;
	if (!op1)
		exit(0);
	op1->data = a;//数据录入
	op1->next = nullptr;
	if (!head)//判断是否为头，头在最后面
	{
		head = op1;
		top = op1;
	}
	else
	{
		op1->next = top;//头不为空，那么就头插法
		top = op1;
	}
	len++;
}

template<typename T>
inline T Stack_my<T>::Top()
{
	if (top)//判断顶是否为空
		return T(top->data);
	else
	{
		std::cout << "No data!!!" << std::endl;
		return false;
	}
}

template<typename T>
inline void Stack_my<T>::Pop()
{
	if (!head)//头为空，栈中没有元素
	{
		std::cout << "Error" << std::endl;
	}
	else
	{
		len--;
		if (!len)
		{
			delete head;
			top = head = nullptr;
		}
		else//删除顶部元素
		{
			op2 = top;
			top = top->next;
			delete op2;
		}
	}
}

template<typename T>
inline bool Stack_my<T>::Empty()
{
	if (head)
		return false;
	else
		return true;
}

template<typename T>
inline int Stack_my<T>::Len()
{
	return len;
}
