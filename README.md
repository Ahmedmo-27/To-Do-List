# To-Do List Application

This project is a simple **To-Do List Application** developed in **C++** using **WinForms GUI** and a **Binary Search Tree (BST)** data structure. The application allows users to manage their tasks with the ability to add, delete, and set priorities for tasks. The tasks are stored and organized based on priority, making it easy to retrieve and display them in sorted order.

## Features

- **Task Management**: Add, delete, and update tasks.
- **Priority Management**: Assign priorities (1 to 5) to tasks. You can set or change the priority of existing tasks.
- **Task Retrieval**: Retrieve tasks based on their priority and description.
- **Sorted Display**: Display all tasks in ascending order of their priority.
- **Search**: Efficiently search for tasks based on description and priority using a Binary Search Tree.

## Technologies Used

- **C++**: The core programming language used for the implementation.
- **WinForms**: Used for creating the graphical user interface (GUI).
- **Binary Search Tree (BST)**: Used to store tasks and efficiently manage priority-based sorting.
- **Dynamic Memory Management**: Utilized for dynamically resizing arrays of tasks during retrieval.

## Installation

### Prerequisites

- **Microsoft Visual Studio** with **C++/CLI** and **.NET Framework** support.
- **Windows OS**: Since this is a WinForms-based application, it is designed for Windows.

### Steps to Run the Application

1. Clone or download the repository:
   ```bash
   git clone https://github.com/Ahmedmo-27/todolist-app.git
   ```

2. Open the solution file (`.sln`) in **Microsoft Visual Studio**.

3. Build the solution and run the project.

4. The application will open, and you can interact with the to-do list via the graphical interface.

## Usage

1. **Add Task**: Enter the task description and assign a priority between 1 and 5.
2. **Delete Task**: Select a task to delete by its description and priority.
3. **Set Task Priority**: Change the priority of a task.
4. **Display Tasks**: View all tasks sorted by priority.

## Example

- **Adding a Task**:
  - Enter a task description, e.g., "Buy groceries", and assign a priority, e.g., 3.
  
- **Displaying Tasks**:
  - The tasks are displayed in ascending order of priority.

## Code Structure

- **`ToDoList.h`**: Contains the definition of the `Task`, `Node`, and `ToDoList` classes. The `ToDoList` class implements the task management functionalities, including adding, deleting, searching, and sorting tasks using a binary search tree.
- **`About.h`**: Contains the `WinForms` implementation for the GUI that provides a simple interface to display information about the application.

## Contributing

If you'd like to contribute to this project, feel free to fork the repository, create a feature branch, and submit a pull request. Please ensure that any changes are well-documented and thoroughly tested.
