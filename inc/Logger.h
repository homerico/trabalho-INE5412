
#ifndef TRABALHO_INE5412_LOGGER_H
#define TRABALHO_INE5412_LOGGER_H

#include <iostream>
#include <vector>
#include "Process.h"
using std::vector;

class Logger
{
public:
	Logger(std::streambuf* rdbuf, int pnum) : out(nullptr) {
		out.rdbuf(rdbuf);
		obuf = new char[MAXBUF];
		this->pnum = pnum;
	}

	~Logger() {delete obuf;};

	void printHeader();	
	void printState(int runningTime, vector<Process*> processess);

private:
	std::ostream out;
	char* obuf;
	int pnum;
	const int MAXBUF = 60;
};

#endif //TRABALHO_INE5412_LOGGER_H
