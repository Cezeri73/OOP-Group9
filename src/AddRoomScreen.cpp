#include "AddRoomScreen.h"
#include "Room.h"

// Constructor to initialize the Add Room Screen
AddRoomScreen::AddRoomScreen()
{
    // Create a new window for adding a room
    window = new Fl_Window(300, 200, "Login Screen");

    // Create a label and input field for entering the room name
    new Fl_Box(20, 30, 80, 30, "Room Name:"); // Label for the input field
    roomName = new Fl_Input(110, 30, 150, 30); // Input field for room name

    // Create an "Enter" button for confirming the room addition
    button = new Fl_Button(110, 130, 80, 30, "Enter");
    button->callback(login_cb, this); // Set the callback function for the button

    // Finalize and display the window
    window->end();
}

// Method to show the Add Room Screen
void AddRoomScreen::show()
{
    window->show(); // Display the window
}

// Method to check if the window is currently visible
bool AddRoomScreen::shown()
{
    return window->visible(); // Return the visibility status of the window
}

// Callback function for the "Enter" button
void AddRoomScreen::login_cb(Fl_Widget *widget, void *data)
{
    AddRoomScreen *screen = (AddRoomScreen *)data; // Cast the data to AddRoomScreen
    screen->handle_login(); // Call the handle_login method
}

// Method to handle the addition of a room
void AddRoomScreen::handle_login()
{
    // Get the room name entered by the user
    std::string roomNameStr = roomName->value();

    // Create a new Room object with the entered name
    Room *roomToAdd = new Room(roomNameStr);

    // Log the room name to the console for debugging
    std::cout << roomNameStr;

    // Hide the window after adding the room
    window->hide();
}
