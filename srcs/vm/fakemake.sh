gcc -Wall -Wextra -Werror -g -o corewar \
	main.c\
	debug.c\
	error.c\
	check_data.c\
	init_vm.c\
	utils.c\
	parsing.c\
	parse_champs.c\
	create_processes.c\
	load_processes.c\
	vm_loop.c\
	process.c\
	op.c\
	../../libft/libft.a
