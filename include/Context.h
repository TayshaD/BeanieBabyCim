//
// Created by taja on 3/29/18.
//

#ifndef BEANIEBABYSIM_CONTEXT_H
#define BEANIEBABYSIM_CONTEXT_H

class Context {
protected:
    int time_ = 0;

public:
    int get_time() {return time_;}

    virtual std::vector<string> ExecuteCommand(std::string command) = 0;

    virtual std::vector<string> Help() = 0;

};
#endif //BEANIEBABYSIM_CONTEXT_H
