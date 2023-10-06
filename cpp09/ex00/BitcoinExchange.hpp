#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>

class BitcoinExchange {
 private:
  std::map<std::string, float> exchangeRate;
  std::multimap<std::string, float> input;

  BitcoinExchange(/* args */);
  BitcoinExchange(const BitcoinExchange &rhs);
  BitcoinExchange &operator=(const BitcoinExchange &rhs);

  void initExchanger(const std::string &userInput);
  bool isValidDate(const std::string &date);
  bool isValidValue(const std::string &value);
  float toFloat(std::string &userInput);
  void exchangeRateReader();
  void inputParser(const std::string &userInput);

 public:
  BitcoinExchange(const std::string &userInput);
  ~BitcoinExchange();
};

#endif