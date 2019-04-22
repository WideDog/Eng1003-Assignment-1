#include <stdio.h>







// FUNCTION PROTOTYPES
void encryptRotation(unsigned char *someString, int someInteger);
void putInSpaces(unsigned char *someString);
char spellCheck3(char letter1, char letter2, char letter3);
char spellCheck4(char letter1, char letter2, char letter3, char letter4);
void rotateByOne(unsigned char *someString);
// FUNCTION PROTOTYPES







int main() {
    
    char userChoice = 0;
    printf("\n\n\nChoose an option:\n\n");
    printf("a). Have a pre-determined message encrypted with a rotation key of your choice.\n\n");
    printf("b). Have a message of your choosing encrypted with a rotation key of your choosing. ");
    printf("Your encrypted message will then be decoded.\n\n");
    scanf("%c", &userChoice);
    if(userChoice < 'a' || userChoice > 'd') 
    {
        printf("Incorrect choice. Terminating program.\n");
        return 0;
    }
    printf("Thankyou.\n\n\n");
    
    
    
    switch(userChoice) {
        case'a': 
        {
            int rotation = 1;
            unsigned char string[] = {'i', 't', ' ', 'b', 'e', ' ', 'l', 'i', 'k', 'e', ' ', 't', 'h', 'a', 't', '\0'};
            printf("The unencrypted message: %s\n", string);
            printf("Type a rotation key\n");
            scanf("%d", &rotation);
            encryptRotation(string, rotation);
            printf("The encrypted message: %s\n\n\n\n", string);
            break;    
        }
        
        case 'b': 
        {
            int rotation = 1;
            unsigned char string[200];
            printf("Type a message. If you wish to put spaces in between words, use a '-' symbol instead of a space.\n");
            scanf("%s", string);
            putInSpaces(string);
            printf("%s\n", string);
            printf("Choose a rotation key.\n");
            scanf("%d", &rotation);
            encryptRotation(string, rotation);
            printf("Your encrypted message: %s\n", string);
            int repetition = 1;
            int wordFound = 0;
            char i = 0;
            char letter1 = 0;
            char letter2 = 0;
            char letter3 = 0;
            char letter4 = 0;
            while(repetition < 26 && wordFound != 1)
            {
                
                rotateByOne(string);
                while(string[i] != '\0')
                {
                    letter1 = string[i];
                    i++;
                    if(spellCheck3(letter1, letter2, letter3) == 1)
                    {
                        wordFound = 1; break;
                    }
                    letter2 = string[i];
                    i++;
                    if(spellCheck3(letter1, letter2, letter3) == 1)
                    {
                        wordFound = 1; break;
                    }
                    letter3 = string[i];
                    i++; 
                    if(spellCheck3(letter1, letter2, letter3) == 1)
                    {
                        wordFound = 1; break;
                    }
                }
                i = 0;
                while(string[i] != '\0')
                {
                    letter1 = string[i];
                    i++;
                    if(spellCheck4(letter1, letter2, letter3, letter4) == 1)
                    {
                        wordFound = 1; break;
                    }
                    letter2 = string[i];
                    i++;
                    if(spellCheck4(letter1, letter2, letter3, letter4) == 1)
                    {
                        wordFound = 1; break;
                    }
                    letter3 = string[i];
                    i++; 
                    if(spellCheck4(letter1, letter2, letter3, letter4) == 1)
                    {
                        wordFound = 1; break;
                    }
                    letter4 = string[i];
                    i++;
                    if(spellCheck4(letter1, letter2, letter3, letter4) == 1)
                    {
                        wordFound = 1; break;
                    }
                }
                i = 0;
                repetition++;
            }
            printf("Your message has been decrypted: %s\n", string);
            break;
        }
        
        
        
        case 'c':
        {
            unsigned char string[200];
            printf("Type a message that you wish to be encrypted.\n")
            scanf("%s", string);
            putInSpaces(string);
            printf("%s\n", string);
            printf("you're a piece of fucking shit you know that");
            char A = 0, B = 0, C = 0, D = 0, E = 0, F = 0, G = 0, H = 0, I = 0, J = 0, K = 0, L = 0, M = 0, N = 0, O = 0, P = 0, Q = 0;
            // have function that takes the base string, the index remembering string, and the letter literals for the substitution
            while(whole subbing thing while ignoring previously seen indexes)
            if(string[i] == string2[1]
            i++, 
            if(string[i] == 'literal')
            sub
            i++
            
            // ideas anyone? FUCKING FUCK FUCK FUCK
            // get the user to type in a letter followed by another letter. You will swap these two letters as substitution. This can be repea
            //ted up to 26 times or until the user types in "0" or some shit.
            //then let them type a message and then you can fuck it up with their stupid fucking substitution. 
            
        
        
        
        
        
        
        
        
        }
        case 'd';
        {
            //this is just fucking stupid
            
        }        
        default: {break;}
    
    }
    
    
    
    
    
    return 0;
}



// FUNCTION DEFINITIONS
void rotateByOne(unsigned char *someString)
{
    int i = 0;
    while(someString[i] != '\0')
    {
        if(someString[i] == '.' || someString[i] == ' ') 
        {
            i++;
        }
        if(someString[i] == '.' || someString[i] == ' ') 
        {
            i++;                                         
        }                                                
        someString[i] = someString[i] + 1;
        if(someString[i] > 122)
        {
            someString[i] = someString[i] - 26;
        }
        if(someString[i] > 90 && someString[i] < 97)
        {
            someString[i] = someString[i] -26;
        }
        i++;
        }
}

void encryptRotation(unsigned char *someString, int someInteger) 
{
    int i = 0;
    while(someString[i] != '\0') 
    {
        if(someString[i] == ' ' || someString[i] == '.') 
        {
            i++;
        }
        if(someString[i] <= 90 && someString[i] >= 65 && someString[i] + someInteger > 90)
        {
            someString[i] = someString[i] + someInteger - 26;
            i++;
        }
        if(someString[i] == ' ' || someString[i] == '.') 
        {
            i++;
        }
        someString[i] = someString[i] + someInteger;
        if(someString[i] > 122)
        {
            someString[i] = someString[i] - 26;
        }
        i++;
    }
   
}

    



void putInSpaces(unsigned char *someString)
{
    int i = 0;
    while(someString[i] != '\0') 
    {
        if(someString[i] == '-') 
        {
            someString[i] = ' ';
        }
    i++;
    }

}

char spellCheck3(char letter1, char letter2, char letter3)
{
    if(letter1 == ' ' && letter2 == 'a' && letter3 == ' ')
    {
        return 1;
    }
    if(letter2 == ' ' && letter3 == 'a' && letter1 == ' ')
    {
        return 1;
    }
    if(letter3 == ' ' && letter1 == 'a' && letter2 == ' ')
    {
        return 1;
    }
            
            
            
    if(letter1 == 't' && letter2 == 'h' && letter3 == 'e')
    {
        return 1;
    }
    if(letter2 == 't' && letter3 == 'h' && letter1 == 'e')
    {
        return 1;
    }
    if(letter3 == 't' && letter1 == 'h' && letter2 == 'e')
    {
        return 1;
    } 
            
    return 0;
}



char spellCheck4(char letter1, char letter2, char letter3, char letter4)
{
    if(letter1 == ' ' && letter2 == 'i' && letter3 == 't' && letter4 == ' ')
    {
       return 1;
    }
    if(letter2 == ' ' && letter3 == 'i' && letter4 == 't' && letter1 == ' ')
    {
        return 1;
    }
    if(letter3 == ' ' && letter4 == 'i' && letter1 == 't' && letter2 == ' ')
    {
        return 1;
    }
    if(letter4 == ' ' && letter1 == 'i' && letter2 == 't' && letter3 == ' ')
    {
        return 1;
    }
            
            
            
    if(letter1 == ' ' && letter2 == 'i' && letter3 == 'n' && letter4 == ' ')
    {
        return 1;
    }
    if(letter2 == ' ' && letter3 == 'i' && letter4 == 'n' && letter1 == ' ')
    {
        return 1;
    }
    if(letter3 == ' ' && letter4 == 'i' && letter1 == 'n' && letter2 == ' ')
    {
        return 1;
    }
    if(letter4 == ' ' && letter1 == 'i' && letter2 == 'n' && letter3 == ' ')
    {
        return 1;
    }
            
            
            
    if(letter1 == ' ' && letter2 == 'i' && letter3 == 's' && letter4 == ' ')
    {
        return 1;
    }
    if(letter2 == ' ' && letter3 == 'i' && letter4 == 's' && letter1 == ' ')
    {
        return 1;
    }
    if(letter3 == ' ' && letter4 == 'i' && letter1 == 's' && letter2 == ' ')
    {
        return 1;
    }
    if(letter4 == ' ' && letter1 == 'i' && letter2 == 's' && letter3 == ' ')
    {
        return 1;
    }
            
            
            
    if(letter1 == ' ' && letter2 == 't' && letter3 == 'o' && letter4 == ' ')
    {
        return 1;
    }
    if(letter2 == ' ' && letter3 == 't' && letter4 == 'o' && letter1 == ' ')
    {
        return 1;
    }
    if(letter3 == ' ' && letter4 == 't' && letter1 == 'o' && letter2 == ' ')
    {
        return 1;
    }
    if(letter4 == ' ' && letter1 == 't' && letter2 == 'o' && letter3 == ' ')
    {
        return 1;
    }
            
            
            
    if(letter1 == ' ' && letter2 == 'b' && letter3 == 'e' && letter4 == ' ')
    {
        return 1;
    }
    if(letter2 == ' ' && letter3 == 'b' && letter4 == 'e' && letter1 == ' ')
    {
        return 1;
    }
    if(letter3 == ' ' && letter4 == 'b' && letter1 == 'e' && letter2 == ' ')
    {
        return 1;
    }
    if(letter4 == ' ' && letter1 == 'b' && letter2 == 'e' && letter3 == ' ')
    {
        return 1;
    }
            
            
            
    if(letter1 == ' ' && letter2 == 'o' && letter3 == 'f' && letter4 == ' ')
    {
        return 1;
    }
    if(letter2 == ' ' && letter3 == 'o' && letter4 == 'f' && letter1 == ' ')
    {
        return 1;
    }
    if(letter3 == ' ' && letter4 == 'o' && letter1 == 'f' && letter2 == ' ')
    {
        return 1;
    }
    if(letter4 == ' ' && letter1 == 'o' && letter2 == 'f' && letter3 == ' ')
    {
        return 1;
    } 
    
    return 0;
}
// FUNCTION DEFINITIONS









/*
 File Stuff.
            FILE *input;
            input = fopen("file.test", "w");
            fprintf(input, "foo");
            fclose(input);
            input = fopen("file.test", "r");
            char str[100];
            fscanf(input, "%s", str);
            printf("%s", str);
 */







