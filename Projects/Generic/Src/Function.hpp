
#pragma once

#include <functional>
#include <tuple>

namespace Lpp{

template<typename F, typename Tuple, size_t ...S >
decltype(auto) apply_tuple_impl(F&& fn, Tuple&& t, std::index_sequence<S...>)
{
	return std::forward<F>(fn)(std::get<S>(std::forward<Tuple>(t))...);
}

template<typename F, typename Tuple>
decltype(auto) apply(F&& fn, Tuple&& t)
{
	std::size_t constexpr tSize
		= std::tuple_size<typename std::remove_reference<Tuple>::type>::value;
	return apply_tuple_impl(
		std::forward<F>(fn),
		std::forward<Tuple>(t),
		std::make_index_sequence<tSize>()
	);
}

template<typename I, typename T, typename... Args>
class Function final : public I {
public:
  Function(std::function<T(Args...)> _function, Args&&... _args);

  T value() const final override;

private:
  const std::function<T(Args...)> m_function;
  const std::tuple<Args...> m_arguments;
};

template<typename I, typename T, typename... Args>
Function<I, T, Args...>::Function(
	std::function<T(Args...)> _function
	, Args&&... _args
) : m_function(_function), m_arguments(std::forward<Args>(_args)...)
{}

template<typename I, typename T, typename... Args>
T Function<I, T, Args...>::value() const{
	return apply(m_function, m_arguments);
}

}
