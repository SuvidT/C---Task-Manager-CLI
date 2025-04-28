#include <iostream>
#include <string>
#include "Tasks.h"

using namespace std;

int main() {
    while (true) {
        Tasks taskManager{};
        string command;

        cout << "TaskMaanger ";
        cin >> command;

        if (command == "add") {
            string description;

            cin >> description;

            taskManager.add_task(description);

        } else if (command == "update") {
            int id;
            string description;

            cin >> id >> description;

            taskManager.update_task(id, description);

        } else if (command == "delete") {
            int id;

            cin >> id;

            taskManager.delete_task(id);

        } else if (command == "mark") {
            string command2;

            cin >> command2;

            if (command2 == "todo") {
                int id;

                cin >> id;

                taskManager.change_progress(id, Task::Progress::Todo);

            } else if (command2 == "in-progress") {
                int id;

                cin >> id;

                taskManager.change_progress(id, Task::Progress::InProgress);

            } else if (command2 == "done") {
                int id;

                cin >> id;

                taskManager.change_progress(id, Task::Progress::Done);

            } else {
                cout << "Command Not Understood, Try Again";

            }

        } else if (command == "list") {
            string command2;

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
                cout << "Command Not Understood, Try Again";

            }
        } else {
            cout << "Command Not Understood, Try Again";

        }

    }
}