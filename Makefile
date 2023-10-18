NAME 		= pipex

define HEAD    
                                            
           /##                              
          |__/                              
  /######  /##  /######   /######  /##   /##
 /##__  ##| ## /##__  ## /##__  ##|  ## /##/
| ##  \ ##| ##| ##  \ ##| ######## \  ####/ 
| ##  | ##| ##| ##  | ##| ##_____/  /##  ## 
| #######/| ##| #######/|  ####### /##/\  ##
| ##____/ |__/| ##____/  \_______/|__/  \__/
| ##          | ##                          
| ##          | ##                          
|__/          |__/                          

endef
export HEAD

DEF_COLOR 	 = \033[0;39m
YELLOW		 = \033[0;93m
GREEN		 = \033[0;92m
BLUE 		 = \033[0;94m
CYAN		 = \033[0;96m
PURPLE		 = \033[0;35m
BOLD		 = \033[1m

FILES 		=	check_errors			\
				cmd_build				\
				exec					\
				free_all				\
				ft_in					\
				ft_putendl_fd			\
				ft_split				\
				ft_strncmp				\
				pipex					\

all: $(NAME)

SRCS_DIR = ./
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))

OBJS_DIR = ./
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))

%.o:%.c $(HEADER)
	@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@echo "\n$(GREEN)pipex successfuly compiled !$(DEF_COLOR)"
	@echo "$(PURPLE)$(BOLD)$$HEAD$(DEF_COLOR)"
	@${CC} ${FLAGS} ${SRCS} -o ${NAME}


clean:
	@$(RM) $(OBJS)
	@echo "$(CYAN)pipex object files cleaned!$(DEF_COLOR)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(CYAN)3$(DEF_COLOR)"
	@sleep 0.2
	@echo "$(CYAN)2$(DEF_COLOR)"
	@sleep 0.2
	@echo "$(CYAN)1$(DEF_COLOR)"
	@sleep 0.2
	@echo "$(GREEN)pipex executable files cleaned!$(DEF_COLOR)"


re: fclean all

.PHONY: all clean fclean re