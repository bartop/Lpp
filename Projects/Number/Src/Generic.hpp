
#pragma once

namespace Lpp{

template<typename T>
bool differs(const T &_lhs, const T &_rhs){
	return !equals(_lhs, _rhs);
}

template<typename T>
T subtract(const T &_lhs, const T &_rhs){
	return add(_lhs, negate(_rhs));
}

}
