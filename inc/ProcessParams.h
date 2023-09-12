
#ifndef TRABALHO_INE5412_PROCESSPARAMS_H
#define TRABALHO_INE5412_PROCESSPARAMS_H

class ProcessParams
{
public:
    ProcessParams(int c, int d, int p) {
        creation_time = c;
        duration = d;
        priority = p;
    }

    friend std::ostream &operator<<(std::ostream& os, const ProcessParams& p) {
        os << "Creation time = " << p.creation_time << " duration = " << p.duration << " Priority = " << p.priority << std::endl;
        return os;
    }

private:
    int creation_time;
    int duration; //seconds
    int priority;
};

#endif //TRABALHO_INE5412_PROCESSPARAMS_H
