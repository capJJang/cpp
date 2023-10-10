#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

#define NEGATIVE_VALUE -1
#define NUMBER_TOO_LARGE -2
#define BAD_INPUT -3

class BitcoinExchange {
 private:
  std::vector<std::pair<std::string, double> > exchangeRate;
  std::vector<std::pair<std::string, double> > input;

  BitcoinExchange(/* args */);
  BitcoinExchange(const BitcoinExchange &rhs);
  BitcoinExchange &operator=(const BitcoinExchange &rhs);

  void initExchanger(const std::string &userInput);
  // bool comparePair(const std::pair<std::string, double> &element,
  //                  const std::string &key);
  void extractKey(const std::string &line, std::string &key,
                  const std::string &deli);
  void extractValue(const std::string &line, double &value,
                    const std::string &deli);
  bool isValidDate(const std::string &date);
  double isValidValue(const double value);
  double toDouble(const std::string &userInput);
  void exchangeRateReader();
  void inputParser(const std::string &userInput);
  void printRate();

 public:
  BitcoinExchange(const std::string &userInput);
  ~BitcoinExchange();
};

#endif