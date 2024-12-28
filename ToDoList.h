#pragma once
#ifndef TODOLIST_H
#define TODOLIST_H

#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

class Task
{
public:
    string description;
    int priority;

    Task(string data = "", int pri = 1)
    {
        description = data;
        priority = pri;
    }
};

class Node
{
public:
    Task task;
    Node* left;
    Node* right;

    Node(Task t)
    {
        task = t;
        left = right = nullptr;
    }
};

class ToDoList
{
private:
    Node* root;

    Node* insert(Node* node, Task task)
    {
        if (node == nullptr)
        {
            return new Node(task);
        }

        if (task.priority > node->task.priority)
        {
            node->left = insert(node->left, task);
        }
        else
        {
            node->right = insert(node->right, task);
        }
        return node;
    }

    void inOrderTraversal(Node* node, string*& tasks, int& size, int& capacity)
    {
        if (node == nullptr)
            return;

        inOrderTraversal(node->left, tasks, size, capacity);

        // Resize the array if needed
        if (size >= capacity)
        {
            capacity *= 2; // Double the capacity
            string* newTasks = new string[capacity];
            for (int i = 0; i < size; ++i)
            {
                newTasks[i] = tasks[i];
            }
            delete[] tasks; // Free old array
            tasks = newTasks; // Point to new array
        }

        // Add the current task to the tasks array
        tasks[size++] = "Priority: " + to_string(node->task.priority) + "  " + node->task.description;

        inOrderTraversal(node->right, tasks, size, capacity);
    }

    Node* deleteTask(Node* node, string data, int priority)
    {
        if (node == nullptr)
            return node;

        // Only delete if both description and priority match
        if (data < node->task.description || (data == node->task.description && priority < node->task.priority))
        {
            node->left = deleteTask(node->left, data, priority);
        }
        else if (data > node->task.description || (data == node->task.description && priority > node->task.priority))
        {
            node->right = deleteTask(node->right, data, priority);
        }
        else // Found the node to delete
        {
            if (node->left == nullptr)
            {
                Node* temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == nullptr)
            {
                Node* temp = node->left;
                delete node;
                return temp;
            }

            Node* temp = findMin(node->right);
            node->task = temp->task;
            node->right = deleteTask(node->right, temp->task.description, temp->task.priority);
        }
        return node;
    }

    Node* findMin(Node* node)
    {
        while (node->left != nullptr)
            node = node->left;
        return node;
    }

    void clear(Node* node)
    {
        if (node == nullptr)
            return;
        clear(node->left);
        clear(node->right);
        delete node;
    }

    Node* search(Node* node, string data, int priority)
    {
        if (node == nullptr || (node->task.description == data && node->task.priority == priority))
            return node;

        if (data < node->task.description || (data == node->task.description && priority < node->task.priority))
            return search(node->left, data, priority);

        return search(node->right, data, priority);
    }

public:

    ToDoList() { root = nullptr; }

    ~ToDoList() { clear(root); }

    void addTask(string data, int priority)
    {
        try {
            if (priority < 1 || priority > 5 )
            {
                throw invalid_argument("Invalid priority! Must be between 1 and 5.");
            }

            Task newTask(data, priority);
            root = insert(root, newTask);
        } catch (const invalid_argument& e) {
            cout << "Error adding task: " << e.what() << endl;
        }
    }

    void deleteTask(string data, int priority)
    {
        try {
            root = deleteTask(root, data, priority);
        } catch (const exception& e) {
            cout << "Error deleting task: " << e.what() << endl;
        }
    }

    bool isFound(string data, int priority)
    {
        try {
            return search(root, data, priority) != nullptr;
        } catch (const exception& e) {
            cout << "Error searching for task: " << e.what() << endl;
            return false;
        }
    }

    string* retrieveAllTasks(int& size)
    {
        try {
            int capacity = 10; // Initial capacity
            size = 0;
            string* tasks = new string[capacity];
            inOrderTraversal(root, tasks, size, capacity);

            // Resize to fit the actual number of tasks
            string* finalTasks = new string[size];
            for (int i = 0; i < size; ++i)
            {
                finalTasks[i] = tasks[i];
            }
            delete[] tasks; // Free the dynamic array
            return finalTasks; // Return the resized array
        } catch (const exception& e) {
            cout << "Error retrieving tasks: " << e.what() << endl;
            return nullptr;
        }
    }

    string retrieveTask(string data, int priority)
    {
        try {
            Node* node = search(root, data, priority);
            if (node)
            {
                return "Priority: " + to_string(node->task.priority) + "  " + node->task.description;
            }
            else
            {
                throw runtime_error("Task not found!");
            }
        } catch (const runtime_error& e) {
            cout << "Error retrieving task: " << e.what() << endl;
            return "";
        }
    }

    void setPriority(string data, int newPriority)
    {
        try {
            if (newPriority < 1 || newPriority > 5)
            {
                throw invalid_argument("Invalid priority! Must be between 1 and 5.");
            }

            // Search for the task with the current priority
            Node* node = nullptr;
            for (int priority = 1; priority <= 5; priority++)
            {
                node = search(root, data, priority);
                if (node != nullptr)
                {
                    break; // Found the task
                }
            }

            if (node == nullptr)
            {
                throw runtime_error("Task not found!");
            }

            // Delete the task with its current priority
            deleteTask(data, node->task.priority);

            // Add a new task with the same description but the new priority
            addTask(data, newPriority);
        } catch (const exception& e) {
            cout << "Error setting priority: " << e.what() << endl;
        }
    }

    void displaySortedByPriority()
    {
        try {
            int size;
            string* tasks = retrieveAllTasks(size);
            for (int i = 0; i < size; ++i)
            {
                cout << tasks[i] << endl;
            }
            delete[] tasks; // Free the dynamic array
        } catch (const exception& e) {
            cout << "Error displaying tasks: " << e.what() << endl;
        }
    }
};

#endif // TODOLIST_H