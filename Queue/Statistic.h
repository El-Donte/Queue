#pragma once
#include <string>
#include <iostream>
struct Stat {
	std::string User;
	int min;
	int hour;
};

class Statistic
{
	 Stat* Queue;
	 int QueueLength;
	 int MaxQueueLength;
public:
	Statistic(int m);
	Statistic();
	~Statistic();
	void AddStat(Stat s);
	void Clear();
	bool IsEmpty();
	bool IsFull();
	void Show();
	int GetCount();
};

