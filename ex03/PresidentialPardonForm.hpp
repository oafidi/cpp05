#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    public:
        PresidentialPardonForm();
        virtual ~PresidentialPardonForm();
        PresidentialPardonForm(std::string target);
        PresidentialPardonForm(const PresidentialPardonForm &other);
        PresidentialPardonForm &operator=(const PresidentialPardonForm &other);

        virtual void executeAction() const;
};

#endif