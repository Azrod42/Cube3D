NAME	=   cub3D

LIBFTNAME = libft.a
LIBFTPATH = ./libft/

SRCS	=	srcs/main.c \
			srcs/parsing/pars_hub.c \
			srcs/parsing/pars_utils.c \
			srcs/parsing/ft_split_cb3d.c \
			srcs/parsing/pars_hub2.c \
			srcs/parsing/pars_hub3.c \
			srcs/parsing/ft_memchr_cb.c \
			srcs/parsing/ft_memcpy_cb.c \
			srcs/parsing/ft_strtrim_cb.c \
			srcs/parsing/pars_map_check.c \
			srcs/parsing/pars_map_check2.c \
			srcs/parsing/ft_strdup_cb.c \
			srcs/parsing/pars_blob.c \
			srcs/parsing/pars_blob2.c \
			srcs/exe/exe_hub.c \
			srcs/exe/raycasting.c \
			srcs/exe/input.c \
			srcs/exit-free.c \
			srcs/exe/minimap.c \
			srcs/exe/minimap2.c \
			srcs/ft_itoa_base_cub.c \
			srcs/ft_atoi_base.c \
			srcs/ft_strjoin_cub.c \
			srcs/exe/input_loop.c \
			srcs/exe/textures.c \
			srcs/exe/rc_2.c \
			srcs/exe/cast2.c \
			srcs/parsing/fix_pars.c \
			

SRCS_B =	srcs/main.c \
			srcs/parsing_bonus/pars_hub_bonus.c \
			srcs/parsing_bonus/pars_utils_bonus.c \
			srcs/parsing/ft_split_cb3d.c \
			srcs/parsing_bonus/pars_hub2_bonus.c \
			srcs/parsing_bonus/pars_hub3_bonus.c \
			srcs/parsing/ft_memchr_cb.c \
			srcs/parsing/ft_memcpy_cb.c \
			srcs/parsing/ft_strtrim_cb.c \
			srcs/parsing_bonus/pars_map_check_bonus.c \
			srcs/parsing_bonus/pars_map_check2_bonus.c \
			srcs/parsing/ft_strdup_cb.c \
			srcs/parsing_bonus/pars_blob_bonus.c \
			srcs/parsing_bonus/pars_blob2_bonus.c \
			srcs/exe/exe_hub.c \
			srcs/exe/raycasting.c \
			srcs/exe/input.c \
			srcs/exit-free.c \
			srcs/exe/minimap.c \
			srcs/exe/minimap2.c \
			srcs/ft_itoa_base_cub.c \
			srcs/ft_atoi_base.c \
			srcs/ft_strjoin_cub.c \
			srcs/exe/input_loop.c \
			srcs/exe/textures.c \
			srcs/exe/rc_2.c \
			srcs/exe/cast2.c \
			srcs/parsing/fix_pars.c \

INCLUDE = includes/cube3d.h \
			
OBJS	= $(SRCS:.c=.o)
OBJS_B	= $(SRCS_B:.c=.o)
RM	=		rm -f
CC	= gcc
FLAGS	= -Wall -Wextra -Werror
MLXFLAGS = -framework AppKit -framework OpenGL -lmlx -Imlx
INCS	= .

.c.o	:
	@echo "${_BOLD}${_BLUE}Making Cube3d > ${_END}${_YELLOW}${<:.c=.o}${_END}"
	@${CC} ${FLAGS} -c $< -o ${<:.c=.o} -I${INCS}

$(NAME)	: flag_use ${OBJS}
	@echo "${_BOLD}✅ ${_IGREEN}Cube3d > *.o Done${_END}"
	@make -C ${LIBFTPATH}
	${_STATUS1}
	@mv $(LIBFTPATH)${LIBFTNAME} ${LIBFTNAME}
	${_DONE}
	${_STATUS2}
	@${CC} ${FLAGS} ${MLXFLAGS} ${OBJS} ${LIBFTNAME} -o ${NAME}
	${_DONE}
	${_PRINTART1}
	${_USAGE}

all	: $(NAME)


bonus : flag_use $(OBJS_B)
	@echo "${_BOLD}✅ ${_IGREEN}Cube3d > *.o Done${_END}"
	@make -C ${LIBFTPATH}
	${_STATUS1}
	@mv $(LIBFTPATH)${LIBFTNAME} ${LIBFTNAME}
	${_DONE}
	make -C ${MLXPATH}
	mv $(MLXPATH)${MLXNAME} ${MLXNAME}
	${_STATUS2}
	@${CC} ${FLAGS} ${MLXFLAGS} ${OBJS_B} ${LIBFTNAME} ${MLXNAME} -o ${NAME}
	${_DONE}
	${_PRINTART1}
	${_USAGE}

re	: fclean all

ree	: all
	./cub3D maps/small.cub
clean:
	${_STATUS3}
	@rm -rf *.o
	${_DONE}
	@sleep 0.5

fclean: clean
	${_STATUS4}
	@make fclean -C ${LIBFTPATH}
	${_DONE}
	${_STATUS5}
	@rm -rf $(OBJS) $(OBJS_B) $(LIBFTNAME) $(NAME)
	${_DONE}
	@sleep 1

mclean: clean
	${_STATUS6}	
	@rm -rf $(OBJS) $(LIBFTNAME) $(NAME)
	${_DONE}

norm :
	norminette -R CheckForbidenHeader

git_add : 
	git add $(SRCS) $(SRCS_B) Makefile ${LIBFTPATH}*.c ${LIBFTPATH}*.h ${LIBFTPATH}Makefile includes/*
	git status

git_push:
	@git commit -m "Autopush Makefile"
	@git push origin master

git_master: git_add git_push

flag_use:
	@echo "${_BOLD}${_BLUE}============================= FLAGS USE =============================${_END}"
	@echo "${_BOLD}${_RED}\t\t      ${FLAGS}${_END}"
	@echo "${_BOLD}${_BLUE}=====================================================================${_END}"

#-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
# This is a minimal set of ANSI/VT100 color codes
_END=$'\x1b[0m
_BOLD=$'\x1b[1m
_UNDER=$'\x1b[4m
_REV=$'\x1b[7m

# Colors
_GREY=$'\x1b[30
_RED=$'\x1b[31m
_GREEN=$'\x1b[32m
_YELLOW=$'\x1b[33m
_BLUE=$'\x1b[34m
_PURPLE=$'\x1b[35m
_CYAN=$'\x1b[36m
_WHITE=$'\x1b[37m

# Inverted, i.e. colored backgrounds
_IGREY=$'\x1b[40m
_IRED=$'\x1b[41m
_IGREEN=$'\x1b[42m
_IYELLOW=$'\x1b[43m
_IBLUE=$'\x1b[44m
_IPURPLE=$'\x1b[45m
_ICYAN=$'\x1b[46m
_IWHITE=$'\x1b[47m
#-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

_DONE=@echo "${_BOLD}✅ ${_IGREEN}Done${_END}"
_STATUS1=@echo "${_BOLD}${_BLUE}Moving libft.a to > ${_END}${_YELLOW}${INCS}/${_END}" && sleep 0.5
_STATUS2=@echo "${_BOLD}${_BLUE}Making > ${_END}${_YELLOW} ${NAME}${_END}" && sleep 0.5
_STATUS3=@echo "${_BOLD}${_BLUE}Removing > ${_END}${_YELLOW}$(OBJS) $(OBJS_B) ${LIBFTNAME}${_END}" && sleep 0.5
_STATUS4=@echo "${_BOLD}${_BLUE}fclean >${_END}${_YELLOW}${LIBFTNAME}${_END}" && sleep 0.5
_STATUS5=@echo "${_BOLD}${_BLUE}Removing > ${_END}${_RED}$(LIBFTNAME) ${_GREEN}$(NAME) ${_CYAN}${LIBFTPATH}${_YELLOW} $(OBJS)${_END}" && sleep 0.5
_STATUS6=@echo "${_BOLD}${_BLUE}Removing > ${_END}${_YELLOW} $(OBJS) $(LIBFTNAME) $(NAME) ${_END}" && sleep 0.5
_STATUS7=@echo "${_BOLD}${_BLUE}GIT ADD : ${SRCS} ${INCLUDE} ${LIBFTPATH}*.c ${LIBFTPATH}*.h ${LIBFTPATH}Makefile Makefile misc/* ${_END}" && sleep 0.5
_STATUS8=@echo "${_BOLD}${_BLUE}GIT COMMIT ...${_END}" && sleep 0.5
_STATUS9=@echo "${_BOLD}${_BLUE}GIT PUSH ...${_END}" && sleep 0.5

.PHONY	: all fclean re .c.o clean norm
