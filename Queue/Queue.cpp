#include <iostream>
#include "Statistic.h"
#include "PrinterQueue.h"

int main()
{
	PrinterQueue QU(5);
	Statistic stats(5);
	QU.Add(1, "user1");
	QU.Add(2, "user2");
	QU.Add(6, "user6");
	QU.Add(10, "user10");
	QU.Add(3, "user5");
	stats.AddStat(QU.Extract());
	stats.AddStat(QU.Extract());
	stats.AddStat(QU.Extract());
	stats.AddStat(QU.Extract());
	stats.AddStat(QU.Extract());
	
	stats.Show();
}
