CC			= c++ -Wall -Wextra -Werror -std=c++98
RM			= rm -rf
NAME		=	Bureaucratie

GREEN		=	\033[1;32m
RED			=	\033[1;31m
DEFAULT		=	\033[0m

OBJ_DIR		=	objs
SRC_DIR		=	$(shell find srcs -type d)
INC_DIR		=	$(shell find includes -type d)

vpath %.cpp $(foreach dir, $(SRC_DIR), $(dir):)
vpath %.hpp $(foreach dir, $(INC_DIR), $(dir):)

SRCS		=	main.cpp					\
				Bureaucrat.cpp				\
				AForm.cpp					\
				ShrubberyCreationForm.cpp	\
				RobotomyRequestForm.cpp		\
				PresidentialPardonForm.cpp


OBJS		=	$(SRCS:%.cpp=${OBJ_DIR}/%.o)

all:	${NAME}

$(NAME): ${OBJS} ${INC_DIR}
		@${CC} ${CFLAGS} ${OBJS} -I ${INC_DIR} -o ${NAME}
		@echo "Bureaucratie compiling finished!"

$(OBJ_DIR)/%.o: %.cpp ${INC_DIR} | $(OBJ_DIR)
		@$(CC) $(CFLAGS) -c $< -o $@ -I ${INC_DIR}

$(OBJ_DIR) :
		@mkdir -p $@

clean:
		@${RM} $(OBJS)

fclean:		clean
		@${RM} ${NAME}
		@echo "Everything cleaned"

re:			clean all

.PHONY:		all clean fclean re