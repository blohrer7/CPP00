/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blohrer <blohrer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 14:29:37 by blohrer           #+#    #+#             */
/*   Updated: 2025/11/14 08:22:58 by blohrer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : count(0), nextIndex(0)
{
}

static bool	getNonEmptyNoDigitsInput(const std::string &prompt,
		std::string &out)
{
	bool	hasDigit;

	while (true)
	{
		std::cout << prompt;
		if (!std::getline(std::cin, out))
			return (false);
		if (out.empty())
		{
			std::cout << "Input cannot be empty. Please try again.\n";
			continue ;
		}
		hasDigit = false;
		for (size_t i = 0; i < out.length(); i++)
		{
			if (std::isdigit(out[i]))
			{
				hasDigit = true;
				break ;
			}
		}
		if (hasDigit)
		{
			std::cout << "Numbers are not allowed here. Please use letters only.\n";
			continue ;
		}
		return (true);
	}
}

bool	isNumeric(const std::string &s)
{
	if (s.empty())
		return (false);
	for (size_t i = 0; i < s.length(); i++)
	{
		if (!std::isdigit(s[i]))
			return (false);
	}
	return (true);
}
static bool	getNumericInput(const std::string &prompt, std::string &out)
{
	while (true)
	{
		std::cout << prompt;
		if (!std::getline(std::cin, out))
			return (false);
		if (out.empty())
		{
			std::cout << "Input cannot be empty. Please try again.\n";
			continue ;
		}
		if (!isNumeric(out))
		{
			std::cout << "Phone number must contain digits only.\n";
			continue ;
		}
		return (true);
	}
}

bool	isValidIndex(const std::string &s)
{
	int	num;

	if (!isNumeric(s))
		return (false);
	num = std::stoi(s);
	return (num >= 1 && num <= 8);
}

void PhoneBook::addContact()
{
	Contact	newContact;

	std::string firstName;
	std::string lastName;
	std::string nickName;
	std::string phoneNumber;
	std::string darkestSecret;
	if (!getNonEmptyNoDigitsInput("Enter your first name: ", firstName))
		return ;
	if (!getNonEmptyNoDigitsInput("Enter your last name: ", lastName))
		return ;
	if (!getNonEmptyNoDigitsInput("Enter your nick name: ", nickName))
		return ;
	if (!getNumericInput("Enter your phone number: ", phoneNumber))
		return ;
	if (!getNonEmptyNoDigitsInput("Enter your darkest secret: ", darkestSecret))
		return ;
	newContact.setContact(firstName, lastName, nickName, phoneNumber,
		darkestSecret);
	contacts[nextIndex] = newContact;
	nextIndex = (nextIndex + 1) % 8;
	if (count < 8)
		count++;
	std::cout << "Contact added successfully!\n";
}

void PhoneBook::displayContacts() const
{
	if (count == 0)
	{
		std::cout << "No contacts to display.\n";
		return ;
	}
	std::cout << std::left;
	std::cout << std::setw(10) << "Index"
				<< " | " << std::setw(10) << "First Name"
				<< " | " << std::setw(10) << "Last Name"
				<< " | " << std::setw(10) << "Nickname" << std::endl;
	for (int i = 0; i < count; i++)
	{
		std::cout << std::setw(10) << (i + 1) << " | ";
		std::cout << std::setw(10) << truncateField(contacts[i].getFirstName()) << " | ";
		std::cout << std::setw(10) << truncateField(contacts[i].getLastName()) << " | ";
		std::cout << std::setw(10) << truncateField(contacts[i].getNickName()) << std::endl;
	}
}

void PhoneBook::showContact(int index) const
{
	if (index < 0 || index >= count)
	{
		std::cout << "Invalid index.\n";
		return ;
	}
	const Contact &c = contacts[index];
	std::cout << "First name: " << c.getFirstName() << std::endl;
	std::cout << "Last name: " << c.getLastName() << std::endl;
	std::cout << "Nickname: " << c.getNickName() << std::endl;
	std::cout << "Phone number: " << c.getPhoneNumber() << std::endl;
	std::cout << "Darkest secret: " << c.getDarkestSecret() << std::endl;
}

std::string PhoneBook::truncateField(const std::string &field) const
{
	if (field.length() > 10)
		return (field.substr(0, 9) + ".");
	return (field);
}

int	main(void)
{
	PhoneBook	pb;
	int			index;

	std::string command;
	std::string input;
	while (true)
	{
		std::cout << "\nEnter command (ADD / SEARCH / EXIT): ";
		if (!std::getline(std::cin, command))
			break ;
		if (command == "ADD")
			pb.addContact();
		else if (command == "SEARCH")
		{
			pb.displayContacts();
			while (true)
			{
				std::cout << "Enter index to view details: ";
				if (!std::getline(std::cin, input))
					break ; // Ctrl+D → exit SEARCH
				if (!isValidIndex(input))
				{
					std::cout << "Invalid input. Please enter a number between 1 and 8.\n";
					continue ;
				}
				index = std::stoi(input) - 1; // safe now
				pb.showContact(index);
				break ;
			}
		}
		else if (command == "EXIT")
		{
			std::cout << "Goodbye!\n";
			break ;
		}
		else
		{
			std::cout << "Unknown command. Try again.\n";
		}
	}
	return (0);
}
