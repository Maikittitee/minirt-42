NAME	:= minirt

CC	:= cc
CFLAGS	:= 

LIB_DIR	:= ./lib/

RENDER_DIR = src/render/

RENDER_FILE	:= main.c \
				renderer.c \
				math.c \
				img.c \
				viewport.c\
				sphere.c\
				color.c\
				object.c\
				plane.c\
				key.c\
				amb.c\
				cylinder.c\
				math2.c\
				dot.c

PARSER_DIR = src/parser/

PARSER_FILE	= ft_checkfile.c \
				ft_print.c \
				ft_print_util.c \
				ft_cnt.c\
				ft_free.c\
				ft_checkformat.c \
				ft_format_obj.c \
				ft_format_obj_util.c \
				ft_checkfmt_util.c \
				ft_assign_obj.c \
				ft_assign_obj_util.c \
				ft_assign_util.c \
				ft_atof.c \
				ft_atorgb.c \


SRCS := $(addprefix $(RENDER_DIR), $(RENDER_FILE)) \
		$(addprefix $(PARSER_DIR), $(PARSER_FILE))
OBJS	:= $(SRCS:.c=.o)

LIBFT_DIR	:= $(LIB_DIR)libft_gnl
LIBFT	:= $(LIBFT_DIR)libft.a

MLX_DIR	:= $(addprefix $(LIB_DIR), mlx/)
MINILIBX	:= $(MLX_DIR)libmlx.a

FRAME_W	:= -framework OpenGL -framework AppKit

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(MLX_DIR)
	@make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(OBJS) $(MINILIBX) -I$(LIBFT_DIR)\
		-L$(LIBFT_DIR) -L$(MLX_DIR) -lft -lmlx $(FRAME_W) -o $(NAME)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean
	rm -f $(PARSER_DIR)/*.o
	rm -f $(RENDER_DIR)/*.o
	rm -f *.o

fclean:	clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
