#include "Room.h"

Room::Room(string name, string description, vector<string> actions, string item)
    : name(name), description(description), actions(actions), item(item) {}

void Room::setName(const string& newName) { name = newName; }
void Room::setDescription(const string& newDescription) { description = newDescription; }
void Room::setActions(const vector<string>& newActions) { actions = newActions; }
void Room::setItem(const string& newItem) { item = newItem; }
string Room::getName() const { return name; }
string Room::getDescription() const { return description; }
vector<string> Room::getActions() const { return actions; }
string Room::getItem() const { return item; }

string Room::toString() const {
    string info = "Room: " + name + "\nDescription: " + description + "\nActions:\n";
    for (const auto& action : actions) {
        info += "- " + action + "\n";
    }
    info += "Item: " + item + "\n";
    return info;
}