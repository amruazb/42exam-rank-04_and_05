#include "microshell.h"

int print_err(char *s)
{
	while(*s)
		write(2, s++,1);
	return 1;
}


int cd(char **av, int i)
{
	if(i != 2)
		return print_err("error: cd: bad arguments\n");
	else if(chdir(av[1]) == -1)
		return print_err("error: cannot change directory "), print_err(av[1]), print_err("\n");
	return 0;
}

int exec(char **av, char **envp, int i)
{
	int fd[2];
	int status;
	int has_pipe = av[i] && !strcmp(av[i], "|");

	if(!has_pipe && !strcmp(*av, "cd"))
		return cd(av, i);
	if(has_pipe && pipe(fd) == -1)
		return print_err("error: fatal\n");
	int pid = fork();
	if(!pid)
	{
		av[i] = 0;
		if(has_pipe && (dup2(fd[1],1) == -1 || close(fd[0]) == -1 || close(fd[1])))
			return print_err("error: fatal\n");
		if(!strcmp(*av, "cd"))
			return cd(av, i);
		execve(*av, av, envp);
		return print_err("error: cannot execute "), print_err(*av), print_err("\n");
	}
	waitpid(pid, &status, 0);
	if (has_pipe && (dup2(fd[0],0) == -1 || close(fd[0]) == -1 || close(fd[1])))
		return print_err("error: fatal\n");
	return WIFEXITED(status) && WEXITSTATUS(status);
}


int main(int ac, char **av,char **envp)
{
	int i = 0;
	int status = 0;

	if(ac > 1)
	{
		while(av[i] && av[++i])
		{
			av += i;
			i = 0;
			while(av[i] && strcmp(av[i], "|"), strcmp(av[i], ";"))
				i++;
			if(i)
				status = exec(av, envp, i);
		}
	}
	return status;
}

