CC			=	gcc

NAMESER		= 	serveur
NAMECLI		= 	client
NAMELIB		= 	libft.a

OBJDIRSER	= 	./objs_server/
OBJDIRCLI	= 	./objs_client/
SRCDIRSER	= 	./srcs_server/
SRCDIRCLI	= 	./srcs_client/
LIBDIR		= 	./libft/
INCDIR		= 	./includes/

SRCSER		=	server.c \
				check_fd.c \
				client_read.c \
				client_write.c \
				close_connection.c \
				get_opt.c \
				init_env.c \
				init_serv.c \
				main_loop.c \
				reset_fd.c \
				debug_serv.c \
				srv_accept.c \
				srv_create.c

SRCCLI		=	client.c \
				usage.c \
				init_client.c \
				main_loop.c \
				init_fd.c \
				check_fd.c \
				read_fd.c \
				read_stdin.c

INCLUDES	=	-I$(INCDIR)
LIBFT		=	-L$(LIBDIR) -lft
CFLAGS		=	-Wall -Wextra -Werror -g $(INCLUDES)

OBJSSER		=	$(patsubst %.c,$(OBJDIRSER)%.o,$(SRCSER))
OBJSCLI		=	$(patsubst %.c,$(OBJDIRCLI)%.o,$(SRCCLI))

all: $(NAMELIB) $(NAMESER) $(NAMECLI)
$(OBJDIRCLI)%.o: $(SRCDIRCLI)%.c
	@mkdir -p $(OBJDIRCLI)
	$(CC) $(CFLAGS) -o $@ -c $<

$(OBJDIRSER)%.o: $(SRCDIRSER)%.c
	@mkdir -p $(OBJDIRSER)
	$(CC) $(CFLAGS) -o $@ -c $<

$(NAMELIB):
	@make -C $(LIBDIR)

$(NAMESER): $(OBJSCOM) $(OBJSSER)
	$(CC) -o $(NAMESER) $(INCLUDES) $(OBJSSER) $(LIBFT) $(CFLAGS)

$(NAMECLI): $(OBJSCOM) $(OBJSCLI)
	$(CC) -o $(NAMECLI) $(INCLUDES) $(OBJSCLI) $(LIBFT) $(CFLAGS)

clean:
	@rm -rf $(OBJDIRSER)
	@rm -rf $(OBJDIRCLI)
	@make -C $(LIBDIR) clean

fclean: clean
	@rm -f $(NAMESER)
	@rm -f $(NAMECLI)
	@make -C $(LIBDIR) fclean

re: fclean all

.PHONY: clean fclean re all
