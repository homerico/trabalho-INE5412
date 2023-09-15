
#include "Context.h"

Context::Context(int rgsize, uint64_t* rgs) : rgsize(rgsize) {
	sp = rgs[Register::SP];
	pc = rgs[Register::PC];
	st = rgs[Register::ST];
	rg = new uint64_t[rgsize];
	for (int i = 0; i < rgsize; ++i)
		rg[i] = rgs[i+3];
}

void Context::updateRegisters(uint64_t* rgs) {
	rg = rgs;
}

uint64_t* Context::getRegisters() {
	return rg;
}

void Context::updateRegister(int rg, uint64_t to) {
	this->rg[rg] = to;
}

uint64_t Context::getRegister(int rg) {
	return this->rg[rg];
}

void Context::updateSP(uint64_t to) {
	sp = to;
}

uint64_t Context::getSP() {
	return sp;
}

void Context::updatePC(uint64_t to) {
	pc = to;
}

uint64_t Context::getPC() {
	return pc;
}

void Context::updateST(uint64_t to) {
	st = to;
}

uint64_t Context::getST() {
	return st;
}
