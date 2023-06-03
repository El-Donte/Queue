#pragma once
#include "Statistic.h"
#include <string>

class PrinterQueue
{
private:
	int* pri;
	std::string* Queue;
	int QueueLength;
	int MaxQueueLength;
	std::string User;
public:
	PrinterQueue(int);
	PrinterQueue();
	~PrinterQueue();
	void Add(int p, std::string u);
	Stat Extract();
	void Clear();
	bool IsEmpty();
	bool IsFull();
	void Show();
	int GetCount();
};

