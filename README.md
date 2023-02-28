# minishell-resources

using history

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
