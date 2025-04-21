#include <iostream>
#include <string>

using namespace std;

// -------------------------

class Task {
public:
    enum class Progress {
        Todo,
        InProgress,
        Done
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

    ~Task();

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
};

// -------------------------

int main() {

}