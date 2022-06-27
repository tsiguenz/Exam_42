/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 19:32:44 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/06/16 15:50:59 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Warlock.hpp"
#include "Fwoosh.hpp"
#include "Fireball.hpp"
#include "Polymorph.hpp"
#include "Dummy.hpp"
#include "TargetGenerator.hpp"
#include "SpellBook.hpp"
#include "BrickWall.hpp"

int main()
{
	Warlock richard("Richard", "foo");
	richard.setTitle("Hello, I'm Richard the Warlock!");
	BrickWall model1;

	Polymorph* polymorph = new Polymorph();
	TargetGenerator tarGen;

	tarGen.learnTargetType(&model1);
	richard.learnSpell(polymorph);

	Fireball* fireball = new Fireball();

	richard.learnSpell(fireball);

	ATarget* wall = tarGen.createTarget("Inconspicuous Red-brick Wall");

	richard.introduce();
	richard.launchSpell("Polymorph", *wall);
	richard.launchSpell("Fireball", *wall);
	delete fireball;
	delete polymorph;
	return 0;
}
