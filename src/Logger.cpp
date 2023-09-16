
#include "Logger.h"

void Logger::printHeader() {
	int l = 0;
	l += std::snprintf(obuf+l, MAXBUF-l, "%7s   ", "tempo");
	for (int i = 1; i <= pnum; ++i)
		l += std::snprintf(obuf+l, MAXBUF-l, "P%i  ", i);
	out << obuf << std::endl;
}

void Logger::printState(int runningTime, vector<Process*> processes) {
	int l = 0;
	
	char* tbuf;
	tbuf = new char[8];
	sprintf(tbuf, "%i-%i", runningTime, runningTime+1);
	l += std::snprintf(obuf+l, MAXBUF-l, "%7s   ", tbuf);

	delete tbuf; tbuf = new char[3];

	for (int i = 0; i < pnum; ++i) {
		Process* p = processes[i];
		switch(p->getState()) {
			case Process::State::NEW:
				tbuf = (char*)"  ";	
				break;
			case Process::State::READY:
				tbuf = (char*)"--";
				break;
			case Process::State::RUNNING:
				tbuf = (char*)"##";
				break;
			case Process::State::BLOCKED:
				tbuf = (char*)"--";
				break;
			case Process::State::TERMINATED:
			default:
				tbuf = (char*)"  ";
		} 
		l += std::snprintf(obuf+l, MAXBUF-l, "%2s  ", tbuf);
	}
	out << obuf << std::endl;
}
