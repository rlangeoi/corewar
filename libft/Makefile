# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rlangeoi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/08 18:25:56 by rlangeoi          #+#    #+#              #
#*   Updated: 2017/10/29 16:45:38 by                  ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

NAME = libft.a

################################################################################


CC			= gcc  
CFLAGS		= -Wall -Wextra -Werror
CPPFLAGS	= -Iinclude

COLOR		= \033[36m
FINCOLOR	= \033[0m

SPY			= 

################################################################################


SRC_PATH	= src

INC_PATH	= include

OBJ_PATH	= obj

SRC_NAME	= ft_atoi.c\
	  ft_atoi_base.c\
	  ft_bzero.c\
	  ft_isalnum.c\
	  ft_isalpha.c\
	  ft_isascii.c\
	  ft_isdigit.c\
	  ft_isprint.c\
	  ft_itoa.c\
	  ft_itoa_base.c\
	  ft_memalloc.c\
	  ft_memccpy.c\
	  ft_memchr.c\
	  ft_memcmp.c\
	  ft_memcpy.c\
	  ft_memdel.c\
	  ft_memndel.c\
	  ft_memmove.c\
	  ft_memset.c\
	  ft_putchar.c\
	  ft_putchar_fd.c\
	  ft_putendl.c\
	  ft_putendl_fd.c\
	  ft_putnbr.c\
	  ft_putnbr_fd.c\
	  ft_putstr.c\
	  ft_putstr_fd.c\
	  ft_strcat.c\
	  ft_strchr.c\
	  ft_strclr.c\
	  ft_strcmp.c\
	  ft_strcpy.c\
	  ft_strdel.c\
	  ft_strdup.c\
	  ft_strequ.c\
	  ft_striter.c\
	  ft_striteri.c\
	  ft_strjoin.c\
	  ft_strlcat.c\
	  ft_strlen.c\
	  ft_strmap.c\
	  ft_strmapi.c\
	  ft_strncat.c\
	  ft_strncmp.c\
	  ft_strncpy.c\
	  ft_strnequ.c\
	  ft_strnew.c\
	  ft_strnstr.c\
	  ft_strrchr.c\
	  ft_strsplit.c\
	  ft_strstr.c\
	  ft_strsub.c\
	  ft_strtrim.c\
	  ft_tolower.c\
	  ft_toupper.c\
	  ft_numlen.c\
	  ft_numlen_base.c\
	  ft_strrev.c\
	  ft_lstnew.c\
	  ft_lstdelone.c\
	  ft_lstdel.c\
	  ft_lstadd.c\
	  ft_lstiter.c\
	  ft_lstmap.c\
	  ft_lstsize.c\
	  ft_lstend.c\
	  ft_lstadd_end.c\
	  ft_lst_at.c\
	  ft_lstrm.c\
	  ft_power.c\
	  ft_sqrt.c\
	  ft_strlower.c\
	  ft_strupper.c\
	  ft_words.c\
	  ft_putnstr.c\
	  ft_putnstr_fd.c\
	  ft_putnwstr.c\
	  ft_putnwstr_fd.c\
	  ft_putunbr.c\
	  ft_putwchar.c\
	  ft_putwchar_fd.c\
	  ft_putwstr.c\
	  ft_putwstr_fd.c\
	  ft_wcharlen.c\
	  ft_wstrlen.c\
	  ft_nwstrlen.c\
	  ft_isdigitstr.c\
	  ft_printf.c\
	  ft_printf_parse.c\
	  ft_conv_d.c\
	  ft_conv_o.c\
	  ft_conv_x.c\
	  ft_conv_lx.c\
	  ft_conv_s.c\
	  ft_conv_c.c\
	  ft_conv_ls.c\
	  ft_conv_lc.c\
	  ft_conv_p.c\
	  ft_conv_per.c\
	  ft_conv_b.c\
	  ft_conv_u.c\
	  ft_ast.c\
	  get_next_line.c\



INC_NAME	=	ft_printf.h libft.h get_next_line.h

OBJ_NAME	= $(SRC_NAME:.c=.o)


################################################################################


SRC			= $(addprefix $(SRC_PATH)/,$(SRC_NAME))
INC			= $(addprefix $(INC_PATH)/,$(INC_NAME))
OBJ			= $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))


################################################################################


all: $(NAME)

$(OBJ_PATH): 
	$(SPY)mkdir $(OBJ_PATH) 2> /dev/null || true 

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(INC)
#	$(SPY)$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@ 
	$(SPY)$(CC) $(OPT) $(CFLAGS) $(CPPFLAGS) -c $< -o $@ 


$(NAME): $(OBJ_PATH) $(OBJ)
	$(SPY)ar rc $(NAME) $(OBJ)
	$(SPY)ranlib $(NAME)
	$(SPY)echo "$(COLOR)LIBFT\t\t\t[OK]$(FINCOLOR)"


clean:
	$(SPY)/bin/rm -rf $(OBJ)
	$(SPY)rmdir $(OBJ_PATH) 2> /dev/null || true
	$(SPY)echo "$(COLOR)LIBFT\t\t\tSuppression *.o$(FINCOLOR)"


fclean: clean
	$(SPY)/bin/rm -rf $(NAME)
	$(SPY)echo "$(COLOR)LIBFT\t\t\tSuppression libft.a$(FINCOLOR)"


re: fclean all


norme:
	$(SPY)echo "$(COLOR)\tNORMINETTE : LIBFT\n$(FINCOLOR)"
	$(SPY)norminette $(SRC)
	$(SPY)norminette include/*.h


.PHONY : all clean fclean re norme

################################################################################
