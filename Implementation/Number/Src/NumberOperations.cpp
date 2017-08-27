
#include "RealNumberOperations.hpp"
#include "NumberOperations.hpp"

namespace Lpp{

bool equals(
	const NumberExchangeFormat &_lhs,
	const NumberExchangeFormat &_rhs
){
	return equals(_lhs.realPart, _rhs.realPart) &&
		equals(_lhs.imaginaryPart, _rhs.imaginaryPart);
}

NumberExchangeFormat add(
	const NumberExchangeFormat &_lhs,
	const NumberExchangeFormat &_rhs
){
	return NumberExchangeFormat(
		add(_lhs.realPart, _rhs.realPart),
		add(_lhs.imaginaryPart, _rhs.imaginaryPart)
	);
}

NumberExchangeFormat multiply(
	const NumberExchangeFormat &_lhs,
	const NumberExchangeFormat &_rhs
){
	return NumberExchangeFormat(
		subtract(
			multiply(_lhs.realPart, _rhs.realPart),
			multiply(_lhs.imaginaryPart, _rhs.imaginaryPart)
		),
		add(
			multiply(_lhs.imaginaryPart, _rhs.realPart),
			multiply(_lhs.realPart, _rhs.imaginaryPart)
		)
	);
}

NumberExchangeFormat divide(
	const NumberExchangeFormat &_lhs,
	const NumberExchangeFormat &_rhs
){
	return NumberExchangeFormat(
		subtract(
			multiply(_lhs.realPart, _rhs.realPart),
			multiply(_lhs.imaginaryPart, _rhs.imaginaryPart)
		),
		add(
			multiply(_lhs.imaginaryPart, _rhs.realPart),
			multiply(_lhs.realPart, _rhs.imaginaryPart)
		)
	);
}

}
