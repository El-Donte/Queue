#include "PrinterQueue.h"
#include "Statistic.h"
#include <iostream>

PrinterQueue::PrinterQueue(int m) {
	MaxQueueLength = m;
	Queue = new std::string[MaxQueueLength];
	pri = new int[MaxQueueLength];
	QueueLength = 0;
}
PrinterQueue::~PrinterQueue() {
	delete[] Queue;
	delete[] pri;
}
void PrinterQueue::Add(int p, std::string u) {
	if (!IsFull()) {
		Queue[QueueLength] = u;
		pri[QueueLength] = p;
		QueueLength++;
	}
}
Stat PrinterQueue::Extract() {
	
	if (!IsEmpty()) {
		
		int max_pri = pri[0];
		int pos_max_pri = 0;		
		
		for (int ii = 1; ii < QueueLength; ii++) {
			if (max_pri < pri[ii]) {
				max_pri = pri[ii];
				pos_max_pri = ii;
			}
		}
		std::string temp = Queue[pos_max_pri];
		int temp2 = pri[pos_max_pri];
		Stat stat;
		stat.User = temp;
		stat.hour =rand() % (24-1);
		stat.min = rand() % (60-1);
		for (int ii = pos_max_pri; ii < QueueLength - 1; ii++) {
			Queue[ii] = Queue[ii + 1];
			pri[ii] = pri[ii + 1];
		}
		QueueLength--;
		return stat;
	}
}
void PrinterQueue::Clear() {
	QueueLength = 0;
}
bool PrinterQueue::IsEmpty() {
	return QueueLength == 0;
}
bool PrinterQueue::IsFull() {
	return MaxQueueLength == QueueLength;
}
void PrinterQueue::Show() {
	std::cout << "\n_______________\n";
	for (int ii = 0; ii < QueueLength; ii++) {
		std::cout << "(" << Queue[ii] << "-" << pri[ii] << ")" << " ";
	}
	std::cout << "\n_______________\n";
}
int PrinterQueue::GetCount() {
	return QueueLength;
}