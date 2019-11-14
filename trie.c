#pragma warning(disable: 4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tree
{
	int isSet;
	char* value;
	struct tree* children;
};

struct tree theTree;

void freeTree(struct tree tree)
{
	if (tree.children != NULL)
	{
		for(int i = 0; i < 256; i++)
			freeTree(tree.children[i]);

		free(tree.children);
	}

	if (tree.value != NULL)
		free(tree.value);
}

int initTree()
{
	theTree.isSet = 0;
	theTree.children = (struct tree*)malloc(sizeof(struct tree) * 256);

	for (int i = 0; i < 256; i++)
	{
		theTree.children[i].isSet = 0;
		theTree.children[i].children = NULL;
		theTree.children[i].value = NULL;
	}

	return 0;
}

char* searchString(const char* string)
{
	struct tree* ptr = &theTree;

	while (*string)
	{
		if (!ptr->children[*string].isSet)
		{
			return NULL;
		}

		ptr = &ptr->children[*string];

		string++;
	}

	return ptr->value;
}

int insertString(const char* string, const char* value)
{
	struct tree* ptr = &theTree;

	int elementIsIn = 1;

	while (*string)
	{
		if (!ptr->children[*string].isSet)
		{
			ptr->children[*string].isSet = 1;
			ptr->children[*string].children = (struct tree*)malloc(sizeof(struct tree) * 256);

			for (int i = 0; i < 256; i++)
			{
				ptr->children[*string].children[i].isSet = 0;
				ptr->children[*string].children[i].children = NULL;
				ptr->children[*string].children[i].value = NULL;
			}

			elementIsIn = 0;
		}

		ptr = &ptr->children[*string];

		string++;
	}

	if (ptr->value == NULL)
	{
		ptr->value = strdup(value);
	}

	return elementIsIn;
}

int main()
{
	const char* string1 = "Hello World";
	const char* string2 = "iyasfipouawfg";
	const char* string3 = "1234567879";
	const char* string4 = "Hot nigga";
	const char* string5 = "yoyoyoyo";
	const char* string6 = "Hello";
	const char* string7 = "Hot";
	const char* string8 = "Hello World";

	const char* val1 = "value1";
	const char* val2 = "value2";
	const char* val3 = "value3";
	const char* val4 = "value4";
	const char* val5 = "value5";
	const char* val6 = "value6";
	const char* val7 = "value7";
	const char* val8 = "value8";

	initTree();

	insertString(string1, val1);
	insertString(string2, val2);
	insertString(string3, val3);
	insertString(string4, val4);
	insertString(string6, val6);
	insertString(string8, val8);

	char* value1 = searchString(string1);
	char* value2 = searchString(string2);
	char* value3 = searchString(string3);
	char* value4 = searchString(string4);
	char* value5 = searchString(string5);
	char* value6 = searchString(string6);
	char* value7 = searchString(string7);

	printf("%s\n", value1 == NULL ? "not found" : value1);
	printf("%s\n", value2 == NULL ? "not found" : value2);
	printf("%s\n", value3 == NULL ? "not found" : value3);
	printf("%s\n", value4 == NULL ? "not found" : value4);
	printf("%s\n", value5 == NULL ? "not found" : value5);
	printf("%s\n", value6 == NULL ? "not found" : value6);
	printf("%s\n", value7 == NULL ? "not found" : value7);

	freeTree(theTree);
}
