#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{

    std::cout << "\n--- Test Form creation  ---" << std::endl;
    try
    {
        Form f("F1", 50, 25);
        std::cout << f << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n--- Test Form grade too high ---" << std::endl;
    try
    {
        Form f("F2", 0, 25);
        std::cout << f << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n--- Test Form grade too low ---" << std::endl;
    try
    {
        Form f("F3", 50, 151);
        std::cout << f << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n--- Test signing ---" << std::endl;
    try
    {
        Bureaucrat b("Omar", 30);
        Form f("F4", 50, 25);
        std::cout << f << std::endl;
        b.signForm(f);
        std::cout << f << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n--- Test bad signing ---" << std::endl;
    try
    {
        Bureaucrat b("Samir", 100);
        Form f("F5", 50, 25);
        std::cout << f << std::endl;
        b.signForm(f);
        std::cout << f << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}