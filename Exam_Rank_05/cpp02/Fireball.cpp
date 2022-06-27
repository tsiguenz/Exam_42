/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fireball.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 23:11:24 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/06/16 11:25:13 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fireball.hpp"

Fireball::Fireball(): ASpell("Fireball", "burnt to a crosp") { }

Fireball::Fireball(std::string const& name, std::string const& effects)
: ASpell(name, effects) { }

Fireball::Fireball(Fireball const& fireball) {
	*this = fireball;
}

Fireball&	Fireball::operator=(Fireball const& fireball) {
	this->name = fireball.name;
	this->effects = fireball.effects;
	return (*this);
}

Fireball::~Fireball() { }

ASpell*	Fireball::clone() {
	return new Fireball;
}
