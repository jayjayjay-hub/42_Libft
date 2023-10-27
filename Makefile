NAME = libft.a
INCLUDE = include/
SRC_DIR = src/
OBJ_DIR = .obj/
CC = cc
CFLAGS = -Wall -Wextra -Werror -I
ARFLAGS = rcs
ECHO = echo -e
RM = rm -rf

#Colors

DEF_COLOR	=	\033[0;39m
ORANGE		=	\033[0;33m
GRAY		=	\033[0;90m
RED			=	\033[0;91m
GREEN		=	\033[1;92m
YELLOW		=	\033[1;93m
BLUE		=	\033[0;94m
MAGENTA		=	\033[0;95m
CYAN		=	\033[0;96m
WHITE		=	\033[0;97m

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

SRC_FILES += $(addprefix $(LIBFT_DIR), $(LIBFT_SRC))
SRC_FILES += $(addprefix $(GNL_DIR), $(GNL_SRC))
SRC_FILES += $(addprefix $(FTPRINTF_DIR), $(FTPRINTF_SRC))

OBJ = $(SRC_FILES:%.c=%.o)

SRCS = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJS = $(addprefix $(OBJ_DIR), $(OBJ))

OBJD = .obj

# SRC 		= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
# OBJ 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

# .c.o:
# 	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

all: $(OBJD) ${NAME}

${NAME}: ${OBJS}
	$(AR) $(ARFLAGS) ${NAME} ${OBJS}

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJD)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@ 

$(OBJD):
	mkdir $(OBJ_DIR)
	mkdir $(OBJ_DIR)$(LIBFT_DIR)
	mkdir $(OBJ_DIR)$(GNL_DIR)
	mkdir $(OBJ_DIR)$(FTPRINTF_DIR)

clean:
	${RM} ${OBJ_DIR}
	$(RM) $(OBJD) 

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY : all bouns clean fclean re
