#include <iostream>
#include <string>
#include "Tasks.h"

using namespace std;

int main() {
    Tasks taskManager;
    string command;

    while (true) {
        cout << "TaskManager> ";
        cin >> command;

        if (command == "add") {
            string description;
            cout << "Description: ";
            cin >> description;
            taskManager.add_task(description);
        } else if (command == "update") {
            int id;
            string description;
            cout << "ID: ";
            cin >> id;
            cout << "Description: ";
            cin >> description;
            taskManager.update_task(id, description);
        } else if (command == "delete") {
            int id;
            cout << "ID: ";
            cin >> id;
            taskManager.delete_task(id);
        } else if (command == "mark") {
            string command2;
            cout << "Progress (todo, in-progress, done): ";
            cin >> command2;

            int id;
            cout << "ID: ";
            cin >> id;

            if (command2 == "todo") {
                taskManager.change_progress(id, Task::Progress::Todo);
            } else if (command2 == "in-progress") {
                taskManager.change_progress(id, Task::Progress::InProgress);
            } else if (command2 == "done") {
                taskManager.change_progress(id, Task::Progress::Done);
            } else {
                cout << "Command Not Understood, Try Again" << endl;
            }
        } else if (command == "list") {
            string command2;
            cout << "List (all, todo, in-progress, done): ";
            cin >> command2;

            if (command2 == "all") {
                taskManager.list_tasks(Task::Progress::None);
            } else if (command2 == "todo") {
                taskManager.list_tasks(Task::Progress::Todo);
            } else if (command2 == "in-progress") {
                taskManager.list_tasks(Task::Progress::InProgress);
            } else if (command2 == "done") {
                taskManager.list_tasks(Task::Progress::Done);
            } else {
                cout << "Command Not Understood, Try Again" << endl;
            }
        } else if (command == "exit") {
            break;
        }
         else {
            cout << "Command Not Understood, Try Again" << endl;
        }
    }

    return 0;
}