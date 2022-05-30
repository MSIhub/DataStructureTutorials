#pragma once
#include <iostream>
#include <cstdio>


void getInputString(char* buffer, int buflen);

int findLengthOfString(char* buffer);

void CaseHandlingString(char* buffer, int length);

void VowelConsonentCounterString(char* buffer, int length);

int wordCounterString(char* buffer, int length);

bool isValidString(char* buffer);

void ReverseString(char* buffer, int length);

void compareTwoStrings(char* buf1, char* buf2);

bool isStringPalindrome(char* buffer, int length);

void findDuplicatesStringHash(char* buffer);

void findDuplicatesStringBitWise(char* buffer);

void isStringAnagramHash(char* buf1, char* buf2);

void StringPermutationRecursive(char* buffer, int k);

void StringPermutationRecursive2(char* buffer, int low, int high);

void Swap(char* c1, char* c2);

void StringTest();