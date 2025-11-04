/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blohrer <blohrer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 14:29:42 by blohrer           #+#    #+#             */
/*   Updated: 2025/11/04 09:50:43 by blohrer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include "Contact.hpp"

class PhoneBook {
	private:
		Contact contacts[8];
		int count;
		int nextIndex;
		std::string truncateField(const std::string &field) const;

	public:
		PhoneBook();
		void addContact();
		void displayContacts() const;
		void showContact(int index) const;
};


#endif
