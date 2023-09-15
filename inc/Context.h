
#ifndef TRABALHO_INE5412_CONTEXT_H
#define TRABALHO_INE5412_CONTEXT_H

#include <cstdint>
using std::uint64_t;

class Context
{
public:
    Context(int rgsize, uint64_t *rgs);
    ~Context() {delete this;};

    enum Register {
	SP = 0, PC, ST
    };

    void 	updateRegisters(uint64_t* rgs);
    uint64_t*	getRegisters();

    void	updateRegister(int rg, uint64_t to);
    uint64_t	getRegister(int rg);

    void	updateSP(uint64_t to);
    uint64_t	getSP();

    void	updatePC(uint64_t to);
    uint64_t	getPC();

    void	updateST(uint64_t to);
    uint64_t	getST();

protected:
    const int rgsize;

    uint64_t *rg;
    uint64_t sp;
    uint64_t pc;
    uint64_t st;
};

#endif //TRABALHO_INE5412_CONTEXT_H
