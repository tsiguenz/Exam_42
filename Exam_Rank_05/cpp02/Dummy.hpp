/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dummy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 23:43:01 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/06/15 23:52:15 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DUMMY_HPP
# define DUMMY_HPP

# include <iostream>
# include "ATarget.hpp"

class Dummy: public ATarget {
	public:
		Dummy();
		Dummy(Dummy const& dummy);
		~Dummy();
		Dummy&	operator=(Dummy const& dummy);
		virtual ATarget*	clone();

	private:

};

#endif //  DUMMY_HPP
