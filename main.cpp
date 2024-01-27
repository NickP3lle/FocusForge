#include <iostream>
#include <string>

#include "task.h"
#include "toDo.h"

int main() {
    Task *task1 = new Task("Task 1", "This is task 1", true, true);
    Task *task2 = new Task("Task 2", "This is task 2", false, true);
    Task *task3 = new Task("Task 3", "This is task 3", true, false);
    Task *task4 = new Task("Task 4", "This is task 4", false, false);
    Task *task5 = new Task("Task 5", "This is task 5", true, true);
    Task *task6 = new Task("Task 6", "This is task 6", false, true);
    Task *task7 = new Task("Task 7", "This is task 7", true, false);
    Task *task8 = new Task("Task 8", "This is task 8", false, false);
    Task *task9 = new Task("Task 9", "This is task 9", true, true);
    Task *task10 = new Task("Task 10", "This is task 10", false, true);

    ToDo toDo;

    toDo.addTask(task1);
    toDo.addTask(task2);
    toDo.addTask(task3);
    toDo.addTask(task4);
    toDo.addTask(task5);
    toDo.addTask(task6);
    toDo.addTask(task7);
    toDo.addTask(task8);
    toDo.addTask(task9);
    toDo.addTask(task10);

    std::cout << toDo << std::endl;

    return 0;
}