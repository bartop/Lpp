
#pragma once

#include "../Boolean/Boolean.hpp"
#include <memory>
#include <functional>

namespace Lpp{

//  This is intermediate class between interface and implementation
//
//  It is designed to be used with interface as parameter for good results
template<typename T>
class TernaryOperator : public T {
public:
	TernaryOperator(
		std::shared_ptr<const Boolean> _condition,
		std::function<std::unique_ptr<const T>()> _ifTrue,
		std::function<std::unique_ptr<const T>()> _else);

	std::shared_ptr<const T> evaluate() const;
private:
	const std::shared_ptr<const Boolean> m_condition;
	const std::function<std::unique_ptr<const T>()> m_ifTrue;
	const std::function<std::unique_ptr<const T>()> m_else;
};

template<typename T>
TernaryOperator::TernaryOperator(
	std::shared_ptr<const Boolean> _conditon,
	std::function<std::unique_ptr<const T>()> _ifTrue,
	std::function<std::unique_ptr<const T>()> _else) : 
		m_condition(_condition),
		m_ifTrue(_ifTrue),
		m_else(_else){}

template<typename T>
std::shared_ptr<const T> evaluate() const{
	if(m_condition.value())
		return m_ifTrue();
	else 
		return m_else();
}

}
