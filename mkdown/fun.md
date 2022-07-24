## Functions
List of C function and new commands that i've learned.

| man | name          | function                                          | definition                                               |
| --- | ------------- | ------------------------------------------------- | -------------------------------------------------------- |
|  1  | **getlogin**  | get username                                      | `char *getlogin(void);`                                  |
|  3  | **getpid**    | get process identification                        | `pid_t getpid(void);`                                    |
|  3  | **getuid**    | get user identity                                 | `uid_t getuid(void);`                                    |
|  3  | **getpwuid**  | get password file entry                           | `struct passwd *getpwuid(uid_t uid);`                    |
|  3  | **perror**    | print a system error message                      | `void perror(const char *s);`                            |
|  3  | **fprintf**   | formatted output conversion                       | `int fprintf(FILE *stream, const char *format, ...);`    |
|  3  | **fwprintf**  | formatted wide-character output conversion        | `int fwprintf(FILE *stream, const wchar_t *format, ...);`|
|  3  | **setlocale** | set the current locale                            | `char *setlocale(int category, const char *locale);`     |
|  3  | **wcslen**    | determine the length of a wide-character string   | `size_t wcslen(const wchar_t *s);`                       |
|  3  | **time**      | get the current `time_t`                          | `time_t time (time_t *timer);`                           |
|  3  | **localtime** | converts the calendar time timep to broken-down   | `struct tm *localtime(const time_t *timep);`             |
|  3  | **asctime**   | converts the broken-down time value tm into a str | `char *asctime(const struct tm *tm);`                    |
|  3  | **fork**      | creates a new process                             | `pid_t fork(void);`                                      | 
|  3  | **sleep**     | suspend execution for an interval of time         | `unsigned int sleep(unsigned int seconds);`              |
|  3  | **chdir**     | change working directory                          | `int chdir(const char *path);`                           |
|  ?  | **strtok**    | extract tokens from strings                       | `char *strtok(char *str, const char *delim);` `#define N " \n\t"` | 
|  2  | **waitpid**   | wait for process to change state                  | `pid_t waitpid(pid_t pid, int *wstatus, int options);`   | 
|  ?  | **execvp**    | execute a command/file [?]                        | `int execvp(const char *file, char *const argv[])`       | 
|  2  | **read**      | read from a file descriptor                       | `ssize_t read(int fd, void *buf, size_t count);`         |
