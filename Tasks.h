#ifndef TASKS_H
#define TASKS_H

#include <string>
#include "Task.h"

class Tasks {
private:
    Task* head;
    int len;

public:
    Tasks();
    ~Tasks();

    int add_task(const std::string& description);
    void update_task(int id, const std::string& newDescription);
    void delete_task(int id);
    void change_progress(int id, Task::Progress newStatus);
    void list_tasks(Task::Progress status);
};

#endif