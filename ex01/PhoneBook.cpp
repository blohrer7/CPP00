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

// TODO: Implement constructor
// - Initialize count = 0
// - Initialize nextIndex = 0
PhoneBook::PhoneBook() : count(0), nextIndex(0) {}

// TODO: Implement addContact()
// - Create a Contact object
// - Prompt the user for each field (first name, last name, nickname, phone, secret)
// - Use std::getline(std::cin, input)
// - Validate: if input is empty, keep asking (unless EOF)
// - Call contact.setContact(...) to store data
// - Store in contacts[nextIndex]
// - Update nextIndex (wrap around 0–7)
// - Update count (don’t exceed 8)
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
void PhoneBook::displayContacts() const {
    
}

// TODO: Implement showContact()
// - Check if index is valid (0 <= index < count)
// - If invalid, print an error and return
// - Otherwise, print all contact fields (with clear labels)
void PhoneBook::showContact(int index) const {
    // TODO
}

// TODO: Implement truncateField()
// - If field.size() > 10: return first 9 chars + "."
// - Otherwise: return field unchanged
std::string PhoneBook::truncateField(const std::string &field) const {
    // TODO
}
