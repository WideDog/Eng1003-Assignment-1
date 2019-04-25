#include <stdio.h>







// FUNCTION PROTOTYPES
void encryptRotation(unsigned char *someString, int someInteger);
void decryptRotation(unsigned char *someString, int someInteger);
void putInSpaces(unsigned char *someString);
char spellCheck4(char letter1, char letter2, char letter3, char letter4);
char spellCheck5(char letter1, char letter2, char letter3, char letter4, char letter5);
void rotateByOne(unsigned char *someString);
void substitute(unsigned char *someString, char originalLiteral, char literalSubstitute, unsigned char *memoryString);
// FUNCTION PROTOTYPES







int main() {
    
    char userChoice = 0;
    printf("\n\n\nChoose an option:\n\n");
    printf("a). Have a message encrypted with a rotation key of your choosing.\n\n");
    printf("b). Have a rotation cipher decrypted after inputting both the cipher and the rotation key.\n\n");
    printf("c). Have a rotation cipher decrpyted after inputting the cipher.\n\n");
    printf("d). Have a message encrypted with a substitution key of your choosing.\n\n");
    printf("e). Have a substitution cypher decrypted after inputting both the cipher and the substitution key.\n\n");
    scanf("%c", &userChoice);
    fgetc(stdin);
    if(userChoice < 'a' || userChoice > 'g') 
    {
        printf("Incorrect choice. Terminating program.\n");
        return 0;
    }
    printf("\n\n\n");
    
    
    
    switch(userChoice) {
        case'a': 
        {
            int rotation = 0;
            unsigned char string[200];
            printf("Type a message. If you wish to put spaces in between words, use a '=' symbol instead of a space.\n");
            fgets(string, 1500, stdin);
            printf("%s\n", string);
            printf("Choose a rotation key.\n");
            scanf("%d", &rotation);
            encryptRotation(string, rotation);
            printf("Your encrypted message: %s\n", string);
            break;
        }
        
        
        case 'b': 
        {
            int rotation = 0;
            unsigned char string[200];
            printf("Type a rotation cipher. If you wish to use spaces in between words, use a '=' symbol instead.\n");
            scanf("%s", string);
            putInSpaces(string);
            printf("Enter the rotation number that was used to make the cipher.");
            scanf("%d", &rotation);
            decryptRotation(string, rotation);
            printf("I assume your message was: %s\n", string);
            break;
        }
        
    
        case 'c':
        {
            unsigned char string[1500];
            int repetition = 1;
            int wordFound = 0;
            int i = 0;
            char letter1 = 0;
            char letter2 = 0;
            char letter3 = 0;
            char letter4 = 0;
            char letter5 = 0;
            printf("Type a rotation cipher. If you wish to put spaces in between words, use a '=' symbol instead of a space.\n");
            fgets(string, 1500, stdin);
            while(repetition < 26 && wordFound != 1)
            {
                
                rotateByOne(string);
                while(string[i] != '\0')
                {
                    letter1 = string[i];
                    i++;
                    if(spellCheck4(letter1, letter2, letter3, letter4) == 1)
                    {
                        wordFound = 1;
                        break;
                    }
                    letter2 = string[i];
                    i++;
                    if(spellCheck4(letter1, letter2, letter3, letter4) == 1)
                    {
                        wordFound = 1;
                        break;
                    }
                    letter3 = string[i];
                    i++; 
                    if(spellCheck4(letter1, letter2, letter3, letter4) == 1)
                    {
                        wordFound = 1;
                        break;
                    }
                    letter4 = string[i];
                    i++;
                    if(spellCheck4(letter1, letter2, letter3, letter4) == 1)
                    {
                        wordFound = 1;
                        break;
                        
                    }
                }
                
                letter1 = 0;
                letter2 = 0;
                letter3 = 0;
                letter4 = 0;
                i = 0;
                
                while(string[i] != '\0')
                {
                    letter1 = string[i];
                    i++;
                    if(spellCheck5(letter1, letter2, letter3, letter4, letter5) == 1)
                    {
                        wordFound = 1;
                        break;
                    }
                    letter2 = string[i];
                    i++;
                    if(spellCheck5(letter1, letter2, letter3, letter4, letter5) == 1)
                    {
                        wordFound = 1;
                        break;
                    }
                    letter3 = string[i];
                    i++;
                    if(spellCheck5(letter1, letter2, letter3, letter4, letter5) == 1)
                    {
                        wordFound = 1;
                        break;
                    }
                    letter4 = string[i];
                    i++;
                    if(spellCheck5(letter1, letter2, letter3, letter4, letter5) == 1)
                    {
                        wordFound = 1;
                        break;
                    }
                    letter5 = string[i];
                    i++;
                    if(spellCheck5(letter1, letter2, letter3, letter4, letter5) == 1)
                    {
                        wordFound = 1;
                        break;
                    }
                
                }
                
                letter1 = 0;
                letter2 = 0;
                letter3 = 0;
                letter4 = 0;
                letter5 = 0;
                i = 0;
                
                repetition++;
                
            }
            if(wordFound == 1)
            {
                printf("I assume your message was: %s\n", string);
            }
            if(wordFound != 1)
            {
                printf("Decryption failed.\n");
            }
            break;
        }
        
        
        case 'd':
        {
            unsigned char string[1500];
            char substitutions[26] = {'0'};
            int interfaceLetter = 'A';
            int i = 0;
            printf("Type a message that you wish to be encrypted.\n");
            printf("If you wish to put spaces in between words, use a '=' symbol instead of a space.\n");
            scanf("%s", string);
            putInSpaces(string);
            printf("%s\n", string);
            printf("You will now be prompted with the letters of the alphabet.\n");
            printf("Each time a letter appears, type the letter you wish the prompt-letter to be replaced with during the encryption.\n");
            printf("Remember: to create a proper substitution alphabet, you must only enter each letter of the alphabet once.\n");
            printf("Please use upper case when entering your substitutions.\n\n");
            while(i < 26)
            {
                printf("Letters you have typed:%s", substitutions);
                printf("\nSubstitution for %c:  ", interfaceLetter);
                scanf(" %c", &substitutions[i]);
                interfaceLetter++;
                i++;
            }
            i = 0;
            int letter = 'A';
            unsigned char indexMemory[1500];
            while(i < 26)
            {
                substitute(string, letter, substitutions[i], indexMemory);
                letter++;
                i++;
            }
            
            printf("%s\n", string);
            break;
            
        }  
        
        
        case 'e':
        {
            unsigned char indexMemory[1500];
            unsigned char string[1500];
            int letter = 'A';
            int interfaceLetter = 'A';
            char substitutions[26];
            int i = 0;
            printf("Type a substitution cipher. If you wish to put spaces in between words, use the '=' symbol instead.\n");
            scanf("%s", string);
            printf("You will now be prompted with the letters of the alphabet.\n");
            printf("At each prompt, please enter the letter you used in your cipher alphabet to substitute the prompt-letter.\n");
            printf("Please use upper case when entering your substitutions.\n\n");
            while(i < 26)
            {
                printf("Substitution for %c:  ", interfaceLetter);
                scanf(" %c", &substitutions[i]);
                interfaceLetter++;
                i++;
            }
            i = 0;
            while(i < 26)
            {
                substitute(string, substitutions[i], letter, indexMemory);
                letter++;
                i++;
            }
            printf("I assume your message was: %s", string);
            break;
        }
        
        case 'f':
        {
            //char str[100];
            //char str2[100];
            //FILE *input;
            //input = fopen("file.test", "w");
            //fprintf(input, str);
            //fclose(input);
            //input = fopen("file.test", "r");
            //fscanf(input, "%s", str2);
            //printf("%s\n", str); 
        }
        
        case 'g':
        {
            unsigned char string[1000];
            fgets(string, 1000, stdin);
            char number = 1;
            while(number < 27)
            {
                rotateByOne(string);
                printf("%d    %s\n", number, string);
                number++; 
            }
        }
        
        default:
        {
            break;
        }
    }
    
    
    
    
    
    return 0;
}



// FUNCTION DEFINITIONS
void rotateByOne(unsigned char *someString)
{
    int i = 0;
    while(someString[i] != '\0')
    {
        if(someString[i] == '.' || someString[i] == ' ' || someString[i] == '!' || someString[i] == '?' || someString[i] == 39 || someString[i] == '"')
        {
            i++;
        }
        else if(someString[i] == '(' || someString[i] == ')' || someString[i] == ';' || someString[i] == ':' || someString[i] == '-' || someString[i] == ',')
        {
            i++;
        }
        else if(someString[i] >= 65 && someString[i] <= 90 && someString[i] + 1 > 90)
        {
            someString[i] = someString[i] + 1 - 26;
            i++;
        }
        else
        {
            someString[i] = someString[i] + 1;
            i++;
        }
    }

}


void encryptRotation(unsigned char *someString, int someInteger) 
{
    int i = 0;
    while(someString[i] != '\0') 
    {
        if(someString[i] == '.' || someString[i] == ' ' || someString[i] == '!' || someString[i] == '?' || someString[i] == 39 || someString[i] == '"')
        {
            i++;
        }
        else if(someString[i] == '(' || someString[i] == ')' || someString[i] == ';' || someString[i] == ':' || someString[i] == '-' || someString[i] == ',')
        {
            i++;
        }
        else if(someString[i] <= 90 && someString[i] >= 65 && someString[i] + someInteger > 90)
        {
            someString[i] = someString[i] + someInteger - 26;
            i++;
        }
        else
        {
            someString[i] = someString[i] + someInteger;
            i++;
        }
    }
   
}




void decryptRotation(unsigned char *someString, int someInteger)
{
    int i = 0;
    while(someString[i] != '\0') 
    {
        if(someString[i] == '.' || someString[i] == ' ' || someString[i] == '!' || someString[i] == '?' || someString[i] == 39 || someString[i] == '"')
        {
            i++;
        }
        else if(someString[i] == '(' || someString[i] == ')' || someString[i] == ';' || someString[i] == ':' || someString[i] == '-' || someString[i] == ',')
        {
            i++;
        }
        else if(someString[i] <= 90 && someString[i] >= 65 && someString[i] - someInteger < 65)
        {
            someString[i] = someString[i] - someInteger + 26;
            i++;
        }
        else
        {
          someString[i] = someString[i] - someInteger;
          i++;
        }
    }
}
    

void putInSpaces(unsigned char *someString)
{
    int i = 0;
    while(someString[i] != '\0') 
    {
        if(someString[i] == '=') 
        {
            someString[i] = ' ';
        }
    i++;
    }

}


void substitute(unsigned char *someString, char originalLiteral, char literalSubstitute, unsigned char *memoryString)
{
    int i = 0;
    while(someString[i] != '\0')
            {
                if(someString[i] == originalLiteral && memoryString[i] != '-')
                {
                    someString[i] = literalSubstitute;
                    memoryString[i] = '-';
                }
                i++;
            }
}





char spellCheck4(char letter1, char letter2, char letter3, char letter4)
{
    
            
            
            
    if(letter1 == ' ' && letter2 == 'I' && letter3 == 'N' && letter4 == ' ')
    {
        return 1;
    }
    if(letter2 == ' ' && letter3 == 'I' && letter4 == 'N' && letter1 == ' ')
    {
        return 1;
    }
    if(letter3 == ' ' && letter4 == 'I' && letter1 == 'N' && letter2 == ' ')
    {
        return 1;
    }
    if(letter4 == ' ' && letter1 == 'I' && letter2 == 'N' && letter3 == ' ')
    {
        return 1;
    }
    
    
    
    if(letter1 == ' ' && letter2 == 'I' && letter3 == 'S' && letter4 == ' ')
    {
        return 1;
    }
    if(letter2 == ' ' && letter3 == 'I' && letter4 == 'S' && letter1 == ' ')
    {
        return 1;
    }
    if(letter3 == ' ' && letter4 == 'I' && letter1 == 'S' && letter2 == ' ')
    {
        return 1;
    }
    if(letter4 == ' ' && letter1 == 'I' && letter2 == 'S' && letter3 == ' ')
    {
        return 1;
    }
            
              
            
    if(letter1 == ' ' && letter2 == 'B' && letter3 == 'E' && letter4 == ' ')
    {
        return 1;
    }
    if(letter2 == ' ' && letter3 == 'B' && letter4 == 'E' && letter1 == ' ')
    {
        return 1;
    }
    if(letter3 == ' ' && letter4 == 'B' && letter1 == 'E' && letter2 == ' ')
    {
        return 1;
    }
    if(letter4 == ' ' && letter1 == 'B' && letter2 == 'E' && letter3 == ' ')
    {
        return 1;
    }
            
            
            
    if(letter1 == ' ' && letter2 == 'O' && letter3 == 'F' && letter4 == ' ')
    {
        return 1;
    }
    if(letter2 == ' ' && letter3 == 'O' && letter4 == 'F' && letter1 == ' ')
    {
        return 1;
    }
    if(letter3 == ' ' && letter4 == 'O' && letter1 == 'F' && letter2 == ' ')
    {
        return 1;
    }
    if(letter4 == ' ' && letter1 == 'O' && letter2 == 'F' && letter3 == ' ')
    {
        return 1;
    } 
    
    
    
    if(letter1 == ' ' && letter2 == 'S' && letter3 == 'O' && letter4 == ' ')
    {
        return 1;
    }
    if(letter2 == ' ' && letter3 == 'S' && letter4 == 'O' && letter1 == ' ')
    {
        return 1;
    }
    if(letter3 == ' ' && letter4 == 'S' && letter1 == 'O' && letter2 == ' ')
    {
        return 1;
    }
    if(letter4 == ' ' && letter1 == 'S' && letter2 == 'O' && letter3 == ' ')
    {
        return 1;
    }
    
    
    
    if(letter1 == ' ' && letter2 == 'O' && letter3 == 'N' && letter4 == ' ')
    {
        return 1;
    }
    if(letter2 == ' ' && letter3 == 'O' && letter4 == 'N' && letter1 == ' ')
    {
        return 1;
    }
    if(letter3 == ' ' && letter4 == 'O' && letter1 == 'N' && letter2 == ' ')
    {
        return 1;
    }
    if(letter4 == ' ' && letter1 == 'O' && letter2 == 'N' && letter3 == ' ')
    {
        return 1;
    } 
    
    
    
    
    
    
    
    return 0;
}






char spellCheck5(char letter1, char letter2, char letter3, char letter4, char letter5)
{
    if(letter1 == ' ' && letter2 == 'A' && letter3 == 'N' && letter4 == 'D' && letter5 == ' ')
    {
        return 1;  
    }
    if(letter5 == ' ' && letter1 == 'A' && letter2 == 'N' && letter3 == 'D' && letter4 == ' ')
    {
        return 1;  
    }
    if(letter4 == ' ' && letter5 == 'A' && letter1 == 'N' && letter2 == 'D' && letter3 == ' ')
    {
        return 1;  
    }
    if(letter3 == ' ' && letter4 == 'A' && letter5 == 'N' && letter1 == 'D' && letter2 == ' ')
    {
        return 1;  
    }
    if(letter2 == ' ' && letter3 == 'A' && letter4 == 'N' && letter5 == 'D' && letter1 == ' ')
    {
        return 1;  
    }
         
    
    
    if(letter1 == ' ' && letter2 == 'C' && letter3 == 'A' && letter4 == 'N' && letter5 == ' ')
    {
        return 1;  
    }
    if(letter5 == ' ' && letter1 == 'C' && letter2 == 'A' && letter3 == 'N' && letter4 == ' ')
    {
        return 1;  
    }
    if(letter4 == ' ' && letter5 == 'C' && letter1 == 'A' && letter2 == 'N' && letter3 == ' ')
    {
        return 1;  
    }
    if(letter3 == ' ' && letter4 == 'C' && letter5 == 'A' && letter1 == 'N' && letter2 == ' ')
    {
        return 1;  
    }
    if(letter2 == ' ' && letter3 == 'C' && letter4 == 'A' && letter5 == 'N' && letter1 == ' ')
    {
        return 1;  
    }
    
    
    
    if(letter1 == ' ' && letter2 == 'T' && letter3 == 'H' && letter4 == 'E' && letter5 == ' ')
    {
        return 1;  
    }
    if(letter5 == ' ' && letter1 == 'T' && letter2 == 'H' && letter3 == 'E' && letter4 == ' ')
    {
        return 1;  
    }
    if(letter4 == ' ' && letter5 == 'T' && letter1 == 'H' && letter2 == 'E' && letter3 == ' ')
    {
        return 1;  
    }
    if(letter3 == ' ' && letter4 == 'T' && letter5 == 'H' && letter1 == 'E' && letter2 == ' ')
    {
        return 1;  
    }
    if(letter2 == ' ' && letter3 == 'T' && letter4 == 'H' && letter5 == 'E' && letter1 == ' ')
    {
        return 1;  
    }
    
    

    if(letter1 == ' ' && letter2 == 'F' && letter3 == 'O' && letter4 == 'R' && letter5 == ' ')
    {
        return 1;  
    }
    if(letter5 == ' ' && letter1 == 'F' && letter2 == 'O' && letter3 == 'R' && letter4 == ' ')
    {
        return 1;  
    }
    if(letter4 == ' ' && letter5 == 'F' && letter1 == 'O' && letter2 == 'R' && letter3 == ' ')
    {
        return 1;  
    }
    if(letter3 == ' ' && letter4 == 'F' && letter5 == 'O' && letter1 == 'R' && letter2 == ' ')
    {
        return 1;  
    }
    if(letter2 == ' ' && letter3 == 'F' && letter4 == 'O' && letter5 == 'R' && letter1 == ' ')
    {
        return 1;  
    }
    
    
    
    if(letter1 == ' ' && letter2 == 'Y' && letter3 == 'O' && letter4 == 'U' && letter5 == ' ')
    {
        return 1;  
    }
    if(letter5 == ' ' && letter1 == 'Y' && letter2 == 'O' && letter3 == 'U' && letter4 == ' ')
    {
        return 1;  
    }
    if(letter4 == ' ' && letter5 == 'Y' && letter1 == 'O' && letter2 == 'U' && letter3 == ' ')
    {
        return 1;  
    }
    if(letter3 == ' ' && letter4 == 'Y' && letter5 == 'O' && letter1 == 'U' && letter2 == ' ')
    {
        return 1;  
    }
    if(letter2 == ' ' && letter3 == 'Y' && letter4 == 'O' && letter5 == 'U' && letter1 == ' ')
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







