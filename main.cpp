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

    int get_id() const {
        return this->id;
    }

    string get_description() const {
        return this->description;
    };

    Progress get_progress() const {
        return this->status;
    };
    Task* get_next() const {
        return this->next; 
    };

    void set_description(const string& newDescription) {
        this->description = newDescription;
    };

    void set_progress(const Progress newStatus) {
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
    int len;

public:
    Tasks() {
        this->head = nullptr;
        this->len = 0;
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
        len += 1;
        Task* newTask = new Task(len, description);

        newTask->set_next(head);
        head = newTask;
        
        return head->get_id();
    };

    void update_task(int id, const string& newDescrioption) {
        if (head == nullptr) {
            throw invalid_argument("There are not tasks to be updated");
        }
        
        Task* current = head;

        while (current != nullptr) {
            if (current->get_id() == id) {
                current->set_description(newDescrioption);
                return ;
            }
            Task* next = current->get_next();
        }
        
        throw invalid_argument("There is not task with id: " + to_string(id));
    };

    void delete_task(int id);

    void change_progress(int id, Task::Progress newStatus);

    void list_tasks(Task::Progress status);
};

// -------------------------

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