#include <fstream>
#include <sstream>
#include <iostream>
#include "LinkedList.h"
#include "Ally.h"
#include "Food.h"

using namespace std;

void introduction() {
    cout << "Welcome to the Castle Adventure!\n";
    cout << "You will navigate through various rooms in the castle, encountering challenges and making decisions that will determine your path.\n";
    cout << "Choose your actions wisely. Let's start your journey!\n\n";
}

int main() {
    LinkedList castleRooms;
    ifstream file("rooms.csv");
    string line;

    if (file.is_open()) {
        while (getline(file, line)) {
            stringstream ss(line);
            string name, description, actionsStr, item;
            vector<string> actions;

            getline(ss, name, ',');
            getline(ss, description, ',');
            getline(ss, actionsStr, ',');
            getline(ss, item);

            stringstream actionStream(actionsStr);
            string action;
            while (getline(actionStream, action, ';')) {
                actions.push_back(action);
            }

            Room newRoom(name, description, actions, item);
            castleRooms.addRoom(newRoom);
        }
        file.close();
    } else {
        cout << "Unable to open file" << endl;
        return 1;
    }

    introduction();

    auto current = castleRooms.getHead();
    int roomCounter = 1; 

    while (current != nullptr) {
        cout << current->room.toString() << endl;

        // Unique interactions for each room based on room number
        switch(roomCounter) {
            case 1: { // Throne Room
                Ally king("King Arthur", "Welcome, traveler. Help us save the kingdom!", 50);
                king.greet();
                Food apple("Royal Apple", 10);
                apple.eat();
                break;
            }
            case 2: { // Hall of Knights
                Ally knight("Sir Lancelot", "My sword is yours, traveler.", 30);
                knight.greet();
                Food jerky("Dried Meat", 15);
                jerky.eat();
                break;
            }
            case 3: { // Royal Library
                Ally wizard("Merlin", "Knowledge is the greatest power.", 100);
                wizard.greet();
                Food potion("Blueberry Tart", 25);
                potion.eat();
                break;
            }
            case 4: { // Dungeon
                Ally prisoner("Scruffy", "Spare some bread for a poor soul?", 5);
                prisoner.greet();
                Food crust("Stale Bread", 2);
                crust.eat();
                break;
            }
        }

        int actionNum = 1;
        for (const auto& action : current->room.getActions()) {
            cout << actionNum++ << ". " << action << endl;
        }

        int choice;
        cout << "Choose an action (1-" << current->room.getActions().size() << "): ";
        cin >> choice;

        if (choice < 1 || choice > current->room.getActions().size()) {
            cout << "Invalid choice. Try again.\n";
        } else {
            cout << "You chose: " << current->room.getActions()[choice - 1] << endl;
            if (choice == current->room.getActions().size()) { 
                current = current->next; 
                roomCounter++; 
            }
        }
    }

    cout << "You have reached the end of your adventure!\n";
    return 0;
}