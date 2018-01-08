NAME =  libftprintf.a
FLAGS = #-Wall -Werror -Wextra
LIBFT_OFILES = $(addprefix libft/, ft_strstr.o ft_strmap.o ft_lstadd.o ft_strdel.o ft_memccpy.o ft_strlen.o ft_putchar_fd.o \
			ft_strchr.o ft_tolower.o ft_strequ.o ft_isalnum.o ft_memmove.o ft_strdup.o ft_isalpha.o \
			ft_memset.o ft_strtrim.o ft_putendl.o ft_strncmp.o ft_memalloc.o ft_strnequ.o ft_lstdelone.o \
			ft_memchr.o ft_striter.o ft_bzero.o ft_memcpy.o ft_isdigit.o ft_memcmp.o ft_strsub.o ft_memdel.o \
			ft_strjoin.o ft_strcmp.o ft_strcpy.o ft_lstnew.o ft_putnbr.o ft_strncat.o ft_isascii.o \
			ft_itoa.o ft_lstmap.o ft_putstr.o ft_strlcat.o ft_putnbr_fd.o ft_strsplit.o ft_lstiter.o \
			ft_strcat.o ft_lstdel.o ft_putendl_fd.o ft_striteri.o ft_strnew.o ft_isprint.o ft_strnstr.o \
			ft_strclr.o ft_strncpy.o ft_putchar.o ft_putstr_fd.o ft_toupper.o ft_strmapi.o \
			ft_strrchr.o ft_strnew_tolower.o ft_strnew_toupper.o ft_printarr.o ft_isspace.o ft_lstsize.o \
			ft_putnchar.o ft_putnstr.o ft_atoi.o ft_putwchar.o ft_putwstr.o ft_utf8_bytelen.o \
			ft_putnwstr.o ft_wstrsize.o ft_itoa_base.o ft_uitoa_base.o ft_str_toupper.o ft_str_tolower.o)
PRINTF_OFILES = $(addprefix formats/, format_c.o format_p.o format_s.o format_d_i.o format_n.o format_o.o format_x.o \
			format_u.o format_b.o format_f.o) \
			ft_printf.o print_manager.o specificator_manager.o ft_chrin_str.o ft_printf_cast_unum.o
INCLUDES = -I ./includes

all: $(NAME)
$(NAME): $(LIBFT_OFILES) $(PRINTF_OFILES)
	@ar rc $(NAME) $(LIBFT_OFILES) $(PRINTF_OFILES)
	@ranlib $(NAME)
	@echo "\033[0;32mlib compiled.\033[0m "
%.o: %.c
	@gcc -o $@ -c $< $(FLAGS) $(INCLUDES)
clean:
	@rm -f $(LIBFT_OFILES) $(PRINTF_OFILES)
	@echo "\033[0;32mCLEANED\033[0m "
fclean: clean
	@rm -f $(NAME)
re:
	@make fclean
	@make
run:
	gcc main.c -L. -lftprintf && ./a.out | cat -e
