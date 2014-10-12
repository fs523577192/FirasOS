#ifndef _BIG_INTEGER_H_
#define _BIG_INTEGER_H_
#include "../../Macro.cpp"

class BigInteger{
protected:
	
	unsigned *array;
	
	BigInteger(unsigned*const theArray){
		array = theArray;
	}
public:
	
	static BigInteger*const BigIntegerNull;
	static unsigned*const NullArray;
	BigInteger(){
		array = new unsigned[2];
		array[0] = 1; array[1] = 0;
	}
	
	BigInteger(const int initial){
		if(initial == INT_MIN){
			array = new unsigned[3];
			array[0] = 2; array[1] = INT_MIN; array[2] = ~0;
		}else{
			array = new unsigned[2];
			array[0] = 1; array[1] = initial;
		}
	}
	
	BigInteger(const BigInteger& origin){
		#ifdef _EXCEPTION_H_
		if(origin.array == NullArray) throw NullPointerException();
		#endif
		register unsigned size = origin.array[0]+1;
		array = new unsigned[size];
		do{
			--size;
			array[size] = origin.array[size];
		}while(size > 0);
	}
	
	~BigInteger(){
		if(array != NullArray) delete array;
	}
protected:
	
	BigInteger trim(){
		if(this == BigIntegerNull || array == NullArray){
		#ifdef _EXCEPTION_H_
			throw NullPointerException();
		#else
			BigInteger n(NullArray);
			return n;
		#endif
		}
		register unsigned size = array[0];
		while(size > 1 && array[size] == 0 && (signed)(
				array[size-1]) >= 0){
			size--;
		}
		while(size > 1 && (signed)(array[size]) == -1 &&
				(signed)(array[size-1]) < 0 &&
				array[size-1] == INT_MIN){
			size--;
		}
		array[0] = size;
		return *this;
	}
	
	BigInteger expand(){
		if(this == BigIntegerNull || array == NullArray){
		#ifdef _EXCEPTION_H_
			throw NullPointerException();
		#else
			BigInteger n(NullArray);
			return n;
		#endif
		}
		
		return *this;
	}
public:
	
	BigInteger _negate(){
		if(this == BigIntegerNull || array == NullArray){
		#ifdef _EXCEPTION_H_
			throw NullPointerException();
		#else
			BigInteger n(NullArray);
			return n;
		#endif
		}
		register unsigned i = 1;
		while(i < array[0] && array[i] == 0) i++;
		array[i] = -array[i];
		i++;
		while(i <= array[0]){
			array[i] = ~array[i];
			i++;
		}
		return *this;
	}
	BigInteger negate(){
		if(this == BigIntegerNull || array == NullArray){
		#ifdef _EXCEPTION_H_
			throw NullPointerException();
		#else
			BigInteger n(NullArray);
			return n;
		#endif
		}
		register BigInteger *temp = new BigInteger(*this);
		return temp->_negate();
	}
	
	BigInteger _absolute(){
		if(this == BigIntegerNull || array == NullArray){
		#ifdef _EXCEPTION_H_
			throw NullPointerException();
		#else
			BigInteger n(NullArray);
			return n;
		#endif
		}
		if((signed)(array[array[0]]) >= 0) return *this;
		return this->_negate();
	}
	BigInteger absolute(){
		if(this == BigIntegerNull || array == NullArray){
		#ifdef _EXCEPTION_H_
			throw NullPointerException();
		#else
			BigInteger n(NullArray);
			return n;
		#endif
		}
		if((signed)(array[array[0]]) >= 0) return *this;
		return this->negate();
	}
	
	int getSign(){
		if(this == BigIntegerNull || array == NullArray)
		#ifdef _EXCEPTION_H_
			throw NullPointerException();
		#else
			return 2;
		#endif
		if((signed)(array[array[0]]) < 0) return -1;
		for(register unsigned size = array[0]; size > 0; size--){
			if(array[size] > 0) return 1;
		}
		return 0;
	}
}; // class BigInteger
BigInteger*const BigInteger::BigIntegerNull = reinterpret_cast<BigInteger*>(0);
unsigned*const BigInteger::NullArray = reinterpret_cast<unsigned*>(0);
#endif // _BIG_INTEGER_H_
