
#include "RealNumberOperations.hpp"
#include "RealNumberExchangeFormat.hpp"
#include "IntegerOperations.hpp"

namespace Lpp{

std::pair<
	RealNumberExchangeFormat,
	RealNumberExchangeFormat
> toCommonDenominator(
	const RealNumberExchangeFormat &_lhs,
	const RealNumberExchangeFormat &_rhs
){
	if(equals(_lhs.denominator, _rhs.denominator))
		return std::make_pair(_lhs, _rhs);
	else{
		const auto lcm = countLCM(_lhs.denominator, _rhs.denominator);
		const auto rightExtension = integerDivide(lcm, _rhs.denominator).first;
		const auto leftExtension = integerDivide(lcm, _lhs.denominator).first;
		return std::make_pair(
			RealNumberExchangeFormat(
				multiply(_lhs.numerator, leftExtension),
				multiply(_lhs.denominator, leftExtension)
			),
			RealNumberExchangeFormat(
				multiply(_rhs.numerator, rightExtension),
				multiply(_rhs.denominator, rightExtension)
			)
		);
	}
}

RealNumberExchangeFormat simplify(
	const RealNumberExchangeFormat &_realNumber
){
	const auto numerator = _realNumber.numerator;
	const auto denominator = _realNumber.denominator;
	const auto gcd = countGCD(numerator, denominator);
	if(equals(gcd, INTEGER_ONE))
		return _realNumber;

	return RealNumberExchangeFormat(
		integerDivide(numerator, gcd).first,
		integerDivide(denominator, gcd).first
	);
}

bool equals(
	const RealNumberExchangeFormat &_lhs,
	const RealNumberExchangeFormat &_rhs
){
	const auto left = simplify(_lhs);
	const auto right = simplify(_rhs);
	return equals(left.numerator, right.numerator) &&
		equals(left.denominator, right.denominator);
}

ResultOfComparison compare(
	const RealNumberExchangeFormat &_lhs,
	const RealNumberExchangeFormat &_rhs
){
	const auto withCommonDenominator = toCommonDenominator(_lhs, _rhs);
	return compare(
		withCommonDenominator.first.numerator,
		withCommonDenominator.second.numerator
	);
}

RealNumberExchangeFormat add(
	const RealNumberExchangeFormat &_lhs,
	const RealNumberExchangeFormat &_rhs
){
	const auto withCommonDenominator = toCommonDenominator(_lhs, _rhs);
	const auto left = withCommonDenominator.first;
	const auto right = withCommonDenominator.second;
	return RealNumberExchangeFormat(
		add(left.numerator, right.numerator),
		left.denominator
	);
}

RealNumberExchangeFormat multiply(
	const RealNumberExchangeFormat &_lhs,
	const RealNumberExchangeFormat &_rhs
){
	return RealNumberExchangeFormat(
		multiply(_lhs.numerator, _rhs.numerator),
		multiply(_lhs.denominator, _rhs.denominator)
	);
}

RealNumberExchangeFormat divide(
	const RealNumberExchangeFormat &_lhs,
	const RealNumberExchangeFormat &_rhs
){
	return RealNumberExchangeFormat(
		multiply(_lhs.numerator, _rhs.denominator),
		multiply(_lhs.denominator, _rhs.numerator)
	);
}

}
