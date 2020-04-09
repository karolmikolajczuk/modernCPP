#pragma once

#include <cmath>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

typedef unsigned long long ull;

class IPv4Manager
{
public:
	IPv4Manager(std::string ip = "");
	IPv4Manager(ull octet1, ull octet2 = 0, ull octet3 = 0, ull octet4 = 0);

	IPv4Manager(const IPv4Manager& ipv4);
	IPv4Manager(IPv4Manager&& ipv4);
	
	IPv4Manager& operator=(const IPv4Manager& ipv4);
	IPv4Manager& operator=(IPv4Manager&& ipv4);
	IPv4Manager& operator=(std::string ipv4);

	std::string getIP_str();
	void setIP(std::string ip);

	ull getFirst();
	void setFirst(ull first_octet);

	ull getSecond();
	void setSecond(ull second_octet);

	ull getThird();
	void setThird(ull third_octet);

	ull getFourth();
	void setFourth(ull fourth_octet);

	std::vector<ull> splitIP();

	bool validateIP(std::string ip);

	friend std::ostream& operator<<(std::ostream& os, IPv4Manager& ip);
	friend std::istream& operator>>(std::istream& is, IPv4Manager& ip);

	friend bool operator<(IPv4Manager& ip1, IPv4Manager& ip2);
	friend bool operator>(IPv4Manager& ip1, IPv4Manager& ip2);

	friend bool operator==(IPv4Manager& ip1, IPv4Manager& ip2);
	friend bool operator!=(IPv4Manager& ip1, IPv4Manager& ip2);

	friend ull operator-(IPv4Manager& ip1, IPv4Manager& ip2);

	friend void printAllAddresses(IPv4Manager& ip1, IPv4Manager& ip2);
	friend void print(const ull& o1, const ull& o2, const ull& o3, const ull& o4);

	~IPv4Manager();

private:

	ull first_octet;
	ull second_octet;
	ull third_octet;
	ull fourth_octet;

	std::string __ip;
};

