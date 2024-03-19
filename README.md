## mini-shell (bash like)

✅ **U CAN USE ON MAC OS**

⚠️ **not tested on LINUX**

📘 **[minishell LOG HERE!](https://maroon-face-0e4.notion.site/MiniShell-shell-process-fd-dup-signal-9c2ce3f3014341dfba5a89d328ff06d3?pvs=4)**

**[USAGE]**  
make -> ./minishell  

**[Features]**  
1. Display a prompt when waiting for a new command.  
.2 Have a working history.  
3. Search and launch the right executable  
(based on the PATH variable or using a relative or an absolute path).  
4. Not interpret unclosed quotes or special characters which are not required by the\ subject such as \ (backslash) or ; (semicolon).  
5. Handle ’ (single quote) which should prevent the shell from interpreting the metacharacters in the quoted sequence.  
6. Handle " (double quote) which should prevent the shell from interpreting the metacharacters in the quoted sequence except for $ (dollar sign).  
7. Implement pipes (| character). The output of each command in the pipeline is connected to the input of the next command via a pipe.  
8. Handle environment variables ($ followed by a sequence of characters) which should expand to their values.  
9. Handle $? which should expand to the exit status of the most recently executed foreground pipeline.  
10. Handle ctrl-C, ctrl-D and ctrl-\ which should behave like in bash.  
11. Built-in function: cd, echo, env, exit, export, pwd, unset  
<img width="776" alt="Screen Shot 2023-10-17 at 5 44 29 PM" src="https://github.com/044apde/minishell/assets/59429612/e43beaee-82cf-482d-a61c-cae15718518c">
