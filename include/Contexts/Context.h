#ifndef BEANIEBABYSIM_CONTEXT_H
#define BEANIEBABYSIM_CONTEXT_H

#include <vector>
#include <string>

class Context {
protected:
    int time_ = 0;

public:
    int get_time() {return time_;}

    virtual std::vector<std::string> ExecuteCommand(std::string command) = 0;

    virtual std::vector<std::string> Help() = 0;

};
#endif //BEANIEBABYSIM_CONTEXT_H
