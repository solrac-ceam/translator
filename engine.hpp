#ifndef ENGINE_HPP
#define ENGINE_HPP

#include <string>
#include <set>

#include "json.hpp"

class Engine
{
private:
	struct LangComp;
public:
	struct LangInfoAndLocale {
		/* Info */
        std::string name;
        std::string endonym; // native name.
        std::string family;
        std::string iso_1;
        std::string iso_2;
        std::string iso_3;
        std::string glottolog;
        std::string script;
        bool        rtl;

        /* Locale */
        std::string translations_of;
        std::string definitions_of;
        std::string synonyms;
        std::string examples;
        std::string see_also;
	};

	Engine();
	std::set<LangInfoAndLocale, LangComp> getLanguages();
	~Engine();
	nlohmann::json sendRequestAndGetResponse(std::string text, std::string sl, std::string tl, std::string hl);

protected:
private:
	struct LangComp {
		bool operator()( const LangInfoAndLocale& lhs, const LangInfoAndLocale& rhs ) {
			return (lhs.name < rhs.name);
		}
	};
	unsigned reducedLevel(unsigned a, std::string str);
	std::string calculateToken(std::string str);
	std::string createRequestUrl(std::string text, std::string sl, std::string tl, std::string hl);
	void loadLanguages();

	std::string                           host_;
	int                                   port_;
	std::set<LangInfoAndLocale, LangComp> languages_;
};


#endif // ENGINE_HPP
