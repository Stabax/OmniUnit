//Exception.hpp

/*
*Cette classe à sémentique d'entité est
*une interface pour des exceptions spécialisées.
*/


#ifndef EXCEPTION_HPP_
#define EXCEPTION_HPP_

#include <exception>

#include "Loggable.hpp"


namespace stb
{

  class Exception : public std::exception, public Loggable
  {
    //fonctions amies
    
  public:   
    //constructeurs
    explicit Exception(std::string const &reason,std::string const &senderFunction, std::string const &senderFile, std::string const& logPath = defaultLogPath) noexcept;

    //destructeur
    virtual ~Exception() noexcept;

    //méthodes statiques et swap
    static void setDefaultLogPath(std::string const& logPath) noexcept;
    static std::string getDefaultLogPath() noexcept;

    //accesseurs
    std::string getDate() const noexcept;
    std::string getSenderFunction() const noexcept;
    std::string getSenderFile() const noexcept;

    //mutateurs

    //méthodes
    virtual const char* what() const noexcept;
    virtual void log() const noexcept;
    
    //opérateurs méthodes ( =, (), [], ->, +=, -=, /=, *=, %=)

  protected:
    //attributs
    std::string _reason; //quel est le problème ?
    std::string _date; //quand le problème est il survenu ?
    std::string _senderFunction; //dans quelle fonction a été créé Le problème ?
    std::string _senderFile; //dans quel fichier CPP a été créé le problème ?

    static std::string defaultLogPath;
    
  };
  typedef Exception Except;
  
  //opérateurs non méthodes (+, ++, -, --, -, *, /, %, ==, !=, <, >, <=, >=, <<, >> )
  
}//namespace

#endif //EXCEPTION_HPP_