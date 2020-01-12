#include "JailSpace.h"
#include <iostream>
using namespace std;

JailSpace::JailSpace(std::string name, int pos)
	:NonProperty(name,pos)
{
}

void JailSpace::display()
{
cout<<     "\t ______________________________\n"
    <<     "\t|          /           /       |\n"
    <<     "\t|         /' .,,,,  ./         |\n"
    <<     "\t|        /';'     ,/           |\n"
    <<     "\t|       / /   ,,//,`'`         |\n"
    <<     "\t|      ( ,, '_,  ,,,' ``       |\n"
    <<     "\t|      |    /@  ,,, ; `        |\n"
    <<     "\t|     /    .   ,''/' `,``      |\n"
    <<     "\t|    /   .     ./, `,, `   ;   |\n"
    <<     "\t| ,./  .   ,-,',` ,,/''\\,'     |\n"
    <<     "\t| |  /; ./,,'`,,'' |   |       |\n"
    <<     "\t| |     /   ','   /    |       |\n"
    <<     "\t| \\___/'   '     |    |        |\n"
    <<     "\t| `,,'      |    /     `\\      |\n"
    <<     "\t|______________________________|\n";
}
