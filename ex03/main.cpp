#include "Intern.hpp"
#include <ctime>
#include <cstdlib>


int main()
{
    std::srand(std::time(NULL));

    Intern intern;

    std::cout << "\n---- SHRUBBERY TEST ----\n";
    try
    {
        Bureaucrat boss("Boss", 1);
        AForm* shrubbery = intern.makeForm("shrubbery creation", "home");
        boss.signForm(*shrubbery);
        boss.executeForm(*shrubbery);
        delete shrubbery;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n---- ROBOTOMY TEST ----\n";
    try
    {
        Bureaucrat boss("Boss", 1);
        AForm* robotomy = intern.makeForm("robotomy request", "home");
        boss.signForm(*robotomy);
        boss.executeForm(*robotomy);
        delete robotomy;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n---- PRESIDENTIAL TEST ----\n";
    try
    {
        Bureaucrat boss("Boss", 1);
        AForm* pardon = intern.makeForm("presidential pardon", "home");
        boss.signForm(*pardon);
        boss.executeForm(*pardon);
        delete pardon;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n---- UNKNOWN FORM TEST ----\n";
    try
    {
        Bureaucrat boss("Boss", 1);
        AForm* invalid = intern.makeForm("Invalid", "home");
        boss.signForm(*invalid);
        boss.executeForm(*invalid);
        delete invalid;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}