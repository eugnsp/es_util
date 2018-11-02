#pragma once
#include <string>
#include <sstream>
#include <stdexcept>

namespace es::util
{
	// TO DO : Rename class
	class Error
	{
	public:
		explicit Error(const std::string& title) : title_(title)
		{ }

		template<typename T>
		Error& operator<<(const T& arg)
		{
			ss_ << arg;
			return *this;
		}

		Error& operator<<(void(*func)(Error&))
		{
			func(*this);
			return *this;
		}

		std::string string() const
		{
			if (is_ok_)
				return title_ + ": OK\n";
			else
				return title_ + " failed\n" + ss_.str() + '\n';
		}

		bool is_OK() const
		{
			return is_ok_;
		}

		void set_error_flag()
		{
			is_ok_ = false;
		}

		void throw_if_error() const
		{
			if (!is_ok_)
				throw std::runtime_error(string());
		}

		friend void error_flag(Error& err);

	private:
		bool is_ok_ = true;
		std::stringstream ss_;
		std::string title_;
	};

	inline void error_flag(Error& err)
	{
		err.is_ok_ = false;
	}
}