#include "Statistic.h"

Statistic::Statistic(int m) {
	MaxQueueLength = m;
	Queue = new Stat[MaxQueueLength];
	QueueLength = 0;
}
Statistic::Statistic() {
	MaxQueueLength = 100;
	Queue = new Stat[MaxQueueLength];
	QueueLength = 0;
}
Statistic::~Statistic(){
	delete[] Queue;
}
void Statistic::AddStat(Stat s){
	if (!IsFull()) {
		Queue[QueueLength++] = s;
	}
}
void Statistic::Clear(){ QueueLength = 0; }
bool Statistic::IsEmpty(){ return QueueLength == 0; }
bool Statistic::IsFull(){ return MaxQueueLength == QueueLength; }
void Statistic::Show(){
	std::cout << "\n_________\n";
	for (int ii = 0; ii < QueueLength; ii++) {
		std::cout << "(" << Queue[ii].User << ";" << Queue[ii].hour << ":" << Queue[ii].min << ")" << " ";
	}
	std::cout << "\n_________\n";
}
int Statistic::GetCount(){ return QueueLength == 0; }