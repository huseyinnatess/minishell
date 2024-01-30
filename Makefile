NAME = minishell
MKDIR = mkdir

CC = gcc

LIBFTP = libft/	
PATHB = build/
PATHO = build/objs/
PATHS = src/
PATHENVP = src/environment/
PATHSP = src/terminal/
PATHSB = src/command/
PATHSEX = src/parsers/
PATHSU = src/syntax/
PATHSE = src/variables/
PATHP = src/pipex/
PATHEX = src/executor/

BUILD_PATHS = $(PATHB) $(PATHO)

src	=	src/main.c \
		src/ft_signal_handler.c \
		src/display_prompt.c \
		src/environment/envp_lstcreate.c \
		src/environment/ft_split_envp.c \
		src/environment/init_envp.c \
		src/environment/free_envp.c \
		src/terminal/term_setting.c \
		src/terminal/term_fd.c \
		src/command/commands.c \
		src/command/command_utils.c \
		src/command/command_utils2.c \
		src/parsers/ft_get_quotes_values.c \
		src/syntax/syntax_error.c \
		src/syntax/ft_has_valid_quotes.c \
		src/syntax/ft_check_redir_syntax.c \
		src/syntax/ft_check_pipe_syntax.c \
		src/variables/ft_parsevar.c \
		src/variables/ft_check_var_rules.c \

OBJS	=	$(addprefix $(PATHO), $(notdir $(patsubst %.c, %.o, $(src))))

FLAGS	=	-Wall -Werror -Wextra -g #-fsanitize=address

LIBFT	=	libft/libft.a

HEADER	=	.inc/environment.h \
			.inc/minishell.h \

READLINE_DIR = /usr/local/opt/readline

READLINE_LIB = -lreadline -lhistory -L $(READLINE_DIR)/lib
	
inc =-Iinc -I$(PATHP) -I$(LIBFTP) -I$(READLINE_DIR)/include 

all: $(BUILD_PATHS) $(NAME)

$(PATHO)%.o:: $(PATHS)%.c
	@echo "Compiling ${notdir $<}			in	$(PATHS)"
	@$(CC) -c $(FLAGS) $(inc) $< -o $@

$(PATHO)%.o:: $(PATHENVP)%.c $(HEADERS)
	@echo "Compiling ${notdir $<}			in	$(PATHENVP)"
	@$(CC) -c $(FLAGS) $(inc) $< -o $@

$(PATHO)%.o:: $(PATHSP)%.c $(HEADERS)
	@echo "Compiling ${notdir $<}			in	$(PATHSP)"
	@$(CC) -c $(FLAGS) $(inc) $< -o $@

$(PATHO)%.o:: $(PATHSB)%.c $(HEADERS)
	@echo "Compiling ${notdir $<}			in	$(PATHSB)"
	@$(CC) -c $(FLAGS) $(inc) $< -o $@

$(PATHO)%.o:: $(PATHSEX)%.c $(HEADERS)
	@echo "Compiling ${notdir $<}			in	$(PATHSEX)"
	@$(CC) -c $(FLAGS) $(inc) $< -o $@

$(PATHO)%.o:: $(PATHSU)%.c $(HEADERS)
	@echo "Compiling ${notdir $<}			in	$(PATHSU)"
	@$(CC) -c $(FLAGS) $(inc) $< -o $@

$(PATHO)%.o:: $(PATHSE)%.c $(HEADERS)
	@echo "Compiling ${notdir $<}			in	$(PATHSE)"
	@$(CC) -c $(FLAGS) $(inc) $< -o $@

$(PATHO)%.o:: $(PATHEX)%.c $(HEADERS)
	@echo "Compiling ${notdir $<}			in	$(PATHEX)"
	@$(CC) -c $(FLAGS) $(inc) $< -o $@

$(NAME): $(LIBFT) $(OBJS) $(HEADERS)
	@$(CC) $(FLAGS) $(LIBFT) $(OBJS) $(READLINE_LIB) -o $(NAME)

	@echo "Success"

$(LIBFT):
	@$(MAKE) -C ./libft

$(PATHB):
	@$(MKDIR) $(PATHB)

$(PATHO):
	@$(MKDIR) $(PATHO)

clean:
	@echo "Cleaning"
	@rm -f $(OBJS)
	@rm -f $(PATHB).tmp*
	@rmdir $(PATHO) $(PATHB)
	@make fclean -C ./libft

fclean: clean
	@rm -f $(NAME)
	@rm -f $(LIBFT)

re: fclean all

.PRECIOUS: $(PATHO)%.o