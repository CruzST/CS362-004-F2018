#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>



/* Function will produce a random character */
char inputChar()
{    // (upper - lower + 1) + lower values obtained from ASCII chart online. c needs to be anywhere between space (32) and } (126)
    int num = (rand() % (125-32 + 1)) + 32;
    char symbol = (char)num;
    return symbol;
}




char *inputString()
{
  char* string = (char*)malloc((sizeof(char)*5) + 1);
  char inputPool[10] = {'r', 'e', 's', 't', 'a', 'y', 'z', 'x', 'w', 'i',};

  int i;
  for (i = 0; i < 5; i++){
    int num;
    num = ((rand() % 10));
    string[i] = inputPool[num];
  }
  string[5] = '\0';
  return string;
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

    /* sets up the state #*/
    if (c == '[' && state == 0) state = 1;
    if (c == '(' && state == 1) state = 2;
    if (c == '{' && state == 2) state = 3;
    if (c == ' '&& state == 3) state = 4;
    if (c == 'a' && state == 4) state = 5;
    if (c == 'x' && state == 5) state = 6;
    if (c == '}' && state == 6) state = 7;
    if (c == ')' && state == 7) state = 8;
    if (c == ']' && state == 8) state = 9;

    /* if block that will get the program to exit */
    if (s[0] == 'r' && s[1] == 'e'
       && s[2] == 's' && s[3] == 'e'
       && s[4] == 't' && s[5] == '\0'
       && state == 9)
    {
      printf("error ");
      exit(200);
    }
    free(s);
  }
}


int main(int argc, char *argv[])
{
    srand(time(NULL));
    testme();
    return 0;
}
