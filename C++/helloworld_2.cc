#include <iostream>
#include <gtkmm/application.h>
#include <gtkmm/window.h>
#include <gtkmm/button.h>
#include <gtkmm/box.h>

class HelloWorld : public Gtk::Window
{
public:
    HelloWorld() // : m_button1("Button 1"), m_button2("Button 2")
    {
        set_title("Hello Buttons!");
        set_border_width(10);
        add(m_box1);

        m_button1.set_label("Button 1");
        m_button2.set_label("Butto 2");

        m_button1.signal_clicked().connect(sigc::bind<Glib::ustring>(sigc::mem_fun(*this, &HelloWorld::on_button_clicked), "button 1"));
        m_box1.pack_start(m_button1);
        m_button1.show();

        m_button2.signal_clicked().connect(sigc::bind<Glib::ustring>(sigc::mem_fun(*this, &HelloWorld::on_button_clicked), "button 2"));
        m_box1.pack_start(m_button2);
        m_button2.show();

        m_box1.show();
    }

protected:
    void on_button_clicked(Glib::ustring data)
    {
        std::cout << data << std::endl;
    }

    Gtk::Box m_box1;
    Gtk::Button m_button1, m_button2;
};

int main(int argc, char *argv[])
{
    auto app = Gtk::Application::create(argc, argv, "org.gtkmm.example");

    HelloWorld helloworld;

    // Shows the window and returns when it is closed.
    return app->run(helloworld);
}
