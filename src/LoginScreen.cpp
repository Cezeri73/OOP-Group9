#include "LoginScreen.h"
#include <FL/fl_ask.H> // For fl_message
#include <string>

// Constructor: Build the UI
LoginScreen::LoginScreen() {
    window = new Fl_Window(300, 200, "Login Screen");
    authorized = false;
    // Username label and input
    new Fl_Box(20, 30, 80, 30, "Username:");
    username_input = new Fl_Input(110, 30, 150, 30);

    // Password label and input
    new Fl_Box(20, 80, 80, 30, "Password:");
    password_input = new Fl_Input(110, 80, 150, 30);
    password_input->type(FL_SECRET_INPUT); // Mask input

    // Login button
    login_button = new Fl_Button(110, 130, 80, 30, "Login");
    login_button->callback(login_cb, this);

    window->end();
    window->show();
    Fl::run();
}

// Static callback to handle button click
void LoginScreen::login_cb(Fl_Widget *widget, void *data) {
    LoginScreen *screen = (LoginScreen *)data;
    screen->handle_login();
}

// Handle login logic
void LoginScreen::handle_login() {
    std::string username = username_input->value();
    std::string password = password_input->value();

    if (username == "admin" && password == "root") {
        authorized = true;
	window->hide();
    } else {
        fl_message("Invalid username or password!");
    }
}
