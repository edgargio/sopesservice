#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <time.h>

int main(int argc, char* argv[])
{
FILE *fp= NULL;
pid_t process_id = 0;
pid_t sid = 0;


process_id = fork();
 
if (process_id < 0)
{
printf("fork fallo!\n");
 
exit(1);
}
 
if (process_id > 0)
{
printf("process_id  %d \n", process_id);
 
exit(0);
}
 
umask(0);
// new session
sid = setsid();
if(sid < 0)
{
 
exit(1);
}

chdir("/");
// Close stdin. stdout and stderr
close(STDIN_FILENO);
close(STDOUT_FILENO);
close(STDERR_FILENO);


fp = fopen ("SistemaLog.txt", "a+");

time_t mytime;
mytime = time(NULL);

fprintf(fp, "inicio del sistema %s",ctime(&mytime));
fflush(fp);
printf("%s",ctime(&mytime));
fclose(fp);


while (1) {    
 sleep(15);
}

return (0);
}
