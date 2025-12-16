NAME				= so_long
FLAGS				= -Wall -Werror -Wextra
FSAN_FLAGS			= -fsanitize=address
LINK_FLAGS			= -L./minilibx-linux -lmlx -lX11 -lXext
LIBFT_A				= ./libft/libft.a
FILES_BONUS			= ./srcs/c_files_bonus/main.c\
					  ./srcs/c_files_bonus/get_player_infos.c\
					  ./srcs/c_files_bonus/map_magagement/get_map.c\
					  ./srcs/c_files_bonus/map_magagement/free_map.c\
					  ./srcs/c_files_bonus/map_magagement/allocate_map.c\
					  ./srcs/c_files_bonus/map_magagement/set_values_map.c\
					  ./srcs/c_files_bonus/map_magagement/get_map_hw.c\
					  ./srcs/c_files_bonus/map_magagement/check_ber_file.c\
					  ./srcs/c_files_bonus/map_magagement/check_map_borders.c\
					  ./srcs/c_files_bonus/map_magagement/check_map_obj.c\
					  ./srcs/c_files_bonus/map_magagement/errors_map.c\
					  ./srcs/c_files_bonus/error_management/errors.c\
					  ./srcs/c_files_bonus/pathfinding/pathfinding.c\
					  ./srcs/c_files_bonus/pathfinding/draw_map_pathfinding.c\
					  ./srcs/c_files_bonus/pathfinding/place_surrounding.c\
					  ./srcs/c_files_bonus/pathfinding/dupe_map.c\
					  ./srcs/c_files_bonus/image_manager.c\
					  ./srcs/c_files_bonus/image_destroy_all.c\
					  ./srcs/c_files_bonus/keyboard_input.c\
					  ./srcs/c_files_bonus/draw_management/draw_stats.c\
					  ./srcs/c_files_bonus/draw_management/draw_elements.c\
					  ./srcs/c_files_bonus/draw_management/draw_utils.c\
					  ./srcs/c_files_bonus/draw_management/draw_map.c
FILES			= ./srcs/c_files/main.c\
					  ./srcs/c_files/get_player_infos.c\
					  ./srcs/c_files/map_magagement/get_map.c\
					  ./srcs/c_files/map_magagement/free_map.c\
					  ./srcs/c_files/map_magagement/allocate_map.c\
					  ./srcs/c_files/map_magagement/set_values_map.c\
					  ./srcs/c_files/map_magagement/get_map_hw.c\
					  ./srcs/c_files/map_magagement/check_ber_file.c\
					  ./srcs/c_files/map_magagement/check_map_borders.c\
					  ./srcs/c_files/map_magagement/check_map_obj.c\
					  ./srcs/c_files/map_magagement/errors_map.c\
					  ./srcs/c_files/error_management/errors.c\
					  ./srcs/c_files/pathfinding/pathfinding.c\
					  ./srcs/c_files/pathfinding/place_surrounding.c\
					  ./srcs/c_files/pathfinding/dupe_map.c\
					  ./srcs/c_files/image_manager.c\
					  ./srcs/c_files/image_destroy_all.c\
					  ./srcs/c_files/keyboard_input.c\
					  ./srcs/c_files/draw_management/draw_stats.c\
					  ./srcs/c_files/draw_management/draw_elements.c\
					  ./srcs/c_files/draw_management/draw_utils.c\
					  ./srcs/c_files/draw_management/draw_map.c
PATH_MINILIBX		= ./minilibx-linux
PATH_LIBFT			= ./libft
MAKE_MINILIBX		= cd $(PATH_MINILIBX) && make
MAKE_LIBFT			= cd $(PATH_LIBFT) && make bonus

$(NAME): $(FILES)
	$(MAKE_MINILIBX)
	$(MAKE_LIBFT)
	cc $(FLAGS) $(FILES) -g $(LIBFT_A) $(LINK_FLAGS) -o $(NAME)

bonus: $(FILES_BONUS)
	$(MAKE_MINILIBX)
	$(MAKE_LIBFT)
	cc $(FLAGS) $(FILES_BONUS) -g $(LIBFT_A) $(LINK_FLAGS) -o $(NAME)

bonus-dont-draw:
	$(MAKE_MINILIBX)
	$(MAKE_LIBFT)
	cc -D DRAW_PATHFINDING=0 $(FLAGS) $(FILES_BONUS) -g $(LIBFT_A) $(LINK_FLAGS) -o $(NAME)

wof:
	$(MAKE_MINILIBX)
	$(MAKE_LIBFT)
	cc $(FILES) $(LIBFT_A) $(LINK_FLAGS) -o $(NAME)	

fsan:
	$(MAKE_MINILIBX)
	$(MAKE_LIBFT)
	cc $(FLAGS) $(FSAN_FLAGS) $(FILES) -g $(LIBFT_A) $(LINK_FLAGS) -o $(NAME)	

re:
	rm -rf $(NAME)
	$(MAKE_MINILIBX)
	$(MAKE_LIBFT)
	cc $(FLAGS) $(FILES) -g $(LIBFT_A) $(LINK_FLAGS) -o $(NAME)

clean:
	cd $(PATH_MINILIBX) && make clean
	cd $(PATH_LIBFT) && make clean

fclean:
	rm -rf $(NAME)
	cd $(PATH_MINILIBX) && make clean
	cd $(PATH_LIBFT) && make fclean
