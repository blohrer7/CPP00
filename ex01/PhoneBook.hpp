/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blohrer <blohrer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 14:29:42 by blohrer           #+#    #+#             */
/*   Updated: 2025/10/28 14:50:19 by blohrer          ###   ########.fr       */
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

	public:
		void setContacts(const std::int& contacts, const std::int& count
						const std::int& nextIndex);
		
}


#endif
