#ifndef _BIG_INTEGER_H_
#define _BIG_INTEGER_H_
#include "../../Macro.cpp"
#define TO_SIGNED(x)	((signed)(x))

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
		if(origin.getArray() == NullArray)
			throw NullPointerException();
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
	
	inline unsigned* getArray(){
		if(this == BigIntegerNull)
		#ifdef _EXCEPTION_H_
			throw NullPointerException();
		#else
			return NullArray;
		#endif
		return array;
	}
	
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
		while(size > 1 && array[size] == 0 && TO_SIGNED(
				array[size-1]) >= 0){
			size--;
		}
		while(size > 1 && TO_SIGNED(array[size]) == -1 &&
				TO_SIGNED(array[size-1]) < 0 &&
				array[size-1] == INT_MIN){
			size--;
		}
		array[0] = size;
		return *this;
	}
	
	BigInteger expand(unsigned newSize, bool extendSign){
		if(getArray() == NullArray){
			BigInteger n(NullArray);
			return n;
		}
		if(newSize <= array[0]) return *(new BigInteger(*this));
		BigInteger nbi(new unsigned[newSize+1]);
		register unsigned i;
		for(i = 0; i <= array[0]; i++) nbi.array[i] = array[i];
		if(extendSign && TO_SIGNED(array[array[0]]) < 0){
			for(; i <= newSize; i++) nbi.array[i] = -1;
		}else{
			for(; i <= newSize; i++) nbi.array[i] = 0;
		}
		return nbi;
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
		if(TO_SIGNED(array[array[0]]) >= 0) return *this;
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
		if(TO_SIGNED(array[array[0]]) >= 0) return *this;
		return this->negate();
	}
	
	int getSign(){
		if(getArray() == NullArray) return 2;
		if(TO_SIGNED(array[array[0]]) < 0) return -1;
		for(register unsigned size = array[0]; size > 0; size--){
			if(array[size] > 0) return 1;
		}
		return 0;
	}
	
	int compareTo(BigInteger bi){
		if(getArray() == NullArray || bi.getArray() == NullArray)
			return 2;
		return 0;
	}
	
	BigInteger _bitwiseNot(){
		if(getArray() == NullArray){
			BigInteger n(NullArray);
			return n;
		}
		for(register unsigned size = array[0]; size > 0; size--){
			array[size] = ~array[size];
		}	
		return (*this);
	}
	
	BigInteger bitwiseNot(){
		if(getArray() == NullArray){
			BigInteger n(NullArray);
			return n;
		}
		register BigInteger* temp = new BigInteger(*this);
		return temp->_bitwiseNot();
	}
	
	BigInteger _bitwiseAnd(BigInteger bi, bool extendSign){
		if(getArray() == NullArray || bi.getArray() == NullArray){
			BigInteger n(NullArray);
			return n;
		}
		register unsigned i;
		if(array[0] <= bi.array[0]){
			for(i = array[0]; i > 0; i--) array[i] &= bi.array[i];
		}else{
			for(i = 1; i <= bi.array[0]; i++)
				array[i] &= bi.array[i];
			if(!extendSign || TO_SIGNED(bi.array[bi.array[0]]) >= 0)
				for(; i <= array[0]; i++)
					array[i] = 0;	// and 0
		}
		return *this;
	}
	BigInteger bitwiseAnd(BigInteger bi, bool extendSign){
		if(getArray() == NullArray || bi.getArray() == NullArray){
			BigInteger n(NullArray);
			return n;
		}
		BigInteger nbi;
		register unsigned i;
		if(array[0] <= bi.array[0]){
			nbi = this->expand(bi.array[0], extendSign);
			for(i = array[0]; i > 0; i--)
				nbi.array[i] &= bi.array[i];
			if(!extendSign || TO_SIGNED(bi.array[bi.array[0]]) >= 0)
				for(; i <= bi.array[0]; i++)
					nbi.array[i] = 0;	// and 0
		}else{
			nbi = *(new BigInteger(*this));
			for(i = 1; i <= bi.array[0]; i++)
				nbi.array[i] &= bi.array[i];
			if(!extendSign || TO_SIGNED(bi.array[bi.array[0]]) >= 0)
				for(; i <= array[0]; i++)
					nbi.array[i] = 0;	// and 0
		}
		return nbi;
	}
	
	BigInteger _bitwiseOr(BigInteger bi, bool extendSign){
		if(getArray() == NullArray || bi.getArray() == NullArray){
			BigInteger n(NullArray);
			return n;
		}
		register unsigned i;
		if(array[0] <= bi.array[0]){
			for(i = array[0]; i > 0; i--) array[i] &= bi.array[i];
		}else{
			for(i = 1; i <= bi.array[0]; i++)
				array[i] |= bi.array[i];
			if(extendSign && TO_SIGNED(bi.array[bi.array[0]]) < 0)
				for(; i <= array[0]; i++)
					array[i] = -1;	// or -1
		}
		return *this;
	}
	BigInteger bitwiseOr(BigInteger bi, bool extendSign){
		if(getArray() == NullArray || bi.getArray() == NullArray){
			BigInteger n(NullArray);
			return n;
		}
		BigInteger nbi;
		register unsigned i;
		if(array[0] <= bi.array[0]){
			nbi = this->expand(bi.array[0], extendSign);
			for(i = array[0]; i > 0; i--)
				nbi.array[i] |= bi.array[i];
			if(extendSign && TO_SIGNED(bi.array[bi.array[0]]) < 0)
				for(; i <= bi.array[0]; i++)
					nbi.array[i] = -1;	// or -1
		}else{
			nbi = *(new BigInteger(*this));
			for(i = 1; i <= bi.array[0]; i++)
				nbi.array[i] |= bi.array[i];
			if(extendSign && TO_SIGNED(bi.array[bi.array[0]]) < 0)
				for(; i <= array[0]; i++)
					nbi.array[i] = -1;	// or -1
		}
		return nbi;
	}
	
	BigInteger _bitwiseXor(BigInteger bi, bool extendSign){
		if(getArray() == NullArray || bi.getArray() == NullArray){
			BigInteger n(NullArray);
			return n;
		}
		register unsigned i;
		if(array[0] <= bi.array[0]){
			for(i = array[0]; i > 0; i--) array[i] &= bi.array[i];
		}else{
			for(i = 1; i <= bi.array[0]; i++)
				array[i] ^= bi.array[i];
			if(extendSign && TO_SIGNED(bi.array[bi.array[0]]) < 0)
				for(; i <= array[0]; i++)
					array[i] = -1;	// or -1
		}
		return *this;
	}
	BigInteger bitwiseXor(BigInteger bi, bool extendSign){
		if(getArray() == NullArray || bi.getArray() == NullArray){
			BigInteger n(NullArray);
			return n;
		}
		BigInteger nbi;
		register unsigned i;
		if(array[0] <= bi.array[0]){
			nbi = this->expand(bi.array[0], extendSign);
			for(i = array[0]; i > 0; i--)
				nbi.array[i] ^= bi.array[i];
			if(extendSign && TO_SIGNED(bi.array[bi.array[0]]) < 0)
				for(; i <= bi.array[0]; i++)
					nbi.array[i] = ~bi.array[i];	// xor -1
			else
				for(; i <= bi.array[0]; i++)
					nbi.array[i] = bi.array[i];	// xor 0
		}else{
			nbi = *(new BigInteger(*this));
			for(i = 1; i <= bi.array[0]; i++)
				nbi.array[i] ^= bi.array[i];
			if(extendSign && TO_SIGNED(bi.array[bi.array[0]]) < 0)
				for(; i <= array[0]; i++)
					nbi.array[i] = ~array[i];	// xor -1
		}
		return nbi;
	}
	
	BigInteger _add(BigInteger bi){
		if(getArray() == NullArray || bi.getArray() == NullArray){
			BigInteger n(NullArray);
			return n;
		}
		register unsigned carry = 0, i;
		if(array[0] <= bi.array[0]){
			for(i = 1; i <= array[0]; i++){
				array[i] += bi.array[i] + carry;
				carry = (carry != 0 &&
					bi.array[i] == array[i] ||
					bi.array[i] > array[i]);
			}
		}else{
			for(i = 1; i <= bi.array[0]; i++){
				array[i] += bi.array[i] + carry;
				carry = (bi.array[i] + carry > array[i]);
				carry = (carry != 0 &&
					bi.array[i] == array[i] ||
					bi.array[i] > array[i]);
			}
			register unsigned sign =
				TO_SIGNED(bi.array[bi.array[0]]) < 0 ? -1 : 0;
			for(; i <= array[0]; i++){
				array[i] += carry + sign;
				carry = (array[i] < carry + sign);
			}
		}
		return *this;
	}
	BigInteger add(BigInteger bi){
		if(getArray() == NullArray || bi.getArray() == NullArray){
			BigInteger n(NullArray);
			return n;
		}
		return this->expand(array[0] < bi.array[0] ? 1 + bi.array[0] :
			1 + array[0], true)._add(bi);
	}
	
}; // class BigInteger
BigInteger*const BigInteger::BigIntegerNull = reinterpret_cast<BigInteger*>(0);
unsigned*const BigInteger::NullArray = reinterpret_cast<unsigned*>(0);
#endif // _BIG_INTEGER_H_
