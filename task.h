#pragma once

#include <iostream>
#include <string>

class Task {
  private:
    std::string name;
    std::string description;
    bool urgent;
    bool important;
    bool completed;

    void setPriority(short int priority);

  public:
    Task(std::string name, std::string description = "", bool urgent = false, bool important = false);
    std::string getName() const;
    std::string getDescription() const;
    short int getPriority() const;
    void setName(std::string name);
    void setDescription(std::string description);
    void complete();
    void uncomplete();
    bool operator==(const Task &other) const;
    bool operator!=(const Task &other) const;

    friend std::ostream &operator<<(std::ostream &out, const Task &task);
};

std::ostream &operator<<(std::ostream &out, const Task &task);