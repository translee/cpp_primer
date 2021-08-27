#pragma once
class Screen
{
public:
	typedef std::string::size_type pos;
	// ¹¹Ôìº¯Êý
	Screen() = default;
	Screen(pos ht, pos wd, char c)
		: height(ht)
		, width(wd)
		, contents(ht * wd, c)
	{}

	char get() const { return contents[cursor]; }
	inline char get(pos ht, pos wd) const;
	Screen& move(pos r, pos c);
	void some_member() const;

private:
	pos cursor = 0;
	pos height = 0, width = 0;
	std::string contents;
	mutable size_t access_ctr;
};

