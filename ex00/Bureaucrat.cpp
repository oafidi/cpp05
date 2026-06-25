#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Default"), grade(150)
{
    std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : name(name), grade(grade)
{
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
    std::cout << "Bureaucrat parametrized constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat destructor called" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &other) : name(other.name), grade(other.grade)
{
    std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &other)
{
    if (this != &other)
        this->grade = other.grade;
    std::cout << "Bureaucrat copy assignement operator called" << std::endl;
    return *this;
}

const std::string Bureaucrat::getName() const
{
    return this->name;
}

int Bureaucrat::getGrade() const 
{
    return this->grade;
}

void Bureaucrat::increment()
{
    if (this->grade == 1)
        throw GradeTooHighException();
    this->grade--;
}

void Bureaucrat::decrement()
{
    if (this->grade == 150)
        throw GradeTooLowException();
    this->grade++;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade is too high!";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade is too low!";
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b)
{
    os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
    return os;
}