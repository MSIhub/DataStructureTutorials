#include "String.h"

void StringTest()
{
	char temp = 'A';
	//temp = 'A';
	//temp = 65;
	std::cout << temp << std::endl;	

	//char X[5];
	//Same array will be create for the below three lines
	char X[5] = { 'A', 'B', 'C', 'D', 'E' };
	/*char X[] = { 'A', 'B', 'C', 'D', 'E' };
	char X[5] = { 65, 66,67,68,69 };*/

	//char X[5] = {'A', 'B'};
	// STRINGS
	char name[10] = { 'J', 'o', 'h', 'n' }; //--> ARRAY OF CHARACTER
	char nameString[10] = { 'J', 'o', 'h', 'n', '\0'}; //--> String [with string terminator, null char]
	//char nameString[] = { 'J', 'o', 'h', 'n', '\0'}; //--> String equivalent declartion
	//char nameString[] = "John";//--> String equivalent declartion
	std::cout << nameString << "\n";

	char nameString2[100];
	//std::cin>> nameString2;// take only till space is there i.e. only one word`
	//fgets(nameString2, 100, stdin);// takes multiple words from comand line
	//std::cout << nameString2;
	getInputString(&nameString2[0], 100);
	std::cout << nameString2 << "\n";
	int lenStr = findLengthOfString(&nameString2[0]);
	std::cout << "Length of the entered string = " << lenStr << std::endl;
	CaseHandlingString(&nameString2[0], lenStr);
	VowelConsonentCounterString(&nameString2[0], lenStr);
	wordCounterString(&nameString2[0], lenStr);
	std::cout << "Is string valid: " << std::boolalpha << isValidString(nameString2) << std::endl;
	ReverseString(&nameString2[0], lenStr);
	std::cout << "Reverse: " << nameString2 << std::endl;
	compareTwoStrings(nameString, nameString2);
	std::cout << "Is string palindrome: " << std::boolalpha << isStringPalindrome(nameString2, lenStr) << std::endl;
	findDuplicatesStringHash(nameString2);
	findDuplicatesStringBitWise(nameString2); 
	isStringAnagramHash(nameString, nameString2);
	std::cout << "\n";
	//StringPermutationRecursive(nameString2, 0);
	StringPermutationRecursive2(nameString2, 0, lenStr);

}

void getInputString(char* buffer, int buflen) //safe way to get multiple words from comand line input
{
	char c;
	int i = 0;
	while ((c = getchar()) != '\n' && i < buflen)
	{
		*(buffer + i) = c;
		i++;
	}
	*(buffer + i) = '\0'; //append null termination

}	

int findLengthOfString(char* buffer)
{
	int searchThreshold = 1000; // to avoid infinite loop search 
	int i = 0;
	while (*(buffer + i) != '\0' && i < searchThreshold)
		i++;

	return i;
	/*for (int i = 0; *(buffer + i) = '\0'; i++)
	{	}*/

}

void CaseHandlingString(char* buffer, int length)
{
	char* UpperCase = new char[length+1];
	char* LowerCase = new char[length+1];
	char* ToggleCase = new char[length+1];
	char* SentanceCase = new char[length+1];
	int i = 0;
	while (*(buffer + i) != '\0' && i < length)
	{
		if (*(buffer + i) >= 65 && *(buffer + i) <= 90) //UpperCase to lowercase 
		{
			ToggleCase[i] = *(buffer + i) + 32;
			LowerCase[i] = *(buffer + i) + 32;
			UpperCase[i] = *(buffer + i);
		}
		else if (*(buffer + i) >= 'a' && *(buffer + i) <= 122) //LowerCase to UpperCase
		{
			ToggleCase[i] = *(buffer + i) - 32; 
			UpperCase[i] = *(buffer + i) - 32;
			LowerCase[i] = *(buffer + i);
		}
		else // Unchange the non alphabetic values
		{
			ToggleCase[i] = *(buffer + i);
			UpperCase[i] = *(buffer + i);
			LowerCase[i] = *(buffer + i);
		}
		i++;
	}
	ToggleCase[i] = '\0';
	UpperCase[i] = '\0';
	LowerCase[i] = '\0';

	SentanceCase = LowerCase;
	if (SentanceCase[0] >= 'a' && SentanceCase[0] <= 122)
		SentanceCase[0] -= 32;


	std::cout << "Toggle Case: ";
	for (int j = 0; ToggleCase[j] != '\0'; j++)
		std::cout << ToggleCase[j];
	std::cout << "\n";

	std::cout << "Upper Case: ";
	for (int j = 0; UpperCase[j] != '\0'; j++)
		std::cout << UpperCase[j];
	std::cout << "\n";

	std::cout << "Lower Case: ";
	for (int j = 0; LowerCase[j] != '\0'; j++)
		std::cout << LowerCase[j];
	std::cout << "\n";

	std::cout << "Sentance Case: ";
	for (int j = 0; SentanceCase[j] != '\0'; j++)
		std::cout << SentanceCase[j];
	std::cout << "\n";

}

void VowelConsonentCounterString(char* buffer, int length)
{
	char VOWEL[] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U' };
	int ccount = 0, vcount = 0;
	bool isCurrCharVowel = false;
	int i = 0;
	while (*(buffer + i) != '\0' && i <= length)
	{
		if (*(buffer + i) >= 'a' && *(buffer + i) <= 122 || *(buffer + i) >= 65 && *(buffer + i) <= 90)
		{
			for (char& c : VOWEL)
			{
				if (*(buffer + i) == c)
				{
					vcount++;
					isCurrCharVowel = true;
				}
			}
			if (!isCurrCharVowel)
				ccount++;
		}
		isCurrCharVowel = false;
		i++;
		
	}
	
	std::cout << "# of vowel in the entered String: " << vcount << std::endl;
	std::cout << "# of consonants in the entered String: " << ccount << std::endl;
}

int wordCounterString(char * buffer, int length)
{
	int wordCount = 1;
	int i = 0;
	while (*(buffer + i) != '\0' && i <= length)
	{
		if (*(buffer + i) == ' ' && *(buffer + i-1) != ' ')
			wordCount++;

		i++;
	}


	std::cout << "# of word in your text: " << wordCount << std::endl;
	return wordCount;
}

bool isValidString(char* buffer)
{
	int i = 0;
	for (i = 0; buffer[i] != '\0'; i++)
	{
		bool condition1 = (buffer[i] >= 65 && buffer[i] <= 90); //Capital Letters // refer http://www.alanwood.net/demos/ansi.html
		bool condition2 = (buffer[i] >= 97 && buffer[i] <= 122); //lowercase Letters
		bool condition3 = (buffer[i] >= 48 && buffer[i] <= 57); // numbers
		if (!condition1 && !condition2 && !condition3)
			return false;
	}
	return true;
}

void ReverseString(char* buffer, int length)//Assuming the compiler allows char* to be mutable
{
	int i = 0;
	int j = length-1;
	for (i=0; i< j; i++, j--)
	{
		char temp = *(buffer + i);
		*(buffer + i) = *(buffer + j);
		*(buffer + j) = temp;
	}

}

void compareTwoStrings(char* buf1, char* buf2)
{
	int i = 0, j = 0;
	for (i = 0, j = 0; buf1[i] != '\0' && buf2[j] != '\0'; i++, j++)
	{
		if (buf1[i] != buf2[j])
			break;
	}
	if (buf1[i] == buf2[j])
		std::cout << buf1 << " equal to " << buf2 << std::endl;
	else if(buf1[i] < buf2[j])
		std::cout << buf1 << " is smaller than " << buf2 << std::endl;
	else
		std::cout << buf1 << " is greater than " << buf2 << std::endl;	
}


bool isStringPalindrome(char* buffer, int length)
{
	int i = 0;
	int j = length-1;
	for (; i < j; i++, j--)
	{
		if (buffer[i] != buffer[j])
			return false;
	}
	return true;
}


void findDuplicatesStringHash(char* buffer)
{
	int asciiElements = 128;

	int* hash = new int[asciiElements]{0}; // Ascii table 0->127 // 97 to 112 are lower case asci elements
	for (int i = 0; buffer[i] != '\0'; i++)
		* (hash + buffer[i]) += 1;
	
	for (int j = 0; j < asciiElements; j++)
	{
		if (*(hash + j) > 1)
			std::cout << "Duplicate element: " << char(j) << " is repeated " << *(hash + j) << std::endl;
	}
}

void findDuplicatesStringBitWise(char* buffer)
{
	//if you want to pass any value of ASCII, then you could use uint256_t from boost/multiprecision
	unsigned int checker = 0; //32 bits of space // Use it for lowercase 26 letters check
	int i = 0;
	for (i = 0; buffer[i] != '\0'; i++)
	{
		int val = buffer[i] - 'a';
		if ((checker & (1 << val)) > 0)
			std::cout << "Duplicate : " << char(buffer[i]) << "\n";
		
		checker |= (1 << val);
	}
}


void isStringAnagramHash(char* buf1, char* buf2)
{
	int asciiElements = 128;
	int i = 0;
	int* hash = new int[asciiElements] {0}; // Ascii table 0->127 // 97 to 112 are lower case asci elements
	for ( i = 0; buf1[i] != '\0'; i++)
		*(hash + buf1[i]) += 1;
	
	for (i = 0; buf2[i] != '\0'; i++)
	{
		*(hash + buf2[i]) -= 1;
		if (hash[buf2[i]] < 0)
		{
			std::cout << "String entered are not anagram";
			break;
		}
	}
	if (buf2[i] == '\0')
		std::cout << "Its Anagram";

}

//STATE SPACE TREE ==> Leaves show the result
//BACKTRACKING ->> //RECURSION  -->> //BRUTEFORCING
void StringPermutationRecursive(char* buffer, int k)
{
	static int checker[100] = {0};
	static char result[100];
	int i = 0;
	if (buffer[k] == '\0')
	{
		result[k] = '\0';
		std::cout << result << "\n";
	}
	else
	{
		for (i = 0; buffer[i] != '\0'; i++)
		{
			if (checker[i] == 0)
			{
				result[k] = buffer[i];
				checker[i] = 1;
				StringPermutationRecursive(buffer, k + 1);
				checker[i] = 0;
			}
		}
	}

}


void StringPermutationRecursive2(char* buffer, int low, int high)
{
	if (low == high)
	{
		std::cout << buffer << std::endl;
		return;
	}
	else
	{
		for (int i = low; i < high; i++)
		{
			Swap(&buffer[low], &buffer[i]);
			StringPermutationRecursive2(buffer, low + 1, high);
			Swap(&buffer[low], &buffer[i]);

		}
	}
}

void Swap(char* c1, char* c2)
{
	char temp = *c1;
	*c1 = *c2;
	*c2 = temp;
}