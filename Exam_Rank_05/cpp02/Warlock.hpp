/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 19:32:27 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/06/16 13:44:07 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WARLOCK_HPP
# define WARLOCK_HPP

# include <iostream>
# include <set>
# include "ASpell.hpp"
# include "SpellBook.hpp"

class Warlock {
	private:
		Warlock();
		Warlock(Warlock const& warlock);
		Warlock&	operator=(Warlock const& warlock);
		std::string	_name;
		std::string	_title;
		SpellBook	_spellBook;

	public:
		Warlock(std::string name, std::string title);
		virtual ~Warlock();
		std::string	getName() const;
		std::string	getTitle() const;
		void	setTitle(std::string const& title);
		void	introduce() const;
		void	learnSpell(ASpell* spell);
		void	forgetSpell(std::string const& spell);
		void	launchSpell(std::string const& spell, ATarget const& target);
};

#endif // WARLOCK_HPP
