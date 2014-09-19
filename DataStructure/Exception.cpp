#ifndef _EXCEPTION_H_
#define _EXCEPTION_H_
class Exception{
protected:
	const char *message;
public:
	char *getMessage();
}; // class Exception

class NullPointerException : public Exception{
private:
	const static char *nullPointerMessage;
public:
	NullPointerException(){
		message = nullPointerMessage;
	}
}; // class NullPointerException
const char *NullPointerException::nullPointerMessage = "Null Pointer Exception";

class IndexOutOfBoundsException : public Exception{
private:
	const static char *indexOutOfBoundsMessage;
public:
	IndexOutOfBoundsException(){
		message = indexOutOfBoundsMessage;
	}
}; // class IndexOutOfBoundsException
const char *IndexOutOfBoundsException::indexOutOfBoundsMessage = "Index Out Of Bounds";

class ArithmeticException : public Exception{
private:
	const static char *arithmeticMessage;
public:
	ArithmeticException(){
		message = arithmeticMessage;
	}
}; // class ArithmeticException
const char *ArithmeticException::arithmeticMessage = "Arithmetic Exception";

class NumberFormatException : public Exception{
private:
	const static char *numberFormatMessage;
public:
	NumberFormatException(){
		message = numberFormatMessage;
	}
}; // class NumberFormatException
const char *NumberFormatException::numberFormatMessage = "Number Format Exception";

class IllegalArgumentException : public Exception{
private:
	const static char *illegalArgumentMessage;
public:
	IllegalArgumentException(){
		message = illegalArgumentMessage;
	}
}; // class IllegalArgumentException
const char *IllegalArgumentException::illegalArgumentMessage = "Illegal Argument";
#endif // _EXCEPTION_H_
