/**
 * @file LoginScreen.cpp
 * @brief Implementation of the LoginScreen class, providing a GUI for user authentication.
 */

#include "LoginScreen.h"
#include <FL/fl_ask.H>
#include <string>

/**
 * @brief Constructor for the LoginScreen class.
 * 
 * Initializes the login screen, including the username and password input fields,
 * and a button to submit the login credentials.
 */
LoginScreen::LoginScreen()
{
    // Create a new window for the login screen
    window = new Fl_Window(300, 200, "Login Screen");
    authorized = false; // Initialize authorization status as false

    // Add a label and input box for the username
    new Fl_Box(20, 30, 80, 30, "Username:");
    username_input = new Fl_Input(110, 30, 150, 30);

    // Add a label and input box for the password
    new Fl_Box(20, 80, 80, 30, "Password:");
    password_input = new Fl_Input(110, 80, 150, 30);
    password_input->type(FL_SECRET_INPUT); // Mask the password input for security

    // Add a button to trigger the login process
    login_button = new Fl_Button(110, 130, 80, 30, "Login");
    login_button->callback(login_cb, this); // Set the callback function for the login button

    // Finalize the window layout and show it
    window->end();
    window->show();
    Fl::run(); // Start the FLTK event loop
}

/**
 * @brief Static callback function for the login button.
 * 
 * This function is triggered when the login button is pressed.
 * It redirects to the `handle_login` method of the LoginScreen object.
 * 
 * @param widget Pointer to the widget triggering the callback.
 * @param data Pointer to the LoginScreen object.
 */
void LoginScreen::login_cb(Fl_Widget *widget, void *data)
{
    // Cast the data pointer to a LoginScreen object
    LoginScreen *screen = (LoginScreen *)data;
    screen->handle_login(); // Call the handle_login method
}

/**
 * @brief Handles the login logic when the login button is pressed.
 * 
 * Verifies the username and password entered by the user. If the credentials
 * are correct, the user is granted access and the login window is closed.
 * Otherwise, an error message is displayed.
 */
void LoginScreen::handle_login()
{
    // Get the username and password entered by the user
    std::string username = username_input->value();
    std::string password = password_input->value();

    // Check if the username and password are correct
    if (username == "admin" && password == "root")
    {
        authorized = true; // Set the authorization status to true
        window->hide();    // Close the login window
    }
    else
    {
        // Display an error message for invalid credentials
        fl_message("Invalid username or password!");
    }
}
