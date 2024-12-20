#ifndef NOTIFICATIONSYSTEM_H
#define NOTIFICATIONSYSTEM_H

#include <iostream>
#include <string>

class Observer {
public:
    virtual void update(const std::string& message) = 0;
};

class NotificationSystem : public Observer {
public:
    void update(const std::string& message) override;
};

#endif
