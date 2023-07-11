#include <iostream>
#include <string>
#include <algorithm>

#include "PerfectMathUtilities.h"
#include "CurrencyManager.h"
#include "BestTestServer.h"
#include "VectorEditor.h"
#include "CoinsMixture.h"
#include "UsbProxyController.h"
#include "BestInteger.h"


void PrintVector(const std::vector<int> vector)
{

	for (const auto& element : vector)
	{
		std::cout << element << ' ';
	}

	std::cout << std::endl;
}



int main()
{
	/*
	Value v1(24.6f);
	Value v2(10);

	Value v3(10.0f);
	Value v4(10);

	std::cout << AreEqual(v2, v3) << std::endl;
	std::cout << AreEqual(v2, v4) << std::endl;

	*/

	//Gold gold{ 33 };

	//Silver silver{ 51 };
	//
	//PrintCoins(gold);
	//PrintCoins(silver);

	//gold = gold + silver;

	//PrintCoins(gold);
	//PrintCoins(silver);
	//
	//gold = gold + 190;
	//PrintCoins(gold);

	/*
	using Coin = Cash::CoinsType;

	auto myCash = Cash(Coin::Silver, 23);
	myCash.PrintAllCash();
	auto reward = Cash(Coin::Gold, 4);
	reward.PrintAllCash();

	myCash += reward;
	myCash.PrintAllCash();

	
	myCash += reward;
	myCash.PrintAllCash();
	
	auto bigReward = reward + reward;
	bigReward.PrintAllCash();

	myCash += bigReward;
	myCash.PrintAllCash();
	*/
	
	
	//auto server = BestTestServer();

	//for (size_t i = 0; i < 12; i++)
	//{
	//	std::string request{ "best request" };
	//	std::string responce{ "empty responce" };
	//	server(request, responce);
	//	server(request);
	//	std::cout << "received responce: " << responce << std::endl << std::endl;
	//}
	

	/*std::vector<int> hps = { 300,200, 1100 };

	std::vector<MultishotDefenceTower> towers{ 42, 24, 10 };

	PrintVector(hps);

	bool areEnemiesProtected = false;

	for (const auto &tower : towers)
	{
		std::transform(hps.begin(), hps.end(), hps.begin(), tower);
	}

	PrintVector(hps);*/
	
	/*UsbProxyController usbController{ "/dev/ttuUSB2" };

	usbController.SendCommand("ping motor");
	usbController.SendCommand("set acceleration");
	usbController.SendCommand("set current");

	usbController.EchoHistory();

	UsbProxyController secondController(usbController);
	secondController.EchoHistory();*/
	
	BestInteger int1 = BestInteger(24);
	BestInteger int2 = 35;
	BestInteger int3{ 410 };

	std::cout << "value is " << int1 << std::endl;
	std::cout << "value is " << int2 << std::endl;
	std::cout << "value is " << int3 << std::endl;
	
	
}
