/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SpellBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 11:47:42 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/06/16 15:05:50 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SpellBook.hpp"

SpellBook::SpellBook() { }

SpellBook::SpellBook(SpellBook const& spellBook) { (void) spellBook; }

SpellBook::~SpellBook() {
	std::map<std::string, ASpell*>::iterator	it = this->_spells.begin();
	std::map<std::string, ASpell*>::iterator	ite = this->_spells.end();

	for (; it != ite; it++)
		delete it->second;
}

SpellBook&	SpellBook::operator=(SpellBook const& spellBook) {
	(void) spellBook;
	return *this;
}

void	SpellBook::learnSpell(ASpell* spell) {
	std::map<std::string, ASpell*>::iterator	it = this->_spells.find(spell->getName());

	if (it == this->_spells.end())
		this->_spells.insert(std::pair<std::string, ASpell*>(spell->getName(), spell->clone()));
}

void	SpellBook::forgetSpell(std::string const& spell) {
	std::map<std::string, ASpell*>::iterator	it = this->_spells.find(spell);

	if (it != this->_spells.end()) {
		delete it->second;
		this->_spells.erase(it);
	}
}

ASpell*	SpellBook::createSpell(std::string const& spellName) {
	std::map<std::string, ASpell*>::iterator	it = this->_spells.find(spellName);

	if (it != this->_spells.end())
		return it->second;
	return NULL;
}
