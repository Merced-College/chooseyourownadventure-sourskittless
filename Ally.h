#ifndef ALLY_H
#define ALLY_H

#include <string>

class Ally {
private:
    std::string name;
    std::string dialogue;

public:
    Ally(std::string name, std::string dialogue);
    void interact() const;
};

#endif