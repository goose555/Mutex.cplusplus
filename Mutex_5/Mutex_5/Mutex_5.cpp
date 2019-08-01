#include <iostream>
#include <thread>
#include <mutex>
#include "SimpleTimer.h"

using namespace std;

mutex mtx;

void Print(char ch) {
	//lock_guard<mutex> lg(mtx);

		unique_lock<mutex> ul(mtx, std::defer_lock); //Не будет lock()

		ul.lock();

	this_thread::sleep_for(chrono::milliseconds(2000));
	
	//mtx.lock();
	for (int i = 0; i < 5; i++)
	{
		for (int i = 0; i < 10; i++)
		{
			cout << ch;
			this_thread::sleep_for(chrono::milliseconds(10));
		}
		cout << endl;
	}

	cout << endl;
	//mtx.unlock();

		//ul.unlock(); //Можно без unlock()

	//this_thread::sleep_for(chrono::milliseconds(2000));
}

int main()
{
	setlocale(LC_ALL, "ru");

	SimpleTimer timer;

	thread t1(Print, '*');
	thread t2(Print, '#');

	t1.join();
	t2.join();

	return 0;
}