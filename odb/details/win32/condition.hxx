// file      : odb/details/win32/condition.hxx
// author    : Boris Kolpackov <boris@codesynthesis.com>
// copyright : Copyright (c) 2009-2010 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#ifndef ODB_DETAILS_WIN32_CONDITION_HXX
#define ODB_DETAILS_WIN32_CONDITION_HXX

#include <odb/pre.hxx>

#include <windows.h>

#include <cstddef> // std::size_t

#include <odb/details/export.hxx>
#include <odb/details/win32/mutex.hxx>

namespace odb
{
  namespace details
  {
    class LIBODB_EXPORT condition
    {
    public:
      ~condition ();
      condition (mutex&);

      void
      signal ();

      void
      wait ();

    private:
      condition (const condition&);
      condition& operator= (const condition&);

    private:
      mutex& mutex_;
      HANDLE event_;

      std::size_t waiters_;
      std::size_t signals_;
    };
  }
}

#include <odb/details/win32/condition.ixx>

#include <odb/post.hxx>

#endif // ODB_DETAILS_WIN32_CONDITION_HXX
