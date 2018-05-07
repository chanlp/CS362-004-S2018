#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char inputChar()
{
    // TODO: rewrite this function
	int randIndex;
	char randChar; 
	int i;
	static char characters[] = "abcdefghijklmnopqrstuvwxyz[]{}() "; // Many options so it may possibly error.
	for (i=0; i<1; i++){
		randIndex = rand() % 33;
		randChar = characters[randIndex];
	}
    //return ' ';
	//printf("%c\n",randChar);
	return randChar;
}

char *inputString(int length)
{
    // TODO: rewrite this function
	int i;
	int index;
	//static char letters[] = "abcdefghijklmnopqrstuvwxyz\0";
	static char letters[] = "reset\0"; // If you just check this string, it errors very quickly. 
	char *randStr = NULL;
	if(length){
		randStr = malloc(sizeof(char) * (length+1));
		if(randStr){
			for (i=0; i<length; i++){
				index = rand() % (int)(sizeof(letters) - 1);
				randStr[i] = letters[index];
				//printf("%c",randStr[i]);
			}
		}
	}
    //return "";
	return randStr; 
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
    s = inputString(6); // Max size of strings
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
