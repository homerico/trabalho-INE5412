
#ifndef TRABALHO_INE5412_CONTEXT_H
#define TRABALHO_INE5412_CONTEXT_H

class Context
{
public:
    Context() = default;
    Context(void (*func)(char *), char * arg);
    ~Context() {delete this;};
protected:
};

#endif //TRABALHO_INE5412_CONTEXT_H
