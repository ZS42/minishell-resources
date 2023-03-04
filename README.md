# minishell-resources
FOR WAIT
https://www.geeksforgeeks.org/wait-system-call-c/

The wait4() subroutine is similar to the wait3() subroutine except that we can specify the process ID of the child. The wait3() subroutine waits for any child process but the wait4() subroutine can wait for a specific child process.

FOR USING HISTORY

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<readline/readline.h>
#include<readline/history.h>

enum { MAXC = 128 };

int main (void){

    char ps[MAXC] = "", 
        *p = getenv("USER"),
        *host = getenv("HOSTNAME"),
        *s = NULL; 
    int count = 1;
    sprintf(ps, "%d %s@%s> ", count, p, host);

    using_history();    /* initialize history */

    while ((s = readline(ps))) {
        if (strcmp (s, "quit") == 0) {
            free (s);
            break;
        }
        add_history (s);
        free (s);
        count++;
        sprintf (ps, "%d %s@%s> ", count, p, host);
    }

    /* get the state of your history list (offset, length, size) */
    HISTORY_STATE *myhist = history_get_history_state ();
    
    FOR READLINE REDISPLAY
    Function: int rl_redisplay ()

    Change what's displayed on the screen to reflect the current contents of rl_line_buffer

   Notes 
   
   ./minishell goes to prompt for your shell using readline
   
   add history stores history and automatically can use arrows to go back and forth.
   
   write these built ins yourself
   
   echo with -n option;
   
    echo $? gives exit status of last closed process
    
    echo $? +$?
    
    0 + 0
    
   cd with only a relative or absolute path;
   
    (absolute path /bin
    
        relative path bin)
        
    cd . stays
    
    cd .. goes one out
    
   pwd;
   
   export;
   
    export inserts into env
    
    export a = aaa
    
    then a = aaa will be in env
    
    if export a = aaa b = bbb
    
    then
    
        a =aaa
        
        b = bbb
        
    will be at end of env
    
   unset;
   
     unset removes from env
     
     unset a 
     
     will remove it from env
     
    
    both export and unset can do multiple variables and values
    
   env;
   
    env is our copy of env
    
   exit;
   
   (only one number acceptable to exit
   
   exit means come out of shell)
   
    
   crash = segfault
   
   
    
   ctrl / dos nothing in parent but in child cat ^\ quit 3
   
   child takes you out of shell
   
    
   ctrl C returns prompt
   
   if command then in child
   
    
    when "" or '' acts as if a single command inside
    
    
    when double quote
    
    echo "$USER > name"
    
    name
    
    ie interpreted
    
    
    when single quote
    
    echo 'USER > name'
    
    $USER
    
    not interpreted
    
     
     
    echo yes > a > b
    
     yes will be in b . a will be created but empty
     
    
    ls -la > a > c > d > e
    
     only e will have ls -la in it
     
  ** order of options doesnt matter ls -la == ls -al
  
  
  << for here doc and followed by delimiter. Will print till delimiter
  
  
  <<a
      
  -> df
    
  -> gh
    
  -> a
    
    
 df
    
 gh
    
    
 here delimiter is a so prints till a
    
  
    
    
    
    
    
    
   
   
   /* retrieve the history list */
    HIST_ENTRY **mylist = history_list ();

    printf ("\nsession history for %s@%s\n\n", p, host);
    for (int i = 0; i < myhist->length; i++) { /* output history list */
        printf (" %8s  %s\n", mylist[i]->line, mylist[i]->timestamp);
        free_history_entry (mylist[i]);     /* free allocated entries */
    }
    putchar ('\n');

    free (myhist);  /* free HIST_ENTRY list */
    free (mylist);  /* free HISTORY_STATE   */

    return 0;
}
Example Use/Output

$ ./bin/readline

1 david@alchemy> command 1

2 david@alchemy> command 2

3 david@alchemy> command 3

4 david@alchemy> quit

session history for david@alchemy

 command 1
 command 2
 command 3
 
 ![image](https://user-images.githubusercontent.com/82111543/221842357-78a06cf1-9382-4210-a349-624b395b9bd5.png)
 
 FOR EXIT AND BONUS
 https://linuxize.com/post/bash-exit/
