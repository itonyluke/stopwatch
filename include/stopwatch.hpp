//Copyright 2021 Anton Pavlyukevich.

//This file is part of a stopwatch.
//
//stopwatch is free software: you can redistribute it and/or modify
//		it under the terms of the GNU General Public License as published by
//the Free Software Foundation, either version 3 of the License, or
//(at your option) any later version.
//
//stopwatch is distributed in the hope that it will be useful,
//but WITHOUT ANY WARRANTY; without even the implied warranty of
//MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//GNU General Public License for more details.
//
//You should have received a copy of the GNU General Public License
//along with stopwatch.  If not, see <https://www.gnu.org/licenses/>.

//
// Created by pavlyukevich.anton@gmail.com on 28.11.21
//

// built and tested on Darwin Kernel Version 18.7.0: Tue Jun 22 19:37:08 PDT 2021; root:xnu-4903.278.70~1/RELEASE_X86_64 x86_64

#ifndef STOPWATCH_HPP
# define STOPWATCH_HPP

# define BOLD "\033[97m"
# define DEFAULT "\033[0m"
# define GREY "\033[2m"
# define DARK_GREY "\033[90m"
# define YELLOW "\033[33m"

# include <iostream>
#ifdef _WIN32
# include <Windows.h>
# else
# include <unistd.h>
#endif

#endif //STOPWATCH_HPP
