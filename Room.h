#ifndef ROOM_H
#define ROOM_H

#include <string>
#include <vector>
using namespace std;

class Room {
private:
    string name;
    string description;
    vector<string> actions;
    string item;

public:
    Room(string name, string description, vector<string> actions, string item);
    void setName(const string& newName);
    void setDescription(const string& newDescription);
    void setActions(const vector<string>& newActions);
    void setItem(const string& newItem);
    string getName() const;
    string getDescription() const;
    vector<string> getActions() const;
    string getItem() const;
    string toString() const;
};

#endif