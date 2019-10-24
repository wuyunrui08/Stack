# Stack
Implementation of the chain stack. Own method
﻿﻿﻿﻿
# 链栈的实现

---

- 栈可谓是一种简单的数据结构，在 C++ 有库函数可以调用 ``#include<stack>`` 我们也可以亲手写一个链栈。链栈的实现形式是通过链表来储存，使用单向链表，使用头插法，头的位置称之为栈顶，其尾部的位置成为栈底。
- 栈的操作有 **进栈** ，**出栈**，**判空**，**访问栈顶** 等操作。自己写栈的结构可以添加自己需要的操作

---

####图示：

![photo1][photo1]

![photo2][photo2]

![photo3][photo3]

---

##main.c

```c++
#include"Stack_my.h"
using namespace std;
int main()
{
	Stack_my<int>s1;
	s1.Push(1);
	cout <<"Stack top: "<< s1.Top() << endl;
	s1.Push(2);
	cout << "Stack top: " << s1.Top() << endl;
	if (s1.Empty())
		cout << "Empty." << endl;
	else
		cout << "Not Empty." << endl;
	s1.Pop();
	cout << "Stack top: " << s1.Top() << endl;
	s1.Pop();
	cout << "Stack top: " << s1.Top() << endl;
	if (s1.Empty())
		cout << "Empty." << endl;
	else
		cout << "Not Empty." << endl;

	return 0;
}

```

##stack_my.h

```c++
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


```
---

- **有错误请指出**
- **有更好的方法请指教**

---

[photo1]:https://img2018.cnblogs.com/blog/1723659/201910/1723659-20191024183826996-1385644670.png


[photo2]:https://img2018.cnblogs.com/blog/1723659/201910/1723659-20191024183842259-742773517.png


[photo3]:https://img2018.cnblogs.com/blog/1723659/201910/1723659-20191024183854268-1425024115.png
