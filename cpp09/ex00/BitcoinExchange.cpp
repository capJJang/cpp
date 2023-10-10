#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(/* args */) {}

BitcoinExchange::BitcoinExchange(const std::string &userInput) {
  initExchanger(userInput);
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &rhs) {
  this->exchangeRate = rhs.exchangeRate;
  this->input = rhs.input;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &rhs) {
  this->exchangeRate = rhs.exchangeRate;
  this->input = rhs.input;
  return *this;
}

void BitcoinExchange::initExchanger(const std::string &userInput) {
  exchangeRateReader();
  inputParser(userInput);
  printRate();
}

void BitcoinExchange::printRate() {
  std::map<std::string, float>::iterator inputIt;
  std::map<std::string, float>::iterator rateIt;
  for (inputIt = input.begin(); inputIt != input.end(); ++inputIt) {
    try {
      rateIt = exchangeRate.lower_bound(inputIt->first);
      std::cout << "rateIT : " << rateIt->first <<"\tinputIt : " << inputIt->first<<std::endl;
      if (!isValidDate(inputIt->first) || !isValidDate(rateIt->first))
        throw std::runtime_error("Error: bad input => " + inputIt->first);
      if (inputIt->first == "Invalid delimeter")
        throw std::runtime_error(rateIt->first);
      if (isValidValue(inputIt->second) == -1.0f ||
          isValidValue(rateIt->second) == -1.0f)
        throw std::runtime_error("Error: too large number.");
      if (isValidValue(inputIt->second) == -2.0f ||
          isValidValue(rateIt->second) == -2.0f)
        throw std::runtime_error("Error: not a positive number.");
      if (isValidValue(inputIt->second) == -3.0f ||
          isValidValue(rateIt->second) == -3.0f)
        throw std::runtime_error("Error: invlaid format");
      std::cout << inputIt->first << " => " << inputIt->second << " = "
                << inputIt->second * rateIt->second << std::endl;
    } catch (const std::exception &e) {
      std::cerr << e.what() << '\n';
    }
  }
}

float BitcoinExchange::toFloat(std::string &userInput) {
  std::stringstream ss(userInput);
  float ret;

  ss >> ret;
  if (ss.fail()) ret = -3.0f;
  return ret;
}

bool BitcoinExchange::isValidDate(const std::string &date) {
  if (date.length() != 10) return false;

  int year = std::atoi(date.substr(0, 4).c_str());
  int month = std::atoi(date.substr(5, 2).c_str());
  int day = std::atoi(date.substr(8, 2).c_str());

  if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31) return false;
  if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
    return false;
  if (month == 2) {
    bool isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    if ((isLeapYear && day > 29) || (!isLeapYear && day > 28)) return false;
  }

  return true;
}

float BitcoinExchange::isValidValue(const float value) {
  if (value < 0) return -1.0f;
  if (value > 1000) return -2.0f;
  return value;
}

void BitcoinExchange::exchangeRateReader() {
  std::string key;
  std::string value;
  std::string inputBuffer;

  std::ifstream is("data.csv");

  if (is.is_open() == false) {
    std::cerr << "Data file open failed" << std::endl;
    exit(1);
  }

  std::getline(is, inputBuffer);
  while (std::getline(is, inputBuffer)) {
    if (inputBuffer.size() < 11) {
      value = -3;
      continue;
    }
    key = inputBuffer.substr(0, 10);
    value = inputBuffer.substr(11, inputBuffer.size() - 1);
    exchangeRate.insert(std::make_pair(key, toFloat(value)));
  }
}

void BitcoinExchange::inputParser(const std::string &userInput) {
  std::string key;
  std::string value;
  std::string delimeter;
  std::string inputBuffer;

  std::ifstream is(userInput.c_str());
  if (is.is_open() == false) {
    std::cerr << userInput << " open failed" << std::endl;
    exit(1);
  }
  std::getline(is, inputBuffer);
  while (std::getline(is, inputBuffer)) {
    if (inputBuffer.size() < 11) {
      value = -3;
      continue;
    }
    key = inputBuffer.substr(0, 10);
    value = inputBuffer.substr(13, inputBuffer.size() - 1);
    delimeter = inputBuffer.substr(10, 3);
    if (delimeter != " | ") key = "Invalid delimeter";
    input.insert(std::make_pair(key, toFloat(value)));
  }
}
