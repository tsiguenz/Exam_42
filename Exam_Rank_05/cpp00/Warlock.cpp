/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 19:32:20 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/06/14 20:03:22 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Warlock.hpp"

Warlock::Warlock() { 
	std::cout << this->_name << ": This looks like another boring day." << std::endl;
}

Warlock::Warlock(std::string name, std::string title): _name(name), _title(title) {
	std::cout << this->_name << ": This looks like another boring day." << std::endl;
}

Warlock::Warlock(Warlock const& warlock) { *this = warlock ; }

Warlock::~Warlock() {
	std::cout << this->_name << ": My job here is done." << std::endl;
}

Warlock&	Warlock::operator=(Warlock const& warlock) {
	this->_title = warlock._title;
	this->_name = warlock._name;
	return *this;
}

std::string	Warlock::getName() const { return this->_name; }

std::string	Warlock::getTitle() const { return this->_title; }

void	Warlock::setTitle(std::string const& title) { this->_title = title; }

void	Warlock::introduce() const {
	std::cout 	<< this->_name << ": I am " 
				<< this->_name << ", " 
				<< this->_title << "!" << std::endl;
}
