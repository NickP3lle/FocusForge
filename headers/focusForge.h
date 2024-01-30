#pragma once

#include "task.h"

#define PRIORITY_COUNT 5

class FocusForge {
  private:
    class PriorityNode {
      public:
        class TaskNode {
          public:
            Task *task;
            TaskNode *next;
            TaskNode *prev;
            TaskNode(Task *task, TaskNode *next = nullptr, TaskNode *prev = nullptr);
        };

        short int priority;
        TaskNode *head;
        TaskNode *tail;

        PriorityNode(short int priority);
        ~PriorityNode();

        void addNode(TaskNode *t);
    };

    PriorityNode priorityType[PRIORITY_COUNT];

  public:
    FocusForge();
    FocusForge(const FocusForge &other) = delete;
    FocusForge &operator=(const FocusForge &other) = delete;

    void addTask(Task *t);
    PriorityNode::TaskNode *removeNode(Task *t);
    bool completeTask(Task *t);
    bool uncompleteTask(Task *t);

    // operator<< overload
    friend std::ostream &operator<<(std::ostream &out, const PriorityNode &priorityNode);
    friend std::ostream &operator<<(std::ostream &out, const FocusForge &focusForge);
};

std::ostream &operator<<(std::ostream &out, const FocusForge::PriorityNode &priorityNode);

std::ostream &operator<<(std::ostream &out, const FocusForge &focusForge);