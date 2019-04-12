/*
** EPITECH PROJECT, 2019
** .
** File description:
** .
*/


#ifndef MY_H_
# define MY_H_

#define BUFF_SIZE 512

typedef struct s_list
{
    char *data;
    struct s_list *next;
    struct s_list *prev;
}t_list;

typedef struct word
{
    int i;
    int z;
    int j;
    char **tab;
}word_t;

char **my_str_to_wordtab(char *, char);
t_list *create_node(void);
t_list *init_listenv(char **);
t_list *add_env(t_list *, char *, char *);
void my_puterror(char *);
char my_puterrorcd(char *, char *);
char my_puterror_execve(char *, char **);
char my_builtin_exit(char **, t_list *);
char *check_directory(t_list *, char *);
char my_builtin_cd(char **, t_list *);
char my_builtin_env(char **, t_list *);
char my_builtin_unsetenv(char **, t_list *);
char my_builtin_setenv(char **, t_list *);
void my_putchar(char);
void my_putstr(char *);
int count_list(t_list *, t_list *);
void my_free(char **);
void my_putchar_err(char);
void my_putstr_err(char *);
void display_env(t_list *);
char **conv_list(t_list *);
char *search_env(t_list *, char *);
t_list *update_env(t_list *, char *, char *);
void remove_env(t_list *, char *);
char *verif_path(char *);
char *my_find_element(char *, t_list *);
char check_command(char **, t_list *);
int my_builtin(char **, t_list *);
char my_execve(char **, t_list *, char *);
char *recursive_execve(char **, char **, char **, int);
int my_strlen(char *);
char *my_strdup(char *);
char *my_strcat(char *, char *, int);
int my_strlen(char *);
char *my_strdup(char *str);
char my_strcmp(char *, char *, int);
int my_getnbr(char *);
#endif /* !MY_H_ */
