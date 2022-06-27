/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SpellBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 11:47:39 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/06/16 15:04:10 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPELLBOOK_HPP
# define SPELLBOOK_HPP

# include <iostream>
# include <map>
# include "ASpell.hpp"

class SpellBook {
	private:
		SpellBook(SpellBook const& spellBook);
		SpellBook&	operator=(SpellBook const& spellBook);
		std::map<std::string, ASpell*>	_spells;

	public:
		SpellBook();
		virtual ~SpellBook();
		void	learnSpell(ASpell* spell);
		void	forgetSpell(std::string const& spellName);
		ASpell*	createSpell(std::string const& spellName);
};

#endif // SPELLBOOK_HPP
