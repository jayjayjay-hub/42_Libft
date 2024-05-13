NAME		= libft
INCLUDE_DIR	= include/
INCLUDE		= -I $(INCLUDE_DIR)
SRC_DIR		= src/
OBJ_DIR		= .obj/
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
AR			= ar
ARFLAGS		= rcs
RM			= rm -rf
NORM		= norminette

LIBFT_DIR	= std_libft/

STDLIB_DIR	= stdlib/
STDLIB_SRC	=	ft_atoi.c\
				ft_calloc.c\
				ft_itoa.c\
				ft_abs.c

CTYPE_DIR	= ctype/
CTYPE_SRC	=	ft_isalnum.c\
				ft_isalpha.c\
				ft_isascii.c\
				ft_isdigit.c\
				ft_isprint.c\
				ft_isspace.c\
				ft_tolower.c\
				ft_toupper.c

MEM_DIR		= mem/
MEM_SRC		=	ft_bzero.c\
				ft_memchr.c\
				ft_memcmp.c\
				ft_memcpy.c\
				ft_memmove.c\
				ft_memset.c

STR_DIR		= str/
STR_SRC		=	ft_strjoin.c\
				ft_strnstr.c\
				ft_strchr.c\
				ft_strrchr.c\
				ft_strlcat.c\
				ft_strlcpy.c\
				ft_strmapi.c\
				ft_strlen.c\
				ft_strtrim.c\
				ft_substr.c\
				ft_strncmp.c\
				ft_strdup.c\
				ft_split.c\
				ft_striteri.c

FD_DIR		= fd/
FD_SRC		=	ft_putchar_fd.c\
				ft_putendl_fd.c\
				ft_putnbr_fd.c\
				ft_putstr_fd.c

LST_DIR		= lst/
LST_SRC		=	ft_lstadd_back.c\
				ft_lstadd_front.c\
				ft_lstclear.c\
				ft_lstdelone.c\
				ft_lstiter.c\
				ft_lstlast.c\
				ft_lstmap.c\
				ft_lstnew.c\
				ft_lstsize.c

LIBFT_SRC	+= $(addprefix $(STDLIB_DIR), $(STDLIB_SRC))
LIBFT_SRC	+= $(addprefix $(CTYPE_DIR), $(CTYPE_SRC))
LIBFT_SRC	+= $(addprefix $(MEM_DIR), $(MEM_SRC))
LIBFT_SRC	+= $(addprefix $(STR_DIR), $(STR_SRC))
LIBFT_SRC	+= $(addprefix $(FD_DIR), $(FD_SRC))
LIBFT_SRC	+= $(addprefix $(LST_DIR), $(LST_SRC))

GNL_DIR		= gnl/
GNL_SRC		= get_next_line.c        get_next_line_utils.c

FTPRINTF_DIR	= ft_printf/
FTPRINTF_SRC	= ft_printf.c      output.c         print_hex.c      print_ptr.c      unsigned_itoa.c

SRC_FILES 	+= $(addprefix $(LIBFT_DIR), $(LIBFT_SRC))
SRC_FILES 	+= $(addprefix $(GNL_DIR), $(GNL_SRC))
SRC_FILES 	+= $(addprefix $(FTPRINTF_DIR), $(FTPRINTF_SRC))

OBJ_FILES 	= $(SRC_FILES:%.c=%.o)

SRCS 		= $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJS 		= $(addprefix $(OBJ_DIR), $(OBJ_FILES))

Y 			= "\033[33m"
R 			= "\033[31m"
G 			= "\033[32m"
B 			= "\033[34m"
X 			= "\033[0m"
UP 			= "\033[A"
CUT 		= "\033[K"

all: ${NAME}

${NAME}: $(OBJ_DIR) ${OBJS}
	@echo $(B) "archiving" $(X)
	$(AR) $(ARFLAGS) ${NAME} ${OBJS}

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@echo $(Y) "compiling" $(X) $<
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
	@echo "\n"

$(OBJ_DIR):
	@echo $(G) "creating obj directory..." $(X)
	@mkdir $(OBJ_DIR)
	@mkdir $(OBJ_DIR)$(LIBFT_DIR)
	@mkdir $(OBJ_DIR)$(LIBFT_DIR)$(STDLIB_DIR)
	@mkdir $(OBJ_DIR)$(LIBFT_DIR)$(CTYPE_DIR)
	@mkdir $(OBJ_DIR)$(LIBFT_DIR)$(MEM_DIR)
	@mkdir $(OBJ_DIR)$(LIBFT_DIR)$(STR_DIR)
	@mkdir $(OBJ_DIR)$(LIBFT_DIR)$(FD_DIR)
	@mkdir $(OBJ_DIR)$(LIBFT_DIR)$(LST_DIR)
	@mkdir $(OBJ_DIR)$(GNL_DIR)
	@mkdir $(OBJ_DIR)$(FTPRINTF_DIR)
	@echo $(G) "obj directory created" $(X)
	@echo "\n"

clean:
	@echo $(R) "cleaning" $(X)
	${RM} ${OBJ_DIR}
	@echo "\n"

fclean:
	@echo $(R) "fcleaning" $(X)
	${RM} ${OBJ_DIR}
	${RM} ${NAME}
	@echo "\n"

re: fclean all

norm:
	@echo "↓↓↓ libft error count ↓↓↓"
	@norminette $(SRCS) $(INCLUDE_DIR) | grep Error | wc -l
	@norminette $(SRCS) $(INCLUDE_DIR) | grep Error || true

.PHONY : all bouns clean fclean re norm
