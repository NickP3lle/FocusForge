#pragma once

#include "task.h"

#define PRIORITY_COUNT 4

class ToDo {
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

        PriorityNode *next;
        PriorityNode *prev;
        PriorityNode(short int priority, PriorityNode *next = nullptr, PriorityNode *prev = nullptr);
        ~PriorityNode();
    };

    PriorityNode *head;
    PriorityNode *tail;

  public:
    ToDo();
    ~ToDo();
    ToDo(const ToDo &other) = delete;
    ToDo &operator=(const ToDo &other) = delete;

    void addTask(Task *t);
    PriorityNode::TaskNode *getNode(Task *t) const;
    // Task *getTask(std::string name) const;
    void *removeNode(PriorityNode::TaskNode *t);
    void addNode(PriorityNode::TaskNode *t);
    void completeTask(Task *t) const;

    // operator<< overload
    friend std::ostream &operator<<(std::ostream &out, const ToDo &toDo);
};

std::ostream &operator<<(std::ostream &out, const ToDo &toDo);