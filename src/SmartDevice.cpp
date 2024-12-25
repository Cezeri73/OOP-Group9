#include "SmartDevice.h"
#include "Light.h"

Fl_Text_Buffer *SmartDevice::notificationBuffer = new Fl_Text_Buffer();
void SmartDevice::addNotification(const std::string &message)
{
	notificationBuffer->append((message + "\n").c_str());
}
const char *SmartDevice::getName()
{
	return name.c_str();
}
json SmartDevice::toJson() const
{
	return json{{"type", type}};
}
SmartDevice *SmartDevice::fromJson(const json &j)
{
	std::string type = j.at("type").get<std::string>();

	if (type == "Light")
	{
		return new Light("Light");
	}
	return nullptr;
}
