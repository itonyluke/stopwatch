#Copyright 2021 Anton Pavlyukevich.
#
#This file is part of a stopwatch.
#
#Stopwatch is free software: you can redistribute it and/or modify
#it under the terms of the GNU General Public License as published by
#the Free Software Foundation, either version 3 of the License, or
#(at your option) any later version.
#
#Stopwatch is distributed in the hope that it will be useful,
#but WITHOUT ANY WARRANTY; without even the implied warranty of
#MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#GNU General Public License for more details.
#
#You should have received a copy of the GNU General Public License
#along with stopwatch.  If not, see <https://www.gnu.org/licenses/>.
#
#
# Created by pavlyukevich.anton@gmail.com on 15.12.21
#
#
# built and tested on Darwin Kernel Version 18.7.0: Tue Jun 22 19:37:08 PDT 2021; root:xnu-4903.278.70~1/RELEASE_X86_64 x86_64

SOURCES						:=	$(wildcard sources/*.cpp)

OBJECTS						:=	$(SOURCES:.cpp=.o)

HEADERS						:=	./include/stopwatch.hpp

COMPILER					:=	clang++

REMOVE_DIRECTORY_ENTRIES	:=	rm -f

COMPILE_FLAGS				:=	-Wall -Wextra -Werror -std=c++98 -pedantic-errors -I

PROGRAM_NAME				:=	stopwatch

JIC_A_OUT					:=	a.out

%.o: %.cpp
								$(COMPILER) $(COMPILE_FLAGS) $(HEADERS) -c $< -o ${<:.cpp=.o}

all:							$(PROGRAM_NAME)

$(PROGRAM_NAME):				$(OBJECTS)
								$(COMPILER) $(COMPILE_FLAGS) $(HEADERS) $(OBJECTS) -o $(PROGRAM_NAME)

$(OBJECTS):						$(HEADERS)

clean:
								$(REMOVE_DIRECTORY_ENTRIES) $(OBJECTS) $(JIC_A_OUT)

fclean:							clean
								$(REMOVE_DIRECTORY_ENTRIES) $(PROGRAM_NAME)

re:								fclean $(PROGRAM_NAME)

.PHONY:							all clean fclean re test
