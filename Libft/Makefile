# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dokwak <dokwak@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/09 01:09:18 by dokwak            #+#    #+#              #
#    Updated: 2021/11/18 01:43:25 by dokwak           ###   ########.fr        #
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

#CC=<컴파일러>
#CFLAGS=<컴파일 옵션>
#LDFLAGS=<링크 옵션>
#LDLIBS=<링크 라이브러리 목록>
#OBJS=<Object 파일 목록>
#TARGET=<빌드 대상 이름>
# 
#all: $(TARGET)
#	 
#clean:
#	    rm -f *.o
#		    rm -f $(TARGET)
#			 
#$(TARGET): $(OBJS)
#	$(CC) -o $@ $(OBJS)

CC = GCC 
CFLAGS = -Wall -Wextra Werror
AR = ar csr

TARGET = libft.a
MANDATORY_PART = 	ft_isalpha \
					ft_isdigit \
					ft_isalnum \
					ft_isascii \
					ft_isprint \
					ft_strlen \
#					ft_memset \
#					ft_bzero \
#					ft_memcpy \
#					ft_memmove \
#					ft_strlcpy \
#					ft_strlcat \
#					ft_toupper \
#					ft_tolower \
#					ft_strchr \
#					ft_strrchr \
#					ft_strncmp \
#					ft_memchr \
#					ft_memcmp \
#					ft_strnstr \
#					ft_atoi \
#					ft_calloc \
#					ft_strdup \
#					ft_substr \
#					ft_strjoin \
#					ft_strtrim \
#					ft_split \
#					ft_itoa \
#					ft_strmapi \
#					ft_striteri \
#					ft_putchar_fd \
#					ft_putstr_fd \
#					ft_putendl_fd \
#					ft_putnbr_fd \
#
#BONUS_PART = 	ft_lstnew \
#				ft_lstadd_front \
#				ft_lstsize \
#				ft_lstlast \
#				ft_lstadd_back \
#				ft_lstdelone \
#				ft_lstclear \
#				ft_lstiter \
#				ft_lstmap 

SRCS_DIR = ./
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(MANDATORY_PART)))
#SRCS_B = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(BONUS_PART)))

OBJS_DIR = ./
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(MANDATORY_PART)))
#OBJS_B = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(BONUS_PART)))


# compile and making object files
# %.o (%.c) is similar with *.o (*.c)
.c.o: $(SRCS)
	$(CC) $(CFLAGS) -c -o $@ $<

# linking
all: $(TARGET)

$(TARGET): $(OBJS)
	$(AR) $@ $^	

#bonus: $(OBJS_B)
	$(AR) $(NAME) $^

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(TARGET)

re : fclean all

.PHONY : all bonus clean fclean re
