#pragma once
#include "ToDoList.h" 
#include <msclr/marshal_cppstd.h> // For string conversion
#include "About.h"

namespace ToDoListApp 
{

    using namespace System;
    using namespace System::Windows::Forms;

    public ref class MyForm : public Form
    {
    public:
        MyForm(void)
        {
            InitializeComponent();
            todoList = new ToDoList(); // Initialize the ToDoList instance
        }

    protected:
        ~MyForm()
        {
            if (components)
            {
                delete components;
            }
            delete todoList; // Clean up the ToDoList instance
        }

    private:
        ToDoList* todoList; // Pointer to the ToDoList instance


        // UI components

    private: System::Windows::Forms::NumericUpDown^ Priority_Bar;


    private: System::Windows::Forms::ListBox^ List_Of_Tasks;


        System::Windows::Forms::Button^ btnAdd;
        System::Windows::Forms::Button^ btnDelete;
        System::Windows::Forms::Button^ btnRetrieve;
        System::Windows::Forms::Button^ btnSetPriority;
    private: System::Windows::Forms::TextBox^ Task_Description;
    private: System::Windows::Forms::Button^ button1;
    private: System::Windows::Forms::Button^ button2;
           System::ComponentModel::Container^ components;

        void InitializeComponent(void)
        {
            this->Task_Description = (gcnew System::Windows::Forms::TextBox());
            this->Priority_Bar = (gcnew System::Windows::Forms::NumericUpDown());
            this->List_Of_Tasks = (gcnew System::Windows::Forms::ListBox());
            this->btnAdd = (gcnew System::Windows::Forms::Button());
            this->btnDelete = (gcnew System::Windows::Forms::Button());
            this->btnRetrieve = (gcnew System::Windows::Forms::Button());
            this->btnSetPriority = (gcnew System::Windows::Forms::Button());
            this->button1 = (gcnew System::Windows::Forms::Button());
            this->button2 = (gcnew System::Windows::Forms::Button());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Priority_Bar))->BeginInit();
            this->SuspendLayout();
            // 
            // Task_Description
            // 
            this->Task_Description->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->Task_Description->Location = System::Drawing::Point(12, 21);
            this->Task_Description->Name = L"Task_Description";
            this->Task_Description->Size = System::Drawing::Size(276, 28);
            this->Task_Description->TabIndex = 0;
            this->Task_Description->Text = L"Task Goes Here";
            // 
            // Priority_Bar
            // 
            this->Priority_Bar->Location = System::Drawing::Point(12, 64);
            this->Priority_Bar->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 0 });
            this->Priority_Bar->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
            this->Priority_Bar->Name = L"Priority_Bar";
            this->Priority_Bar->Size = System::Drawing::Size(135, 22);
            this->Priority_Bar->TabIndex = 1;
            this->Priority_Bar->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
            // 
            // List_Of_Tasks
            // 
            this->List_Of_Tasks->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->List_Of_Tasks->ItemHeight = 22;
            this->List_Of_Tasks->Location = System::Drawing::Point(320, 38);
            this->List_Of_Tasks->Name = L"List_Of_Tasks";
            this->List_Of_Tasks->Size = System::Drawing::Size(200, 180);
            this->List_Of_Tasks->TabIndex = 2;
            // 
            // btnAdd
            // 
            this->btnAdd->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->btnAdd->Location = System::Drawing::Point(12, 92);
            this->btnAdd->Name = L"btnAdd";
            this->btnAdd->Size = System::Drawing::Size(120, 46);
            this->btnAdd->TabIndex = 2;
            this->btnAdd->Text = L"Add Task";
            this->btnAdd->Click += gcnew System::EventHandler(this, &MyForm::btnAdd_Click);
            // 
            // btnDelete
            // 
            this->btnDelete->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->btnDelete->Location = System::Drawing::Point(186, 92);
            this->btnDelete->Name = L"btnDelete";
            this->btnDelete->Size = System::Drawing::Size(120, 46);
            this->btnDelete->TabIndex = 3;
            this->btnDelete->Text = L"Delete Task";
            this->btnDelete->Click += gcnew System::EventHandler(this, &MyForm::btnDelete_Click);
            // 
            // btnRetrieve
            // 
            this->btnRetrieve->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->btnRetrieve->Location = System::Drawing::Point(12, 170);
            this->btnRetrieve->Name = L"btnRetrieve";
            this->btnRetrieve->Size = System::Drawing::Size(120, 46);
            this->btnRetrieve->TabIndex = 4;
            this->btnRetrieve->Text = L"Retrieve Tasks";
            this->btnRetrieve->Click += gcnew System::EventHandler(this, &MyForm::btnRetrieve_Click);
            // 
            // btnSetPriority
            // 
            this->btnSetPriority->BackColor = System::Drawing::SystemColors::ControlLight;
            this->btnSetPriority->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->btnSetPriority->Location = System::Drawing::Point(186, 170);
            this->btnSetPriority->Name = L"btnSetPriority";
            this->btnSetPriority->Size = System::Drawing::Size(120, 46);
            this->btnSetPriority->TabIndex = 5;
            this->btnSetPriority->Text = L"Set Priority";
            this->btnSetPriority->UseVisualStyleBackColor = false;
            this->btnSetPriority->Click += gcnew System::EventHandler(this, &MyForm::btnSetPriority_Click);
            // 
            // button1
            // 
            this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->button1->Location = System::Drawing::Point(430, 222);
            this->button1->Name = L"button1";
            this->button1->Size = System::Drawing::Size(90, 48);
            this->button1->TabIndex = 6;
            this->button1->Text = L"Exit";
            this->button1->UseVisualStyleBackColor = true;
            this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
            // 
            // button2
            // 
            this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->button2->Location = System::Drawing::Point(12, 231);
            this->button2->Name = L"button2";
            this->button2->Size = System::Drawing::Size(90, 31);
            this->button2->TabIndex = 7;
            this->button2->Text = L"About";
            this->button2->UseVisualStyleBackColor = true;
            this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
            // 
            // MyForm
            // 
            this->BackColor = System::Drawing::SystemColors::Control;
            this->ClientSize = System::Drawing::Size(532, 274);
            this->Controls->Add(this->button2);
            this->Controls->Add(this->button1);
            this->Controls->Add(this->Task_Description);
            this->Controls->Add(this->Priority_Bar);
            this->Controls->Add(this->btnAdd);
            this->Controls->Add(this->btnDelete);
            this->Controls->Add(this->btnRetrieve);
            this->Controls->Add(this->btnSetPriority);
            this->Controls->Add(this->List_Of_Tasks);
            this->Name = L"MyForm";
            this->Text = L"To-Do List";
            this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Priority_Bar))->EndInit();
            this->ResumeLayout(false);
            this->PerformLayout();

        }

        // Event handlers
        void btnAdd_Click(System::Object^ sender, System::EventArgs^ e);
        void btnDelete_Click(System::Object^ sender, System::EventArgs^ e);
        void btnRetrieve_Click(System::Object^ sender, System::EventArgs^ e);
        void btnSetPriority_Click(System::Object^ sender, System::EventArgs^ e);
        void MyForm_Load(System::Object^ sender, System::EventArgs^ e);
        void button1_Click(System::Object^ sender, System::EventArgs^ e);
        void button2_Click(System::Object^ sender, System::EventArgs^ e);
};
}