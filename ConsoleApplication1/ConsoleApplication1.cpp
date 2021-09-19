// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <thread>
#include <string>


using namespace std;
#include "oneapi/tbb.h"
oneapi::tbb::concurrent_queue<int> ResultQueue;

class LongTask {
public:
	void operator()() const {
		cout << "inside LongTask" << endl;
		// do long computation
		// post message to GUI!
		this_thread::sleep_for(5s);

		ResultQueue.emplace(5);

		cout << "done w/ long task" << endl;
	}
};

#include "oneapi/tbb/task_arena.h"

int main()
{
    std::cout << "Hello World!\n";

	{
		tbb::task_arena a;
		tbb::task_arena a2;
		tbb::task_arena a3;
		tbb::task_arena a4;
		tbb::task_arena a5;
		tbb::task_arena a6;
		a.enqueue(LongTask());
		a2.enqueue(LongTask());
		a3.enqueue(LongTask());
		a4.enqueue(LongTask());
		a5.enqueue(LongTask());
		a6.enqueue(LongTask());

		a.enqueue([]() {
			cout << "func!" << endl;
			});
	}

	cout << "Waiting..." << endl;
	this_thread::sleep_for(6s);

	cout << "Size: " << ResultQueue.unsafe_size() << endl;

	int a;
	if (ResultQueue.try_pop(a))
	{
		cout << a << endl;
	}

	cout << "done!" << endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file


