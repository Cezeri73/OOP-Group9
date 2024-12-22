#ifndef INOTIFIABLE_H
#define INOTIFIABLE_H

#include <string>

class INotifiable {
public:
    virtual ~INotifiable() = default;
    virtual void sendNotification(const std::string& message) = 0;
};

#endif // INOTIFIABLE_H

