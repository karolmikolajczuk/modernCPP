#include "IPv4Manager.h"

IPv4Manager::IPv4Manager(std::string ip) : __ip{ ip }, first_octet{ NULL }, second_octet{ NULL },
third_octet{ NULL }, fourth_octet{ NULL } {
	if (!ip.empty()) {
		std::vector<ull> splitted;
		for (int cursor = 0; cursor != std::string::npos; ) {
			splitted.push_back(
				std::stoull(
					this->__ip.substr(
						cursor, this->__ip.find(
							".", cursor) - cursor)));
			cursor = this->__ip.find(".", cursor);
			if (cursor != std::string::npos) cursor += 1;
		}
		this->first_octet = splitted.front();
		this->second_octet = splitted.at(1);
		this->third_octet = splitted.at(2);
		this->fourth_octet = splitted.back();
	}
}

IPv4Manager::IPv4Manager(ull octet1, ull octet2, ull octet3, ull octet4) :
	first_octet{ octet1 }, second_octet{ octet2 }, third_octet{ octet3 }, fourth_octet{ octet4 } {

	this->__ip = std::to_string(this->first_octet) + "." + std::to_string(this->second_octet) + "." +
		std::to_string(this->third_octet) + "." + std::to_string(this->fourth_octet);
}

IPv4Manager::IPv4Manager(const IPv4Manager& ipv4) : __ip{ ipv4.__ip }, 
first_octet{ ipv4.first_octet }, second_octet{ ipv4.second_octet }, 
third_octet{ ipv4.third_octet }, fourth_octet{ ipv4.fourth_octet } {

}

IPv4Manager::IPv4Manager(IPv4Manager&& ipv4) : __ip{ ipv4.__ip }, first_octet{ ipv4.first_octet },
second_octet{ ipv4.second_octet }, third_octet{ ipv4.third_octet }, fourth_octet{ ipv4.fourth_octet } {
	ipv4.~IPv4Manager();
}

IPv4Manager& IPv4Manager::operator=(const IPv4Manager& ipv4) {
	this->__ip = ipv4.__ip;
	this->first_octet = ipv4.first_octet;
	this->second_octet = ipv4.second_octet;
	this->third_octet = ipv4.third_octet;
	this->fourth_octet = ipv4.fourth_octet;
	return *this;
}

IPv4Manager& IPv4Manager::operator=(IPv4Manager&& ipv4) {
	this->__ip = ipv4.__ip;
	this->first_octet = ipv4.first_octet;
	this->second_octet = ipv4.second_octet;
	this->third_octet = ipv4.third_octet;
	this->fourth_octet = ipv4.fourth_octet;
	ipv4.~IPv4Manager();
	return *this;
}

IPv4Manager& IPv4Manager::operator=(std::string ipv4) {
	this->__ip = ipv4;
	return *this;
}

std::string IPv4Manager::getIP_str() {
	return this->__ip;
}

void IPv4Manager::setIP(std::string ip) {
	this->__ip = ip;
}

ull IPv4Manager::getFirst() {
	return this->first_octet;
}

void IPv4Manager::setFirst(ull first_octet) {
	this->first_octet = first_octet;
}

ull IPv4Manager::getSecond() {
	return this->second_octet;
}

void IPv4Manager::setSecond(ull second_octet) {
	this->second_octet = second_octet;
}

ull IPv4Manager::getThird() {
	return this->third_octet;
}

void IPv4Manager::setThird(ull third_octet) {
	this->third_octet = third_octet;
}

ull IPv4Manager::getFourth() {
	return this->fourth_octet;
}

void IPv4Manager::setFourth(ull fourth_octet) {
	this->fourth_octet = fourth_octet;
}

std::vector<ull> IPv4Manager::splitIP() {
	std::vector<ull> ip_splitted;

	// re 
	for (int cursor = 0; cursor != std::string::npos; ) {
		ip_splitted.push_back(
			std::stoull(
				this->__ip.substr(
					cursor, this->__ip.find(
						".", cursor) - cursor)) + 1);
		cursor = this->__ip.find(".", cursor);
		if (cursor != std::string::npos) cursor += 1;
	}

	for (const auto& el : ip_splitted) {
		std::cout << el << " ";
	}
	std::cout << '\n';

	return ip_splitted;
}

bool IPv4Manager::validateIP(std::string ip) {
	std::vector<short> ip_splitted;

	// try to split ip, but first check syntax

	// check each octet values 0-255

	// check where are dot's i.e. 1..1.1

	return true;
}

std::ostream& operator<<(std::ostream& os, IPv4Manager& ip) {
	os << ip.getIP_str() << std::endl;
	return os;
}

std::istream& operator>>(std::istream& is, IPv4Manager& ip) {
	is >> ip.__ip;
	return is;
}

bool operator<(IPv4Manager& ip1, IPv4Manager& ip2) {
	const auto ip1_ull = ip1.splitIP();
	const auto ip2_ull = ip2.splitIP();

	if (ip1_ull.front() > ip2_ull.front()) return false;
	if (ip1_ull.at(1) > ip2_ull.at(1)) return false;
	if (ip1_ull.at(2) > ip2_ull.at(2)) return false;

	return ip1_ull.back() < ip2_ull.back();
}

bool operator>(IPv4Manager& ip1, IPv4Manager& ip2) {
	const auto ip1_ull = ip1.splitIP();
	const auto ip2_ull = ip2.splitIP();

	if (ip1_ull.front() < ip2_ull.front()) return false;
	if (ip1_ull.at(1) < ip2_ull.at(1)) return false;
	if (ip1_ull.at(2) < ip2_ull.at(2)) return false;

	return ip1_ull.back() > ip2_ull.back();
}

bool operator==(IPv4Manager& ip1, IPv4Manager& ip2) {
	const auto ip1_ull = ip1.splitIP();
	const auto ip2_ull = ip2.splitIP();

	return  ip1_ull.front() == ip2_ull.front() &&
		ip1_ull.at(1) == ip2_ull.at(1) &&
		ip1_ull.at(2) == ip2_ull.at(2) &&
		ip1_ull.back() == ip1_ull.back();
}

bool operator!=(IPv4Manager& ip1, IPv4Manager& ip2) {
	const auto ip1_ull = ip1.splitIP();
	const auto ip2_ull = ip2.splitIP();

	return ip1_ull.front() != ip2_ull.front() ||
		ip1_ull.at(1) != ip2_ull.at(1) ||
		ip1_ull.at(2) != ip2_ull.at(2) ||
		ip1_ull.back() != ip2_ull.back();
}

ull operator-(IPv4Manager& ip1, IPv4Manager& ip2) {
	const auto ip_1_splitted = ip1.splitIP();
	const auto ip_2_splitted = ip2.splitIP();

	const short octet = 256; // how many ip's are in 1 octet
	short count_octet = 3; // how many times to multiply

	auto lambda_octets = [&](const ull result, ull next) {
		ull temp = 256;
		for (short index = 1; index < count_octet; ++index) {
			temp *= octet;
		}
		--count_octet;
		return result + (next * temp);
	};
	
	ull ip1_sum = std::accumulate(std::begin(ip_1_splitted),
		std::begin(ip_1_splitted)+2, 1, lambda_octets);
	ip1_sum += ip_1_splitted.at(3);

	count_octet = 3;
	ull ip2_sum = std::accumulate(std::begin(ip_2_splitted),
		std::begin(ip_2_splitted)+2, 1, lambda_octets);
	ip2_sum += ip_2_splitted.at(3);

	std::cout << ip1_sum << ' ' << ip2_sum << '\n';
	return (ip1_sum > ip2_sum) ? 
		(ip1_sum - ip2_sum - 1): (ip2_sum - ip1_sum - 1);
}

IPv4Manager::~IPv4Manager() {
	if (!this->__ip.empty())
		this->__ip.clear();
}

void print(const ull& o1, const ull& o2, const ull& o3, const ull& o4) {
	std::cout << o1 << '.' << o2 << '.' << o3 << '.' << o4 << '\n';
}

void printAllAddresses(IPv4Manager& ip1, IPv4Manager& ip2) {
	if (ip1 > ip2) std::swap(ip1, ip2);

	auto ip_lower = ip1.splitIP();
	auto ip_higher = ip2.splitIP();

	// because of incrementing in split function we are taking it back to true values
	--ip_lower[0]; --ip_lower[1]; --ip_lower[2]; --ip_lower[3];
	--ip_higher[0]; --ip_higher[1]; --ip_higher[2]; --ip_higher[3];

	short octet_highest = ip_lower.front(),
		octet_second_h = ip_lower.at(1),
		octet_third_h = ip_lower.at(2),
		octet_lowest = ip_lower.back();

	std::cout << "---------------------------------------------\n";
	// print all ip's till first(highest) octet's are the same
	for (; octet_highest <= ip_higher.front(); ++octet_highest) {
	
		for (; octet_second_h <= 255; ++octet_second_h) {
			if (octet_second_h == 255) {
				octet_second_h = 0;
				break;
			}
		
			for (; octet_third_h <= 255; ++octet_third_h) {
				if (octet_third_h == 255) {
					octet_third_h = 0;
					break;
				}
			
				for (; octet_lowest <= 255; ++octet_lowest) {
					print(octet_highest, octet_second_h, octet_third_h, octet_lowest);
					if (octet_highest == ip_higher.front() && octet_second_h == ip_higher.at(1) &&
						octet_third_h == ip_higher.at(2) && octet_lowest == ip_higher.back()) {
						return;
					}
					else if (octet_lowest == 255) {
						octet_lowest = 0;
						break;
					}
				}
			}
		}
	}
	std::cout << "---------------------------------------------\n";
}

