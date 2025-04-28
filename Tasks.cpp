#include "Tasks.h"
#include <stdexcept>
#include <iostream>

using namespace std;

Tasks::Tasks() {
    this->head = nullptr;
    this->len = 0;
}

Tasks::~Tasks() {
    Task* current = head;
    while (current != nullptr) {
        Task* next = current->get_next();
        delete current;
        current = next;
    }
}

int Tasks::add_task(const string& description) {
    len += 1;
    Task* newTask = new Task(len, description);

    newTask->set_next(head);
    head = newTask;

    return head->get_id();
}

void Tasks::update_task(int id, const string& newDescription) {
    if (head == nullptr) {
        throw invalid_argument("There are no tasks to be updated");
    }

    Task* current = head;
    while (current != nullptr) {
        if (current->get_id() == id) {
            current->set_description(newDescription);
            return;
        }
        current = current->get_next();
    }

    throw invalid_argument("There is no task with id: " + to_string(id));
}

void Tasks::delete_task(int id) {
    if (head == nullptr) {
        throw invalid_argument("There are no tasks to be deleted");
    }

    if (head->get_id() == id) {
        Task* temp = head;
        head = head->get_next();
        delete temp;
        len--;
        return;
    }

    Task* current = head;
    Task* prev = nullptr;

    while (current != nullptr) {
        if (current->get_id() == id) {
            if (prev != nullptr) {
                prev->set_next(current->get_next());
            } else {
                head = current->get_next();
            }
            delete current;
            len--;
            return;
        }
        prev = current;
        current = current->get_next();
    }

    throw invalid_argument("There is no task with id: " + to_string(id));
}

void Tasks::change_progress(int id, Task::Progress newStatus) {
    if (head == nullptr) {
        throw invalid_argument("There is no task to change the progress of");
    }

    Task* current = head;
    while (current != nullptr) {
        if (current->get_id() == id) {
            current->set_progress(newStatus);
            return;
        }
        current = current->get_next();
    }

    throw invalid_argument("There is no task with id: " + to_string(id));
}

void Tasks::list_tasks(Task::Progress status) {
    Task* current = head;

    if (status == Task::Progress::None) {
        while (current != nullptr) {
            cout << current->get_id() << " " << current->get_description() << " " << current->get_progress() << endl;
            current = current->get_next();
        }
    } else {
        while (current != nullptr) {
            if (current->get_progress() == status) {
                cout << current->get_id() << " " << current->get_description() << " " << current->get_progress() << endl;
            }
            current = current->get_next();
        }
    }
}