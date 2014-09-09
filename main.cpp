
#include "NGHP.h"

void printusage()
{
	printf("\n  usage: ./nghp host [get|set] var value\n\n");
	printf("  example: get hp_duration\n    ./nghp http://localhost get hp_duration\n\n");
	printf("  example: set hp_duration\n    ./nghp http://localhost set hp_duration 80.5\n\n");

}

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		printusage();
		return 0;
	}

	try
	{
		NGHP nghp(argv[1], 5);
		string result;

		if (strcmp(argv[2], "get") == 0)
		{
			if (argc != 4)
			{
				printusage();
				return 0;
			}

			result = nghp.getCVar(argv[3]);
		}
		else if (strcmp(argv[2], "set") == 0)
		{
			if (argc != 5)
			{
				printusage();
				return 0;
			}

			result = nghp.setCVar(argv[3], argv[4]);
		}
		else
		{
			printusage();
			return 0;
		}

		cout << "result: " << result << endl << "body: " << nghp.getResponseBody() << endl << "http code: " << nghp.getResponseCode() << endl << "http message: " << nghp.getResponseMessage() << endl;
	}
	catch (CurlException &exception)
	{
		cout << "exception: " << exception.what() << endl;
	}

	return 0;
}
