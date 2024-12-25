#ifndef USER_H
#define USER_H

#include "INotifiable.h"
#include <iostream>

class User : public INotifiable {
private:
    std::string name;

public:
    User(const std::string& userName) : name(userName) {}
    void sendNotification(const std::string& message) override {
        std::cout << "Notification for " << name << ": " << message << std::endl;
    }
};

#endif // USER_H

