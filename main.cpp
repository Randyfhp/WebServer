#include <fastcgi++/request.hpp>
#include <fastcgi++/manager.hpp>
#include <fastcgi++/log.hpp>

class HelloWorld : public Fastcgipp::Request<wchar_t>
{
    //! [Request definition]
    //! [Response definition]
    bool response()
    {

        DEBUG_LOG("enviroment" << environment().host)
        for (auto cgets_begin  = environment().gets.cbegin(); cgets_begin != environment().gets.cend(); ++cgets_begin) {
            DEBUG_LOG("gets " << cgets_begin->key() << cgets_begin->value());
        }
        

        DEBUG_LOG("enviroment" << environment().host);

        //! [Response definition]
        //! [HTTP header]
        out << L"Content-Type: text/html; charset=utf-8\r\n\r\n";
        //! [HTTP header]

        //! [Output]
        out << L"<!DOCTYPE html>\n"
               L"<html>"
               L"<head>"
               L"<meta charset='utf-8' />"
               L"<title>fastcgi++: Hello World</title>"
               L"</head>"
               L"<body>"
               L"<p>"
               L"English: Hello World<br>"
               L"Russian: Привет мир<br>"
               L"Greek: Γεια σας κόσμο<br>"
               L"Chinese: 世界您好<br>"
               L"Japanese: 今日は世界<br>"
               L"Runic English?: ᚺᛖᛚᛟ ᚹᛟᛉᛚᛞ<br>"
               L"</p>"
               L"</body>"
               L"</html>";
        //! [Output]

        //! [Return]
        return true;
    }
};

int main()
{
    Fastcgipp::Manager<HelloWorld> manager;
    //! [Manager]
    //! [Signals]
    manager.setupSignals();
    //! [Signals]
    //! [Listen]
    manager.listen();
    //! [Listen]
    //! [Start]
    manager.start();
    //! [Start]
    //! [Join]
    manager.join();

    return 0;
}
