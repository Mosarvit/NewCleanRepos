#include "Utilities.h"

string Utilities::stringPadding(string original, size_t charCount)
{
	original.resize(charCount, ' ');
	return original;
}
