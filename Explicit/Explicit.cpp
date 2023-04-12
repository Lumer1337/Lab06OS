// Explicit.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <Windows.h>
#include "..\..\Dll2\Dll2\Stack.h"
using namespace std;

int main2() 
{
	Stack myStack;
	myStack.push(1);
	myStack.push(2);
	myStack.push(3);
	myStack.saveToFile("myStack.bin");
	myStack.loadFromFile("myStack.bin");

	std::cout << "Stack after saving to file(321): " << std::endl;
	std::cout << myStack.pop() << std::endl;
	std::cout << myStack.pop() << std::endl;
	std::cout << myStack.pop() << std::endl;

	myStack.push(4);
	myStack.push(5);
	myStack.push(6);

	myStack.saveToFile("myStack.bin");
	myStack.loadFromFile("myStack.bin");

	std::cout << "Stack after loading from file(654): " << std::endl;
	std::cout << myStack.pop() << std::endl;
	std::cout << myStack.pop() << std::endl;
	std::cout << myStack.pop() << std::endl;


	std::cout << "Stack after loading from file(-1-1-1): " << std::endl;
	myStack.saveToFile("myStack.bin");
	myStack.loadFromFile("myStack.bin");
	std::cout << myStack.pop() << std::endl;
	std::cout << myStack.pop() << std::endl;
	std::cout << myStack.pop() << std::endl;

	return 0;
}

int main1()
{
    HINSTANCE dll = LoadLibrary(L"Dll2.dll");
    if (dll == NULL)
    {
        cout << "Error";
        return 1;
    }
	else
	{
		cout << "Library created successfully\n"; 
		void(Stack:: * pConstructor)();
		(FARPROC&)pConstructor = GetProcAddress(dll, "??0Stack@@QEAA@XZ");
		Stack* c = (Stack*)HeapAlloc(GetProcessHeap(), NULL, sizeof(Stack));
		(c->*pConstructor)();
		void(Stack:: * pPush)(int);
		(FARPROC&)pPush = GetProcAddress(dll, "?push@Stack@@QEAAXH@Z");
		(c->*pPush)(1);
		(c->*pPush)(2);
		(c->*pPush)(3);
		(c->*pPush)(4); 
		(c->*pPush)(5);
		(c->*pPush)(6);
		(c->*pPush)(7);
		int(Stack:: * pPop)();
		(FARPROC&)pPop = GetProcAddress(dll, "?pop@Stack@@QEAAHXZ");
		(c->*pPop)();
		cout << "Stack: " << endl;
		void(Stack:: * pDestructor)();
		(FARPROC&)pDestructor = GetProcAddress(dll, "??1Stack@@QEAA@XZ");
		(c->*pDestructor)();
		FreeLibrary(dll);
	}
	return 0;
}

int main()
{
	main1();
	main2();
}


