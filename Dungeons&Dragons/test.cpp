#include "pack.hpp"

#include <fstream>

struct ni : public std::vector<int>{
  public:
  float a=8;
  const char* b="hmm";
  std::tuple<const char*&,float&> pack={b,a};
};

// Dosent Debug
//struct pc : public Pack, public Unpack
//{
//	int a=99;
//	float b=4.5;
//protected:
//	Data pack() const override
//	{
//		static Packer p;
//		return p.pack(a,b);
//	}
//	void unpack(Iterator start, Iterator end)
//	{
//		static Unpacker u;
//		u.unpack(a,b);
//	}
//};

int main()
{
	Packer p;
	Unpacker u;
	ni n={.a=5.0f,.b="abba"};
	//pc pp;
	int a[] = {4,6,9,7};
	int b[4];
	p.pack(n,"Hello, World!", 3.14159265358979, std::vector<std::vector<int>>{{1,2,3,4,5,6,7,8,9},{0,1,2,3,4,5,6,7,8},{9,8,7,6,5,4,3,2,1}},std::make_pair("aa",9.7f));
	// Data d = p.pack(std::vector<int>{1,2,3,4,5,6,7,8,9});
	p.save("data.dat");
	Data d = p.pack(a);
	p.save("debug");
	u.load("data.dat");
	std::vector<std::vector<int>> v;
	const char* str;
	double important_number;
	ni na;
	std::pair<const char*, float> pair;
	std::cout << u.unpack(na,str,important_number,v,pair) << std::endl;
	u.load(d);
	std::cout << u.unpack(b) << std::endl;
	std::cout << "na.a = " << na.a << ", na.b = " << na.b << std::endl;
	std::cout << "String = " << str << std::endl;
	std::cout << "Important Number = " << important_number << std::endl;
	std::cout << "Vector = {";
	for(std::vector<int> s : v){
		std::cout << "{";
		for(int e : s)
			std::cout << e << ", ";
		std::cout << "}" << std::endl;
	}
	std::cout << "}" << std::endl;
	std::cout << "Pair: " << pair.first << " " << pair.second << std::endl;
	for(int e : b)
		std::cout << e << " " << std::endl;

	//std::cout << "PP: a = " << pp.a << ", b = " << pp.b << std::endl;
}
