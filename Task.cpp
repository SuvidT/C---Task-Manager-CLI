#include "Task.h"
#include <iostream>

// Remove using namespace std;

Task::Task(int id, std::string description) {
    this->id = id;
    this->description = description;
    this->status = Progress::Todo;
    this->next = nullptr;
}

int Task::get_id() const {
    return this->id;
}

std::string Task::get_description() const {
    return this->description;
}

Task::Progress Task::get_progress() const {
    return this->status;
}

Task* Task::get_next() const {
    return this->next;
}

void Task::set_description(const std::string& newDescription) {
    this->description = newDescription;
}

void Task::set_progress(const Progress newStatus) {
    this->status = newStatus;
}

void Task::set_next(Task* nextTask) {
    this->next = nextTask;
}

std::ostream& operator<<(std::ostream& os, const Task::Progress& progress) {
    switch (static_cast<int>(progress)) {
    case static_cast<int>(Task::Progress::Todo):
        os << "Todo";
        break;
    case static_cast<int>(Task::Progress::InProgress):
        os << "InProgress";
        break;
    case static_cast<int>(Task::Progress::Done):
        os << "Done";
        break;
    case static_cast<int>(Task::Progress::None):
        os << "None";
        break;
    default:
        os << "Unknown";
        break;
    }
    return os;
}