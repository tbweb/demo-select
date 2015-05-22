# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: btournoi <btournoi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/06/10 14:15:06 by btournoi          #+#    #+#              #
#    Updated: 2014/06/10 14:30:04 by btournoi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: btournoi <btournoi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/02 13:17:01 by btournoi          #+#    #+#              #
#    Updated: 2014/06/10 14:14:43 by btournoi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	gcc

NAME		=	libft.a

INCLUDES	=	-I./includes/

CFLAGS		=	-Wall -Wextra -Werror -g $(INCLUDES)

SRCDIR		=	./srcs/

OBJDIR		=	./objs/

SRC			=	ft_tputchar.c \
				ft_memset.c \
				ft_bzero.c \
				ft_memcpy.c \
				ft_memccpy.c \
				ft_memmove.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_strlen.c \
				ft_strdup.c \
				ft_strndup.c \
				ft_strcpy.c \
				ft_strncpy.c \
				ft_strcat.c \
				ft_strncat.c \
				ft_strlcat.c \
				ft_strchr.c \
				ft_strrchr.c \
				ft_strstr.c \
				ft_strnstr.c \
				ft_strcmp.c \
				ft_atoi.c \
				ft_isalpha.c \
				ft_isdigit.c \
				ft_isalnum.c \
				ft_isascii.c \
				ft_toupper.c \
				ft_toupper.c \
				ft_tolower.c \
				ft_strncmp.c \
				ft_isprint.c \
				ft_putstr.c \
				ft_putchar.c \
				ft_putnbr.c \
				ft_putnbr_uint.c \
				ft_putnbr_double.c \
				ft_memalloc.c \
				ft_memdel.c \
				ft_strnew.c \
				ft_strdel.c \
				ft_strclr.c \
				ft_striter.c \
				ft_striteri.c \
				ft_strequ.c \
				ft_strnequ.c \
				ft_putstr_fd.c \
				ft_putchar_fd.c \
				ft_putnbr_fd.c \
				ft_putendl_fd.c \
				ft_putendl.c \
				ft_strsub.c \
				ft_strjoin.c \
				ft_strtrim.c \
				ft_strsplit.c \
				ft_wordsplit.c \
				ft_strsplitslash.c \
				ft_strsplit_not_quote.c \
				ft_itoa.c \
				ft_strmap.c \
				ft_strmapi.c \
				ft_stronlydigit.c \
				ft_strsignanddigit.c \
				ft_lstnew.c \
				ft_lstadd.c \
				ft_lstendadd.c \
				ft_lstnextadd.c \
				ft_lstdelone.c \
				ft_lstdel.c \
				ft_lstiter.c \
				ft_lstmap.c \
				ft_delnodecontent.c \
				ft_putlst.c \
				ft_putlstsize.c \
				ft_tabcpy.c \
				ft_tabncpy.c \
				ft_tabnew.c \
				ft_puttab.c \
				ft_tabdup.c \
				ft_tablen.c \
				ft_tabdel.c \
				ft_tabdelline.c \
				ft_tabaddstr.c \
				ft_chrset.c \
				ft_strrev.c \
				ft_ismemchr.c \
				ft_memchrlen.c \
				ft_memjoin.c \
				ft_free_t_line.c \
				ft_verif_occurrence.c \
				ft_hexstrtoi.c \
				ft_insert_char_in_str.c \
				ft_ishexa.c \
				ft_isnalpha.c \
				ft_strhexa.c \
				ft_isstrint.c \
				ft_pow.c \
				ft_atob.c \
				ft_atoui.c \
				ft_btoa.c \
				ft_btoi.c \
				ft_ctobtoa.c \
				ft_itoa_long.c \
				get_next_line.c \
				ft_abs.c


OBJS = $(patsubst %.c,$(OBJDIR)%.o,$(SRC))

$(OBJDIR)%.o: $(SRCDIR)%.c
	@$(CC) $(CFLAGS) -o $@ -c $<

all: $(NAME)

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "Libft created"

clean:
	@/bin/rm -f $(OBJS)
	@echo ".o file Libft delete"

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "Binary libft delete"


re: fclean all

.PHONY: clean fclean re all
