#include "MyForm.h"
#include "About.h"
#include <string>

using namespace ToDoListApp;
using namespace std;

void MyForm::btnAdd_Click(System::Object^ sender, System::EventArgs^ e)
{
	// Get the task description and priority
    String^ description = Task_Description->Text;
    int priority = (int)Priority_Bar->Value;

    // Check for empty description
    if (String::IsNullOrEmpty(description))
    {
        MessageBox::Show("Please enter a task description.");
        return;
    }

    // Convert to string
    msclr::interop::marshal_context context;
    string desc = context.marshal_as<string>(description);
	
    // Check if the description contains only letters and spaces
    for (char c : desc)
    {
        if (!isalpha(c) && c != ' ')
        {
            MessageBox::Show("Task description must contain only letters and spaces.");
            return;
        }
    }

    // Check if the task already exists
    int size;
    string* tasks = todoList->retrieveAllTasks(size);
    bool taskExists = false;

	// Iterate through tasks to check if the task already exists
    for (int i = 0; i < size; ++i)
    {
        size_t separatorPos = tasks[i].find("  ");
        if (separatorPos != string::npos)
        {
            string taskDescription = tasks[i].substr(separatorPos + 2);
            if (taskDescription == desc)
            {
                taskExists = true;
                break;
            }
        }
    }

    delete[] tasks; // Free the dynamic array

    if (taskExists)
    {
        MessageBox::Show("Task already exists!");
    }
    else
    {
        try
        {
            todoList->addTask(desc, priority);
            MessageBox::Show("Task added successfully!");
        }
        catch (const exception& ex)
        {
            MessageBox::Show("Error adding task: " + gcnew String(ex.what()));
        }
    }
}

void MyForm::btnDelete_Click(System::Object^ sender, System::EventArgs^ e)
{
	// Get the task description and priority
    String^ description = Task_Description->Text;
    int priority = (int)Priority_Bar->Value;

    // Check for empty description
    if (String::IsNullOrEmpty(description))
    {
        MessageBox::Show("Please enter a task description.");
        return;
    }

    // Convert description to std::string
    msclr::interop::marshal_context context;
    string desc = context.marshal_as<string>(description);

    // Retrieve all tasks
    int size;
    string* tasks = todoList->retrieveAllTasks(size);
    bool taskExists = false;
    bool priorityMatch = false;

    // Iterate through tasks to check if the task exists and matches the priority
    for (int i = 0; i < size; ++i)
    {
        size_t separatorPos = tasks[i].find("  ");
        if (separatorPos != string::npos)
        {
            string taskPriorityStr = tasks[i].substr(10, separatorPos - 10); // Extract the priority as a string
            string taskDescription = tasks[i].substr(separatorPos + 2);     // Extract the task description
            int taskPriority = stoi(taskPriorityStr);                       // Convert priority to integer

            if (taskDescription == desc)
            {
                taskExists = true; // Task exists
                if (taskPriority == priority)
                {
                    priorityMatch = true; // Priority matches
                    break;
                }
            }
        }
    }

    delete[] tasks; // Free the dynamic array

    // Handle task existence and priority match conditions
    if (taskExists==false)
    {
        MessageBox::Show("Task does not exist.");
        return;
    }

    if (priorityMatch == false)
    {
        MessageBox::Show("The priority entered does not match the task.");
        return;
    }

    // Attempt to delete the task
    try
    {
        todoList->deleteTask(desc, priority);
        MessageBox::Show("Task deleted successfully.");
    }
    catch (const runtime_error& ex)
    {
        MessageBox::Show("Error deleting task: " + gcnew String(ex.what()));
    }
}

void MyForm::btnRetrieve_Click(System::Object^ sender, System::EventArgs^ e)
{
    List_Of_Tasks->Items->Clear();
    int size;
    string* tasks = todoList->retrieveAllTasks(size);

    for (int i = 0; i < size; ++i)
    {
        List_Of_Tasks->Items->Add(gcnew String(tasks[i].c_str()));
    }

    delete[] tasks; // Free the dynamic array
}

void MyForm::btnSetPriority_Click(System::Object^ sender, System::EventArgs^ e)
{
    String^ description = Task_Description->Text;
    int newPriority = (int)Priority_Bar->Value;

    // Check if the new priority is within the valid range
    if (newPriority < 1 || newPriority > 5)
    {
        MessageBox::Show("Priority must be between 1 and 5.");
        return;
    }

    // Check for empty description
    if (String::IsNullOrEmpty(description))
    {
        MessageBox::Show("Please enter a task description.");
        return;
    }

    // Convert to string
    msclr::interop::marshal_context context;
    string desc = context.marshal_as<string>(description);

    try
    {
        // Attempt to set the priority
        todoList->setPriority(desc, newPriority);
        MessageBox::Show("Priority updated successfully!");
    }
    catch (const runtime_error& ex)
    {
        MessageBox::Show("Error updating priority: " + gcnew String(ex.what()));
    }
}

void MyForm::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	// Display a confirmation dialog before exiting
    if (MessageBox::Show("Are You Sure You Want To Exit The Application", "Message", MessageBoxButtons::YesNo, MessageBoxIcon::Warning)
        == System::Windows::Forms::DialogResult::Yes)
    {
        Application::Exit();
    }
    else
    {
        return;
    }
}

void MyForm::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
	// Display the About form
    About::MyForm1^ aboutForm = gcnew About::MyForm1();
    aboutForm->Show();
}

void MyForm::MyForm_Load(System::Object^ sender, System::EventArgs^ e)
{
	todoList = new ToDoList(); // Initialize the ToDoList instance
}

// Main function
[STAThreadAttribute]
int main(cli::array<System::String^>^ args)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Application::Run(gcnew MyForm());
    return 0;
}