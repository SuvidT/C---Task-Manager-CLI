# Command Line Input Task Manager

## Todo

### Commands
- [x] add {description}
- [x] update {id} {description}
- [x] delete {id}
- [x] mark
    - [x] todo {id}
    - [x] in-progress {id}
    - [x] done {id}
- [x] list
    - [x] all
    - [x] todo
    - [x] in-progress
    - [x] done

### Classes:
- [x] task: this is a node of data
- [x] tasks: this handles all the tasks
- [x] main: this handles all the commands

Task Properties:
- id
- description
- status
- createdAt
- updatedAt

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
TaskManager list done

# Listing tasks by status
TaskManager list done
TaskManager list todo
TaskManager list in-progress
```