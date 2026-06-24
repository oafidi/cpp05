#ifndef INTERN_HPP
# define INTERN_HPP

# include "ShrubberyCreationForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"

class Intern
{
    private:
        AForm* makeShrubbery(const std::string& target);
        AForm* makeRobotomy(const std::string& target);
        AForm* makePresidential(const std::string& target);

    public:
        Intern();
        ~Intern();
        Intern(const Intern &other);
        Intern &operator=(const Intern &other);

        class InvalidForm : public std::exception
        {
            public:
                const char* what() const throw();
        };

        AForm *makeForm(const std::string &name, const std::string &target);
};

#endif