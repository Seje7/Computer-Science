#include <stdlib.h> 
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#define READERS_LENGTH 100

// stlib is used for memory allocation
// stdio is used for input and output functions
// string.h is used for stering manipulations (strok) 
// unistd.h is used to call fork and dup
// fcntl is used for theopen function
// sys/wait is used to call wait function

char** tokenize(char* input, int* token_count){ // function to tokenized strings 
char **temp_array = malloc(READERS_LENGTH * sizeof(char)); // another array to store the tokenized strings 
char *ptr = strtok(input, " \t"); // uses spaces and tab spaces as delimeters

temp_array[*token_count] = ptr; // moves string into temp_array
(*token_count)++;

while((ptr = strtok(NULL, " \t")) != NULL){ // loops through the rest of the strings 
temp_array[*token_count] = ptr;
(*token_count)++;
}

return temp_array; // returns the tokenized strings 
}

int main(int argc, char *argv[]) {
int tokenc = 0 , redirect_checker = 0; 
char** tokenv = malloc (READERS_LENGTH * sizeof(char*));
char * input = malloc (READERS_LENGTH * sizeof(char)); // array to read input 

printf("PROMPT$: "); // proionts a shell prompt
while(fgets(input, READERS_LENGTH, stdin)){ // reads input from shell
input[strcspn(input, "\n")] = 0;

if (input[0] != 0){ // checks if the input is a new line
tokenv = tokenize(input, &tokenc); // calls the tokenize function

int pid = fork();  // create a fork 

 if (pid == 0) {// Child process

 for (int i = 0; i < tokenc; i++){ // checks for a redirect symbol
if (strcmp(tokenv[i], ">") == 0){
    redirect_checker = 1; // Mark as found

int file = open(tokenv[i+1], O_WRONLY
  | O_CREAT | O_TRUNC, 0644); // Open file for writing
   if (file < 0) { // checks for error in opening file 
    perror("open");
    return 1;}

dup2(file, 1); // redirect standard output to file
tokenv[i] = NULL; // set ">" to Null not to get passed into the execvp function
execvp(tokenv[0], tokenv); // executes the command 
perror("execvp failed");  // If execvp fails
exit(1);  // Exit child process

close(file); // close file 
break; // ends the loop 
}}

if (redirect_checker != 1) { // checks if there is no redirect symbol
    if (execvp(tokenv[0], tokenv) < 0){ // checks for a command without redirection and runs it 
    for (int i = 0; i < tokenc; i++) { // if there is no command to be run
    printf("%s\n", tokenv[i]); // print whatever is inputed in the shell
}}
    //perror("execvp failed");  // If execvp fails
    //exit(1);  // Exit child process
} 
    } else if (pid > 0) {  // Parent process: Wait for child to finish
        wait(NULL);
    } else {
        perror("fork failed");   // Fork failed
}

tokenc = 0; // resets the token count back to zero
redirect_checker = 0; // resets the redirect_checker
}
printf("PROMPT$: "); // prints another prompt

} 
free(tokenv); // frees the tokenv array
free(input);  // frees the input array 

    return 0;}
