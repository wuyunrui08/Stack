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
