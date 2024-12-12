int glob = 6;

char buf[] = “a write to stdout\n”;
int main(void)
{
    int var;
    pid_t pid;

    var = 88;
    write(STDOUT_FILENO, buf, sizeof(buf)-1);
    printf(“before fork\n”);
    
    if ((pid = fork()) == 0)
    {
        glob++; var++; /* child */
    }
    else
        sleep(2); /* parent */

     printf(“pid = %d, glob = %d, var = %d\n”, getpid(), glob, var);
     exit (0);
 }