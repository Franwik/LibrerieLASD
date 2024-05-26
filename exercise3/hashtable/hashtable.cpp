
namespace lasd {

// Hashable
/* ************************************************************************** */

// Operators

class Hashable<int> {
public:
  unsigned long operator()(const int &dat) { return (dat * dat); }
};

class Hashable<double> {
public:
  unsigned long operator()(const double &dat) {
    long integer = floor(dat);
    long fractional = pow(2, 24) * (dat - integer);
    return (integer * fractional);
  }
};

class Hashable<string> {
public:
  unsigned long operator()(const std::string &dat) {
    unsigned long hash = 5381;
    for (unsigned long i = 0; i < dat.length(); i++) {
      hash = (hash << 5) + dat[i];
    }
    return hash;
  }
};

/* ************************************************************************** */

} // namespace lasd
