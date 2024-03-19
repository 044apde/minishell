## mini-shell (bash like)

✅ U CAN USE ON MAC OS

⚠️ not tested on LINUX

<b>Display a prompt when waiting for a new command.</b>  

<b>Have a working historyy</b>  

<b>Search and launch the right executable (based on the PATH variable or using a relative or an absolute path).</b>  

<b>Not interpret unclosed quotes or special characters which are not required by the\ subject such as \ (backslash) or ; (semicolon).</b>  

<b>Handle ’ (single quote) which should prevent the shell from interpreting the metacharacters in the quoted sequence.</b>  

<b>Handle " (double quote) which should prevent the shell from interpreting the metacharacters in the quoted sequence except for $ (dollar sign).</b>  

<b>Implement pipes (| character). The output of each command in the pipeline is connected to the input of the next command via a pipe.</b>  

<b>Handle environment variables ($ followed by a sequence of characters) which should expand to their values.</b>  

<b>Handle $? which should expand to the exit status of the most recently executed foreground pipeline.</b>  

<b>Handle ctrl-C, ctrl-D and ctrl-\ which should behave like in bash.</b>  

<b>Built-in function</b>  
-cd  
-echo  
-env  
-exit  
-export  
-pwd  
-unset  

[dev log](https://maroon-face-0e4.notion.site/MiniShell-b7652a0e380240259411b837c9e862a0?pvs=4)

<img width="776" alt="Screen Shot 2023-10-17 at 5 44 29 PM" src="https://github.com/044apde/minishell/assets/59429612/e43beaee-82cf-482d-a61c-cae15718518c">
