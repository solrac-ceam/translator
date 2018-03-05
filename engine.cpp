#include "engine.hpp"

#include <chrono>

#include "httplib.h"

Engine::Engine()
	: host_("translate.googleapis.com"), port_(80), languages_()
{
	// Ctor
	loadLanguages();
}

std::set<Engine::LangInfoAndLocale, Engine::LangComp> Engine::getLanguages()
{
	return languages_;
}

unsigned Engine::reducedLevel(unsigned a, std::string str)
{
	for (unsigned i = 0; i < str.length(); i += 3) {
		unsigned d = str.at(i+2);
        d = (d >= 'a') ? d - 87 : d - '0';
        d = (str.at(i+1) == '+') ? a >> d : a << d;
        a = (str.at(i) == '+') ? (a + d) & 4294967295u : a ^ d;
	}

	return a;
}

std::string Engine::calculateToken(std::string str)
{
	std::chrono::time_point<std::chrono::system_clock> currentTime = std::chrono::system_clock::now();
	//std::chrono::duration<double,std::chrono::hours::period> hoursSinceEpoch(currentTime.time_since_epoch());
	//unsigned tkk = hoursSinceEpoch.count();
	unsigned tkk = std::chrono::duration_cast<std::chrono::hours>(currentTime.time_since_epoch()).count();

	unsigned a = tkk;
	for (unsigned i = 0; i < str.length(); ++i) {
		a += unsigned((unsigned char)(str.at(i)));
		a = reducedLevel(a, "+-a^+6");
	}
	a = reducedLevel(a, "+-3^+b+-f");
	a = (a < 0) ? (a & 2147483647) + 2147483648 : a;
	a %= 1000000;

	return std::to_string(a) + "." + std::to_string(a ^ tkk);
}

std::string Engine::createRequestUrl(std::string text, std::string sl, std::string tl, std::string hl)
{
	// "https://translate.google.com/translate_a/single?client=t&sl=en&tl=es&hl=pt-BR&dt=at&dt=bd&dt=ex&dt=ld&dt=md&dt=qca&dt=rw&dt=rm&dt=ss&dt=t&ie=UTF-8&oe=UTF-8&otf=2&ssel=5&tsel=5&kc=2&tk=307470.180716&q=dog"
    return std::string("/translate_a/single?client=gtx") +
		   "&sl=" + sl +
		   "&tl=" + tl +
		   "&hl=" + hl +
		   "&dt=at&dt=bd&dt=ex&dt=ld&dt=md&dt=qca&dt=rw&dt=rm&dt=ss&dt=t" +
		   "&ie=UTF-8&oe=UTF-8" +
		   "&q=" + text;
}

nlohmann::json Engine::sendRequestAndGetResponse(std::string text, std::string sl, std::string tl, std::string hl)
{
	nlohmann::json jsonRes;

	httplib::Client cli(host_.c_str(), port_);
	std::shared_ptr<httplib::Response> res = cli.get(createRequestUrl(text,sl,tl,hl).c_str());
	if ((res != nullptr) && (res->status == 200)) {
		jsonRes = nlohmann::json::parse(res->body);
	}
	else {
		jsonRes["status"] = res->status;
	}

	return jsonRes;
}

void Engine::loadLanguages()
{
	LangInfoAndLocale langTemp;

	/*
	langTemp.name            = "";
	langTemp.endonym         = "";
	langTemp.family          = "";
	langTemp.iso_1           = "";
	langTemp.iso_2           = "";
	langTemp.iso_3           = "";
	langTemp.glottolog       = "";
	langTemp.script          = "";
	langTemp.translations_of = "";
	langTemp.definitions_of  = "";
	langTemp.synonyms        = "";
	langTemp.examples        = "";
	langTemp.see_also        = "";
	langTemp.rtl             = ;
	languages_.insert(langTemp);
	*/

	langTemp.name            = " Auto Detect"; // the begin space is to put it on top of the set.
	langTemp.endonym         = "";
	langTemp.family          = "";
	langTemp.iso_1           = "auto";
	langTemp.iso_2           = "auto";
	langTemp.iso_3           = "auto";
	langTemp.glottolog       = "";
	langTemp.script          = "";
	langTemp.translations_of = "";
	langTemp.definitions_of  = "";
	langTemp.synonyms        = "";
	langTemp.examples        = "";
	langTemp.see_also        = "";
	langTemp.rtl             = false;
	languages_.insert(langTemp);

	langTemp.name            = "Afrikaans";
	langTemp.endonym         = "Afrikaans";
	langTemp.family          = "Indo-European";
	langTemp.iso_1           = "af";
	langTemp.iso_2           = "afr";
	langTemp.iso_3           = "afr";
	langTemp.glottolog       = "afri1274";
	langTemp.script          = "Latn";
	langTemp.translations_of = "Vertalings van %s";
	langTemp.definitions_of  = "Definisies van %s";
	langTemp.synonyms        = "Sinonieme";
	langTemp.examples        = "Voorbeelde";
	langTemp.see_also        = "Sien ook";
	langTemp.rtl             = false;
	languages_.insert(langTemp);

	langTemp.name            = "Albanian";
	langTemp.endonym         = "Shqip";
	langTemp.family          = "Indo-European";
	langTemp.iso_1           = "sq";
	langTemp.iso_2           = "sqi";
	langTemp.iso_3           = "sqi";
	langTemp.glottolog       = "alba1267";
	langTemp.script          = "Latn";
	langTemp.translations_of = "Përkthimet e %s";
	langTemp.definitions_of  = "Përkufizime të %s";
	langTemp.synonyms        = "Sinonime";
	langTemp.examples        = "Shembuj";
	langTemp.see_also        = "Shihni gjithashtu";
	langTemp.rtl             = false;
	languages_.insert(langTemp);

	langTemp.name            = "Amharic";
	langTemp.endonym         = "አማርኛ";
	langTemp.family          = "Afro.Asiatic";
	langTemp.iso_1           = "am";
	langTemp.iso_2           = "amh";
	langTemp.iso_3           = "amh";
	langTemp.glottolog       = "amha1245";
	langTemp.script          = "Ethi";
	langTemp.translations_of = "የ %s ትርጉሞች";
	langTemp.definitions_of  = "የ %s ቃላት ፍችዎች";
	langTemp.synonyms        = "ተመሳሳይ ቃላት";
	langTemp.examples        = "ምሳሌዎች";
	langTemp.see_also        = "የሚከተለውንም ይመልከቱ";
	langTemp.rtl             = false;
	languages_.insert(langTemp);

	langTemp.name            = "Arabic";
	langTemp.endonym         = "العربية";
	langTemp.family          = "Afro-Asiatic";
	langTemp.iso_1           = "ar";
	langTemp.iso_2           = "ara";
	langTemp.iso_3           = "ara";
	langTemp.glottolog       = "stan1318";
	langTemp.script          = "Arab";
	langTemp.translations_of = "ترجمات %s";
	langTemp.definitions_of  = "تعريفات %s";
	langTemp.synonyms        = "مرادفات";
	langTemp.examples        = "أمثلة";
	langTemp.see_also        = "انظر أيضًا";
	langTemp.rtl             = true;
	languages_.insert(langTemp);

	langTemp.name            = "Armenian";
	langTemp.endonym         = "Հայերեն";
	langTemp.family          = "Indo-European";
	langTemp.iso_1           = "hy";
	langTemp.iso_2           = "hye";
	langTemp.iso_3           = "hye";
	langTemp.glottolog       = "nucl1235";
	langTemp.script          = "Armn";
	langTemp.translations_of = "%s-ի թարգմանությունները";
	langTemp.definitions_of  = "%s-ի սահմանումները";
	langTemp.synonyms        = "Հոմանիշներ";
	langTemp.examples        = "Օրինակներ";
	langTemp.see_also        = "Տես նաև";
	langTemp.rtl             = false;
	languages_.insert(langTemp);

	langTemp.name            = "Azerbaijani";
	langTemp.endonym         = "Azərbaycanca";
	langTemp.family          = "Turkic";
	langTemp.iso_1           = "az";
	langTemp.iso_2           = "aze";
	langTemp.iso_3           = "aze";
	langTemp.glottolog       = "nort2697";
	langTemp.script          = "Latn";
	langTemp.translations_of = "%s sözünün tərcüməsi";
	langTemp.definitions_of  = "%s sözünün tərifləri";
	langTemp.synonyms        = "Sinonimlər";
	langTemp.examples        = "Nümunələr";
	langTemp.see_also        = "Həmçinin, baxın:";
	langTemp.rtl             = false;
	languages_.insert(langTemp);

	langTemp.name            = "Basque";
	langTemp.endonym         = "Euskara";
	langTemp.family          = "Language Isolate";
	langTemp.iso_1           = "eu";
	langTemp.iso_2           = "eus";
	langTemp.iso_3           = "eus";
	langTemp.glottolog       = "basq1248";
	langTemp.script          = "Latn";
	langTemp.translations_of = "%s esapidearen itzulpena";
	langTemp.definitions_of  = "Honen definizioak: %s";
	langTemp.synonyms        = "Sinonimoak";
	langTemp.examples        = "Adibideak";
	langTemp.see_also        = "Ikusi hauek ere";
	langTemp.rtl             = false;
	languages_.insert(langTemp);

	langTemp.name            = "Belarusian";
	langTemp.endonym         = "беларуская";
	langTemp.family          = "Indo-European";
	langTemp.iso_1           = "be";
	langTemp.iso_2           = "bel";
	langTemp.iso_3           = "bel";
	langTemp.glottolog       = "bela1254";
	langTemp.script          = "Cyrl";
	langTemp.translations_of = "Пераклады %s";
	langTemp.definitions_of  = "Вызначэннi %s";
	langTemp.synonyms        = "Сінонімы";
	langTemp.examples        = "Прыклады";
	langTemp.see_also        = "Гл. таксама";
	langTemp.rtl             = false;
	languages_.insert(langTemp);

	langTemp.name            = "Bengali";
	langTemp.endonym         = "বাংলা";
	langTemp.family          = "Indo-European";
	langTemp.iso_1           = "bn";
	langTemp.iso_2           = "ben";
	langTemp.iso_3           = "ben";
	langTemp.glottolog       = "ben";
	langTemp.script          = "Beng";
	langTemp.translations_of = "%s এর অনুবাদ";
	langTemp.definitions_of  = "%s এর সংজ্ঞা";
	langTemp.synonyms        = "প্রতিশব্দ";
	langTemp.examples        = "উদাহরণ";
	langTemp.see_also        = "আরো দেখুন";
	langTemp.rtl             = false;
	languages_.insert(langTemp);

	langTemp.name            = "Bosnian";
	langTemp.endonym         = "Bosanski";
	langTemp.family          = "Indo-European";
	langTemp.iso_1           = "bs";
	langTemp.iso_2           = "bos";
	langTemp.iso_3           = "bos";
	langTemp.glottolog       = "bosn1245";
	langTemp.script          = "Latn";
	langTemp.translations_of = "Prijevod za: %s";
	langTemp.definitions_of  = "Definicije za %s";
	langTemp.synonyms        = "Sinonimi";
	langTemp.examples        = "Primjeri";
	langTemp.see_also        = "Pogledajte i";
	langTemp.rtl             = false;
	languages_.insert(langTemp);

	langTemp.name            = "Bulgarian";
	langTemp.endonym         = "български";
	langTemp.family          = "Indo-European";
	langTemp.iso_1           = "bg";
	langTemp.iso_2           = "bul";
	langTemp.iso_3           = "bul";
	langTemp.glottolog       = "bulg1262";
	langTemp.script          = "Cyrl";
	langTemp.translations_of = "Преводи на %s";
	langTemp.definitions_of  = "Дефиниции за %s";
	langTemp.synonyms        = "Синоними";
	langTemp.examples        = "Примери";
	langTemp.see_also        = "Вижте също";
	langTemp.rtl             = false;
	languages_.insert(langTemp);

	langTemp.name            = "Catalan";
	langTemp.endonym         = "Català";
	langTemp.family          = "Indo-European";
	langTemp.iso_1           = "ca";
	langTemp.iso_2           = "cat";
	langTemp.iso_3           = "cat";
	langTemp.glottolog       = "stan1289";
	langTemp.script          = "Latn";
	langTemp.translations_of = "Traduccions per a %s";
	langTemp.definitions_of  = "Definicions de: %s";
	langTemp.synonyms        = "Sinònims";
	langTemp.examples        = "Exemples";
	langTemp.see_also        = "Vegeu també";
	langTemp.rtl             = false;
	languages_.insert(langTemp);

	langTemp.name            = "Cebuano";
	langTemp.endonym         = "Cebuano";
	langTemp.family          = "Austronesian";
	langTemp.iso_1           = "ceb";
	langTemp.iso_2           = "ceb";
	langTemp.iso_3           = "ceb";
	langTemp.glottolog       = "cebu1242";
	langTemp.script          = "Latn";
	langTemp.translations_of = "Mga Paghubad sa %s";
	langTemp.definitions_of  = "Mga kahulugan sa %s";
	langTemp.synonyms        = "Mga Kapulong";
	langTemp.examples        = "Mga pananglitan:";
	langTemp.see_also        = "Kitaa pag-usab";
	langTemp.rtl             = false;
	languages_.insert(langTemp);

	langTemp.name            = "Chichewa";
	langTemp.endonym         = "Nyanja";
	langTemp.family          = "Atlantic-Congo";
	langTemp.iso_1           = "ny";
	langTemp.iso_2           = "nya";
	langTemp.iso_3           = "nya";
	langTemp.glottolog       = "nyan1308";
	langTemp.script          = "Latn";
	langTemp.translations_of = "Matanthauzidwe a %s";
	langTemp.definitions_of  = "Mamasulidwe a %s";
	langTemp.synonyms        = "Mau ofanana";
	langTemp.examples        = "Zitsanzo";
	langTemp.see_also        = "Onaninso";
	langTemp.rtl             = false;
	languages_.insert(langTemp);

	langTemp.name            = "Chinese Simplified";
	langTemp.endonym         = "简体中文";
	langTemp.family          = "Sino-Tibetan";
	langTemp.iso_1           = "zh-CN";
	langTemp.iso_2           = "zho-CN";
	langTemp.iso_3           = "zho-CN";
	langTemp.glottolog       = "mand1415";
	langTemp.script          = "Hans";
	langTemp.translations_of = "%s的翻译";
	langTemp.definitions_of  = "%s的定义";
	langTemp.synonyms        = "同义词";
	langTemp.examples        = "示例";
	langTemp.see_also        = "另请参阅";
	langTemp.rtl             = false;
	languages_.insert(langTemp);

	langTemp.name            = "Chinese Traditional";
	langTemp.endonym         = "正體中文";
	langTemp.family          = "Sino-Tibetan";
	langTemp.iso_1           = "zh-TW";
	langTemp.iso_2           = "zho-TW";
	langTemp.iso_3           = "zho-TW";
	langTemp.glottolog       = "mand1415";
	langTemp.script          = "Hant";
	langTemp.translations_of = "「%s」的翻譯";
	langTemp.definitions_of  = "「%s」的定義";
	langTemp.synonyms        = "同義詞";
	langTemp.examples        = "例句";
	langTemp.see_also        = "另請參閱";
	langTemp.rtl             = false;
	languages_.insert(langTemp);

	langTemp.name            = "Corsican";
	langTemp.endonym         = "Corsu";
	langTemp.family          = "Indo-European";
	langTemp.iso_1           = "co";
	langTemp.iso_2           = "cos";
	langTemp.iso_3           = "cos";
	langTemp.glottolog       = "cors1242";
	langTemp.script          = "Latn";
	langTemp.translations_of = "Traductions de %s";
	langTemp.definitions_of  = "Définitions de %s";
	langTemp.synonyms        = "Synonymes";
	langTemp.examples        = "Exemples";
	langTemp.see_also        = "Voir aussi";
	langTemp.rtl             = false;
	languages_.insert(langTemp);

	langTemp.name            = "Croatian";
	langTemp.endonym         = "Hrvatski";
	langTemp.family          = "Indo-European";
	langTemp.iso_1           = "hr";
	langTemp.iso_2           = "hrv";
	langTemp.iso_3           = "hrv";
	langTemp.glottolog       = "croa1245";
	langTemp.script          = "Latn";
	langTemp.translations_of = "Prijevodi riječi ili izraza %s";
	langTemp.definitions_of  = "Definicije riječi ili izraza %s";
	langTemp.synonyms        = "Sinonimi";
	langTemp.examples        = "Primjeri";
	langTemp.see_also        = "Također pogledajte";
	langTemp.rtl             = false;
	languages_.insert(langTemp);

	langTemp.name            = "Czech";
	langTemp.endonym         = "Čeština";
	langTemp.family          = "Indo-European";
	langTemp.iso_1           = "cs";
	langTemp.iso_2           = "ces";
	langTemp.iso_3           = "ces";
	langTemp.glottolog       = "czec1258";
	langTemp.script          = "Latn";
	langTemp.translations_of = "Překlad výrazu %s";
	langTemp.definitions_of  = "Definice výrazu %s";
	langTemp.synonyms        = "Synonyma";
	langTemp.examples        = "Příklady";
	langTemp.see_also        = "Viz také";
	langTemp.rtl             = false;
	languages_.insert(langTemp);

	langTemp.name            = "Danish";
	langTemp.endonym         = "Dansk";
	langTemp.family          = "Indo-European";
	langTemp.iso_1           = "da";
	langTemp.iso_2           = "dan";
	langTemp.iso_3           = "dan";
	langTemp.glottolog       = "dani1285";
	langTemp.script          = "Latn";
	langTemp.translations_of = "Oversættelser af %s";
	langTemp.definitions_of  = "Definitioner af %s";
	langTemp.synonyms        = "Synonymer";
	langTemp.examples        = "Eksempler";
	langTemp.see_also        = "Se også";
	langTemp.rtl             = false;
	languages_.insert(langTemp);

	langTemp.name            = "Dutch";
	langTemp.endonym         = "Nederlands";
	langTemp.family          = "Indo-European";
	langTemp.iso_1           = "nl";
	langTemp.iso_2           = "nld";
	langTemp.iso_3           = "nld";
	langTemp.glottolog       = "dutc1256";
	langTemp.script          = "Latn";
	langTemp.translations_of = "Vertalingen van %s";
	langTemp.definitions_of  = "Definities van %s";
	langTemp.synonyms        = "Synoniemen";
	langTemp.examples        = "Voorbeelden";
	langTemp.see_also        = "Zie ook";
	langTemp.rtl             = false;
	languages_.insert(langTemp);

	langTemp.name            = "English";
	langTemp.endonym         = "English";
	langTemp.family          = "Indo-European";
	langTemp.iso_1           = "en";
	langTemp.iso_2           = "eng";
	langTemp.iso_3           = "eng";
	langTemp.glottolog       = "stan1293";
	langTemp.script          = "Latn";
	langTemp.translations_of = "Translations of %s";
	langTemp.definitions_of  = "Definitions of %s";
	langTemp.synonyms        = "Synonyms";
	langTemp.examples        = "Examples";
	langTemp.see_also        = "See also";
	langTemp.rtl             = false;
	languages_.insert(langTemp);

	langTemp.name            = "Esperanto";
	langTemp.endonym         = "Esperanto";
	langTemp.family          = "Artificial Language";
	langTemp.iso_1           = "eo";
	langTemp.iso_2           = "epo";
	langTemp.iso_3           = "epo";
	langTemp.glottolog       = "espe1235";
	langTemp.script          = "Latn";
	langTemp.translations_of = "Tradukoj de %s";
	langTemp.definitions_of  = "Difinoj de %s";
	langTemp.synonyms        = "Sinonimoj";
	langTemp.examples        = "Ekzemploj";
	langTemp.see_also        = "Vidu ankaŭ";
	langTemp.rtl             = false;
	languages_.insert(langTemp);

	langTemp.name            = "Estonian";
	langTemp.endonym         = "Eesti";
	langTemp.family          = "Uralic";
	langTemp.iso_1           = "et";
	langTemp.iso_2           = "est";
	langTemp.iso_3           = "est";
	langTemp.glottolog       = "esto1258";
	langTemp.script          = "Latn";
	langTemp.translations_of = "Sõna(de) %s tõlked";
	langTemp.definitions_of  = "Sõna(de) %s definitsioonid";
	langTemp.synonyms        = "Sünonüümid";
	langTemp.examples        = "Näited";
	langTemp.see_also        = "Vt ka";
	langTemp.rtl             = false;
	languages_.insert(langTemp);

	langTemp.name            = "Filipino";
	langTemp.endonym         = "Tagalog";
	langTemp.family          = "Austronesian";
	langTemp.iso_1           = "tl";
	langTemp.iso_2           = "tgl";
	langTemp.iso_3           = "tgl";
	langTemp.glottolog       = "tgl";
	langTemp.script          = "taga1270";
	langTemp.translations_of = "Mga pagsasalin ng %s";
	langTemp.definitions_of  = "Mga kahulugan ng %s";
	langTemp.synonyms        = "Mga Kasingkahulugan";
	langTemp.examples        = "Mga Halimbawa";
	langTemp.see_also        = "Tingnan rin ang";
	langTemp.rtl             = false;
	languages_.insert(langTemp);

	// TODO: add here the missing languages

	langTemp.name            = "Spanish";
	langTemp.endonym         = "Español";
	langTemp.family          = "Indo-European";
	langTemp.iso_1           = "es";
	langTemp.iso_2           = "spa";
	langTemp.iso_3           = "spa";
	langTemp.glottolog       = "stan1288";
	langTemp.script          = "Latn";
	langTemp.translations_of = "Traducciones de %s";
	langTemp.definitions_of  = "Definiciones de %s";
	langTemp.synonyms        = "Sinónimos";
	langTemp.examples        = "Ejemplos";
	langTemp.see_also        = "Ver también";
	langTemp.rtl             = false;
	languages_.insert(langTemp);

	// TODO: add here the missing languages
}

Engine::~Engine()
{
	// Dtor
}
