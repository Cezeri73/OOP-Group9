#ifndef NOTIFICATIONSYSTEM_H
#define NOTIFICATIONSYSTEM_H

#include <vector>
#include <algorithm>
#include <iostream>
#include "INotifiable.h"

class NotificationSystem {
private:
    std::vector<INotifiable*> subscribers;

public:
    void subscribe(INotifiable* subscriber) { subscribers.push_back(subscriber); }
    void notify(const std::string& message) {
        for (auto subscriber : subscribers) {
            subscriber->sendNotification(message);
        }
    }
};

#endif // NOTIFICATIONSYSTEM_H

