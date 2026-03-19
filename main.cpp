#include <fstream>
#include <sstream>
#include <iostream>
#include "LinkedList.h"
#include "Ally.h"
#include "Food.h"

using namespace std;

void introduction() {
    cout << "Welcome to the Castle Adventure!\n";
    cout << "Navigate the rooms and survive!\n\n";
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
    }

    introduction();

    auto current = castleRooms.getHead();
    while (current != nullptr) {
        cout << current->room.toString() << endl;

        // Trigger Ally in the Throne Room
        if (current->room.getName() == "Throne Room") {
            Ally king("The King", "I seek a hero to save this realm.");
            king.interact();
        }

        // Trigger Food if the room has a Magic Scroll
        if (current->room.getItem() == "Magic Scroll") {
            Food snack("Royal Apple", 10);
            snack.consume();
        }

        int actionNum = 1;
        auto roomActions = current->room.getActions();
        for (const auto& action : roomActions) {
            cout << actionNum++ << ". " << action << endl;
        }

        int choice;
        cout << "Choose an action: ";
        cin >> choice;

        if (choice > 0 && choice <= roomActions.size()) {
            cout << "You chose: " << roomActions[choice - 1] << endl;
            // Move to next room if "Leave the room" is chosen (assumed last action)
            if (choice == roomActions.size()) {
                current = current->next;
            }
        } else {
            cout << "Invalid choice.\n";
        }
    }

    cout << "Adventure Complete!\n";
    return 0;
}