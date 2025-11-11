/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blohrer <blohrer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 14:29:37 by blohrer           #+#    #+#             */
/*   Updated: 2025/11/04 11:10:16 by blohrer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : count(0), nextIndex(0) {}

void PhoneBook::addContact() {
	Contact newContact;
	std::string firstName;
	std::string lastName;
	std::string nickName;
	std::string phoneNumber;
	std::string darkestSecret;

	std::cout<< "Enter your first name: ";
	if(!std::getline(std::cin, firstName))
		return;
	std::cout<< "Enter your last name: ";
	if(!std::getline(std::cin, lastName))
		return;
	std::cout<< "Enter your nick name: ";
	if(!std::getline(std::cin, nickName))
		return;
	std::cout<< "Enter your phone number: ";
	if(!std::getline(std::cin, phoneNumber))
		return;
	std::cout<< "Enter your darkest secret: ";
	if(!std::getline(std::cin, darkestSecret))
		return;
	newContact.setContact(firstName, lastName, nickName, phoneNumber, darkestSecret);
	contacts[nextIndex] = newContact;
	nextIndex = (nextIndex + 1) % 8;
	if(count < 8)
		count++;
	std::cout << "Contact added successfully!\n";
}

// TODO: Implement displayContacts()
// - Print a table header: Index | First Name | Last Name | Nickname
// - Use std::setw(10) for each column
// - Loop from 0 to count-1
//   - For each contact, use truncateField() for formatting
//   - Skip if contact.isEmpty() == true (optional)
// - Align output properly (right-aligned fields)
void PhoneBook::displayContacts() const 
{
	if(count == 0)
	{
		std::cout << "No contacts to display.\n";
		return;
	}
	std::cout << std::setw(10) << "Index" << "  | "
              << std::setw(10) << "First Name" << "  | "
              << std::setw(10) << "Last Name" << "  | "
              << std::setw(10) << "Nickname" << std::endl;
	for(int i = 0; i < count; i++){
	std::cout << std::setw(10) << "" << i << " | ";
	std::cout << std::setw(10) << truncateField(contacts[i].getFirstName()) << " | ";
	std::cout << std::setw(10) << truncateField(contacts[i].getLastName()) << " | ";
	std::cout << std::setw(10) << truncateField(contacts[i].getNickName()) << std::endl;
	i++;
	}
}

// TODO: Implement showContact()
// - Check if index is valid (0 <= index < count)
// - If invalid, print an error and return
// - Otherwise, print all contact fields (with clear labels)
// void PhoneBook::showContact(int index) const {
//     // TODO
// }

// // TODO: Implement truncateField()
// // - If field.size() > 10: return first 9 chars + "."
// // - Otherwise: return field unchanged
// std::string PhoneBook::truncateField(const std::string &field) const {
//     // TODO
// }
std::string PhoneBook::truncateField(const std::string &field) const {
    // TODO: if field.size() > 10, return first 9 chars + "."
    // otherwise return field unchanged
    return field;
}


int main() {
    PhoneBook pb;
    std::string command;

    while (true) {
        std::cout << "\nEnter command (ADD / SEARCH / EXIT): ";
        if (!std::getline(std::cin, command))
            break;

        if (command == "ADD") {
            pb.addContact();
        }
        else if (command == "SEARCH") {
            pb.displayContacts();
        }
        else if (command == "EXIT") {
            std::cout << "Goodbye!\n";
            break;
        }
        else {
            std::cout << "Unknown command. Try again.\n";
        }
    }
    return 0;
}