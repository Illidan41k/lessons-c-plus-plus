#include "RegularExpressions.h"
#include <string>
using std::string;
using std::regex;
using std::smatch;
#include <iostream>
using std::cout;
using std::endl;

void RegularExpressions::DoIt()
{
    
    const string input = "cat kitty Ccatti catrin";

    const regex expression(R"(cat)");
    smatch m;

    if (regex_search(input, m, expression))
    {
         for (string &&str : m)
         { 
             cout << str << endl;
         }
    }
    
}

void RegularExpressions::Iterators()
{
    std::string input("cat kitty Catti catrin");
    std::regex expression(R"(cat)");

    std::cout << input << std::endl;

    std::sregex_iterator iter(input.begin(), input.end(), expression);
    std::sregex_iterator end;

    while (iter != end)
    {

        std::cout << "match" << ": " << (*iter)[0] << std::endl;
        
        ++iter;
    }

}

void RegularExpressions::Experiments()
{
    std::string input("cat citty Catti catrin  mokc.train"); 
    std::regex expression(R"(.cat)");

    std::cout << input << std::endl;

    std::sregex_iterator iter(input.begin(), input.end(), expression);
    std::sregex_iterator end;

    while (iter != end)
    {

        std::cout << "match" << ": " << (*iter)[0] << std::endl;

        ++iter;
    }
}

void RegularExpressions::Symbols()
{
    std::string input("file.txt,  file1.txt, pitxterrr");
    std::regex expression(R"(\.txt)");

    std::cout << input << std::endl;

    std::sregex_iterator iter(input.begin(), input.end(), expression);
    std::sregex_iterator end;

    while (iter != end)
    {

        std::cout << "match" << ": " << (*iter)[0] << std::endl;

        ++iter;
    }
}

void RegularExpressions::AvailableValues()
{
    std::string input("Minsk Madrid M oscow MOGILEV M1F9 M9del");
    std::regex expression(R"(M...)");
    //std::regex expression(R"(M[iao][nds])");
    //std::regex expression(R"(M[a-zA-Z][a-zA-Z])");
    //std::regex expression(R"(M[^0-9][^0-9])"); 

    std::cout << input << std::endl;

    std::sregex_iterator iter(input.begin(), input.end(), expression);
    std::sregex_iterator end;

    while (iter != end)
    {

        std::cout << "match" << ": " << (*iter)[0] << std::endl;

        ++iter;
    }
}

void RegularExpressions::PatternSearch()
{
    std::string input("12.04.1878     03.02.2021  df.we.trop 13.18.1870");
    //std::regex expression(R"(..\...\.....)");
    //std::regex expression(R"([0-9][0-9]\.[0-9][0-9]\.[0-9][0-9][0-9][0-9])");
    
    //std::string str("(0[1-9]|[12][0-9]|3[01])");

    std::regex expression(R"((0[1-9]|[12][0-9]|3[01])\.(0[0-9]|1[012])\.[12][0-9][0-9][0-9])");
    std::cout << input << std::endl;

    std::sregex_iterator iter(input.begin(), input.end(), expression);
    std::sregex_iterator end;

    while (iter != end)
    {

        std::cout << "match" << ": " << (*iter)[0] << std::endl;

        ++iter;
    }
}

void RegularExpressions::MetaSymbols()
{
    std::cout << "=============" << std::endl;
    std::cout << "acd\bef"<<std::endl;
    std::cout << "=============" << std::endl;

    std::string input("12.04.1878     03.02.2021  df.we.trop");
    //std::regex expression(R"([0-9][0-9]\.[0-9][0-9]\.[0-9][0-9][0-9][0-9])");
    std::regex expression(R"(\d\d\.\d\d\.\d\d\d\d)");

    std::cout << input << std::endl;

    std::sregex_iterator iter(input.begin(), input.end(), expression);
    std::sregex_iterator end;

    while (iter != end)
    {

        std::cout << "match" << ": " << (*iter)[0] << std::endl;

        ++iter;
    }
}

void RegularExpressions::EmailValidation()
{
    std::string input("dchernashtan@gmail.com   nagibator2003@mail.ru     ole4kaNeZnauKakDelat@Email.ry ");
    std::regex expression(R"(\w+@\w+\.\w+)");

    std::cout << input << std::endl;

    std::sregex_iterator iter(input.begin(), input.end(), expression);
    std::sregex_iterator end;

    while (iter != end)
    {

        std::cout << "match" << ": " << (*iter)[0] << std::endl;

        ++iter;
    }
}

void RegularExpressions::RandomFeatures()
{

    //std::string input("this text doesn't actually mean sometexttthisnerg texter");
    std::string input(" hey hey yo yo");
    //std::regex expression(R"(\btext)");
    //std::regex expression(R"(\Btext)");
    //std::regex expression(R"(this)");
    //std::regex expression(R"(er$)");
    std::regex expression(R"([ ]+(\w+)[ ]+\1)");

    std::cout << input << std::endl;

    std::sregex_iterator iter(input.begin(), input.end(), expression);
    std::sregex_iterator end;

    while (iter != end)
    {

        std::cout << "match" << ": " << (*iter)[0] << std::endl;

        ++iter;
    }
}
