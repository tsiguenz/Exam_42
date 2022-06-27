/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 19:32:27 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/06/14 19:58:01 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WARLOCK_H
# define WARLOCK_H

#include <iostream>

class Warlock {
	private:
		Warlock();
		Warlock(Warlock const& warlock);
		Warlock&	operator=(Warlock const& warlock);
		std::string	_name;
		std::string	_title;

	public:
		Warlock(std::string name, std::string title);
		~Warlock();
		std::string	getName() const;
		std::string	getTitle() const;
		void	setTitle(std::string const& title);
		void	introduce() const;
};

#endif // WARLOCK_H
