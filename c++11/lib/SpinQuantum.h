#ifndef _SPIN_QUANTUM_H
#define _SPIN_QUANTUM_H 1

#include <iostream>
#include <iomanip>
#include <boost/serialization/serialization.hpp>

class SpinQuantum {
private:
  friend class boost::serialization::access;
  template <class Archive>
  void serialize(Archive& ar, const unsigned int version) { ar & m_nspin; }
public:
  const static SpinQuantum zero() { return SpinQuantum(0); }
  SpinQuantum() : m_nspin(0) { }
  SpinQuantum(int nspin) : m_nspin(nspin) { }

  inline bool operator== (const SpinQuantum& other) const { return m_nspin == other.m_nspin; }
  inline bool operator!= (const SpinQuantum& other) const { return m_nspin != other.m_nspin; }
  inline bool operator<  (const SpinQuantum& other) const { return m_nspin <  other.m_nspin; }
  inline bool operator>  (const SpinQuantum& other) const { return m_nspin >  other.m_nspin; }

  inline SpinQuantum operator* (const SpinQuantum& other) const { return SpinQuantum(m_nspin+other.m_nspin); }

  inline bool   parity()  const { return false; }
  inline double clebsch() const { return 1.0; }

  SpinQuantum operator+ () const { return SpinQuantum(+m_nspin); }
  SpinQuantum operator- () const { return SpinQuantum(-m_nspin); }

  friend std::ostream& operator<< (std::ostream& ost, const SpinQuantum& q) {
    ost << "(" << std::setw(2) << q.m_nspin << ")";
    return ost;
  }
private:
  int m_nspin;
};

#endif // _SPIN_QUANTUM_H
