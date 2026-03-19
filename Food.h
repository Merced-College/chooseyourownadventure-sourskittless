#ifndef FOOD_H
#define FOOD_H

#include <string>

class Food {
private:
    std::string type;
    int healthValue;

public:
    Food(std::string type, int healthValue);
    void consume() const;
};

#endif