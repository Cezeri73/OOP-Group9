/**
 * @file LoginScreen.h
 * @brief Header file for the LoginScreen class, providing a GUI for user authentication.
 */

#pragma once

#include <FL/Fl_Window.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Box.H>

/**
 * @class LoginScreen
 * @brief Represents the login screen for user authentication.
 * 
 * This class provides input fields for username and password, 
 * along with a login button to validate user credentials.
 */
class LoginScreen
{
public:
    /**
     * @brief Constructor for the LoginScreen class.
     * 
     * Initializes the login screen with input fields and a login button.
     */
    LoginScreen();

    /**
     * @brief Displays the login screen.
     */
    void show();

    /**
     * @brief Indicates whether the user is authorized.
     * 
     * This flag is set to true upon successful login.
     */
    bool authorized;

private:
    Fl_Window *window; ///< Main window for the login screen.
    Fl_Input *username_input; ///< Input field for entering the username.
    Fl_Input *password_input; ///< Input field for entering the password.
    Fl_Button *login_button; ///< Button to trigger the login process.

    /**
     * @brief Static callback function for the login button.
     * 
     * This function redirects to the `handle_login` method.
     * 
     * @param widget Pointer to the widget triggering the callback.
     * @param data Pointer to the LoginScreen instance.
     */
    static void login_cb(Fl_Widget *widget, void *data);

    /**
     * @brief Handles the login logic.
     * 
     * Verifies the entered username and password and updates the authorization status.
     */
    void handle_login();
};
