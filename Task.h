#ifndef TASK_H
#define TASK_H

#include <string>
#include <iostream>

class Task {
public:
    enum class Progress {
        Todo,
        InProgress,
        Done,
        None
    };

private:
    int id;
    std::string description;
    Progress status;
    Task* next;

public:
    Task(int id, std::string description);

    int get_id() const;
    std::string get_description() const;
    Progress get_progress() const;
    Task* get_next() const;

    void set_description(const std::string& newDescription);
    void set_progress(const Progress newStatus);
    void set_next(Task* nextTask);

    friend std::ostream& operator<<(std::ostream& os, const Task::Progress& progress);
};

#endif