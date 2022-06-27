/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dummy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 23:43:05 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/06/15 23:53:59 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dummy.hpp"

Dummy::Dummy(): ATarget("Target Practice Dummy") { }

Dummy::Dummy(Dummy const& dummy) {
	*this = dummy;
}

Dummy::~Dummy() { }

Dummy&	Dummy::operator=(Dummy const& dummy) {
	this->type = dummy.type;
	return *this;
}
ATarget*	Dummy::clone() {
	return new Dummy;
}
