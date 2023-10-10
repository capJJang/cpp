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

bool comparePair(const std::pair<std::string, double> &element,
                 const std::string &key) {
  return element.first < key;
}

void BitcoinExchange::printRate() {
  std::vector<std::pair<std::string, double> >::iterator inputIt;
  std::vector<std::pair<std::string, double> >::iterator rateIt;
  for (inputIt = input.begin(); inputIt != input.end(); ++inputIt) {
    try {
      rateIt = std::lower_bound(exchangeRate.begin(), exchangeRate.end(),
                                inputIt->first, comparePair);
      if (rateIt->first != inputIt->first) --rateIt;
      if (!isValidDate(inputIt->first) || !isValidDate(rateIt->first))
        throw std::runtime_error("Error: bad input => " + inputIt->first);
      if (inputIt->first == "Invalid delimeter")
        throw std::runtime_error(rateIt->first);
      if (inputIt->second == NUMBER_TOO_LARGE ||
          rateIt->second == NUMBER_TOO_LARGE)
        throw std::runtime_error("Error: too a large number.");
      if (inputIt->second == NEGATIVE_VALUE || rateIt->second == NEGATIVE_VALUE)
        throw std::runtime_error("Error: not a positive number.");
      if (inputIt->second == BAD_INPUT || rateIt->second == BAD_INPUT)
        throw std::runtime_error("Error: invlaid format");
      std::cout << inputIt->first << " => " << inputIt->second << " = "
                << inputIt->second * rateIt->second << std::endl;
    } catch (const std::exception &e) {
      std::cerr << e.what() << '\n';
    }
  }
}

double BitcoinExchange::toDouble(const std::string &userInput) {
  std::stringstream ss(userInput);
  double ret;

  ss >> ret;
  if (ss.fail()) ret = BAD_INPUT;
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

double BitcoinExchange::isValidValue(const double value) {
  if (value < static_cast<double>(0)) return NEGATIVE_VALUE;
  if (value > static_cast<double>(1000)) return NUMBER_TOO_LARGE;
  return value;
}

void BitcoinExchange::extractValue(const std::string &line, double &value,
                                   const std::string &deli) {
  const char *deli_pos = std::strstr(line.c_str(), deli.c_str());
  if (deli_pos == 0)
    value = BAD_INPUT;
  else {
    value = isValidValue(toDouble(deli_pos + deli.size()));
  }
}

void BitcoinExchange::extractKey(const std::string &line, std::string &key,
                                 const std::string &deli) {
  const char *deli_pos = std::strstr(line.c_str(), deli.c_str());
  if (deli_pos == 0)
    key = line;
  else
    key = line.substr(0, deli_pos - line.data());
  // std::cout << key << std::endl;
}

void BitcoinExchange::exchangeRateReader() {
  std::string key;
  double value;
  std::string inputBuffer;

  std::ifstream is("data.csv");

  if (is.is_open() == false) {
    std::cerr << "Data file open failed" << std::endl;
    exit(1);
  }

  std::getline(is, inputBuffer);
  while (std::getline(is, inputBuffer)) {
    extractKey(inputBuffer, key, ",");
    extractValue(inputBuffer, value, ",");
    exchangeRate.push_back(std::make_pair(key, value));
  }
  std::sort(exchangeRate.begin(), exchangeRate.end());
}

void BitcoinExchange::inputParser(const std::string &userInput) {
  std::string key;
  double value;
  std::string delimeter;
  std::string inputBuffer;

  std::ifstream is(userInput.c_str());
  if (is.is_open() == false) {
    std::cerr << userInput << " open failed" << std::endl;
    exit(1);
  }
  std::getline(is, inputBuffer);
  while (std::getline(is, inputBuffer)) {
    extractKey(inputBuffer, key, " | ");
    extractValue(inputBuffer, value, " | ");
    input.push_back(std::make_pair(key, value));
  }
}
