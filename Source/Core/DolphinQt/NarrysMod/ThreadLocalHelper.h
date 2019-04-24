#pragma once
#include <cstddef>

//Source https://blogs.msdn.microsoft.com/jeremykuhne/2006/04/18/using-clr-and-__declspecthread/
template <typename T>
class ThreadLocal

{
private:
  DWORD threadLocalIndex;

  ThreadLocal(ThreadLocal const&);

  T* GetPointer(void) { return static_cast<T*>(::TlsGetValue(this->threadLocalIndex)); }

  void SetPointer(T* value) { ::TlsSetValue(this->threadLocalIndex, static_cast<void*>(value)); }

public:
  void SetValue(const T& value)

  {
    T* currentPointer = this->GetPointer();

    if (currentPointer == NULL)

    {
      this->SetPointer(new T(value));
    }

    else

    {
      *currentPointer = value;
    }
  }

  T& GetValue(void)

  {
    T* currentPointer = this->GetPointer();

    if (currentPointer == NULL)

    {
      this->SetPointer(new T());
    }

    return *this->GetPointer();
  }

  void DeleteValue()

  {
    T* currentPointer = this->GetPointer();

    if (currentPointer != NULL)

    {
      delete currentPointer;

      this->SetPointer(NULL);
    }
  }

  ThreadLocal(const T& value)

  {
    this->threadLocalIndex = ::TlsAlloc();

    this->SetValue(value);
  }

  ThreadLocal() { this->threadLocalIndex = ::TlsAlloc(); }

  virtual ~ThreadLocal()

  {
    this->DeleteValue();

    ::TlsFree(this->threadLocalIndex);
  }
};
