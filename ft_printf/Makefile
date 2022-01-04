# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dokwak <dokwak@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/04 16:59:12 by dokwak            #+#    #+#              #
#    Updated: 2022/01/04 17:18:16 by dokwak           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
# Basic script for makefile
#
# target ... : prerequisites(or dependencies) ...
#	(tab)	recipe
# $@: target name
# %.o (%.c) is similar with *.o (*.c)
# $<: first file of dependencies list
# $^: the whole file list of dependencies
# $?: file list that touched latter than TARGERT
# $+: similiart with $^ but includes duplicates file name
# ar command options

# <c> : Create the archive.  The specified archive is always created if it did not exist, when you request an update.  But a warning is issued unless you specify in advance that you expect to create it, by using this modifier.

# <s> : Add an index to the archive, or update it if it already exists.  Note this command is an exception to the rule that there can only be one command letter, as it is possible to use it as either a command or a modifier.  In either case it does the same thing.

# <r> : Insert the files member... into archive (with replacement). This operation differs from q in that any previously existing members are deleted if their names match those being added.

#CC=<compiler>
#CFLAGS=<compiler option>
#LDFLAGS=<link option>
#LDLIBS=<list of link libraries>
#OBJS=<list of objects files>
#NAME=<name of target to build>
# 
#all: $(NAME)
#	 
#clean:
#	    rm -f *.o
#		    rm -f $(NAME)
#			 
#$(NAME): $(OBJS)
#	$(CC) -o $@ $(OBJS)
#
CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs

NAME = libftprintf.a
MANDATORY_PART = 	ft_printf


# SRCS (.c files)
SRCS = $(addsuffix .c, $(MANDATORY_PART))
SRCS_B = $(addsuffix .c, $(BONUS_PART))

# OBJS (.o files)
OBJS_MANDATORY = $(addsuffix .o, $(MANDATORY_PART))
OBJS_BONUS = $(addsuffix .o, $(BONUS_PART))

# OBJS script
# $@: target name
# %.o (%.c) is similar with *.o (*.c)
# $<: first file of dependencies list
.c.o: $(SRCS) $(SRCS_B)
	$(CC) $(CFLAGS) -c -o $@ $< 

ifdef WITH_BONUS
	OBJS = $(OBJS_MANDATORY) $(OBJS_BONUS)
else
	OBJS = $(addsuffix .o, $(MANDATORY_PART))
endif
#linking
$(NAME): $(OBJS)
	$(AR) $@ $^

# rules
all: $(NAME)

bonus:
	@make WITH_BONUS=1 all

clean :
	rm -f $(OBJS_MANDATORY) $(OBJS_BONUS)

fclean : clean
	rm -f $(NAME) $(OBJS_MANDATORY) $(OBJS_BONUS)
re : clean all

.PHONY : all clean fclean re bonus
