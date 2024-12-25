/**
 * @file MainWindow.cpp
 * @brief Implementation of the MainWindow class, providing the main interface for managing rooms and smart devices.
 */

#include "MainWindow.h"

// Define a static instance of the AddRoomScreen
AddRoomScreen MainWindow::addRoomScreen;
RemoveRoomScreen MainWindow::removeRoomScreen;

/**
 * @brief Constructor for the MainWindow class.
 * 
 * Initializes the main window with a specified width, height, and title, and loads program data from a file.
 * 
 * @param w Width of the window.
 * @param h Height of the window.
 * @param name Title of the window.
 */
MainWindow::MainWindow(int w, int h, const char *name) : Fl_Window(w, h, name)
{
    loadProgram(); // Load the program's data (rooms) from a file
};

/**
 * @brief Saves the current state of the program to a file.
 * 
 * Converts all rooms to JSON format and writes the data to a file named "saveFile."
 */
void MainWindow::saveProgram()
{
    json allRoomsJson = json::array(); // Create a JSON array to store room data
    for (const auto &room : Room::allRooms)
    {
        allRoomsJson.push_back(room->toJson()); // Convert each room to JSON and add to the array
    }

    std::ofstream outFile("saveFile"); // Open the file for writing
    if (outFile.is_open())
    {
        outFile << allRoomsJson.dump(4); // Write the JSON data to the file with 4-space indentation
        outFile.close(); // Close the file
    }
    else
    {
        std::cerr << "Error opening file for writing!" << std::endl; // Print error message if file cannot be opened
    }
}

/**
 * @brief Loads the program's state from a file.
 * 
 * Reads JSON data from the file "saveFile" and recreates the rooms in the program.
 * If the file cannot be opened, an error message is displayed.
 */
void MainWindow::loadProgram()
{
    std::ifstream inFile("saveFile"); // Open the file for reading
    if (inFile.is_open())
    {
        json allRoomsJson;
        inFile >> allRoomsJson; // Read the JSON data from the file

        for (const auto &roomJson : allRoomsJson)
        {
            Room::fromJson(roomJson); // Create rooms from the JSON data
        }
    }
    else
    {
        std::cerr << "Error opening file for reading!" << std::endl; // Print error message if file cannot be opened
    }
    updateButtons(); // Update the UI to reflect the loaded data
}

/**
 * @brief Updates the UI with room buttons and controls.
 * 
 * Clears the current window and repopulates it with updated room data,
 * including buttons for each room and system notifications.
 */
void MainWindow::updateButtons()
{
    Fl_Window::hide(); // Hide the window temporarily
    this->clear(); // Clear all widgets from the window
    this->begin(); // Begin adding widgets to the window

    // Retrieve all rooms from the program's data
    std::vector<Room *> rooms = Room::allRooms;

    // Add a button for removing rooms
    removeRoomButton = new Fl_Button(900, 60, 200, 30, "Remove Room");
    removeRoomButton->callback([](Fl_Widget *widget, void *data)
                                {
        MainWindow* mw = static_cast<MainWindow*>(data);
        removeRoomScreen.show();
        while(removeRoomScreen.shown()){
            Fl::wait();
        }
        mw->updateButtons(); }, this);

    // Add a button for adding new rooms
    addRoomButton = new Fl_Button(900, 20, 200, 30, "Add Room");
    addRoomButton->callback([](Fl_Widget *widget, void *data)
                            {
        MainWindow* mw = static_cast<MainWindow*>(data);
        addRoomScreen.show(); // Show the AddRoomScreen window
        while(addRoomScreen.shown()){ // Wait while the AddRoomScreen is displayed
            Fl::wait();
        }
        mw->updateButtons(); // Update the buttons after adding a room
    }, this);

    // Create a notification display for system messages
    Fl_Text_Display *notificationDisplay = new Fl_Text_Display(350, 80, 500, 300, "Notification Sys");
    Fl_Text_Buffer *notificationBuffer = SmartDevice::notificationBuffer;
    notificationDisplay->buffer(notificationBuffer); // Set the notification buffer
    notificationDisplay->textfont(FL_COURIER); // Set font to Courier
    notificationDisplay->textsize(14); // Set font size
    notificationDisplay->color(FL_BLACK); // Set background color
    notificationDisplay->textcolor(FL_WHITE); // Set text color

    int yPosition = 20; // Initialize the vertical position for room buttons
    for (size_t i = 0; i < rooms.size(); i++)
    {
        // Create a button for each room
        Fl_Button *roomButton = new Fl_Button(100, yPosition, 200, 30, rooms[i]->roomName.c_str());
        roomButton->callback([](Fl_Widget *widget, void *data)
                             {
            Room* r = static_cast<Room*>(data);
            r->showRoom(); // Show the room details when the button is clicked
        }, rooms[i]);
        yPosition += 40; // Move to the next vertical position for the next button
    }

    this->end(); // Finish adding widgets to the window
    this->show(); // Show the updated window
}

/**
 * @brief Saves the program state before hiding the window.
 * 
 * Overrides the default hide method to ensure the program's data is saved to a file.
 */
void MainWindow::hide()
{
    this->saveProgram(); // Save the program's data to the file
    Fl_Window::hide(); // Hide the window
}
