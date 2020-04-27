#include <stdio.h>
#include <stdlib.h>
#include <string>
int main(int argc, char *argv[])
{	
    if(argc == 1){
        printf("此程序可以解决在共享Windows目录下'ln'命令无法执行的问题。\n");
        printf("请把原始ln命令改名为ln_ori，然后把此程序更名为'ln'，代替原始ln命令文件即可。\n");
        return 0;
    }
	std::string cmd("/bin/ln_ori");
	std::string cp("cp");
	for (int i = 1; i < argc; i++)
	{
		cmd += " ";
		cmd += argv[i];
	}
	//printf("%s\n", cmd.c_str());
	int status = system(cmd.c_str());
    int execute_failed = 0;

    if (-1 == status)
    {
        execute_failed = 1;
    }
    else
    {
        if (WIFEXITED(status))
        {
            if (0 == WEXITSTATUS(status))
            {
                execute_failed = 0;
            }
            else
            {
                execute_failed = 1;
            }
        }
    }

    
    
    
    
	if(execute_failed){
		printf("execute ln failed.\nUse copy instead:");
		cp += " -f ";
		for (int i = argc-2; i <= argc-1; i++)
		{
			cp += " ";
			cp += argv[i];
		}
		printf("%s\n", cp.c_str());
		system(cp.c_str());
	}
	return 0;
}

