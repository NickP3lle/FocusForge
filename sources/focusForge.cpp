#include "../headers/focusForge.h"

FocusForge::PriorityNode::TaskNode::TaskNode(Task *task, TaskNode *next, TaskNode *prev)
    : task(task), next(next), prev(prev) {}

FocusForge::PriorityNode::PriorityNode(short int priority) : priority(priority) {}

FocusForge::PriorityNode::~PriorityNode() {
    TaskNode *curr = head;
    TaskNode *next = nullptr;

    while (curr != nullptr) {
        next = curr->next;
        delete curr;
        curr = next;
    }
}

void FocusForge::PriorityNode::addNode(TaskNode *t) {
    if (head == nullptr) {
        head = t;
        tail = t;
    } else {
        tail->next = t;
        t->prev = tail;
        tail = t;
    }
}

FocusForge::FocusForge()
    : priorityType{PriorityNode(0), PriorityNode(1), PriorityNode(2), PriorityNode(3), PriorityNode(-1)} {}

void FocusForge::addTask(Task *t) {
    PriorityNode::TaskNode *node = new PriorityNode::TaskNode(t);
    short int priority = t->getPriority();

    priorityType[priority == -1 ? 4 : priority].addNode(node);
}

FocusForge::PriorityNode::TaskNode *FocusForge::removeNode(Task *t) {
    short int priority = t->getPriority();
    PriorityNode::TaskNode *curr = priorityType[priority == -1 ? 4 : priority].head;
    PriorityNode::TaskNode *prev = nullptr;

    while (curr != nullptr) {
        if (*(curr->task) == *t) {
            if (prev == nullptr) {
                priorityType[priority == -1 ? 4 : priority].head = curr->next;
            } else {
                prev->next = curr->next;
            }

            if (curr->next == nullptr) {
                priorityType[priority == -1 ? 4 : priority].tail = prev;
            } else {
                curr->next->prev = prev;
            }

            curr->next = nullptr;
            curr->prev = nullptr;

            return curr;
        }

        prev = curr;
        curr = curr->next;
    }

    return nullptr;
}

bool FocusForge::completeTask(Task *t) {
    if (t->getPriority() == -1) {
        return false;
    }

    PriorityNode::TaskNode *node = removeNode(t);

    if (node == nullptr) {
        return false;
    }

    t->complete();

    priorityType[4].addNode(node);

    return true;
}

bool FocusForge::uncompleteTask(Task *t) {
    if (t->getPriority() != -1) {
        return false;
    }

    PriorityNode::TaskNode *node = removeNode(t);

    if (node == nullptr) {
        return false;
    }

    t->uncomplete();

    priorityType[t->getPriority()].addNode(node);

    return true;
}

std::ostream &operator<<(std::ostream &out, const FocusForge::PriorityNode &priorityNode) {
    out << "\033[1;" << 34 << "m"
        << "Priority " << priorityNode.priority << ":"
        << "\033[0m" << std::endl
        << std::endl;

    FocusForge::PriorityNode::TaskNode *node = priorityNode.head;

    while (node != nullptr) {
        out << *(node->task) << std::endl;
        node = node->next;
    }

    out << std::endl;

    return out;
}

std::ostream &operator<<(std::ostream &out, const FocusForge &focusForge) {
    for (int i = 0; i < PRIORITY_COUNT; i++) {
        out << focusForge.priorityType[i];
    }
    return out;
}