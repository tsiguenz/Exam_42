/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BrickWall.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 23:43:01 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/06/16 11:47:44 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRICKWALL_HPP
# define BRICKWALL_HPP

# include <iostream>
# include "ATarget.hpp"

class BrickWall: public ATarget {
	public:
		BrickWall();
		BrickWall(BrickWall const& brickWall);
		~BrickWall();
		BrickWall&	operator=(BrickWall const& brickWall);
		virtual ATarget*	clone();

	private:

};

#endif //  BRICKWALL_HPP
