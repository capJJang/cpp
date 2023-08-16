class Fixed
{
private:
	int					numberValue;
	static const int	fractionalBits = 8;
public:
	Fixed(/* args */);
	~Fixed();
	Fixed(const Fixed& origin);
	Fixed &operator=(const Fixed &fix);
	int		getRawBits() const;
	void	setRawBits(int const raw);
};
