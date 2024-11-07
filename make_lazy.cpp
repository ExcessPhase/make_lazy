#include <iostream>
#include <optional>
#include <type_traits>
#include <functional>
#include <vector>
#include <string>

template<typename F>
class lazy;


template<typename F>
lazy<F> make_lazy(F&&_r);


template<typename F>
class lazy
{	public:
#ifdef __cplusplus > 201703L
	typedef typename std::invoke_result<F>::type type;
#else
	typedef typename std::decay<decltype(std::declval<F>()())>::type type;
#endif
	private:
	std::optional<type> m_sO;
	F m_sF;
	public:
	lazy(F &&_r)
		:m_sF(std::move(_r))
	{
	}
	type &get(void)
	{	if (!m_sO)
			m_sO.emplace(m_sF());
		return *m_sO;
	}
	friend lazy<F> make_lazy(F&&_r);
};
template<typename F>
lazy<F> make_lazy(F&&_r)
{	return lazy<F>(std::move(_r));
}
int main(int argc, char**argv)
{
	auto sLazy = make_lazy(
		[](void)
		{		/// something expensive which one only wants to do
				/// if really necessary
				/// potentially reading a file and returning the contents
			return std::vector<std::string>();
		}
	);
	if (argc > 1)
		const auto &sLines = sLazy.get();
	std::cout << "Hello World!\n";
}
