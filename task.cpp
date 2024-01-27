#include "task.h"

Task::Task(std::string name, std::string description, bool urgent, bool important)
    : name(name), description(description), urgent(urgent), important(important), completed(false) {}

// Get the name of the task
std::string Task::getName() const { return name; }

// Get the description of the task
std::string Task::getDescription() const { return description; }

// Get the priority of the task
// -1 = completed
// 0 = not urgent or important
// 1 = important but not urgent
// 2 = urgent but not important
// 3 = urgent and important
short int Task::getPriority() const { return completed ? -1 : ((urgent ? 2 : 0) + (important ? 1 : 0)); }

// Set the name of the task
void Task::setName(std::string name) { this->name = name; }

// Set the description of the task
void Task::setDescription(std::string description) { this->description = description; }

// Set the priority of the task
// 0 = not urgent or important
// 1 = important but not urgent
// 2 = urgent but not important
// 3 = urgent and important
void Task::setPriority(short int priority) {
    urgent = priority >= 2;
    important = priority % 2 == 1;
}

// Mark the task as completed
void Task::complete() { completed = true; }

// Mark the task as not completed
void Task::uncomplete() { completed = false; }

// Compare two tasks
bool Task::operator==(const Task &other) const { return name == other.name && description == other.description; }

// Compare two tasks
bool Task::operator!=(const Task &other) const { return !(*this == other); }

// operator<< overload
std::ostream &operator<<(std::ostream &out, const Task &task) {
    out << "Name: " << task.name << std::endl;
    out << "Description: " << task.description << std::endl;
    out << "Priority: " << task.getPriority() << std::endl;
    out << "Completed: " << (task.completed ? "Yes" : "No") << std::endl;
    return out;
}