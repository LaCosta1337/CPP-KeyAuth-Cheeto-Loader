#include <iostream>
#include "api/KeyAuth.hpp"
#include "xorstr.hpp"
#include <tlhelp32.h>
#include <fstream>
#include <filesystem>
#include <urlmon.h>
#pragma comment (lib, "urlmon.lib")
using namespace KeyAuth;



std::string name = XorStr(""); 
std::string ownerid = XorStr(""); 
std::string secret = XorStr(""); 
std::string version = XorStr("1.0"); 
api KeyAuthApp(name, ownerid, secret, version);

void loadcheat()
{
	HRESULT a = URLDownloadToFile(NULL, _T("yourdownloadlink.dll"), _T("C:/Windwos/System32/lol.dll"), 0, NULL);//Change lol.dll to your dll name //only use if you have a internal if not feel free to delete this line

	HRESULT ab = URLDownloadToFile(NULL, _T("yourdownloadlink.exe"), _T("C:/Windwos/System32/lol.exe"), 0, NULL);//Change lol.exe to your injector or external cheat name 

	system("start C:/Windwos/System32/lol.exe "); //if your opens the dll put C:/Windwos/System32/lol.dll after the other directory example: C:/Windwos/System32/lol.exe C:/Windwos/System32/lol.dll
}
void drv()
{                                   //driver download link              //path of download
	HRESULT a = URLDownloadToFile(NULL, _T("yourdownloadlink.sys"), _T("C:/Windwos/System32/lol.sys"), 0, NULL);//Change lol.sys to your drivers name
	                                //mapper download link              //path of download
	HRESULT ab = URLDownloadToFile(NULL, _T("yourdownloadlink.exe"), _T("C:/Windwos/System32/mapper.exe"), 0, NULL);//Change mapper.exe to your mapper name

	system("C:/Windwos/System32/mapper.exe C:/Windwos/System32/lol.sys");

}
void loader()
{
	std::cout << XorStr("\n\n [1] Load Drivers\n [2] Load Cheat\n [3] Discord\n [4] Website\n\n Choose option: ");


	int option;
	std::cin >> option;
	switch (option)
	{
	case 1:
		drv();
		loader();
		break;
	case 2:
		loadcheat();
		loader();
		break;
	case 3:
		system("start yourinv");
		loader();
		break;
	case 4:
		system("start yourwebsite.com");
		loader();
		break;
	}
}


int main()
{

	SetConsoleTitleA(XorStr("C++ KeyAuth Cheat Loader | Example by @LaCosta#1337").c_str());
	std::cout << XorStr("\n\n Connecting..");
	KeyAuthApp.init();
	system(XorStr("cls").c_str());
	
	std::cout << XorStr("\n\n [1] Login\n [2] Register\n [3] Upgrade\n [4] License key only\n\n Choose option: ");

	int option;
	std::string username;
	std::string password;
	std::string key;

	std::cin >> option;
	switch (option)
	{
		case 1:
			std::cout << XorStr("\n\n Enter username: ");
			std::cin >> username;
			std::cout << XorStr("\n Enter password: ");
			std::cin >> password;
			KeyAuthApp.login(username, password);
			break;
		case 2:
			std::cout << XorStr("\n\n Enter username: ");
			std::cin >> username;
			std::cout << XorStr("\n Enter password: ");
			std::cin >> password;
			std::cout << XorStr("\n Enter license: ");
			std::cin >> key;
			KeyAuthApp.regstr(username,password,key);
			break;
		case 3:
			std::cout << XorStr("\n\n Enter username: ");
			std::cin >> username;
			std::cout << XorStr("\n Enter license: ");
			std::cin >> key;
			KeyAuthApp.upgrade(username, key);
			break;
		case 4:
			std::cout << XorStr("\n Enter license: ");
			std::cin >> key;
			KeyAuthApp.license(key);
			break;
		default:
			std::cout << XorStr("\n\n Status: Failure: Invalid Selection");
			Sleep(3000);
			exit(0);
	}
	
	
	#pragma region
	time_t rawtime = mktime(&KeyAuthApp.user_data.expiry);
	struct tm* timeinfo;
	timeinfo = localtime(&rawtime);
	printf(XorStr("\n Your Subscription Expires At: %s").c_str(), asctime(timeinfo));
	
	time_t currtime;
	struct tm* tminfo;
	time(&currtime);
	tminfo = localtime(&currtime);

	std::time_t x = std::mktime(tminfo);
	std::time_t y = std::mktime(&KeyAuthApp.user_data.expiry);
	if (x != (std::time_t)(-1) && y != (std::time_t)(-1))
	{
		double difference = std::difftime(y, x) / (60 * 60 * 24);
		std::cout << "\n " << difference << " day(s) left" << std::endl;
	}
	#pragma endregion Display Expiration Date and Days Left Until Expiry
	
	loader(); 
}
