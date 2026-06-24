#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("ShrubberyCreationForm", "defaultTarget", 145, 137)
{
	std::cout << "Shrubbery default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
	: AForm("ShrubberyCreationForm", target, 145, 137)
{
	std::cout << "Shrubbery parameterized constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &other)
	: AForm(other)
{
	std::cout << "Shrubbery copy constructor called" << std::endl;
}

ShrubberyCreationForm &	ShrubberyCreationForm::operator=(ShrubberyCreationForm const &other)
{
	if (this != &other)
		AForm::operator=(other);
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "Shrubbery destructor called" << std::endl;
}

void ShrubberyCreationForm::executeForm() const
{
    std::string filename = this->getTarget() + "_shrubbery";
    std::ofstream filestream(filename.c_str());

    if (!filestream.is_open())
        throw std::runtime_error("Failed to open file: " + filename);

    filestream << "              &&& &&  & &&\n";
    filestream << "          && &\\/&\\|& ()|/ @, &&\n";
    filestream << "          &\\/(/&/&||/& /_/)_&/_&\n";
    filestream << "       &() &\\/&|()|/&\\/ '%\" & ()\n";
    filestream << "      &_\\_&&_\\ |& |&&/&__%_/_& &&\n";
    filestream << "    &&   && & &| &| /& & % ()& /&&\n";
    filestream << "     ()&_---()&\\&\\|&&-&&--%---()~\n";
    filestream << "         &&     \\||| \n";
    filestream << "                 |||\n";
    filestream << "                 |||\n";
    filestream << "                 |||\n";
    filestream << "           , -=-~  .-^- _\n";

    filestream.close();
}