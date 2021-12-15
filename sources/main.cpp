//Copyright 2021 Anton Pavlyukevich.

//This file is part of a stopwatch.
//
//Stopwatch is free software: you can redistribute it and/or modify
//it under the terms of the GNU General Public License as published by
//the Free Software Foundation, either version 3 of the License, or
//(at your option) any later version.
//
//Stopwatch is distributed in the hope that it will be useful,
//but WITHOUT ANY WARRANTY; without even the implied warranty of
//MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//GNU General Public License for more details.
//
//You should have received a copy of the GNU General Public License
//along with stopwatch.  If not, see <https://www.gnu.org/licenses/>.

//
// Created by pavlyukevich.anton@gmail.com on 15.12.21
//

// built and tested on Darwin Kernel Version 18.7.0: Tue Jun 22 19:37:08 PDT 2021; root:xnu-4903.278.70~1/RELEASE_X86_64 x86_64

#include "../include/stopwatch.hpp"

//handle signals
static void	signalHandler(int signum)
{
	std::cout << "\b\b\n" << DEFAULT << std::flush;
	std::cout << GREY << "Interrupt signal (" << signum << ") received." << DEFAULT << std::endl;

	// cleanup and close up stuff here
	// terminate program

	exit(signum);
}

//add zeros where necessary
const char	*add_zero(int num)
{
	return (num < 10 ? "0" : "\0");
}

//output stopwatch
int	main(void)
{
	unsigned int seconds;
	unsigned int minutes;
	unsigned int hours;

	seconds = 0;
	minutes = 0;
	hours = 0;
	signal(SIGINT, signalHandler);
	while (true)
	{
		std::cout.flush() << "\r";
		std::cout << GREY << "> " << DEFAULT << BOLD << add_zero(hours) << hours;
		std::cout << ":" << add_zero(minutes) << minutes;
		std::cout << ":" << add_zero(seconds) << seconds;
		seconds++;
		if (seconds == 61)
		{
			if (minutes == 59)
			{
				std::cout << "\r";
				hours++;
				if (hours == 24)
					break ;
				else
				{
					std::cout << GREY << "> " << DEFAULT << BOLD << add_zero(hours) << hours;
					minutes = 0;
					std::cout << ":" << add_zero(minutes) << minutes;
					seconds = 0;
					std::cout << ":" << add_zero(seconds) << seconds;
					seconds++;
				}
			}
			else
			{
				std::cout << "\r";
				std::cout << GREY << "> " << DEFAULT << BOLD << add_zero(hours) << hours;
				minutes++;
				std::cout << ":" << add_zero(minutes) << minutes;
				seconds = 0;
				std::cout << ":" << add_zero(seconds) << seconds;
				seconds++;
			}
		}
		sleep(1);
	}
	std::cout << DEFAULT << "\r" << YELLOW << "the entire day has passed since the start of the stopwatch" << DEFAULT << std::endl;
	return (0);
}
