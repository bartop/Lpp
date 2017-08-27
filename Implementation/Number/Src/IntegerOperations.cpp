
#include "IntegerOperations.hpp"
#include "IntegerExchangeFormat.hpp"

#include <limits>
#include <stack>
#include <cassert>
#include <vector>

namespace Lpp{

namespace{

const unsigned NEGATIVE_SIGN_MEANINGLESS_VALUE = std::numeric_limits<unsigned>::max();
const unsigned POSITIVE_SIGN_MEANINGLESS_VALUE = std::numeric_limits<unsigned>::min();

constexpr inline
unsigned high(unsigned x) {
	return x >> (std::numeric_limits<unsigned>::digits / 2);
}

constexpr inline
unsigned low(unsigned x) {
	return ((1L << (std::numeric_limits<unsigned>::digits / 2)) - 1) & x;
}

//<TODO type="performance" severity="medium" reason="This magic should be implemented in assembly">
inline
std::pair<unsigned, unsigned> multiply(unsigned a, unsigned b) {
	unsigned s0, s1, s2, s3;

	unsigned x = low(a) * low(b);
	s0 = low(x);

	x = high(a) * low(b) + high(x);
	s1 = low(x);
	s2 = high(x);

	x = s1 + low(a) * high(b);
	s1 = low(x);

	x = s2 + high(a) * high(b) + high(x);
	s2 = low(x);
	s3 = high(x);

	return std::make_pair(
		s1 << (std::numeric_limits<unsigned>::digits / 2) | s0,
		s3 << (std::numeric_limits<unsigned>::digits / 2) | s2
	);
}
//</TODO>

constexpr inline
std::pair<unsigned, unsigned> addWithCarry(
	unsigned _lhs,
	unsigned _rhs,
	unsigned _carry
) noexcept {
	return std::make_pair<unsigned, unsigned>(
		 _lhs + _rhs + _carry,
		(_lhs + _rhs + _carry < _lhs ||
		 _lhs + _rhs + _carry < _rhs ||
		 _lhs + _rhs + _carry < _carry) ?
			1 : 0
	);
}

constexpr inline
unsigned unsignedMsb() noexcept {
	return std::numeric_limits<unsigned>::max() &
		(1u << (std::numeric_limits<unsigned>::digits - 1));
}

constexpr inline
unsigned getMsb(unsigned _number) noexcept {
	return unsignedMsb() & _number;
}

inline
unsigned getSign(const std::vector<unsigned> &_vector){
	if (_vector.size() == 0)
		return POSITIVE_SIGN_MEANINGLESS_VALUE;
	else
		return getMsb(_vector.at(_vector.size() - 1)) ?
			NEGATIVE_SIGN_MEANINGLESS_VALUE : POSITIVE_SIGN_MEANINGLESS_VALUE;
}

inline
unsigned safeAt(
	const std::vector<unsigned> &_vec,
	unsigned index
) noexcept {
	return index >= _vec.size() ? getSign(_vec) : _vec.at(index);
}

bool hasRedundantElements(const std::vector<unsigned> &_vector) noexcept {
	if(_vector.size() <= 1)
		return false;

	return (_vector.at(_vector.size() - 1) == getSign(_vector)) &&
			getMsb(_vector.at(_vector.size() - 1)) ==
				getMsb(_vector.at(_vector.size() - 2));
}

inline
std::vector<unsigned> removeUnusedBytes(
	std::vector<unsigned> _vector
) noexcept {
	while(hasRedundantElements(_vector)){
		_vector.pop_back();
	}
	return _vector;
}

inline
bool overflowedNegative(
	const std::vector<unsigned> &_lhs,
	const std::vector<unsigned> &_rhs,
	const std::vector<unsigned> &_result
){
	return getSign(_lhs) && getSign(_rhs) && !getSign(_result);
}

inline
bool overflowedPositive(
	const std::vector<unsigned> &_lhs,
	const std::vector<unsigned> &_rhs,
	const std::vector<unsigned> &_result
){
	return !getSign(_lhs) && !getSign(_rhs) && getSign(_result);
}
std::vector<unsigned> addVectors(
	const std::vector<unsigned> &_lhs,
	const std::vector<unsigned> &_rhs
){
	std::vector<unsigned> result;
	unsigned carry = 0;
	unsigned i = 0;
	while(i < std::max(_lhs.size(), _rhs.size())){
		const auto sum =
			addWithCarry(safeAt(_lhs, i), safeAt(_rhs, i), carry);

		result.push_back(sum.first);
		carry = sum.second;
		++i;
	}

	if(overflowedNegative(_lhs, _rhs, result))
		result.push_back(NEGATIVE_SIGN_MEANINGLESS_VALUE);

	if(overflowedPositive(_lhs, _rhs, result))
		result.push_back(POSITIVE_SIGN_MEANINGLESS_VALUE);

	return removeUnusedBytes(result);
}


std::vector<unsigned> multiplyWithShiftByNumber(
	const std::vector<unsigned> &_lhs,
	unsigned _rhs,
	unsigned _shift
){
	std::vector<unsigned> result(_lhs.size() + _shift + 1);
	for(unsigned i = 0; i < _lhs.size(); ++i){
		const auto multiplyResult  = multiply(_rhs, _lhs[i]);
		const auto addResult =
			addWithCarry(multiplyResult.first, result[i + _shift], 0);

		result[i + _shift] = addResult.first;
		result[i + _shift + 1] =
			multiplyResult.second + addResult.second;
	}

	while(result[result.size() - 1] == 0)
		result.pop_back();

	return result;
}

std::pair<IntegerExchangeFormat,
	IntegerExchangeFormat> unsignedDivide(
		const IntegerExchangeFormat &_lhs,
		const IntegerExchangeFormat &_rhs
){
	const auto divisor = _rhs;
	auto comparisonResult = compare(_lhs, divisor);
	auto dividend = _lhs.longInteger;
	auto result = INTEGER_ZERO.longInteger;
	//<TODO type="performance" severity="critical" reason="This algorithm needs optimization - it is very slow implementation">
	while(comparisonResult != ResultOfComparison::RightSideGreater){
		dividend = subtract(IntegerExchangeFormat(dividend), divisor).longInteger;
		result = addVectors(result, INTEGER_ONE.longInteger);
		comparisonResult = compare(dividend, divisor);
	}
	//</TODO>
	return std::make_pair(result, dividend);
}

IntegerExchangeFormat unsignedMultiply(
	const IntegerExchangeFormat &_lhs,
	const IntegerExchangeFormat &_rhs
){
	std::vector<unsigned> result;
	//<TODO type="performance" severity="high" reason="This algorithm needs optimization - it is the simplest implementation">
	for(unsigned i = 0; i < _rhs.longInteger.size(); ++i){
		const auto partialResult = multiplyWithShiftByNumber(
			_lhs.longInteger,
			_rhs.longInteger.at(i),
			i
		);
		result = addVectors(result, partialResult);
	}
	//</TODO>
	//<TODO type="code style" severity="minor" reason="This check should not ever happen. There must be a way to omit it">
	if(result.empty())
		result.push_back(0);
	//</TODO>
	return result;
}

IntegerExchangeFormat countUnsignedGCD(
	const IntegerExchangeFormat &_lhs,
	const IntegerExchangeFormat &_rhs
){
	const auto dividend = max(_lhs, _rhs);
	const auto divisor = min(_lhs, _rhs);
	if(equals(divisor, INTEGER_ZERO))
		return dividend;
	else
		return countGCD(
			divisor,
			integerDivide(dividend, divisor).second
		);
}

}

bool isNegative(
	const IntegerExchangeFormat &_number
){
	return getSign(_number.longInteger) != 0;
}

bool equals(
	const IntegerExchangeFormat &_lhs,
	const IntegerExchangeFormat &_rhs
){
	return _lhs.longInteger == _rhs.longInteger;
}

ResultOfComparison compare(
	const IntegerExchangeFormat &_lhs,
	const IntegerExchangeFormat &_rhs
){
	const auto difference = subtract(_lhs, _rhs);

	if(equals(difference, INTEGER_ZERO))
		return ResultOfComparison::Equal;
	else
		return (getSign(difference.longInteger) == 0) ?
			ResultOfComparison::LeftSideGreater :
			ResultOfComparison::RightSideGreater;
}

IntegerExchangeFormat negate(
	const IntegerExchangeFormat &_lhs
){
	auto result = _lhs.longInteger;
	for(auto &it : result){
		it = ~it;
	}
	return addVectors(result, {1});
}

IntegerExchangeFormat absoluteValue(
	const IntegerExchangeFormat &_lhs
){
	return getSign(_lhs.longInteger) ? negate(_lhs) : _lhs;
}

IntegerExchangeFormat add(
	const IntegerExchangeFormat &_lhs,
	const IntegerExchangeFormat &_rhs
){
	return addVectors(_lhs.longInteger, _rhs.longInteger);
}

IntegerExchangeFormat multiply(
	const IntegerExchangeFormat &_lhs,
	const IntegerExchangeFormat &_rhs
){
	if(getSign(_lhs.longInteger) == getSign(_rhs.longInteger))
		return unsignedMultiply(
			absoluteValue(_lhs),
			absoluteValue(_rhs)
		);
	else
		return negate(
			unsignedMultiply(
				absoluteValue(_lhs),
				absoluteValue(_rhs)
			)
		);
}

std::pair<
	IntegerExchangeFormat,
	IntegerExchangeFormat
> integerDivide(
	const IntegerExchangeFormat &_lhs,
	const IntegerExchangeFormat &_rhs
){
	const auto unsignedResult = unsignedDivide(
		absoluteValue(_lhs),
		absoluteValue(_rhs)
	);
	if(getSign(_lhs.longInteger) != getSign(_rhs.longInteger)) {
		return std::make_pair(
			negate(unsignedResult.first)
			, getSign(_rhs.longInteger) == 0 ?
				negate(unsignedResult.second) : unsignedResult.second
		);
	} else {
		return std::make_pair(
			unsignedResult.first
			, getSign(_rhs.longInteger) == 0 ?
				unsignedResult.second : negate(unsignedResult.second)
		);
	}
}

IntegerExchangeFormat max(
	const IntegerExchangeFormat &_lhs,
	const IntegerExchangeFormat &_rhs
){
	const auto comparisonResult = compare(_lhs, _rhs);
	if(comparisonResult == ResultOfComparison::LeftSideGreater)
		return _lhs;
	else
		return _rhs;
}

IntegerExchangeFormat min(
	const IntegerExchangeFormat &_lhs,
	const IntegerExchangeFormat &_rhs
){
	const auto comparisonResult = compare(_lhs, _rhs);
	if(comparisonResult == ResultOfComparison::RightSideGreater)
		return _lhs;
	else
		return _rhs;
}

IntegerExchangeFormat countGCD(
	const IntegerExchangeFormat &_lhs,
	const IntegerExchangeFormat &_rhs
){
	const auto absLeft = absoluteValue(_lhs);
	const auto absRight = absoluteValue(_rhs);
	return countUnsignedGCD(absLeft, absRight);
}

IntegerExchangeFormat countLCM(
	const IntegerExchangeFormat &_lhs,
	const IntegerExchangeFormat &_rhs
){
	return integerDivide(
			multiply(_lhs, _rhs),
			countGCD(_lhs, _rhs)
	).first;
}

}
