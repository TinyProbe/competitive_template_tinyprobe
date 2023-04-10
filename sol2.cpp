#include <bits/stdc++.h>
#include <unistd.h>
#define untieio\
	cin.tie(0)->ios::sync_with_stdio(0)
#define testcase(N)\
	int tc; for (N ? tc = N : fin >> tc; tc > 0; --tc) solve()
#define __MAIN__(N)\
	void solve();\
	signed main() { untieio; testcase(N); assert(fin && !(fin >> tc)); }
using namespace std;
using namespace chrono;

static class fastin {
	static constexpr int MAX_SIZE = 25e6;
	char buffer[MAX_SIZE];
	int index, size;
	bool state;
private:
	const char* next_chars() {
		if (index == size) { state = false; return buffer + index; }
		while (++index < size && isspace(buffer[index]));
		int l = index--;
		while (++index < size) if (isspace(buffer[index])) break;
		buffer[index] = '\0', state = index != l;
		return buffer + l;
	}
	char next_char() {
		if (index == size) { state = false; return '\0'; }
		while (++index < size && isspace(buffer[index]));
		if (index == size) { state = false; return '\0'; }
		return buffer[index];
	}
	long long atoll2(const char* s) {
		long long ll = 0, sign = 1;
		if (*s == '+' || *s == '-') { sign = -(*s++ - ','); }
		while (*s && isdigit(*s)) { ll = ll * 10 + (*s++ - '0'); }
		return ll * sign;
	}
	int lowercmp(const char* s1, const char* s2) {
		while (*s1 && *s2 && tolower(*s1) == tolower(*s2)) ++s1, ++s2;
		return *s1 - *s2;
	}
public:
	fastin() : index(-1), state(true) { assert((size = (int) read(0, buffer, MAX_SIZE)) < MAX_SIZE); }
	fastin& operator>>(bool& b)       { const char* cstr = next_chars();
		b = (!lowercmp(cstr, "true") ? true : (!lowercmp(cstr, "false") ? false : atoll2(cstr)));
		return *this; }
	fastin& operator>>(char& c)       { char tmp = next_char(); c = (tmp ? tmp : c); return *this; }
	fastin& operator>>(char* s)       { strcpy(s, next_chars()); return *this;   }
	fastin& operator>>(string& s)     { s = string(next_chars()); return *this;  }
	fastin& operator>>(double& d)     { d = atof(next_chars()); return *this;    }
	fastin& operator>>(float& f)      { f = atof(next_chars()); return *this;    }
	fastin& operator>>(long long& ll) { ll = atoll2(next_chars()); return *this; }
	fastin& operator>>(long& l)       { l = atoll2(next_chars()); return *this;  }
	fastin& operator>>(int& i)        { i = atoll2(next_chars()); return *this;  }
	fastin& operator>>(short& sh)     { sh = atoll2(next_chars()); return *this; }
	fastin& operator>>(unsigned long long& ull) { try { ull = stoull(next_chars()); } catch (...) {} return *this; }
	fastin& operator>>(unsigned long& ul)       { try { ul = stoul(next_chars()); } catch (...) {} return *this;   }
	fastin& operator>>(unsigned int& ui)        { try { ui = stoul(next_chars()); } catch (...) {} return *this;   }
	fastin& operator>>(unsigned short& ush)     { try { ush = stoul(next_chars()); } catch (...) {} return *this;  }
	operator bool() { return state; }
} fin;
static class fastout {
	static constexpr int MAX_SIZE = 25e6;
	char buffer[MAX_SIZE];
	int size;
public:
	~fastout() { assert(size == (int) write(1, buffer, size)); }
	fastout& operator<<(const bool& b)       { return (b ? *this << "true" : *this << "false"); }
	fastout& operator<<(const char& c)       { buffer[size++] = c; return *this; }
	fastout& operator<<(const char* s)       { int len = strlen(s); memcpy(buffer + size, s, len); size += len; return *this; }
	fastout& operator<<(const string& s)     { memcpy(buffer + size, s.c_str(), s.size()); size += s.size(); return *this; }
	fastout& operator<<(const double& d)     { return *this << to_string(d);  }
	fastout& operator<<(const float& f)      { return *this << to_string(f);  }
	fastout& operator<<(const long long& ll) { return *this << to_string(ll); }
	fastout& operator<<(const long& l)       { return *this << to_string(l);  }
	fastout& operator<<(const int& i)        { return *this << to_string(i);  }
	fastout& operator<<(const short& sh)     { return *this << to_string(sh); }
	fastout& operator<<(const unsigned long long& ull) { return *this << to_string(ull); }
	fastout& operator<<(const unsigned long& ul)       { return *this << to_string(ul);  }
	fastout& operator<<(const unsigned int& ui)        { return *this << to_string(ui);  }
	fastout& operator<<(const unsigned short& ush)     { return *this << to_string(ush); }
} fout;
#ifdef __TINY__
static class timetracker {
	time_point<system_clock> begin, end;
public:
	timetracker() { begin = system_clock::now(); }
	~timetracker() { end = system_clock::now(); fout << '\n' << microseconds(end - begin).count() << " us\n"; }
} _time_tracker;
#endif
#define int int64_t
#define F first
#define S second

__MAIN__(0);
void solve() {
	
}
