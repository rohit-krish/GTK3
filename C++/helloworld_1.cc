#include <iostream>
#include <gtkmm/application.h>
#include <gtkmm/button.h>
#include <gtkmm/window.h>

class HelloWorld : public Gtk::Window
{
public:
    HelloWorld() : m_button("Hello World")
    {
        set_border_width(10);
        m_button.signal_clicked().connect(sigc::mem_fun(*this, &HelloWorld::on_button_clicked));

        add(m_button);

        m_button.show();
    }

protected:
    // Signal handlers
    void on_button_clicked()
    {

        std::cout << "Hello World" << std::endl;
    }

    // Member widgets:
    Gtk::Button m_button;
};

int main(int argc, char **argv)
{
    auto app = Gtk::Application::create(argc, argv, "org.gtkmm.example");

    HelloWorld helloworld;

    return app->run(helloworld);
}