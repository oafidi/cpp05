#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(Intern const &other)
{
	std::cout << "Intern copy constructor called" << std::endl;
	(void)other;
}

Intern &Intern::operator=(Intern const &other)
{
    std::cout << "Intern copy assignment operator called" << std::endl;
	(void)other;
	return (*this);
}

Intern::~Intern(void)
{
	std::cout << "Intern destructor constructor" << std::endl;
}

const char*Intern::InvalidForm::what() const throw()
{
    return "Invalid Form!";
}

AForm *Intern::makeShrubbery(const std::string& target)
{
    return (new ShrubberyCreationForm(target));
}

AForm *Intern::makeRobotomy(const std::string& target)
{
    return (new RobotomyRequestForm(target));
}

AForm *Intern::makePresidential(const std::string& target)
{
    return (new PresidentialPardonForm(target));
}

AForm *Intern::makeForm(const std::string &name, const std::string &target)
{
    std::string types[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};
    AForm *(Intern::*forms[3])(const std::string&) = {
        &Intern::makePresidential,
        &Intern::makeRobotomy,
        &Intern::makeShrubbery,
    };

    for (int i = 0; i < 3; i++)
    {
        if (types[i] == name)
        {
            std::cout << "Intern creates " << name << " form" << std::endl;
            return (this->*forms[i])(target);
        }
    }
    throw InvalidForm();
}
