# Command Line Input Task Manager

## Todo
- [ ] add
- [ ] update
- [ ] delete
- [ ] list
    - [ ] todo
    - [ ] in-progress
    - [ ] done
- [ ] mark
    - [ ] todo
    - [ ] in-progress
    - [ ] delete


## Implementation
```
# Adding a new task
TaskManager add "Buy groceries"
# Output: Task added successfully (ID: 1)

# Updating and deleting tasks
TaskManager update 1 "Buy groceries"
TaskManager delete 1

# Marking a task as in progress or done

TaskManager mark in-progress 1
TaskManager mark done 1

# Listing all tasks
TaskManager list

# Listing tasks by status
TaskManager list done
TaskManager list todo
TaskManager list in-progress
```