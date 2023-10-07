#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(/* args */) {}

BitcoinExchange::BitcoinExchange(const std::string &userInput) {
  initExchanger(userInput);
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &rhs) { (void)rhs; }

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &rhs) {
  (void)rhs;
  return *this;
}

void BitcoinExchange::initExchanger(const std::string &userInput) {
  exchangeRateReader();
  inputParser(userInput);
}

void BitcoinExchange::errFileCorrupted() {
  std::cerr << "File corrupted" << std::endl;
  exit(1);
}

float BitcoinExchange::toFloat(std::string &userInput) {
  std::stringstream ss(userInput);
  float ret;

  ss >> ret;
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

bool BitcoinExchange::isValidValueForExchangeRate(const std::string &value) {
  std::stringstream ss(value);
  float floatValue;

  ss >> floatValue;
  return !ss.fail() && floatValue >= 0;
}

bool BitcoinExchange::isValidValueForInput(const std::string &value) {
  std::stringstream ss(value);
  float floatValue;

  ss >> floatValue;
  return !ss.fail() && (floatValue >= 0 && floatValue <= 1000);
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
  if (inputBuffer != "date,exchange_rate") errFileCorrupted();
  while (std::getline(is, inputBuffer)) {
    key = inputBuffer.substr(0, 10);
    value = inputBuffer.substr(11, inputBuffer.size() - 1);
    if ((isValidDate(key) && isValidValueForExchangeRate(value)) == false)
      errFileCorrupted();
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
  if (inputBuffer != "date | value") errFileCorrupted();
  while (std::getline(is, inputBuffer)) {
    key = inputBuffer.substr(0, 10);
    if (!isValidDate(key)) errFileCorrupted();
    value = inputBuffer.substr(13, inputBuffer.size() - 1);
    delimeter = inputBuffer.substr(10, 3);
    if (delimeter != " | ") errFileCorrupted();
    if (isValidValueForInput(value) == false) errFileCorrupted();
    input.insert(std::make_pair(key, toFloat(value)));
  }
  // for (std::map<std::string, float>::const_iterator it = input.begin();
  // it != input.end(); ++it)
  // std::cout << it->first << " | " << it->second << std::endl;
}
