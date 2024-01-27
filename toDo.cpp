#include "toDo.h"

ToDo::PriorityNode::TaskNode::TaskNode(Task *task, TaskNode *next, TaskNode *prev) : task(task), next(next), prev(prev) {}

ToDo::PriorityNode::PriorityNode(short int priority, PriorityNode *next, PriorityNode *prev)
    : priority(priority), head(nullptr), tail(nullptr), next(next), prev(prev) {}

ToDo::PriorityNode::~PriorityNode() {
    TaskNode *curr = head;
    TaskNode *next = nullptr;
    while (curr != nullptr) {
        next = curr->next;
        delete curr;
        curr = next;
    }
}

ToDo::ToDo() {
    PriorityNode *curr = nullptr;
    PriorityNode *node = new PriorityNode(-1);
    tail = node;
    for (int i = 0; i < PRIORITY_COUNT; i++) {
        curr = node;
        node = new PriorityNode(i, curr);
        curr->prev = node;
    }
    head = node;
}

ToDo::~ToDo() {
    PriorityNode *curr = head;
    PriorityNode *next = nullptr;
    while (curr != nullptr) {
        next = curr->next;
        delete curr;
        curr = next;
    }
}

void ToDo::addTask(Task *t) {
    PriorityNode *curr = head;
    while (curr != nullptr && curr->priority != t->getPriority()) {
        curr = curr->next;
    }
    if (curr == nullptr) {
        return;
    }
    PriorityNode::TaskNode *node = new PriorityNode::TaskNode(t, nullptr, curr->tail);
    if (curr->head == nullptr) {
        curr->head = node;
    } else {
        curr->tail->next = node;
    }
    curr->tail = node;
}

ToDo::PriorityNode::TaskNode *ToDo::getNode(Task *t) const {
    PriorityNode *curr = head;
    while (curr != nullptr && curr->priority != t->getPriority()) {
        curr = curr->next;
    }
    if (curr == nullptr) {
        return nullptr;
    }
    PriorityNode::TaskNode *node = curr->head;
    while (node != nullptr && node->task && *(node->task) != *t) {
        node = node->next;
    }
    return node;
}

void ToDo::completeTask(Task *t) const { t->complete(); }

std::ostream &operator<<(std::ostream &out, const ToDo &toDo) {
    ToDo::PriorityNode *curr = toDo.head;
    for (int i = PRIORITY_COUNT - 1; i >= -1; i--) {
        out << "\033[1;" << 34 << "m"
            << "Priority " << i << ":"
            << "\033[0m" << std::endl
            << std::endl;
        ToDo::PriorityNode::TaskNode *node = curr->head;
        while (node != nullptr) {
            out << *(node->task) << std::endl;
            node = node->next;
        }
        curr = curr->next;
        out << std::endl;
    }
    return out;
}