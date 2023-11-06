NAME		= libft.a
INCLUDE		= include/
SRC_DIR		= src/
OBJ_DIR		= .obj/
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -I
ARFLAGS		= rcs
RM			= rm -rf
NORM		= norminette

LIBFT_DIR	= libft/
LIBFT_SRC	= ft_isalnum.c  ft_isalpha.c  ft_isascii.c  ft_isdigit.c  ft_isprint.c\
				ft_bzero.c    ft_calloc.c   ft_memchr.c   ft_memcmp.c   ft_memcpy.c   ft_memmove.c  ft_memset.c\
				ft_putchar_fd.c  ft_putendl_fd.c  ft_putnbr_fd.c   ft_putstr_fd.c\
				ft_atoi.c     ft_itoa.c     ft_tolower.c  ft_toupper.c\
				ft_split.c     ft_strdup.c    ft_strjoin.c   ft_strlcpy.c   ft_strmapi.c   ft_strnstr.c   ft_strtrim.c \
				ft_strchr.c    ft_striteri.c  ft_strlcat.c   ft_strlen.c    ft_strncmp.c   ft_strrchr.c   ft_substr.c\
				ft_lstadd_back.c   ft_lstclear.c      ft_lstiter.c       ft_lstmap.c        ft_lstsize.c \
				ft_lstadd_front.c  ft_lstdelone.c     ft_lstlast.c       ft_lstnew.c

GNL_DIR		= gnl/
GNL_SRC		= get_next_line.c        get_next_line_utils.c

FTPRINTF_DIR	= ft_printf/
FTPRINTF_SRC	= ft_printf.c      output.c         print_hex.c      print_ptr.c      unsigned_itoa.c

SRC_FILES 	+= $(addprefix $(LIBFT_DIR), $(LIBFT_SRC))
SRC_FILES 	+= $(addprefix $(GNL_DIR), $(GNL_SRC))
SRC_FILES 	+= $(addprefix $(FTPRINTF_DIR), $(FTPRINTF_SRC))

OBJ 		= $(SRC_FILES:%.c=%.o)

SRCS 		= $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJS 		= $(addprefix $(OBJ_DIR), $(OBJ))


all: $(OBJ_DIR) ${NAME}

${NAME}: ${OBJS}
	$(AR) $(ARFLAGS) ${NAME} ${OBJS}

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@ 

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)
	@mkdir $(OBJ_DIR)$(LIBFT_DIR)
	@mkdir $(OBJ_DIR)$(GNL_DIR)
	@mkdir $(OBJ_DIR)$(FTPRINTF_DIR)

clean:
	${RM} ${OBJ_DIR}

fclean: clean
	${RM} ${NAME}

re: fclean all

norm:
	@echo -n libft_norminette : 
	@norminette $(SRCS) $(INCLUDE) | grep Error || true
	@echo " finish"

.PHONY : all bouns clean fclean re norm
