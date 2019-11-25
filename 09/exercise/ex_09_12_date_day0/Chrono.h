

namespace Chrono {
enum class Month {
    jan=1, feb, mar, apr, may, jun,
    jul, aug, sep, oct, nov, dec
};

Month operator++(Month const& m);

class Date {
public:
    class Invalid { };
    Date(int y, Month m, int d);
    Date(long int d);
    Date();

    //Nonmodifying operations
    long int days() const { return d; }
    int day() const;
    Month month() const;
    int year() const;

    //Modifying operations
    void add_day(int n);
    void add_month(int n);
    void add_year(int n);

private:
    long int d;
};

bool is_date(int y, Month m, int d);
bool leapyear(int y);
bool operator==(const Date& a, const Date& b);
bool operator!=(const Date& a, const Date& b);
std::ostream& operator<<(std::ostream& os, const Date& d);
std::istream& operator>>(std::istream& is, Date& dd);
} // Chrono
