#include <iostream>
#include <string>

#include "headers/focusForge.h"
#include "headers/task.h"

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

    FocusForge focusForge;

    focusForge.addTask(task1);
    focusForge.addTask(task2);
    focusForge.addTask(task3);
    focusForge.addTask(task4);
    focusForge.addTask(task5);
    focusForge.addTask(task6);
    focusForge.addTask(task7);
    focusForge.addTask(task8);
    focusForge.addTask(task9);
    focusForge.addTask(task10);

    std::cout << focusForge << std::endl;

    return 0;
}