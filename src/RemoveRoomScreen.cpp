#include "RemoveRoomScreen.h"
#include "Room.h"

// Constructor to initialize the RemoveRoomScreen
RemoveRoomScreen::RemoveRoomScreen()
{
    // Create a window with dimensions 300x200 and a title "Remove Room"
    window = new Fl_Window(300, 200, "Remove Room");

    // Create a label "Room Name:" on the screen
    new Fl_Box(20, 30, 80, 30, "Room Name:");

    // Create an input field to get the room name from the user
    roomName = new Fl_Input(110, 30, 150, 30);

    // Create a button labeled "Enter" that will trigger a callback when clicked
    button = new Fl_Button(110, 130, 80, 30, "Enter");

    // Set the callback function for the button click event
    button->callback(login_cb, this);

    // End the window definition, indicating that the window has been fully defined
    window->end();
}

// Show the window to the user
void RemoveRoomScreen::show()
{
    window->show(); // Display the window
}

// Return whether the window is currently visible
bool RemoveRoomScreen::shown()
{
    return window->visible(); // Check if the window is currently visible
}

// Callback function when the "Enter" button is clicked
void RemoveRoomScreen::login_cb(Fl_Widget *widget, void *data)
{
    // Cast the data back to the RemoveRoomScreen object
    RemoveRoomScreen *screen = (RemoveRoomScreen *)data;

    // Handle the login action (in this case, room removal)
    screen->handle_login();
}

// Handle the logic of removing a room
void RemoveRoomScreen::handle_login()
{
    // Get the room name entered by the user in the input field
    std::string roomNameStr = roomName->value();

    // Iterate through the list of all rooms and find the room to remove
    for(int i = Room::allRooms.size() - 1; i >= 0; i--) {
        // If the room name matches the entered name, remove the room from the list
        if(Room::allRooms[i]->roomName == roomNameStr){
            Room::allRooms.erase(Room::allRooms.begin() + i); // Remove room from vector
            break; // Exit the loop after the room is removed
        }
    }

    // Hide the window after the operation is complete
    window->hide();
}
