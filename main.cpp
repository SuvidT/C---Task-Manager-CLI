#include <iostream>
#include <string>

using namespace std;

// -------------------------

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
    string description;
    Progress status;
    // todo: created time
    // todo: updated time
    Task* next;

public:
    Task(int id, string description) {
        this->id = id;
        this->description = description;
        this->status = Progress::Todo;
        this->next = nullptr;
    }

    ~Task() {
        delete next;
    };

    string get_description() const {
        return this->description;
    };

    Progress get_progress() const {
        return this->status;
    };
    Task* get_next() const {
        return this->next; 
    };

    void change_description(const string& newDescription) {
        this->description = newDescription;
    };

    void change_progress(const Progress newStatus) {
        this->status = newStatus;
    };

    void set_next(Task* nextTask) {
        this->next = nextTask;
    };
};

// -------------------------

class Tasks {
private:
    Task* head;

public:
    Tasks() {
        this->head = nullptr;
    };

    // not sure how this works exactly, or why there aren't other ways of doing this, will have to ask later
    ~Tasks() {
        Task* current = head;

        while (current != nullptr) {
            Task* next = current->get_next();
            delete current;
            current = next;
        }
    };

    int add_task(const string& description) {
        return 0;
    };

    void update_task(int id, const string& newDescrioption);

    void delete_task(int id);

    void change_progress(int id, Task::Progress newStatus);

    void list_tasks(Task::Progress status);
};

// -------------------------

int main() {

}