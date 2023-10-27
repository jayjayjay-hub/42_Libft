NAME = libft.a
INCLUDE = include
SRC_DIR = src/
OBJ_DIR = obj/
CC = cc
CFLAGS = -Wall -Wextra -Werror -I
ARFLAGS = rcs
ECHO = echo -e

FTIS_DIR	= ft_is/
FTIS		= ft_isalnum.c  ft_isalpha.c  ft_isascii.c  ft_isdigit.c  ft_isprint.c

FTMEM_DIR	= ft_mem/
FTMEM		= ft_bzero.c    ft_calloc.c   ft_memchr.c   ft_memcmp.c   ft_memcpy.c   ft_memmove.c  ft_memset.c

FTPUT_DIR	= ft_put/
FTPUT		= ft_putchar_fd.c  ft_putendl_fd.c  ft_putnbr_fd.c   ft_putstr_fd.c

FTTO_DIR	= ft_to/
FTTO		= ft_atoi.c     ft_itoa.c     ft_tolower.c  ft_toupper.c

FTSTR_DIR	= ft_str/
FTSTR		= ft_split.c     ft_strdup.c    ft_strjoin.c   ft_strlcpy.c   ft_strmapi.c   ft_strnstr.c   ft_strtrim.c \
				ft_strchr.c    ft_striteri.c  ft_strlcat.c   ft_strlen.c    ft_strncmp.c   ft_strrchr.c   ft_substr.c

FTLST_DIR	= ft_lst/
FTLST		= ft_lstadd_back.c   ft_lstclear.c      ft_lstiter.c       ft_lstmap.c        ft_lstsize.c \
				ft_lstadd_front.c  ft_lstdelone.c     ft_lstlast.c       ft_lstnew.c

GNL_DIR		= gnl/
GNL			= get_next_line.c        get_next_line_utils.c

FTPRINTF_DIR	= ft_printf/
FTPRINTF		= ft_printf.c      output.c         print_hex.c      print_ptr.c      unsigned_itoa.c

SRC_FILES += $(addprefix $(FTIS_DIR), $(FTIS))
SRC_FILES += $(addprefix $(FTMEM_DIR), $(FTMEM))
SRC_FILES += $(addprefix $(FTPUT_DIR), $(FTPUT))
SRC_FILES += $(addprefix $(FTTO_DIR), $(FTTO))
SRC_FILES += $(addprefix $(FTSTR_DIR), $(FTSTR))
SRC_FILES += $(addprefix $(FTLST_DIR), $(FTLST))
SRC_FILES += $(addprefix $(GNL_DIR), $(GNL))
SRC_FILES += $(addprefix $(FTPRINTF_DIR), $(FTPRINTF))

SRC += $(addprefix $(SRC_DIR), $(SRC_FILES))

OBJ = $((addprefix $(OBJ_DIR), $(SRC)):.c=.o)

all: ${NAME}

${NAME}: ${OBJ}
	$(AR) $(ARFLAGS) ${NAME} ${OBJ}

clean:
	${RM} ${OBJ} 

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY : all bouns clean fclean re
