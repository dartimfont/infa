#include <iostream>
struct x
{
	enum lexemeType
	{
		LEFT_BRACKET, RIGHT_BRACKET,
		OP_PLUS, OP_MINUS, OP_MUL, OP_DIV,
		NUMBER,
		END_OF_FILE,
		LENGTH
	};
};


int main()
{
	int a = x::lexemeType::LENGTH;


	return 0;
}