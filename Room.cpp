#include "Room.h"

Room::Room(string name, string description, vector<string> actions, string item)
    : name(name), description(description), actions(actions), item(item) {}

string Room::getName() const { return name; }
string Room::getItem() const { return item; }
vector<string> Room::getActions() const { return actions; }

string Room::toString() const {
    string info = "\n----------------------------\nRoom: " + name + 
                  "\nDescription: " + description + "\nItem: " + item;
    return info;
}