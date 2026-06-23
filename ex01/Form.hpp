#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <exception>
# include "Bureaucrat.hpp"

class Form
{
    private:
        const std::string name;
        bool is_signed;
        const int grade_to_sign;
        const int grade_to_execute;
    public:
        class GradeTooHighException : public std::exception 
        {
            public:
                const char * what() const throw();
        };

        class GradeTooLowException : public std::exception 
        {
            public:
                const char * what() const throw();
        };

        Form();
        ~Form();
        Form(const std::string name, const int grade_to_sign, const int grade_to_execute);
        Form(const Form &other);
	    Form& operator=(const Form &other);

        std::string getName() const;
        bool getIsSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;
        void beSigned(Bureaucrat const& bureaucrat);

};

std::ostream &operator<<(std::ostream &os, const Form &f);

#endif
