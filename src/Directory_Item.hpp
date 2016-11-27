//Directory_Item.hpp

/*
*Cette classe abstraite est une base
*représentant tout ce qu'on peut
*trouver dans un répertoire
*(répertoire, son, executable, image, txt...)
*/

#ifndef DIRECTORY_ITEM_H_
#define DIRECTORY_ITEM_H_

//#include <sys/stat.h>
#include <string>
#include "general_exceptions.hpp"

/*les modes pour POSIX:
*3 chiffres
*u g o (user group other)
*0 = aucun droit
*1 = execution, 2 = écriture, 3 = execution + écriture 
*4 = lecture, 5 = execution + lecture, 6 = lecture + écriture
*7 = tout les droits
*/

mode_t getMode(short mode);

class Directory_Item
{
  //fonctions amies

public:
  //constructeurs
  Directory_Item(std::string const& path);
  Directory_Item(Directory_Item const& Obj) = delete;

  //destructeur
  virtual ~Directory_Item();

  //méthodes statiques et swap
  static bool exist(std::string const &path);

  //accesseurs
  std::string getPath() const;

  //mutateurs
  void setPath(std::string const& path);

  //méthodes
  void load();
  void close();
  bool isOpen() const;
  bool isPathSet() const;
  bool exist() const;
  void remove();

  //opérateurs méthodes ( =, (), [], -> )
  Directory_Item& operator=(Directory_Item const& Obj) = delete;

protected:
  //attributs
  std::string _path;
};
//opérateurs non méthodes (+, ++, -, --, +=, -=, /=, *=, %=, +, -, *, /, %, ==, !=, <, >, <=, >=, <<, >> )

#endif //DIRECTORY_ITEM_H_
