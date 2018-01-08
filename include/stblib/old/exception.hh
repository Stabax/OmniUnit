//exception.hh

/*
Copyright (c) 1998, Regents of the University of California All rights
reserved. Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

    Redistributions of source code must retain the above copyright notice,
    this list of conditions and the following disclaimer.
    Redistributions in binary form must reproduce the above copyright notice,
    this list of conditions and the following disclaimer in the documentation
    and/or other materials provided with the distribution.
    Neither the name of the University of California, Berkeley nor the names
    of its contributors may be used to endorse or promote products derived
    from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS "AS IS" AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE REGENTS AND CONTRIBUTORS BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/


#ifndef EXCEPTION_HH_
#define EXCEPTION_HH_

#include <exception>
#include <string>

namespace stb
{



//=============================================================================
//=============================================================================
// EXCEPTIONS DEFINITION ======================================================
//=============================================================================
//=============================================================================



class exception : public std::exception
{
public:

  exception(std::string const& msg, std::string const& name):
  _msg("[stblib.exception - " + name + " : " + msg + "]")
  {
  }

  virtual ~exception()
  {
  }

  virtual const char* what() const noexcept
  {
    return _msg.c_str();
  }

protected:
  std::string const _msg;
};





class Date_exception : public exception
{
public:

  Date_exception(std::string const& msg):
  exception(msg, "Date_exception")
  {
  }

  virtual ~Date_exception()
  {
  }
};





class Unit_exception : public exception
{
public:

  Unit_exception(std::string const& msg):
  exception(msg, "Unit_exception")
  {
  }

  virtual ~Unit_exception()
  {
  }
};



}//namespace stb

#endif //EXCEPTION_HH_