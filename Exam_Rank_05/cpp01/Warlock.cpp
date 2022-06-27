/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 19:32:20 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/06/16 14:40:24 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Warlock.hpp"

Warlock::Warlock() { 
	std::cout << this->_name << ": This looks like another boring day." << std::endl;
}

Warlock::Warlock(std::string name, std::string title): _name(name), _title(title), _spellBook() {
	std::cout << this->_name << ": This looks like another boring day." << std::endl;
}

Warlock::Warlock(Warlock const& warlock) { *this = warlock ; }

Warlock::~Warlock() {
	std::map<std::string, ASpell*>::iterator	it = this->_spellBook.begin();
	std::map<std::string, ASpell*>::iterator	ite = this->_spellBook.end();

	for (; it != ite; it++) {
		delete (*it).second;
	}
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

void	Warlock::learnSpell(ASpell* spell) {
	std::map<std::string, ASpell*>::iterator	it = this->_spellBook.find(spell->getName());
	if (it == this->_spellBook.end())
		this->_spellBook.insert(std::pair<std::string, ASpell*>(spell->getName(), spell->clone()));
}

void	Warlock::forgetSpell(std::string const& spell) {
	std::map<std::string, ASpell*>::iterator	it = this->_spellBook.find(spell);
	if (it != this->_spellBook.end()) {
			delete it->second;
			this->_spellBook.erase(spell);
	}
}

void	Warlock::launchSpell(std::string const& spell, ATarget const& target) {
	std::map<std::string, ASpell*>::iterator	it = this->_spellBook.find(spell);

	if (it != this->_spellBook.end())
		it->second->launch(target);
}
