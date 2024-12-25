#pragma once

#include <FL/Fl_Window.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Box.H>

class LoginScreen
{
public:
    LoginScreen();
    void show();
    bool authorized;

private:
    Fl_Window *window;
    Fl_Input *username_input;
    Fl_Input *password_input;
    Fl_Button *login_button;
    static void login_cb(Fl_Widget *widget, void *data);
    void handle_login();
};
