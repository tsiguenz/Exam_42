/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BrickWall.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 23:43:05 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/06/16 11:45:54 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BrickWall.hpp"

BrickWall::BrickWall(): ATarget("Inconspicuous Red-brick Wall") { }

BrickWall::BrickWall(BrickWall const& brickWall) {
	*this = brickWall;
}

BrickWall::~BrickWall() { }

BrickWall&	BrickWall::operator=(BrickWall const& brickWall) {
	this->type = brickWall.type;
	return *this;
}
ATarget*	BrickWall::clone() {
	return new BrickWall;
}
