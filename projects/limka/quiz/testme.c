#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char inputChar()
{
    // set to a random char with ASCII value between 1 and 126
    int choice;
    char c;

    	// set pool of chars
    char pool[13] = { '[', '(', '{', ' ', 'a', 'x', '}', ')', ']', 'r', 'e', 's', 't'};

    	// randomize the choice from the pool
    choice = rand() % 13;
    c = pool[choice];
   
    return c;
}

char *inputString()
{
    // create a random string with 4 characters
    int str_len = 5;
    int choice;
    int select;

    	// set up char selection randomization
    char c;
    char pool[13] = {'[', '(', '{', ' ', 'a', 'x', '}', ')', ']', 'r', 'e', 's', 't'};

    	// initialize string
    char* str = malloc(sizeof(char)* str_len);

    select = rand() % 5;
    if(select == 1){
       str = "reset";
    }else{
    	// populate string with random characters
       for(int i = 0; i < str_len - 1; i++){
          choice = rand() % 9;
          c = pool[choice];
          str[i] = c;
       }
    }
  
    return str;
}

void testme()
{
  int tcCount = 0;
  char *s;
  char c;
  int state = 0;
  while (1)
  {
    tcCount++;
    c = inputChar();
    s = inputString();
    printf("Iteration %d: c = %c, s = %s, state = %d\n", tcCount, c, s, state);

    if (c == '[' && state == 0) state = 1;
    if (c == '(' && state == 1) state = 2;
    if (c == '{' && state == 2) state = 3;
    if (c == ' '&& state == 3) state = 4;
    if (c == 'a' && state == 4) state = 5;
    if (c == 'x' && state == 5) state = 6;
    if (c == '}' && state == 6) state = 7;
    if (c == ')' && state == 7) state = 8;
    if (c == ']' && state == 8) state = 9;
    if (s[0] == 'r' && s[1] == 'e'
       && s[2] == 's' && s[3] == 'e'
       && s[4] == 't' && s[5] == '\0'
       && state == 9)
    {
      printf("error ");
      exit(200);
    }
  }
}


int main(int argc, char *argv[])
{
    srand(time(NULL));
    testme();
    return 0;
}
