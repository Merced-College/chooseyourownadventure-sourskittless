#ifndef FOOD_H
#define FOOD_H

#include <string>

class Food {
private:
    std::string name;
    int benefit;

public:
    Food(std::string name, int benefit);
    void eat() const;
};

#endif