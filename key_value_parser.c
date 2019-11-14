#include <string.h>
#include <stdio.h>

void parse(const char* str)
{
	

	/* strchr  - find first occurence
	 * strrchr - find last occurence
	 * if not equal -> more than one colon */
	if(strchr(str, ':') != strrchr(str, ':'))
	{
		printf("Invalid pair!\nToo many colons!\n\n");

		return;
	}

	/* parse key */
	char* key = strtok(str, ":");
	/* parse value */
	char* value = strtok(NULL, ":");

	/* triggers if line is empty or single colon */
	if(key == NULL)
	{
		printf("Invalid pair!\nKey missing!\n\n");

		return;
	}

	/* triggers for :abc or abc: */
	if(value == NULL)
	{
		printf("Invalid pair!\nValue missing!\n\n");

		return;
	}

	/* print values on success */
	printf("key:   <%s>\n", key);
	printf("value: <%s>\n\n", value);
}

int main()
{
	char str1[] = "Hallo:Welt";
	char str2[] = "Hallo:Welt:";
	char str3[] = "Hallo:";
	char str4[] = ":Welt";
	char str5[] = ":";
	char str6[] = "";
	
	parse(str1);
	parse(str2);
	parse(str3);
	parse(str4);
	parse(str5);
	parse(str6);

	return 0;
}