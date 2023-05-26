#parameters====================================================================

CC		= cc
AR		= ar
ARFLAGS	= crs
CFLAGS	= -Wall -Wextra -Werror

NAME	= fdf
INCLUDE	= includes/



#libraries=====================================================================

LIBS	= libft
B_LIBS	= libft_bonus
ARCH	= ft
B_ARCH	= ft_bonus

LIBFT	= libft/libft.a
LIBFT_B	= libft_bonus/libft_bonus.a



#sources=======================================================================

SRCS	= srcs/main.c \
		  srcs/are_there_errors_in_args.c \
		  srcs/are_there_errors_in_args/check_input_data.c \
		  srcs/are_there_errors_in_args/compare_character.c \
		  srcs/errors.c \
		  srcs/parse_the_map_file.c \
		  srcs/parse_the_map_file/convert_line_feed_to_space.c \
		  srcs/parse_the_map_file/get_min_max_value.c \
		  srcs/parse_the_map_file/release_points.c \
		  srcs/run_mlx.c \
		  srcs/run_mlx/color.c \
		  srcs/run_mlx/color_mix.c \
		  srcs/run_mlx/create_dist_index.c \
		  srcs/run_mlx/draw_lines.c \
		  srcs/run_mlx/ft_abs.c \
		  srcs/run_mlx/hooks.c \
		  srcs/run_mlx/hooks/apply_new_pov.c \
		  srcs/run_mlx/hooks/field_of_view.c \
		  srcs/run_mlx/hooks/reset_settings.c \
		  srcs/run_mlx/hooks/rotate_view.c \
		  srcs/run_mlx/hooks/set_colormap.c \
		  srcs/run_mlx/hooks/set_colormap/colormap.c \
		  srcs/run_mlx/hooks/set_colormap/colormap2.c \
		  srcs/run_mlx/hooks/shift_view.c \
		  srcs/run_mlx/hooks/z_ratio.c \
		  srcs/run_mlx/hooks/zoom.c \
		  srcs/run_mlx/mlx_img.c \
		  srcs/run_mlx/refresh_centroid.c \
		  srcs/run_mlx/refresh_dist_index.c \
		  srcs/run_mlx/refresh_view_point.c \
		  srcs/run_mlx/vector.c \
		  srcs/run_mlx/vector2.c \
		  srcs/run_mlx/write_dots_info.c \
		  srcs/run_mlx/write_proj_info.c

B_SRCS	=

OBJS	= $(SRCS:.c=.o)
B_OBJS	= $(B_SRCS:.c=.o)




ifdef BONUS
	TARGET_OBJS = $(B_OBJS)
	TARGET_LIB = $(LIBFT_B)
	TARGET_LIBS = $(B_LIBS)
	TARGET_ARCH = $(B_ARCH)
else
	TARGET_OBJS = $(OBJS)
	TARGET_LIB = $(LIBFT)
	TARGET_LIBS = $(LIBS)
	TARGET_ARCH = $(ARCH)
endif

#rules=========================================================================

.PHONY: all
all :
	make $(NAME)

$(NAME) : $(TARGET_LIB) $(TARGET_OBJS)
	$(CC) -o $@ $(TARGET_OBJS) $(foreach lib, $(TARGET_LIBS), -L$(lib)) $(foreach arch, $(TARGET_ARCH), -l$(arch)) -L. -lmlx


$(LIBFT) :
	make -C libft

$(LIBFT_B) :
	make -C libft_bonus



.PHONY: bonus
bonus :
	make BONUS=0 $(NAME)

#const options=================================================================

%.o : %.c
	$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o $@

.PHONY: clean
clean :
	$(foreach lib, $(LIBS), make fclean -C $(lib);)
	$(foreach lib, $(B_LIBS), make fclean -C $(lib);)
	rm -f $(OBJS) $(B_OBJS)

.PHONY: fclean
fclean :
	make clean
	rm -f $(NAME)

.PHONY: re
re :
	make fclean
	make all
