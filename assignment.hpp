#include<iostream>
#include<chrono>

using namespace std::chrono;

int main()
{
	double duration;
	auto start = std::chrono:: steady_clock::now();
	auto finish = std::chrono::steady_clock::now();

	finish = steady_clock::time_point 1 = steady_clock::now();
	start = steady_clock::time_point 2 = steady_clock::now();

	duration = finish - start;
	std::cout << "The elapsed time(ms) is " << duration << endl;
	return 0;
}